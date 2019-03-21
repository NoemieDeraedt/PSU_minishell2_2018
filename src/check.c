/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** check.c
*/

#include "my.h"

int check_exit(char *input)
{
    if (input[0] == 'e' && input[1] == 'x' && input[2] == 'i' && input[3] == 't'
        && input[4] == '\n')
        return 1;
    return 0;
}

void check_commands(char *input, char **env)
{
    if (input[0] == 'c' && input[1] == 'd' && input[2] == ' ')
        my_cd(input);
    if (input[0] == 'e' && input[1] == 'n' && input[2] == 'v')
        display_env(env);
    if (input[0] == 's' && input[1] == 'e' && input[2] == 't' && input[3] == 'e'
        && input[4] == 'n' && input[5] == 'v') {
        if (input[6] == ' ')
            my_setenv(input, env);
        else
            display_env(env);
    }
    if (input[0] == '.' && input[1] == '/')
        my_exec(input, env);
}
