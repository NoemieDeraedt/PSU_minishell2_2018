/*
** EPITECH PROJECT, 2019
** pipe.c
** File description:
** pipe.c
*/

#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include "my.h"

void end_pipe(pid_t pid1, pid_t pid2, int *pipefd)
{
    int status1;
    int status2;

    close(pipefd[0]);
    close(pipefd[1]);
    waitpid(pid2, &status2, 0);
    waitpid(pid1, &status1, 0);

}

void pipe_func(char **env, char *str, char *str2)
{
    pid_t pid1;
    pid_t pid2;
    int pipefd[2];

    pipe(pipefd);
    pid1 = fork();
    if (pid1 == 0) {
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[0]);
        check_commands(str2, env);
        exit(pid1);
    }
    pid2 = fork();
    if (pid2 == 0) {
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[1]);
        check_commands(str, env);
        exit(pid2);
    }
    end_pipe(pid1, pid2, pipefd);
}