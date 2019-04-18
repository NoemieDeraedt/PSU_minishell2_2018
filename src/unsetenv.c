/*
** EPITECH PROJECT, 2019
** unsetenv.c
** File description:
** unsetenv.c
*/

#include <stdlib.h>
#include "my.h"

int compare_env(char *input, char *str, int j)
{
    for (int i = 0; str[i] != '='; i++)
        if (input[i + j] != str[i])
            return 84;
    return 0;
}

int find_env_var(char *input, char **env, int j)
{
    int i;

    for (i = 0; env[i]; i++) {
        if (compare_env(input, env[i], j) == 0)
            return i;
    }
    return -1;
}

int my_unsetenv(char *input, char **my_env)
{
    int i = find_env_var(input, my_env, 9);

    if (i == -1)
        return 0;
    free(my_env[i]);
    my_env[i] = malloc(sizeof(char) * (my_strlen(input) - 7));
    for (; my_env[i + 1]; i++)
        my_env[i] = my_env[i + 1];
    my_env[i] = NULL;
    return 0;
}