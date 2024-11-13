#include <stdio.h>
#include <string.h>
#include <dirent.h>

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

int main() 
{
    char *pattern = "du*m*txt";

    DIR *dir = opendir(".");
    if (dir == NULL)
    {
        perror("opendir");
        return 1;
    }

    struct dirent *entity;
    entity = readdir(dir);

    while (entity != NULL) 
    {
        if (match_pattern(entity->d_name, pattern))
            printf("%s\n", entity->d_name);
        entity = readdir(dir);
    }

    closedir(dir);
    return 0;
}