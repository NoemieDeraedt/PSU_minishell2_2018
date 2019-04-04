/*
** EPITECH PROJECT, 2019
** write_error.c
** File description:
** write_error.c
*/

#include "my.h"

void command_not_found(char *str)
{
    write(2, "./", 2);
    write(2, str, my_strlen(str));
    write(2, ": Command not found.\n", 22);
}

void permission_denied(char *str)
{
    write(2, str, my_strlen(str));
    write(2, ": Permission denied.\n", 22);
}