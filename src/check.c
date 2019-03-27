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
        if (input[6] == ' ' && input[7] && input[7] != ' ' && input[7] != '\n')
            my_setenv(input, env);
        else
            display_env(env);
    }
    if (compare_args(input, "./") == 0)
        my_exec(input, env);
    if (compare_args(input, "unsetenv") == 0)
        my_unsetenv(input, env);
    if (compare_args(input, "pwd") == 0)
        my_pwd();
}

char *transform_input(int i, char *input)
{
    char *str = malloc(sizeof(char) * my_strlen(input));
    int j = 0;

    for (; input[i] == ' ' || input[i] == ';'; i++);
    for (; input[i] != ';' && input[i] != '\n'; i++) {
        str[j] = input[i];
        j++;
    }
    return str;
}

void check_semicolon(char *input, char **env)
{
    int i = 0;
    char *str = malloc(sizeof(char) * my_strlen(input));

    if (find_semicolon(input, i) == -1)
        check_commands(input, env);
    else {
        for (int j = 0; j < count_semicolon(input); j++) {
            for (int k = 0; i != -1; k++) {
                str = transform_input(i, input);
                i = find_semicolon(input, i + 1);
                check_commands(str, env);
            }
        }
    }
    free(str);
}
