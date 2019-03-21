/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

void my_putchar(char c);
void my_isneg(int nb);
void my_put_nbr(int nb);
void my_swap(char *a, char *b);
void my_putstr(char const *str);
int my_strlen(char const *str);
int my_compute_power_rec(int nb, int power);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
void my_revstr(char *str);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strdup(char const *src);
void my_show_word_array(char *const *tab);
char *int_to_char(int number);
char *number_in_array(char *str, int value);
char *get_next_line(int fd);
int check_exit(char *input);
void check_commands(char *input, char **env);
void my_cd(char *input);
void display_env(char **env);
int my_printf(char *arg1, ...);
void my_setenv(char *input, char **env);
void my_exec(char *input, char **env);
char **create_env(char **env);
char *counter_file(char *input);