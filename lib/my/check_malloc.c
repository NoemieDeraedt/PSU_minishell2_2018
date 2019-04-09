/*
** EPITECH PROJECT, 2019
** check_malloc.c
** File description:
** check_malloc.c
*/

#include "../../include/my.h"

void check_malloc(char *str)
{
    if (!str)
        exit(84);
}

void check_double_malloc(char **str)
{
    if (str == NULL)
        exit(84);
}