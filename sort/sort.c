#include <stdio.h>
#include <string.h>
#include <stddef.h>

void sort_list(char **list)
{
    char *temp;
    int i;
    int len;

    (i = 1 , len = 0);
    while (list && list[len])
        len++;
    while (--len)
    {
        i = -1;
        while (++i < len)
        {
            if (strcmp(list[i], list[i + 1]) > 0)
            {
                temp = list[i + 1];
                list[i + 1] = list[i];
                list[i] = temp;
            }
        }
        i = -1;
        while (list[++i])
            printf("%s\n",list[i]);
        printf("%d\n==================\n", len);
    }
}

int main() {
    char *list[] = {"debouchment",
                    "zip",
                    "wendwas",
                    "incipient",
                    "natch",
                    "curio",
                    "kluge",
                    "modicum",
                    "ornery",
                    "warble",
                    "peep",
                    "styx",
                    "vestige",
                    "weald",
                    NULL};
    sort_list(list);

    return 0;
}