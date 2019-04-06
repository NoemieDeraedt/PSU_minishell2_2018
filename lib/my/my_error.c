/*
** EPITECH PROJECT, 2019
** my_error.c
** File description:
** my_error.c
*/

#include "../../include/my.h"

void my_error(char *str)
{
    write(2, str, my_strlen(str));
}