/*
** EPITECH PROJECT, 2019
** execute.c
** File description:
** execute.c
*/

#include "my.h"

void my_exec(char *input, char **env)
{
    char *file = counter_file(input);
    char *argv[100];
    int k = 0;
    int p = 0;

    argv[0] = malloc(sizeof(char) * 100);
    for (int j = 0; input[j]; j++)
        if (input[j] == ' ') {
            argv[k] = malloc(sizeof(char) * 100);
            k++;
            p = 0;
        } else {
            argv[k][p] = input[j];
            p++;
        }
    file[my_strlen(file) - 1] = '\0';
    execve(file, env, argv);
    if (errno == ENOENT)
        my_printf("ERROR\n");
    free(file);
}
