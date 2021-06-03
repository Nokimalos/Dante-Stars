/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-1-dante-kaan.bouldoires
** File description:
** initialize_cells
*/

#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "generator.h"

static void find_stars(gen_t *maze)
{
    maze->count = rand() % 2;
    if (maze->mat[maze->i + 1][maze->j - 2] == '*'
    && maze->mat[maze->i - 1][maze->j] == '*') {
        if (maze->count == 0) {
            maze->mat[maze->i + 1][maze->j] = '*';
            maze->mat[maze->i + 1][maze->j - 1] = '*';
        } else {
            maze->mat[maze->i + 1][maze->j] = '*';
            maze->mat[maze->i][maze->j] = '*';
        }
    }
}

void fill_maze(gen_t *maze)
{
    for (maze->i = 1; maze->i < maze->rows - 1; maze->i += 2)
        for (maze->j = 2; maze->j < maze->cols; maze->j += 2)
            find_stars(maze);
    maze->mat[maze->rows - 1][maze->cols - 1] = '*';
    if (maze->rows % 2 == 0 && maze->cols % 2 == 0)
        maze->mat[maze->rows - 1][maze->cols - 2] = '*';
}

int initialize_cells(gen_t *maze, char **argv)
{
    srand(time(NULL));
    maze->cols = atoi(argv[1]);
    maze->rows = atoi(argv[2]);
    if (maze->rows == 0 || maze->cols == 0)
        return 84;
    get_malloc(maze);
    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            if (i == 0 || j == 0)
                maze->mat[i][j] = '*';
            else
                maze->mat[i][j] = 'X';
        }
    }
    is_this_perfect(maze, argv);
    return 0;
}

void print_maze(gen_t *maze)
{
    for (int i = 0; i < maze->rows - 1; i++)
        printf("%s\n", maze->mat[i]);
    printf("%s", maze->mat[maze->rows - 1]);
}

int main(int argc, char **argv)
{
    gen_t maze;

    if (error_handling(argc, argv) == 84)
        return 84;
    if (initialize_cells(&maze, argv) == 84)
        return 84;
    print_maze(&maze);
    free_array(&maze);
    return 0;
}
