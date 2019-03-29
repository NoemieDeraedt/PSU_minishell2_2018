/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** check.c
*/

#include "my.h"

int compare_args(char *input, char *str)
{
    for (int i = 0; i < my_strlen(str); i++) {
        if (input[i] != str[i])
            return 84;
    }
    return 0;
}

int check_exit(char *input)
{
    if (compare_args(input, "exit\n") == 0)
        return 1;
    return 0;
}

char *transform_input(int i, char *input)
{
    char *str = malloc(sizeof(char) * my_strlen(input));
    int j = 0;

    for (; input[i] == ' ' || input[i] == ';'; i++);
    for (; input[i] != ';' && input[i] != '\n'; i++) {
        str[j] = input[i];
        j++;
    }
    return str;
}

void check_semicolon(char *input, char **env)
{
    int i = 0;
    char *str = malloc(sizeof(char) * my_strlen(input));

    if (find_semicolon(input, i) == -1)
        check_commands(input, env);
    else {
        for (int j = 0; j < count_semicolon(input); j++) {
            for (int k = 0; i != -1; k++) {
                str = transform_input(i, input);
                i = find_semicolon(input, i + 1);
                check_commands(str, env);
            }
        }
    }
    free(str);
}
