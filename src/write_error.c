/*
** EPITECH PROJECT, 2019
** write_error.c
** File description:
** write_error.c
*/

#include "my.h"

void command_not_found(char *str)
{
    my_error("./");
    my_error(str);
    my_error(": Command not found.\n");
}

void permission_denied(char *str)
{
    my_error("./");
    my_error(str);
    my_error(": Permission denied.\n");
}