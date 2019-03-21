/*
** EPITECH PROJECT, 2018
** my_put_nbr.c
** File description:
** lib
*/

#include "../../include/my.h"

void my_put_nbr(int n)
{
    if (n == -2147483648)
        my_putstr("-2147483648");
    if (n >= 10) {
        my_put_nbr(n / 10);
        my_put_nbr(n % 10);
    } else
        my_putchar(48 + n);
}
