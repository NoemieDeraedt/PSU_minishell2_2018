/*
** EPITECH PROJECT, 2019
** sep_redir.c
** File description:
** sep_redir.c
*/

#include "my.h"

int semicolon(char **env, char *input, char *str)
{
    int i = 0;

    for (int j = 0; j < count_semicolon(input) + 1; j++) {
        for (int k = 0; i != -1; k++) {
            transform_input(i, input, ';', str);
            i = find_char(input, i + 1, ';');
            redirections(env, str);
        }
    }
    return 0;
}

int redirections(char **env, char *input)
{
    if (find_right_redirect(input) == 0) {
        if (pipes(env, input) == 84)
            return 84;
    } else {
        if (right_redir(input, env) == 84)
            return 84;
    }
    return 0;
}

int pipes(char **env, char *input)
{
    int i = 0;
    char *str = NULL;
    char *str2 = malloc(sizeof(char) * my_strlen(input));

    str = malloc(sizeof(char) * my_strlen(input));
    if (str == NULL || str2 == NULL)
        return 84;
    if (find_char(input, 0, '|') != -1) {
        transform_input(i, input, '|', str);
        i = find_char(input, i + 1, '|');
        my_strcpy(str2, str);
        transform_input(i, input, '|', str);
        i = find_char(input, i + 1, '|');
        pipe_func(env, str, str2);
    } else
        if (check_commands(input, env) == 84)
            return 84;
    free(str);
    free(str2);
    return 0;
}

int check_sep(char *input, char **env)
{
    char *str = malloc(sizeof(char) * (my_strlen(input) + 1));

    if (str == NULL)
        return 84;
    if (input[0] == '\n' || input[0] == '\t' || input[0] == ' ')
        return 0;
    if (find_char(input, 0, ';') == -1) {
        if (redirections(env, input) == 84)
            return 84;
    } else
        if (semicolon(env, input, str))
            return 84;
    free(str);
    return 0;
}