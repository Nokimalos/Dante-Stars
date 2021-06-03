/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-1-dante-kaan.bouldoires
** File description:
** err_handling
*/

#include "generator.h"

static int my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < '0' || str[i] > '9')
            return 84;
    return (0);
}

int error_handling(int argc, char **argv)
{
    if (argc < 3 || argc > 4)
        return 84;
    if (my_str_isnum(argv[1]) == 84 || my_str_isnum(argv[2]) == 84)
        return 84;
    return 0;
}