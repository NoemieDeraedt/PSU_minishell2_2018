/*
** EPITECH PROJECT, 2018
** my_strncat.c
** File description:
** lib
*/

#include "../../include/my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    char len_dest;

    len_dest = my_strlen(dest);
    for (i = 0; i < nb && src[i] != 0; i++)
        dest[len_dest + i] = src[i];
    dest[len_dest + i] = '\0';
    return (dest);
}
