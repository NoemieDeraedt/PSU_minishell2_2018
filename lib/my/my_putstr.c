/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** lib
*/

#include <unistd.h>
#include "../../include/my.h"

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}
