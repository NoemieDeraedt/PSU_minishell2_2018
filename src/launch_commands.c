/*
** EPITECH PROJECT, 2019
** launch_commands.c
** File description:
** launch commands
*/

#include "my.h"

char *counter_file(char *input)
{
    char *file = malloc(sizeof(char) * (my_strlen(input) - 2));

    for (int i = 0; input[i]; i++)
        file[i] = input[i + 2];
    return file;
}

int check_no_commands(char *input)
{
    if (compare_args(input, "cd ") != 0 && compare_args(input, "env") != 0 &&
    compare_args(input, "setenv") != 0 && compare_args(input, "./") != 0 &&
    compare_args(input, "unsetenv") != 0 && compare_args(input, "pwd") != 0 &&
    compare_args(input, "exit\n") != 0 && compare_args(input, "ls") != 0) {
        for (int i = 0; input[i] != ' ' && input[i]; i++)
            write(2, &input[i], 1);
        write(2, ": Command not found.\n", 22);
        return 0;
    }
    return 1;
}

void check_commands(char *input, char **env)
{
    if (check_no_commands(input) == 0)
        return;
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
    if (compare_args(input, "ls") == 0)
        my_ls(input, env);
}