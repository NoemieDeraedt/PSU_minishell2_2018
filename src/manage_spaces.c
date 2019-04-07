/*
** EPITECH PROJECT, 2019
** manage_spaces.c
** File description:
** manage_spaces.c
*/

#include "my.h"

char *delete_spaces(char *str)
{
    int len_str = my_strlen(str);
    char *dest = malloc(sizeof(char) * len_str + 1);
    int j = 0;

    for (int i = 0; str[i] == ' ' || str[i] == '\t'; i++)
        if (str[i] == ' ' || str[i] == '\t')
            str[i] = '~';
    for (int i = len_str - 1; str[i] == ' ' || str[i] == '\t'; i--)
        if (str[i] == ' ' || str[i] == '\t')
            str[i] = '~';
    for (int i = 0; i < my_strlen(str); i++)
        if (str[i] != '~') {
            dest[j] = str[i];
            j++;
        }
    return dest;
}