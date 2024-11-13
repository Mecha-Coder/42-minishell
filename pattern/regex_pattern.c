#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int match_pattern(char *filename, char *pattern)
{
    if (*pattern == '\0')
        return *filename == '\0';
    
    if (*pattern == '*')
        return (match_pattern(filename, pattern + 1) || (*filename && match_pattern(filename + 1, pattern)));
    
    if (*pattern == *filename)
        return match_pattern(filename + 1, pattern + 1);
    
    return FALSE;
}

void test(char **filenames, char *pattern) 
{
    int i = -1;

    printf("Entity: ");
    while (filenames[++i]) 
        printf("%s | ", filenames[i]);

    printf("\nPattern: %s\n****\n", pattern);

    i = -1;
    while (filenames[++i]) 
    {
        if (match_pattern(filenames[i], pattern))
            printf("%s\n", filenames[i]);
    }
    printf("---------------------------------------\n\n");

}

int main()
{
    printf("\n\n");
    char *list1[] = {"dm.txt", "dummy2.txt", "dummy.txt", "text.txt", NULL};
    char *list2[] = {"dm.txt", "dummy2.txt", "dummy.txt", "text.txt", "test.jpg", "dump.log", NULL};

    test(list2, "*txt");
    test(list2, "du*");
    test(list2, "dummy*xt");
    test(list2, "yoyo*xt");
    
    test(list1, "*");
    test(list1,"d*m*txt");
    test(list1, "*mm*txt");
    test(list1, "*m*");
}
