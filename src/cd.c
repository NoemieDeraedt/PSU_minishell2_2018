/*
** EPITECH PROJECT, 2019
** cd.c
** File description:
** cd.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include "my.h"

int my_cd(char *input, __attribute__((unused)) char **env)
{
    char *path = malloc(sizeof(char) * my_strlen(input) + 1);
    int i;

    if (path == NULL)
        return 84;
    for (i = 0; i < my_strlen(input); i++)
        path[i] = input[i + 3];
    path[my_strlen(path) - 1] = '\0';
    chdir(path);
    if (errno == EACCES && path[0] != '.' && path[1] != '.')
        error_message(path, ": Permission denied.\n");
    if (errno == ENOTDIR && path[0] != '.' && path[1] != '.')
        error_message(path, ": Not a directory.\n");
    if (errno == ENOENT && path[0] != '.' && path[1] != '.')
        error_message(path, ": No such file or directory.\n");
    free(path);
    return 0;
}