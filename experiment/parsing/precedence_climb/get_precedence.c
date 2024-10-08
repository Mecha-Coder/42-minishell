#include "header.h"

// function returns the precedence of operators.
// The algorithm handles binary operators by comparing their precedence and associativity to decide the order of operations
int get_precedence(TokenType type)
{
    switch (type) {
        case TOKEN_PLUS:
        case TOKEN_MINUS: return 1;
        case TOKEN_MULTIPLY:
        case TOKEN_DIVIDE: return 2;
        default: return 0;
    }
}