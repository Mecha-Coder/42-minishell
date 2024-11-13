#include "header.h"

void prompt_heredoc(t_tree *node)
{
    int i;

    i = -1;
    if (!node)
        return;
    while (node->in && node->in[++i].type)
    {
        if (node->in[i].type == HERE)
            heredoc(node->in[i].herefd, node->in[i].content);
    }
    prompt_heredoc(node->left);
    prompt_heredoc(node->right);
}


void execute(t_tree *node, int *reset)
{
    if (!node)
        return ;
    
    if (node->type == AND)
    {
        execute(node->left, reset);
        execute(node->right, reset);
    }
    else if (node->type == CMD)
    {
        pid_t id;
        int i = -1;
        int fd;

        while (node->in && node->in[++i].type)
        {
            if (node->in[i].type == HERE)
            {
                close(node->in[i].herefd[1]);
                dup2(node->in[i].herefd[0], STDIN_FILENO);
                close(node->in[i].herefd[0]);
            }
            else // File failed to open (stop execute)
            {
                fd = open(node->in[i].content, O_RDONLY, 0777);
                if (fd == -1)
                {
                    printf("%s: No such file or directory\n", node->in[i].content);
                    return ;
                }
                dup2(fd, STDIN_FILENO);
                close(fd);
            }
        }


        while (node->out && node->out[++i].type)
        {
            fd = open(node->out[i].content, O_WRONLY | O_CREAT | O_TRUNC, 0777);
            if (fd == -1)
            {
                printf("%s: Output issue\n", node->out[i].content);
                return ;
            }
            dup2(fd, STDOUT_FILENO);
            close(fd);
        }
    
        id = fork();
        if (!id)
            execve(node->path, node->arg, NULL);

        wait(NULL);
        dup2(reset[STDIN_FILENO], STDIN_FILENO);
        dup2(reset[STDOUT_FILENO], STDOUT_FILENO);

        //Reset STDIN and STDOUT
    }
}



int main()
{
    char *arg1[] = {"echo", "Hello", NULL};
    char *path1  = "/usr/bin/echo"; 

    char *arg2[] = {"echo", "Hi", NULL};
    char *path2  = "/usr/bin/echo"; 

    char *arg3[] = {"cat", NULL};
    char *path3  = "/usr/bin/cat"; 

    t_token t4[] = {
        {HERE, "DONE", 0, 0},
        {HERE, "EOF", 0, 0},
        {RD, "dummy.txt", 0, 0},
        {0, NULL, 0, 0}
    };

    t_token t5[] = {
        {HERE, "STOP", 0, 0},
        {0, NULL, 0, 0}
    };

    t_token t6[] = {
        {WR, "out.txt", 0, 0},
        {0, NULL, 0, 0}
    };
       
            //   info  type arg   path    in   out   left  right pipe  term
    t_tree n5 = {NULL, CMD, arg2,  path2, NULL,  t6,   NULL, NULL, NULL, 0};
    t_tree n4 = {NULL, CMD, arg1,  path1,   t5,  NULL, NULL, NULL, NULL, 0};
    t_tree n3 = {NULL, CMD, arg3,  path3,   t4,  NULL, NULL, NULL, NULL, 0};
    t_tree n2 = {NULL, AND, NULL,  NULL,   NULL, NULL,  &n4,  &n5, NULL, 0};
    t_tree n1 = {NULL, AND, NULL,  NULL,   NULL, NULL,  &n2,  &n3, NULL, 0};

    //visualize_tree(&n1, 0);

    int reset[2];

    reset[STDIN_FILENO] = dup(STDIN_FILENO);
    reset[STDOUT_FILENO] = dup(STDOUT_FILENO);

    prompt_heredoc(&n1);
    execute(&n1, reset);
}