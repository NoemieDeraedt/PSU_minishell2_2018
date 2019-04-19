/*
** EPITECH PROJECT, 2019
** launch_commands.c
** File description:
** launch commands
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

char *counter_file(char *input)
{
    char *file = malloc(sizeof(char) * (my_strlen(input)));
    int i;

    if (file == NULL)
        return NULL;
    for (i = 0; input[i]; i++)
        file[i] = input[i + 2];
    file[i - 1] = '\0';
    return file;
}

int check_no_commands(char *input, char **env)
{
    if (compare_args(input, "cd ") != 0 && compare_args(input, "env") != 0 &&
    compare_args(input, "setenv") != 0 && compare_args(input, "./") != 0 &&
    compare_args(input, "unsetenv") != 0 && compare_args(input, "pwd") != 0 &&
    compare_args(input, "exit\n") != 0) {
        if (exec_command(input, env) == 0)
            return 0;
        else {
            for (int i = 0; input[i] != ' ' && input[i] != '\n'; i++)
                write(2, &input[i], 1);
            my_error(": Command not found.\n");
            return 0;
        }
    }
    return 1;
}

int check_commands(char *input, char **env)
{
    int i = 0;

    if (check_no_commands(input, env) == 0)
        return 0;
    if (compare_args(input, "cd ") == 0)
        i = my_cd(input);
    if (compare_args(input, "env") == 0)
        display_env(env);
    if (compare_args(input, "setenv") == 0) {
        if (input[6] == ' ' && input[7] && input[7] != ' ' && input[7] != '\n')
            i = my_setenv(input, env);
        else
            display_env(env);
    }
    if (compare_args(input, "./") == 0)
        i = my_exec(input, env);
    if (compare_args(input, "unsetenv") == 0)
        i = my_unsetenv(input, env);
    if (compare_args(input, "pwd") == 0)
        i = my_pwd();
    return i;
}