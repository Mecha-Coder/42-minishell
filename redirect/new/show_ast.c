#include "header.h"

static void show_info(t_tree *node);
static void print_indent_level(int i);
static void show_token_2(t_token *token);

/*Visualize tree*/
void visualize_tree(t_tree *node, int level)
{
    if (!node)
        return;
    print_indent_level(level);
    show_info(node);
    level++;
    visualize_tree(node->left, level);
    visualize_tree(node->right, level);
}


static void show_info(t_tree *node)
{
    if (node->type == AND)
        printf("AND");
    else if (node->type == CMD)
    {
        printf("CMD");
        printf("\nIN: ");
        show_token_2(node->in);
        printf("\nOUT: ");
        show_token_2(node->out);
    }
    printf("\n");
}

static void show_token_2(t_token *token)
{
    int i;

    i = -1;
    if (!token)
        return ;
    while(token[++i].type)
    {
        if (token[i].type == HERE)  
            printf("%s%s ","<HERE>",token[i].content);
        else if (token[i].type == STR)
            printf("%s%s ","<STR>",token[i].content);
    }
}

static void print_indent_level(int i)
{
    while (i > 1 && i--)
        printf("      ");
    if (i)
        printf("|_____");
}

