/*
** EPITECH PROJECT, 2019
** sep_redir.c
** File description:
** sep_redir.c
*/

#include "my.h"

char *semicolon(char **env, char *input, char *str)
{
    int i = 0;

    for (int j = 0; j < count_semicolon(input) + 1; j++) {
        for (int k = 0; i != -1; k++) {
            transform_input(i, input, ';', str);
            i = find_char(input, i + 1, ';');
            // check_commands(str, env);
            redirections(env, str);
        }
    }
    return str;
}

void redirections(char **env, char *input)
{
    if (find_right_redirect(input) == 0)
        check_commands(input, env);
    else
        right_redir(input, env);
}

void pipes(char **env, char *input)
{

}

void check_sep(char *input, char **env)
{
    char *str = malloc(sizeof(char) * my_strlen(input));

    check_malloc(str);
    if (input[0] == '\n' || input[0] == '\t' || input[0] == ' ')
        return;
    if (find_char(input, 0, ';') == -1)
        redirections(env, input);
    else
        semicolon(env, input, str);
    free(str);
}