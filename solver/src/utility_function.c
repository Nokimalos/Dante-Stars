/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** utility_function.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "my.h"

int find(char *str, char c)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            return (TRUE);
    return (FALSE);
}

int count(char *str, char c)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            count += 1;
    return (count);
}

void print_array(char **array)
{
    int i = 0;

    for (i = 0; array[i + 1] != NULL; i += 1)
        printf("%s\n", array[i]);
    printf("%s", array[i]);
}

int get_number(char *nb)
{
    if (strlen(nb) == 1)
        return (nb[0] - 48);
    else
        return (atoi(nb));
}

int **create_tab(int rows, int cols)
{
    int **map = malloc(sizeof(int *) * (rows + 1));
    int i = 0;

    if (map == NULL)
        return (NULL);
    for (i = 0; i < rows; i += 1) {
        map[i] = malloc(sizeof(int) * cols + 1);
        if (map[i] == NULL)
            return (NULL);
    }
    map[i] = NULL;
    return (map);
}