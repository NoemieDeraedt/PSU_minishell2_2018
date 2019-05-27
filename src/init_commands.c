/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** init_commands
*/

#include <stdlib.h>
#include "struct.h"
#include "my.h"

commands_t *init_commands(void)
{
    commands_t *commands = malloc(sizeof(commands_t) * 4);

    commands[0].command = my_strdup("cd");
    commands[0].function = my_cd;
    commands[1].command = my_strdup("env");
    commands[1].function = display_env;
    commands[2].command = my_strdup("setenv");
    commands[2].function = my_setenv;
    commands[3].command = my_strdup("unsetenv");
    commands[3].function = my_unsetenv;
    return commands;
}