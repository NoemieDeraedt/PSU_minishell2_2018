/*
** EPITECH PROJECT, 2019
** execute.c
** File description:
** execute.c
*/

#include "my.h"

char **argv_in_double_array(char *input)
{
    int k = 0;
    int p = 0;
    char **argv = malloc(sizeof(char) * 100);

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
    return argv;
}

void my_exec(char *input, char **env)
{
    char *file = counter_file(input);
    char **argv = argv_in_double_array(input);
    pid_t pid_fils = fork();

    file[my_strlen(file) - 1] = '\0';
    if (pid_fils == 0)
        execve(file, env, argv);
    else
        wait(NULL);
    if (errno == ENOENT)
        my_printf("ERROR\n");
    kill(pid_fils, SIGUSR1);
    free(file);
}
