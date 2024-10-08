#include "header.h"

// function handles numbers and parentheses
// The main parsing function processes tokens based on their precedence.
// It recursively parses sub-expressions, ensuring that operators with higher precedence are evaluated first.

int parse_primary() 
{
    if (current_token.type == TOKEN_NUMBER)
    {
        int value = current_token.value;
        next_token();
        return value;
    } 
    
    else if (current_token.type == TOKEN_LPAREN) 
    {
        next_token();
        int value = parse_expression(0);
        if (current_token.type != TOKEN_RPAREN) 
        {
            fprintf(stderr, "Expected ')'\n");
            exit(1);
        }
        next_token();
        return value;

    } 
    
    else 
    {
        fprintf(stderr, "Unexpected token\n");
        exit(1);
    }
}
