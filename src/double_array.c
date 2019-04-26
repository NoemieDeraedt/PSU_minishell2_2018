/*
** EPITECH PROJECT, 2019
** double_array.c
** File description:
** double array
*/

#include <stdlib.h>
#include "my.h"

char **fill_path(char **argv, char *input, int p)
{
    int k = 0;

    for (int j = 5; input[j] != '\0'; j++) {
        if (argv[k] == NULL)
            return NULL;
        if (input[j] == ':') {
            argv[k][p] = '/';
            argv[k][p + 1] = '\0';
            k++;
            argv[k] = malloc(sizeof(char) * 100);
            p = 0;
        } else {
            argv[k][p] = input[j];
            p++;
        }
    }
    argv[k][p] = '\0';
    argv[k + 1] = NULL;
    return argv;
}

char **path_double_array(char *input)
{
    int p = 0;
    char **argv = malloc(sizeof(char) * 100);

    if (argv == NULL)
        return NULL;
    argv[0] = malloc(sizeof(char) * 100);
    argv = fill_path(argv, input, p);
    return argv;
}