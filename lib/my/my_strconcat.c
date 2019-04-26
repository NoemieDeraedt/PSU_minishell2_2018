/*
** EPITECH PROJECT, 2019
** my_strconcat.c
** File description:
** my_strconcat.c
*/

#include <stdlib.h>
#include "my.h"

char *my_strconcat(char *str1, char *str2)
{
    int i;
    int j = 0;
    char *dest = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2)) + 1);

    if (dest == NULL)
        return NULL;
    for (i = 0; i < my_strlen(str1); i++)
        dest[i] = str1[i];
    for (; i < my_strlen(str1) + my_strlen(str2); i++, j++)
        dest[i] = str2[j];
    dest[i] = '\0';
    return dest;
}