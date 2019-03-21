/*
** EPITECH PROJECT, 2018
** my_printf.c
** File description:
** my_printf
*/

#include "../../include/my.h"
#include <stdarg.h>

int conditions(char *arg1, int i, va_list args)
{
    switch (arg1[i]) {
        case 'd':
            my_put_nbr(va_arg(args, int));
            break;
        case 'c':
            my_putchar(va_arg(args, int));
            break;
        case 's':
            my_putstr(va_arg(args, char *));
            break;
        case 'l':
            my_put_nbr(va_arg(args, long));
            break;
        default:
            my_putchar('%');
            my_putchar(arg1[i]);
    }
    return i;
}

int my_printf(char *arg1, ...)
{
    int i;
    va_list args;

    va_start(args, arg1);
    for (i = 0; arg1[i]; i++) {
        if (arg1[i] == '%') {
            i++;
            i = conditions(arg1, i, args);
        } else
            my_putchar(arg1[i]);
    }
    va_end(args);
    return (0);
}
