/*
** EPITECH PROJECT, 2018
** my_revstr.c
** File description:
** lib
*/

#include "../../include/my.h"

void my_revstr(char *str)
{
    int len_str;
    int i = 0;

    len_str = my_strlen(str);
    while (i <= len_str) {
        my_swap(&str[i], &str[len_str - 1]);
        i++;
        len_str--;
    }
}
