/*
** EPITECH PROJECT, 2021
** dante
** File description:
** algorithm
*/

#include "my.h"
#include <stdlib.h>

void free_algo(int **array, int rows)
{

    for (int i = 0; i < rows + 4; i += 1) {
        free(array[i]);
    }
    free(array);
}

int **create_limit(int rows, int cols)
{
    int **map = create_tab(rows + 3, cols + 2);

    for (int i = 0; i < rows + 3; i += 1) {
        for (int j = 0; j < cols + 2; j += 1) {
            map[i][j] = 0;
            map[0][j] = 1;
            map[rows + 1][j] = 1;
        }
        map[i][0] = 1;
        map[i][cols] = 1;
    }
    return (map);
}

int **duplicate_map(char **maze, int rows, int cols)
{
    int **map = create_limit(rows, cols);

    for (int i = 1; i < rows + 1; i += 1) {
        for (int j = 1; j < cols; j += 1) {
            if (maze[i - 1][j - 1] == 'X')
                map[i][j] = wall;
            else
                map[i][j] = path;
        }
    }
    map[rows][cols - 1] = end;
    return (map);
}

int dfs(int **map, int rows, int cols)
{
    if (map[rows][cols] == end)
        return (1);
    if (map[rows][cols] == path) {
        map[rows][cols] = wall;
        if (dfs(map, rows - 1, cols) == 1) {
            map[rows][cols] = crumb;
            return (1);
        } if (dfs(map, rows, cols - 1) == 1) {
            map[rows][cols] = crumb;
            return (1);
        } if (dfs(map, rows, cols + 1) == 1) {
            map[rows][cols] = crumb;
            return (1);
        } if (dfs(map, rows + 1, cols) == 1) {
            map[rows][cols] = crumb;
            return (1);
        }
    }
    return (0);
}
