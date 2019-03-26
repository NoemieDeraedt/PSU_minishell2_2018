/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** main.c
*/

#include "my.h"

int main(int argc, char **argv, char **env)
{
    char *input = malloc(sizeof(char) * 1000);
    char **my_env = create_env(env);
    size_t bufsize = 32;
    int size = 0;

    if (argc != 1)
        return 84;
    while (check_exit(input) != 1 && size != -1) {
        my_printf("$> ");
        size = getline(&input, &bufsize, stdin);
        check_commands(input, my_env); 
    }
    free(input);
    return 0;
}
