/*
** EPITECH PROJECT, 2019
** env.c
** File description:
** env.c
*/

#include "my.h"

char **create_env(char **env)
{
    char **my_env;
    int i;
    int a;
    int b;

    for (i = 0; env[i]; i++);
    my_env = malloc(sizeof(char *) * (i + 10));
    if (my_env == NULL)
        return NULL;
    for (a = 0; env[a]; a++) {
        my_env[a] = malloc(sizeof(char) * (my_strlen(env[a]) + 1));
        if (my_env[a] == NULL)
            return NULL;
        for (b = 0; b < my_strlen(env[a]); b++)
            my_env[a][b] = env[a][b];
    }
    my_env[a] = NULL;
    return my_env;
}

void display_env(char **env)
{
    int j;

    for (j = 0; env[j]; j++)
        my_printf("%s\n", env[j]);
}