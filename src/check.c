/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** check.c
*/

#include <unistd.h>
#include "my.h"

int compare_args(char *input, char *str)
{
    for (int i = 0; i < my_strlen(str); i++)
        if (input[i] != str[i])
            return 84;
    return 0;
}

int check_exit(char *input)
{
    if (compare_args(input, "exit\n") == 0)
        return 1;
    return 0;
}

char *transform_input(int i, char *input, char sep, char *str)
{
    int j = 0;

    for (; input[i] == ' ' || input[i] == sep; i++);
    for (; input[i] != sep && input[i] != '\n'; i++) {
        str[j] = input[i];
        j++;
    }
    str[j] = '\0';
    delete_spaces(str, str);
    return str;
}

int check_alphanum(char *input)
{
    for (int i = 0; i < my_strlen(input); i++) {
        if ((input[i] < '0' || (input[i] > 'Z' && input[i] < 'a')
        || input[i] > 'z') && input[i] != ' ' && input[i] != '\n' &&
        input[i] != '/') {
            my_error("setenv: Variable name must contain ");
            my_error("alphanumeric characters.\n");
            return 1;
        }
    }
    return 0;
}