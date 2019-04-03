/*
** EPITECH PROJECT, 2019
** execute.c
** File description:
** execute.c
*/

#include "my.h"

char **argv_in_double_array(char *input)
{
    int k = 0;
    int p = 0;
    char **argv = malloc(sizeof(char) * 100);

    argv[0] = malloc(sizeof(char) * 100);
    for (int j = 0; input[j] != '\n'; j++) {
        if (input[j] == ';' || input[j] == '\0')
            return argv;
        if (input[j] == ' ') {
            k++;
            argv[k] = malloc(sizeof(char) * 100);
            p = 0;
            check_malloc(argv[k]);
        } else {
            argv[k][p] = input[j];
            p++;
        }
    }
    return argv;
}

void my_exec(char *input, char **env)
{
    char *file = counter_file(input);
    char **argv = argv_in_double_array(input);
    pid_t pid_fils = fork();

    file[my_strlen(file) - 1] = '\0';
    if (pid_fils == 0)
        execve(file, argv, env);
    else
        wait(NULL);
    kill(pid_fils, SIGUSR1);
    free(file);
}

int exec_command(char *input, char **env)
{
    char *file = my_strconcat("/bin/", input);
    char **argv = argv_in_double_array(input);
    char *new = malloc(sizeof(char) * my_strlen(file));
    pid_t pid_fils;

    for (int i = 0; file[i] != ' ' && file[i] != '\n'; i++)
        new[i] = file[i];
    if (open(new, O_RDONLY) == -1)
        return -1;
    pid_fils = fork();
    if (pid_fils == 0)
        execve(new, argv, env);
    else
        wait(NULL);
    kill(pid_fils, SIGUSR1);
    free(file);
    return 0;
}