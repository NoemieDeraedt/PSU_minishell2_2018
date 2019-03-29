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

    for (i = 0; env[i]; i++);
    my_env = malloc(sizeof(char *) * (i + 10));
    for (a = 0; env[a]; a++) {
        my_env[a] = malloc(sizeof(char) * my_strlen(env[a]));
        for (int b = 0; env[a][b]; b++)
            my_env[a][b] = env[a][b];
    }
    return my_env;
}

void display_env(char **env)
{
    int j;

    for (j = 0; env[j]; j++)
        my_printf("%s\n", env[j]);
}