#include "header.h"

int main(int ac, char **av, char **env)
{
    (void)ac;
    (void)av;

    char *cmd1[] = {"print", "Done", "Now", NULL};
    char *cmd2[] = {"cat", NULL};
    char *cmd3[] = {"tr", "a-z", "A-Z",NULL};
    
    t_tree root, a1, a2, b1, b2;

    memset(&root, 0, sizeof(t_tree));
    memset(&a1, 0, sizeof(t_tree));
    memset(&a2, 0, sizeof(t_tree));
    memset(&b1, 0, sizeof(t_tree));
    memset(&b2, 0, sizeof(t_tree));

    root.type = PIPE;
    root.left = &a1;
    root.right = &a2;

    a1.type = PIPE;
    a1.left = &b1;
    a1.right = &b2;

    b1.type = CMD;
    b1.cmd = cmd1;
    b1.path = "/usr/bin/env";
    b1.env = env;

    b2.type = CMD;
    b2.cmd = cmd2;
    b2.path = "/usr/bin/cat";
    b2.env = env;

    a2.type = CMD;
    a2.cmd = cmd3;
    a2.path = "/usr/bin/tr";
    a2.env = env;

    printf("Exit status = %d\n", descent_tree(&root));
}