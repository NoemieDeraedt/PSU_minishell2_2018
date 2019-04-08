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
            argv[k][p] = '\0';
            k++;
            argv[k] = malloc(sizeof(char) * 100);
            p = 0;
            check_malloc(argv[k]);
        } else {
            argv[k][p] = input[j];
            p++;
        }
    }
    argv[k + 1] = NULL;
    return argv;
}

void check_status(int status)
{
    if (status == 136)
        my_error("Floating exception\n");
    if (status == 139)
        my_error("Segmentation fault\n");
    if (status == 134)
        my_error("Abort\n");
}

int check_errors(char *file)
{
    if (access(file, X_OK) == -1) {
        if (errno == EACCES)
            permission_denied(file);
        if (errno == ENOENT)
            command_not_found(file);
        return 84;
    }
    if (opendir(file) != NULL) {
        permission_denied(file);
        return 84;
    }
    return 0;
}

void my_exec(char *input, char **env)
{
    char *file = counter_file(input);
    char **argv = argv_in_double_array(input);
    pid_t pid_fils;
    int status;

    file[my_strlen(file) - 1] = '\0';
    if (check_errors(file) == 84)
        return;
    pid_fils = fork();
    if (pid_fils == 0)
        execve(file, argv, env);
    else {
        waitpid(pid_fils, &status, 0);
        check_status(status);
    }
    kill(pid_fils, SIGUSR1);
    free(file);
}

int exec_command(char *input, char **env)
{
    char *file = my_strconcat("/bin/", input);
    char **argv = argv_in_double_array(input);
    char *new = malloc(sizeof(char) * my_strlen(file));
    int i;
    pid_t pid_fils;

    for (i = 0; file[i] && file[i] != ' ' && file[i] != '\n'; i++)
        new[i] = file[i];
    new[i] = '\0';
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