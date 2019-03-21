/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** lib
*/

#include "../../include/my.h"

void my_putstr(char const *str)
{
    int i;

    for (i = 0; str[i]; i++)
        my_putchar(str[i]);
}
