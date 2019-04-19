/*
** EPITECH PROJECT, 2019
** argv.c
** File description:
** argv.c
*/

#include <stdlib.h>
#include "my.h"

char **fill_array(char **argv, char *input, int p)
{
    int k = 0;

    for (int j = 0; input[j] != '\n'; j++) {
        if (argv[k] == NULL)
            return NULL;
        if (input[j] == ';' || input[j] == '\0')
            return argv;
        if (input[j] == ' ') {
            argv[k][p] = '\0';
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

char **argv_in_double_array(char *input)
{
    int p = 0;
    char **argv = malloc(sizeof(char) * 100);

    if (argv == NULL)
        return NULL;
    argv[0] = malloc(sizeof(char) * 100);
    argv = fill_array(argv, input, p);
    return argv;
}