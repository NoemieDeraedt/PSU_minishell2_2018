/*
** EPITECH PROJECT, 2018
** my_show_word_array.c
** File description:
** task03
*/

#include "../../include/my.h"

void my_show_word_array(char * const *tab)
{
    int i = 0;
    int j;

    while (tab[i]){
        i++;
    }
    for (j = 0; j < i; j++) {
        my_putstr(tab[j]);
        my_putchar('\n');
    }
}
