#ifndef EVAL_H
#define EVAL_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>

//*********************************************/

#define NUMBER 0

#define TRUE 1
#define FALSE 0

//*********************************************/

typedef struct s_tree
{
    char *s;
    int type;
    int val;
    struct s_tree *left;
    struct s_tree * right;
} t_node;

//*********************************************/

// Buid tree
void build_tree(t_node *node);
void branch(t_node *node, int i);
int scan_number(t_node *node);
int scan_bracket(t_node *node);
int scan_bracket(t_node *node);
int scan_multiply_divide(t_node *node);
int scan_plus_minus(t_node *node);

// Utils
t_node *create_node(void);
void visualize_tree(t_node *node, int level);
void destroy_tree(t_node *node);
void detail_node(t_node *node);
int evaluate(t_node *node);

#endif