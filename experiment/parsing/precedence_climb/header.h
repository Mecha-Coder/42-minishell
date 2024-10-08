#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>

typedef enum 
{
    TOKEN_NUMBER, 
    TOKEN_PLUS, 
    TOKEN_MINUS, 
    TOKEN_MULTIPLY, 
    TOKEN_DIVIDE, 
    TOKEN_LPAREN, 
    TOKEN_RPAREN, 
    TOKEN_END 
} TokenType;

typedef struct {
    TokenType type;
    int value;
} Token;

const char *input;
Token current_token;


void    next_token();
int     parse_expression(int precedence);
int     get_precedence(TokenType type);
int     parse_primary(); 

#endif