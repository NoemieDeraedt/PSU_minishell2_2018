/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** lib
*/

int my_strlen(char const *str)
{
    int i;
    int compteur = 0;

    for (i = 0; str[i]; i++) {
        compteur++;
    }
    return (compteur);
}
