/*
** EPITECH PROJECT, 2019
** execute.c
** File description:
** execute.c
*/

#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>
#include "my.h"

void check_status(int status)
{
    if (status == 136)
        my_error("Floating exception (core dumped)\n");
    if (status == 139)
        my_error("Segmentation fault (core dumped)\n");
    if (status == 134)
        my_error("Abort (core dumped)\n");
}

int check_errors(char *file)
{
    if (access(file, X_OK) == -1) {
        if (errno == EACCES)
            permission_denied(file);
        else if (errno == ENOENT)
            command_not_found(file);
        return 84;
    }
    if (opendir(file) != NULL) {
        permission_denied(file);
        return 84;
    }
    return 0;
}

int my_exec(char *input, char **env)
{
    char *file = counter_file(input);
    char **argv = argv_in_double_array(input);
    pid_t pid;
    int status;

    if (argv == NULL || file == NULL)
        return 84;
    file[my_strlen(file) - 1] = '\0';
    if (check_errors(file) == 84)
        return 0;
    pid = fork();
    if (pid == 0)
        execve(file, argv, env);
    else {
        waitpid(pid, &status, 0);
        check_status(status);
    }
    kill(pid, status);
    free_assets(argv, file);
    return 0;
}