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

char **create_args(char *input, char c)
{
    int i = 0;
    int k;
    char **str = malloc(sizeof(char *) * (2 + 1));

    for (int j = 0; j < find_right_redirect(input) + 1; j++) {
        for (k = 0; i != -1; k++) {
            str[k] = malloc(sizeof(char) * (my_strlen(input) + 1));
            if (str[k] == NULL)
                return NULL;
            str[k] = my_strcpy(str[k], transform_input(i, input, c, str[k]));
            i = find_char(input, i + 1, c);
        }
    }
    str[2] = NULL;
    str[1][my_strlen(str[1]) - 1] = '\0';
    return str;
}

int check_double_redir(char *input)
{
    for (int i = 0; input[i]; i++) {
        if (input[i] == '>' && input[i + 1] && input[i + 1] == '>'
        && input[i + 2] && input[i + 2] != '>')
        return 1;
    }
    return 0;
}

int right_redir(char *input, char **env)
{
    char **str = create_args(input, '>');
    int fd;
    pid_t pid;

    if (str == NULL)
        return 84;
    if (check_double_redir(input) == 0)
        fd = open(str[1], O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    else
        fd = open(str[1], O_CREAT | O_RDWR | O_APPEND, S_IRUSR | S_IWUSR);
    pid = fork();
    if (pid == 0) {
        dup2(fd, 1);
        close(fd);
        check_commands(str[0], env);
        free_double_array(str);
        exit(pid);
    } else
        wait(NULL);
    free_double_array(str);
    return 0;
}