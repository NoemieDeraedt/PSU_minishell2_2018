/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** check.c
*/

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

void transform_input(int i, char *input, char sep, char *str)
{
    int j = 0;

    for (; input[i] == ' ' || input[i] == sep; i++);
    for (; input[i] != sep && input[i] != '\n'; i++) {
        str[j] = input[i];
        j++;
    }
    delete_spaces(str, str);
}

int find_right_redirect(char *input)
{
    int count = 0;

    for (int i = 0; input[i]; i++)
        if (input[i] == '>')
            count++;
    return count;
}

int check_alphanum(char *input)
{
    for (int i = 0; i < my_strlen(input); i++) {
        if ((input[i] < '0' || (input[i] > 'Z' && input[i] < 'a')
        || input[i] > 'z') && input[i] != ' ' && input[i] != '\n') {
            write(2, "setenv: Variable name must ", 27);
            write(2, "contain alphanumeric characters.\n", 34);
            return 1;
        }
    }
    return 0;
}