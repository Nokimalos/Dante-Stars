/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-1-dante-kaan.bouldoires
** File description:
** utils
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include "generator.h"

void free_array(gen_t *maze)
{
    for (int i = 0; maze->mat[i]; i++)
        free(maze->mat[i]);
    free(maze->mat);
}

bool get_malloc(gen_t *maze)
{
    int i = 0;

    maze->mat = malloc((maze->rows + 1) * sizeof(char *));
    if (!maze->mat)
        return false;
    for (i = 0; i < maze->rows; i++) {
        maze->mat[i] = malloc((maze->cols + 1) * sizeof(char));
        if (!maze->mat[i])
            return false;
    }
    maze->mat[i] = NULL;
    return true;
}
