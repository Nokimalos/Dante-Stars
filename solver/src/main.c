/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int main(int argc, char const** argv)
{
    char *buffer;
    char **map;
    int rows;
    int cols;

    if (argc != 2)
        return (EXIT_ERROR);
    buffer = read_map(argv[1]);
    if (buffer == NULL)
        return (84);
    if (check_map(buffer) == 84)
        return (84);
    rows = count_rows(buffer) + 1;
    cols = count_cols(buffer);
    map = str_to_tab(buffer, "\n");
    maze_solving(map, rows, cols);
    free(buffer);
    return (0);
}
