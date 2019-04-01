/*
** EPITECH PROJECT, 2019
** cd.c
** File description:
** cd.c
*/

#include "my.h"

void my_cd(char *input)
{
    char *path = malloc(sizeof(char) * my_strlen(input));
    int i;

    for (i = 0; i < my_strlen(input); i++)
        path[i] = input[i + 3];
    path[my_strlen(path) - 1] = '\0';
    chdir(path);
    free(path);
}

void my_pwd(void)
{
    char *buffer = malloc(sizeof(char) * 50);
    size_t size = 42;

    getcwd(buffer, size);
    my_printf("%s\n", buffer);
    free(buffer);
}

void my_ls(char *input, char **env)
{
    char **argv = argv_in_double_array(input);
    pid_t pid_fils = fork();

    if (pid_fils == 0)
        execve("/bin/ls", argv, env);
    else
        wait(NULL);
    kill(pid_fils, SIGUSR1);
}