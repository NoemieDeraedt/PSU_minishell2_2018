/*
** EPITECH PROJECT, 2019
** launch_commands.c
** File description:
** launch commands
*/

#include <stdlib.h>
#include <unistd.h>
#include "struct.h"
#include "my.h"

char *counter_file(char *input)
{
    char *file = malloc(sizeof(char) * (my_strlen(input)));
    int i;

    if (file == NULL)
        return NULL;
    if (input[0] == '.') {
        for (i = 0; input[i]; i++)
            file[i] = input[i + 2];
        file[i - 1] = '\0';
    } else if (input[0] == '/')
        my_strcpy(file, input);
    return file;
}

int check_commands(char *input, char **env)
{
    int i = 0;
    commands_t *commands = init_commands();

    for (int i = 0; commands[i].command; i++) {
        if (compare_args(input, commands[i].command) == 0) {
            i = (*commands[i].function)(input, env);
            return i;
        }
    }
    if (exec_command(input, env) == 0 || local_exec(input, env) == 0)
        return 0;
    else {
        input[my_strlen(input) - 1] = '\0';
        my_error(&input[i]);
        my_error(": Command not found.\n");
    }
    return i;
}