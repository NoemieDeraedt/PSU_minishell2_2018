/*
** EPITECH PROJECT, 2018
** CPE_getnextline_2018
** File description:
** getnextline.c
*/

#include "../../include/my.h"
#include "../../include/get_next_line.h"

char *get_next_line(int fd)
{
    static char buff[1000];
    char *result = malloc(1000);
    static int i = 0;
    int j = 0;

    if (fd == -1)
        return (NULL);
    read(fd, buff, READ_SIZE);
    close(fd);
    for (; buff[i] != '\n' && buff[i] != '\0'; i++) {
        result[j] = buff[i];
        j++;
    }
    for (; result[j]; j++)
        result[j] = '\0';
    if (result[0] == '\0')
        return NULL;
    i++;
    return result;
}
