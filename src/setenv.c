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
    my_env = malloc(sizeof(char *) * (i + 10));
    for (a = 0; env[a]; a++) {
        my_env[a] = malloc(sizeof(char) * my_strlen(env[a]));
        for (int b = 0; env[a][b]; b++)
            my_env[a][b] = env[a][b];
    }
    return my_env;
}

int find_equal(char *name)
{
    int j = 0;

    for (int i = 0; name[i]; i++) {
        if (name[i] == '=')
            j++;
    }
    if (j == 2)
        return 84;
    return 0;
}

void new_env_var(char *input, char **my_env)
{
    int a;
    int j;
    int k;
    int n = 0;
    char *name = malloc(sizeof(char) * (my_strlen(input) - 7));

    for (k = 7; input[k]; k++) {
        if (input[k] != ' ' && input[k] != '\n')
            name[n] = input[k];
        else
            name[n] = '=';
        n++;
    }
    if (find_equal(name) == 84 && name[n - 1] == '=')
        name[n - 1] = '\0';
    for (a = 0; my_env[a]; a++);
    my_env[a] = malloc(sizeof(char) * my_strlen(name));
    for (j = 0; name[j]; j++)
        my_env[a][j] = name[j];
    free(name);
}

void change_env_var(char *input, char **my_env)
{
    int i = find_env_var(input, my_env, 7);
    int a;
    int j;
    int k;
    int n = 0;
    char *name = malloc(sizeof(char) * (my_strlen(input) - 7));

    free(my_env[i]);
    for (k = 7; input[k]; k++) {
        if (input[k] != ' ' && input[k] != '\n')
            name[n] = input[k];
        else
            name[n] = '=';
        n++;
    }
    if (find_equal(name) == 84 && name[n - 1] == '=')
        name[n - 1] = '\0';
    my_env[i] = malloc(sizeof(char) * my_strlen(name));
    for (j = 0; name[j]; j++)
        my_env[i][j] = name[j];
    free(name);
}

void my_setenv(char *input, char **my_env)
{
    if (find_env_var(input, my_env, 7) == -1)
        new_env_var(input, my_env);
    else 
        change_env_var(input, my_env);
}

void display_env(char **env)
{
    int j;

    for (j = 0; env[j]; j++)
        my_printf("%s\n", env[j]);
}
