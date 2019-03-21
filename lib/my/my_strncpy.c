/*
** EPITECH PROJECT, 2018
** my_strncpy.c
** File description:
** lib
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int j;

    for (j = 0; j < n; j++) {
        dest[j] = src[j];
    }
    return (dest);
}
