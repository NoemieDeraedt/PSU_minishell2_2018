/*
** EPITECH PROJECT, 2019
** struct.h
** File description:
** struct.h
*/

#ifndef PSU_MINISHELL2_2018_STRUCT_H
#define PSU_MINISHELL2_2018_STRUCT_H

typedef struct commands_s
{
    char *command;
    int (*function)(char *input, char **env);
} commands_t;

#endif //PSU_MINISHELL2_2018_STRUCT_H
