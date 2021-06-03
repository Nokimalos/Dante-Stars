/*
** EPITECH PROJECT, 2021
** dante
** File description:
** error handling
*/

#include "my.h"

int check_path(int **map, int rows, int cols)
{
    int count = 0;

    for (int i = 1; i < rows + 2; i += 1)
        for (int j = 1; j < cols; j += 1)
            if (map[i][j] == crumb)
                count += 1;
    if (count == 0)
        return (84);
    else
        return (0);
}

int check_map(char *buffer)
{
    int i = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == '*' || buffer[i] == 'X' || buffer[i] == '\n')
            i += 1;
        else
            return (84);
    }
    return (0);
}