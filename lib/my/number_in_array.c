/*
** EPITECH PROJECT, 2018
** number_in_array.c
** File description:
** number_in_array
*/

#include <stdlib.h>
#include "../../include/my.h"

int counter(int i, char *str)
{
    int count = 0;

    for (int j = i; str[j] >= '0' && str[j] <= '9'; j++)
        count++;
    return (count);
}

char *rep(int count, int i, char *str)
{
    char *result = malloc(sizeof(str));
    int n = 0;

    for (int j = i; j != count + i; j++) {
        result[n] = str[j];
        n++;
    }
    return (result);
}

char *number_in_array(char *str, int value)
{
    int count = 0;
    int count_value = 1;
    char *result;

    result = malloc(my_strlen(str));
    for (int i = 0; str[i]; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            count = counter(i, str);
            result = rep(count, i, str);
            if (value == count_value)
                return (result);
            count_value++;
            i += count;
            for (int k = 0; k <= my_strlen(str); k++)
                result[k] = '\0';
        }
    }
    return (result);
}
