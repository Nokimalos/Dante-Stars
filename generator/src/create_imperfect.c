/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-1-dante-kaan.bouldoires
** File description:
** create_imperfect
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "generator.h"

static void fill_cols(gen_t *maze)
{
    if (maze->count == 0) {
        maze->mat[maze->i + 1][maze->j] = '*';
        maze->mat[maze->i + 1][maze->j - 1] = '*';
        if (maze->j < maze->cols - 1)
            maze->mat[maze->i + 1][maze->j + 1] = '*';
    } else {
        maze->mat[maze->i + 1][maze->j] = '*';
        maze->mat[maze->i][maze->j] = '*';
    }
}

static void find_stars_imperfect(gen_t *maze)
{
    maze->count = rand() % 2;
    if (maze->mat[maze->i + 1][maze->j - 2] == '*'
    && maze->mat[maze->i - 1][maze->j] == '*')
        fill_cols(maze);
}

static void fill_maze_imperfect(gen_t *maze)
{
    for (maze->i = 1; maze->i < maze->rows - 1; maze->i += 2)
        for (maze->j = 2; maze->j < maze->cols; maze->j += 2)
            find_stars_imperfect(maze);
    maze->mat[maze->rows - 1][maze->cols - 1] = '*';
    if (maze->rows % 2 == 0 && maze->cols % 2 == 0)
        maze->mat[maze->rows - 1][maze->cols - 2] = '*';
}

void is_this_perfect(gen_t *maze, char **argv)
{
    if (argv[3] == NULL)
        fill_maze_imperfect(maze);
    else if (strcmp(argv[3], "perfect") == 0)
        fill_maze(maze);
}