/*
** EPITECH PROJECT, 2019
** redir.c
** File description:
** redir.c
*/

#include "my.h"

void right_redir(char *input, char **env)
{
    char **str = malloc(sizeof(char) * 2);
    int i = 0;
    int fd;
    pid_t pid;

    check_double_malloc(str);
    for (int j = 0; j < find_right_redirect(input) + 1; j++) {
        for (int k = 0; i != -1; k++) {
            str[k] = malloc(sizeof(char) * my_strlen(input));
            check_malloc(str[k]);
            transform_input(i, input, '>', str[k]);
            i = find_char(input, i + 1, '>');
        }
    }
    pid = fork();
    fd = open(str[1], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    dup2(fd, 1);
    check_commands(str[0], env);
    kill(pid, SIGUSR1);
    for (int i = 0; i < 2; i++)
        free(str[i]);
    free(str);
}