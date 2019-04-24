/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** main.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int count_semicolon(char *input)
{
    int j = 0;

    for (int i = 0; input[i]; i++)
        if (input[i] == ';')
            j++;
    return j;
}

int find_char(char *input, int i, char c)
{
    for (; input[i]; i++)
        if (input[i] == c)
            return i;
    return -1;
}

void free_double_array(char **array)
{
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}

void free_assets(char **my_env, char *input)
{
    free(input);
    for (int i = 0; my_env[i]; i++)
        free(my_env[i]);
    free(my_env);
}

int main(int argc, char **argv, char **env)
{
    char *input = NULL;
    char **my_env = create_env(env);
    size_t bufsize;
    int size = 0;

    if (argc != 1 || my_env == NULL || argv[1])
        return 84;
    while (size != -1) {
        my_printf("$> ");
        size = getline(&input, &bufsize, stdin);
        input[size - 1] = '\0';
        delete_spaces(input, input);
        if (check_exit(input) == 1)
            break;
        if (check_sep(input, my_env) == 84)
            return 84;
    }
    my_printf("exit\n");
    free_assets(my_env, input);
    return 0;
}