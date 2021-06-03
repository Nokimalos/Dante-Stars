/*
** EPITECH PROJECT, 2021
** dante
** File description:
** maze
*/

#include "my.h"
#include <stdio.h>

char **update_maze(char **maze, int **map, int rows, int cols)
{
    for (int i = 1; i < rows + 2; i += 1)
        for (int j = 1; j < cols; j += 1)
            if (map[i][j] == crumb || map[i][j] == 2)
                maze[i - 1][j - 1] = 'o';
    return (maze);
}

int maze_solving(char **map, int rows, int cols)
{
    int **algo = duplicate_map(map, rows, cols);

    dfs(algo, 1, 1);
    if (check_path(algo, rows, cols) == 84) {
        free_map(map);
        free_algo(algo, rows);
        printf("no solution found");
        return (0);
    } else {
        map = update_maze(map, algo, rows, cols);
        print_array(map);
        free_map(map);
        free_algo(algo, rows);
        return (0);
    }
    return (0);
}