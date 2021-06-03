/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-1-dante-kaan.bouldoires
** File description:
** generator
*/

#ifndef GENERATOR_H_
#define GENERATOR_H_

#include <stdbool.h>

typedef struct gen_s {
    char **mat;
    int rows;
    int cols;
    int count;
    int check;
    int i;
    int j;
} __attribute__((__packed__))gen_t;

bool get_malloc(gen_t *maze);
int initialize_cells(gen_t *maze, char **argv);
int error_handling(int argc, char **argv);
void fill_maze(gen_t *maze);
void is_this_perfect(gen_t *maze, char **argv);
void free_array(gen_t *maze);
int main(int argc, char **argv);

#endif/* !GENERATOR_H_ */