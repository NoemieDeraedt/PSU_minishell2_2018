/*
** EPITECH PROJECT, 2018
** my_isneg.c
** File description:
** lib
*/

#include <unistd.h>
#include "../../include/my.h"

void my_isneg(int n)
{
    char negative = 'N';
    char positive = 'P';

    if (n < 0) {
        my_putchar(negative);
    } else {
        my_putchar(positive);
    }
}
