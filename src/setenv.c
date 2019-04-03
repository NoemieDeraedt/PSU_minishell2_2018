/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** commands.c
*/

#include "my.h"

int find_equal(char *name)
{
    int j = 0;

    for (int i = 0; name[i]; i++)
        if (name[i] == '=')
            j++;
    if (j != 1)
        return 84;
    return 0;
}

int check_alphanum(char *input)
{
    for (int i = 0; i < my_strlen(input); i++) {
        if ((input[i] < '0' || (input[i] > 'Z' && input[i] < 'a')
        || input[i] > 'z') && input[i] != ' ' && input[i] != '\n') {
            write(2, "setenv: Variable name must ", 27);
            write(2, "contain alphanumeric characters.\n", 34);
            return 1;
        }
    }
    return 0;
}

void new_env_var(char *input, char **my_env)
{
    int a;
    int j;
    int n = 0;
    char *name = malloc(sizeof(char) * (my_strlen(input) - 7));

    check_malloc(name);
    if (check_alphanum(input) == 1)
        return;
    for (int k = 7; input[k]; k++, n++) {
        if (input[k] != ' ' && input[k] != '\n')
            name[n] = input[k];
        else
            name[n] = '=';
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
    int j;
    int k;
    int n = 0;
    char *name = malloc(sizeof(char) * (my_strlen(input) - 7));

    check_malloc(name);
    free(my_env[i]);
    for (k = 7; input[k]; k++) {
        if (input[k] != ' ' && input[k] != '\n')
            name[n] = input[k];
        else
            name[n] = '=';
        n++;
    }
    if (find_equal(name) == 84 && name[n] == '=')
        name[n] = '\0';
    my_env[i] = malloc(sizeof(char) * my_strlen(name));
    check_malloc(my_env[i]);
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