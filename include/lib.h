/*
** EPITECH PROJECT, 2019
** lib.h
** File description:
** lib.h
*/

#ifndef PSU_MINISHELL2_2018_LIB_H
#define PSU_MINISHELL2_2018_LIB_H

int my_printf(char *arg1, ...);
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
char *my_strconcat(char *str1, char *str2);
char *int_to_char(int number);
char *number_in_array(char *str, int value);
char *get_next_line(int fd);

#endif //PSU_MINISHELL2_2018_LIB_H
