/*
** EPITECH PROJECT, 2019
** redir.c
** File description:
** redir.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

char **create_args(char *input)
{
    int i = 0;
    char **str = malloc(sizeof(char) * 2);

    for (int j = 0; j < find_right_redirect(input) + 1; j++) {
        for (int k = 0; i != -1; k++) {
            str[k] = malloc(sizeof(char) * my_strlen(input));
            if (str[k] == NULL)
                return NULL;
            transform_input(i, input, '>', str[k]);
            i = find_char(input, i + 1, '>');
        }
    }
    return str;
}

int right_redir(char *input, char **env)
{
    char **str = create_args(input);
    int fd;
    pid_t pid;

    if (str == NULL)
        return 84;
    str[1][my_strlen(str[1]) - 1] = '\0';
    fd = open(str[1], O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    pid = fork();
    if (pid == 0) {
        dup2(fd, 1);
        close(fd);
        check_commands(str[0], env);
        exit(pid);
    } else
        wait(NULL);
    for (int i = 0; i < 2; i++)
        free(str[i]);
    free(str);
    return 0;
}