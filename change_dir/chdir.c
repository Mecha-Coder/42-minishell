#include <stdio.h>
#include <unistd.h>
#include <limits.h>

/*
char *getcwd (char *buf, size_t size);
return
 OK > buf pointer to current directory path
 KO > NULL and errno
*/
void show_current_dir(void)
{
    char dir[PATH_MAX];
    if (getcwd(dir, sizeof(dir)))  
        printf("%s\n", dir);
    else                           
        perror("getcwd() error");
}

/*
int *chdir (const *buf);
return
 OK > 0
 KO > -1 and errno
*/
int main() {
    
    show_current_dir();
    if (chdir("../") != 0)
        perror("chdir() to /usr failed");
    show_current_dir();
    return 0;
}