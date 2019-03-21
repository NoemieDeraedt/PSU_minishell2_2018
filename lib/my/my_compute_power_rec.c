/*
** EPITECH PROJECT, 2018
** my_compute_power_rec.c
** File description:
** lib
*/

int my_compute_power_rec(int nb, int p)
{
    int power = nb;

    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    power = nb * my_compute_power_rec(nb, p - 1);
    return (power);
}
