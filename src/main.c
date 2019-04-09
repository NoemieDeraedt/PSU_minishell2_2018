/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** main.c
*/

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

void free_assets(char **my_env, char *input)
{
    free(input);
    for (int i = 0; my_env[i]; i++)
        free(my_env[i]);
    free(my_env);
}

int main(int argc, char **argv, char **env)
{
    char *input = malloc(sizeof(char) * 1000);
    char **my_env = create_env(env);
    size_t bufsize = 1000;
    int size = 0;

    if (argc != 1)
        return 84;
    check_malloc(input);
    input[0] = '\0';
    while (check_exit(input) != 1 && size != -1) {
        my_printf("$> ");
        size = getline(&input, &bufsize, stdin);
        delete_spaces(input, input);
        if (input != NULL)
            check_sep(input, my_env);
    }
    free_assets(my_env, input);
    return 0;
}