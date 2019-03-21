/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** main.c
*/

#include "my.h"

int main(int argc, char **argv, char **env)
{
    char *input = malloc(sizeof(char) * 1000);
    char **my_env = create_env(env);

    if (argc != 1)
        return 84;
    while (check_exit(input) != 1) {
        my_putstr("$> ");
        read(0, input, 1000);
        check_commands(input, my_env);
    }
    free(input);
    for (int i = 0; my_env[i]; i++)
        free(my_env[i]);
    return 0;
}
