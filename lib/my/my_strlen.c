/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** lib
*/

int my_strlen(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++);
    return i;
}
