#include "../eval.h"

int isnumber(char c, int exclude_zero)
{
    if (exclude_zero && c >= '1' && c <= '9')
        return (TRUE);
    if (!exclude_zero && c >= '0' && c <= '9')
        return (TRUE);
    return (FALSE);
}

int convert_number(char *s, int size)
{
    int result, sign, i;

    result = 0;
    sign = 1;
    i = 0;

    if (s[i] == '-' && ++i)
        sign = -1;
    while (i < size)
        result = (10 * result) + (s[i++] - '0');
    return (result * sign);
}

int scan_number(t_node *node)
{
    int i, size;
    
    size = 0;
    i = strlen(node->s) - 1;

    while (i > -1)
    {
        if (isnumber(node->s[i], FALSE))
        {    
            size++;
            if (i == 0 && isnumber(node->s[i], TRUE))
            {
                node->val = convert_number(node->s, size);
                node->type = NUMBER;
                return (TRUE);
            }
        }
        else if (size && isnumber(node->s[i + 1], TRUE))
        {
            if (node->s[i] == '-')
                node->val = convert_number(&node->s[i], ++size);
            else
                node->val = convert_number(&node->s[i + 1], size);
            node->type = NUMBER;
            return (TRUE);
        }
        i--;
    }
    return (FALSE);
}

/* Main Test
void show_result(char *s)
{
    t_node *root;
    
    root = create_node();
    root->s = s;
    if (scan_number(root))
    {
        printf("-type: %d\n", root->type);
        printf("-type: %d\n", root->val);
        printf("-left: \"%p\"\n", root->left);
        printf("-right: \"%p\"\n", root->right);
    }
    else
        printf("\nIs not a number\n");
    printf("-------------------------\n\n");
}

int main()
{
    char s1[] = "  -432  ";
    show_result(s1);

    char s2[] = "342   ";
    show_result(s2);

    char s3[] = " 5444435";
    show_result(s3);

    char s4[] = "-34213";
    show_result(s4);

    char s5[] = "  -321";
    show_result(s5);

    char s6[] = "66";
    show_result(s6);

    char s7[] = "abc";
    show_result(s7);
    
    return (0);
}
*/

/* test convert_number function
int main()
{
    char s1[] = "-3424432abs";
    char s2[] = "2133 ";
    char s3[] = "-2147483648a";
    char s4[] = "2147483647--";
    char s5[] = "-2";
    char s6[] = "-1";
    char s7[] = "0";
    char s8[] = "1";
    char s9[] = "2";
    char s10[] = "-11";
    char s11[] = "111";

    printf("\n%d\n", convert_number(s1, strlen(s1) - 3));
    printf("\n%d\n", convert_number(s2, strlen(s2) - 1));
    printf("\n%d\n", convert_number(s3, strlen(s3) - 1));
    printf("\n%d\n", convert_number(s4, strlen(s4) - 2));
    printf("\n%d\n", convert_number(s5, strlen(s5)));
    printf("\n%d\n", convert_number(s6, strlen(s6)));
    printf("\n%d\n", convert_number(s7, strlen(s7)));
    printf("\n%d\n", convert_number(s8, strlen(s8)));
    printf("\n%d\n", convert_number(s9, strlen(s9)));
    printf("\n%d\n", convert_number(s10, strlen(s10)));
    printf("\n%d\n", convert_number(s11, strlen(s11)));
}
*/