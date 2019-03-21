/*
** EPITECH PROJECT, 2018
** my_swap.c
** File description:
** my swap
*/

void my_swap(char *a, char *b)
{
    int d = *a;
    *a = *b;
    *b = d;
}
