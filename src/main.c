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

int find_semicolon(char *input, int i)
{
    for (; input[i]; i++) {
        if (input[i] == ';')
            return i;
    }
    return -1;
}

int main(int argc, char **argv, char **env)
{
    char *input = malloc(sizeof(char) * 1000);
    char **my_env = create_env(env);
    size_t bufsize = 32;
    int size = 0;

    if (argc != 1)
        return 84;
    while (check_exit(input) != 1 && size != -1) {
        my_printf("$> ");
        size = getline(&input, &bufsize, stdin);
        check_semicolon(input, my_env);
    }
    free(input);
    return 0;
}
