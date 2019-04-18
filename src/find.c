/*
** EPITECH PROJECT, 2019
** find.c
** File description:
** find.c
*/

#include "my.h"

int find_equal(char *name)
{
    int j = 0;

    for (int i = 0; name[i]; i++)
        if (name[i] == '=')
            j++;
    if (j != 1)
        return 84;
    return 0;
}