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

char *get_name(char *input)
{
    char *name = malloc(sizeof(char) * (my_strlen(input) - 6));
    int n = 0;

    if (name == NULL)
        return NULL;
    for (int k = 7; input[k]; k++, n++)
        if (input[k] != ' ' && input[k] != '\n')
            name[n] = input[k];
        else
            name[n] = '=';
    if (find_equal(name) == 84 && name[n - 1] == '=')
        name[n - 1] = '\0';
    return name;
}

int new_env_var(char *input, char **my_env)
{
    int a;
    char *name;

    if (check_alphanum(input) == 1)
        return 0;
    name = get_name(input);
    if (name == NULL)
        return 84;
    for (a = 0; my_env[a]; a++);
    my_env[a] = malloc(sizeof(char) * my_strlen(name));
    if (my_env[a] == NULL)
        return 84;
    my_strcpy(my_env[a], name);
    free(name);
    return 0;
}

int change_env_var(char *input, char **my_env)
{
    int i = find_env_var(input, my_env, 7);
    int n = 0;
    char *name = malloc(sizeof(char) * (my_strlen(input) - 7));

    if (name == NULL)
        return 84;
    for (int k = 7; input[k]; k++, n++)
        if (input[k] != ' ' && input[k] != '\n')
            name[n] = input[k];
        else
            name[n] = '=';
    if (find_equal(name) == 84 && name[n - 1] == '=')
        name[n - 1] = '\0';
    my_env[i] = malloc(sizeof(char) * my_strlen(name));
    if (my_env[i] == NULL)
        return 84;
    for (int j = 0; name[j]; j++)
        my_env[i][j] = name[j];
    free(name);
    return 0;
}

int my_setenv(char *input, char **my_env)
{
    if (find_env_var(input, my_env, 7) == -1) {
        if (new_env_var(input, my_env) == 84)
            return 84;
    } else {
        if (change_env_var(input, my_env) == 84)
            return 84;
    }
    return 0;
}