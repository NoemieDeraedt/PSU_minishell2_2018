/*
** EPITECH PROJECT, 2019
** cd.c
** File description:
** cd.c
*/

#include "my.h"

int my_cd(char *input)
{
    char *path = malloc(sizeof(char) * my_strlen(input) + 1);
    int i;

    if (path == NULL)
        return 84;
    for (i = 0; i < my_strlen(input); i++)
        path[i] = input[i + 3];
    path[my_strlen(path) - 1] = '\0';
    chdir(path);
    if (errno == ENOTDIR && path[0] != '.' && path[1] != '.') {
        my_error(path);
        my_error(": Not a directory.\n");
    }
    free(path);
    return 0;
}

int my_pwd(void)
{
    char *buffer = malloc(sizeof(char) * 50);
    size_t size = 42;

    if (buffer == NULL)
        return 84;
    getcwd(buffer, size);
    my_printf("%s\n", buffer);
    free(buffer);
    return 0;
}