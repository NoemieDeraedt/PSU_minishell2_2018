/*
** EPITECH PROJECT, 2019
** unsetenv.c
** File description:
** unsetenv.c
*/

#include "my.h"

int compare_env(char *input, char *str, int j)
{
    for (int i = 0; str[i] != '='; i++) {
        if (input[i + j] != str[i]) {
            return 84;
        }
    }
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

void my_unsetenv(char *input, char **env)
{
    int i = find_env_var(input, env, 9);
}