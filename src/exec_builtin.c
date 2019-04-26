/*
** EPITECH PROJECT, 2019
** exec
** File description:
** exec
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "my.h"

void fill_new(char *new, char *file)
{
    int i;

    for (i = 0; file[i] && file[i] != ' ' && file[i] != '\n'; i++)
        new[i] = file[i];
    new[i] = '\0';
}

char *find_command(char *input)
{
    char *command = malloc(sizeof(char) * my_strlen(input));
    int i;

    for (i = 0; input[i] != ' ' && input[i] != '\0' && input[i] != '\n';
        i++)
        command[i] = input[i];
    command[i] = '\0';
    return command;
}

char *assign_path(char *input, char **env)
{
    int path_place = find_env_var("PATH", env, 0);
    char *command = find_command(input);
    char **path;

    if (path_place == -1)
        return "E";
    path = path_double_array(env[path_place]);
    for (int i = 0; path[i]; i++)
        if (access(my_strconcat(path[i], command), R_OK) != -1)
            return my_strconcat(path[i], input);
    return "E";
}

int exec_command(char *input, char **env)
{
    char *file = assign_path(input, env);
    char **argv = argv_in_double_array(file);
    char *new = malloc(sizeof(char) * (my_strlen(file) + 1));
    pid_t pid_fils;

    if (file == NULL || argv == NULL || new == NULL)
        return 84;
    if (file[0] == 'E')
        return -1;
    fill_new(new, file);
    pid_fils = fork();
    if (pid_fils == 0)
        execve(new, argv, env);
    else
        wait(NULL);
    kill(pid_fils, SIGUSR1);
    free(file);
    free_assets(argv, new);
    return 0;
}