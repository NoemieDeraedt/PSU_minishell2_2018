/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** commands.c
*/

#include "my.h"

char *counter_file(char *input)
{
    char *file = malloc(sizeof(char) * (my_strlen(input) - 2));

    for (int i = 0; input[i]; i++)
        file[i] = input[i + 2];
    return file;
}

char **create_env(char **env)
{
    char **my_env;
    int i;
    int a;

    for (i = 0; env[i]; i++);
    my_env = malloc(sizeof(char *) * (i - 2));
    for (a = 0; env[a]; a++) {
        my_env[a] = malloc(sizeof(char) * my_strlen(env[a]) + 10);
        for (int b = 0; env[a][b]; b++)
            my_env[a][b] = env[a][b];
    }
    return my_env;
}

void my_setenv(char *input, char **my_env)
{
    int a;
    int j;
    int k;
    int n = 0;
    char *name = malloc(sizeof(char) * (my_strlen(input) - 7));

    for (k = 7; input[k]; k++) {
        if (input[k] != ' ' && input[k] != '\n')
            name[n] = input[k];
        else /*if (input[k] == ' ' && input[k] == '\n')*/
            name[n] = '=';
        n++;
    }
    name[n] = '\0';
    for (a = 0; my_env[a]; a++);
    my_env[a] = malloc(sizeof(char) * my_strlen(name));
    for (j = 0; name[j]; j++)
        my_env[a][j] = name[j];
    free(name);
}

void display_env(char **env)
{
    for (int j = 0; env[j]; j++)
        my_printf("%s\n", env[j]);
}

void my_cd(char *input)
{
    char *path = malloc(sizeof(char) * my_strlen(input));
    int i;

    for (i = 0; i < my_strlen(input); i++)
        path[i] = input[i + 3];
    path[my_strlen(path) - 1] = '\0';
    chdir(path);
    free(path);
}
