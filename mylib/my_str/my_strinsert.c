/*
** EPITECH PROJECT, 2020
** mylib
** File description:
** my_strinsert
*/

#include <stdlib.h>
#include "my.h"

void my_strinsert(char **str, char *insertion, int pos)
{
    int len = my_strlen(*str);
    int insert_len = my_strlen(insertion);
    char *newstr;

    if (pos > len + 1)
        return;
    newstr = malloc(sizeof(char) * (len + insert_len + 1));
    my_strncpy(newstr, *str, pos);
    printf("-%s\n", newstr);
    my_strcat(newstr, insertion);
    printf("-%s\n", newstr);
    my_strcat(newstr, *str + pos);
    printf("-%s\n", newstr);
    free(*str);
    *str = newstr;
}