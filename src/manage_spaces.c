/*
** EPITECH PROJECT, 2019
** manage_spaces.c
** File description:
** manage_spaces.c
*/

#include "my.h"

void delete_spaces(char *str, char *dest)
{
    int len_str = my_strlen(str);
    int j = 0;

    for (int i = 0; str[i] == ' ' || str[i] == '\t'; i++)
        if (str[i] == ' ' || str[i] == '\t')
            str[i] = '~';
    for (int i = len_str - 1; str[i] == ' ' || str[i] == '\t' ||
        str[i] == '\n'; i--)
        if (str[i] == ' ' || str[i] == '\t')
            str[i] = '~';
    for (int i = 0; i < my_strlen(str); i++)
        if (str[i] != '~') {
            dest[j] = str[i];
            j++;
        }
    dest[j] = '\n';
}