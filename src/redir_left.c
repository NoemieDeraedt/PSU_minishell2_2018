/*
** EPITECH PROJECT, 2019
** redir_left.c
** File description:
** redir_left.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int left_redir(char **env, char *input)
{
    pid_t pid;
    int fd;
    int status;
    char **str = create_args(input, '<');

    fd = open(str[1], O_RDONLY);
    pid = fork();
    if (pid == 0) {
        dup2(fd, STDIN_FILENO);
        close(fd);
        check_commands(str[0], env);
        exit(pid);
    }
    wait(NULL);
    return 0;
}