/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** check.c
*/

#include "my.h"

int compare_args(char *input, char *str)
{
    for (int i = 0; i < my_strlen(str); i++) {
        if (input[i] != str[i])
            return 84;
    }
    return 0;
}

int check_exit(char *input)
{
    if (compare_args(input, "exit\n") == 0)
        return 1;
    return 0;
}

void check_commands(char *input, char **env)
{
    if (compare_args(input, "cd ") == 0)
        my_cd(input);
    if (compare_args(input, "env") == 0)
        display_env(env);
    if (compare_args(input, "setenv") == 0) {
        if (input[6] == ' ')
            my_setenv(input, env);
        else
            display_env(env);
    }
    if (compare_args(input, "./") == 0)
        my_exec(input, env);
    if (compare_args(input, "unsetenv") == 0)
        my_unsetenv(input, env);
}
