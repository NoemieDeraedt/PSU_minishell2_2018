/*
** EPITECH PROJECT, 2018
** my_strcpy.c
** File description:
** lib
*/

char *my_strcpy(char *dest, char const *src)
{
    int count = 0;
    int j;

    for (j = 0; src[j] != '\0'; j++) {
        count++;
        dest[j] = src[j];
    }
    return (dest);
}
