/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** my
*/

#ifndef _MY_H_
#define _MY_H_

#define TRUE (0)
#define FALSE (84)
#define EXIT_ERROR (84)

typedef enum {
    path,
    wall,
    end,
    crumb
} state;

void free_map(char **map);
char *read_map(char const *filepath);
int count_cols(char const *buffer);
int count_rows(char const *buffer);
char **str_to_tab(char *str, char *filter);
void print_array(char **array);
int count(char *str, char c);
int find(char *str, char c);
int **create_tab(int rows, int cols);
int main(int argc, char const **argv);
int dfs(int **map, int rows, int cols);
int **duplicate_map(char **maze, int rows, int cols);
int **create_limit(int rows, int cols);
void free_algo(int **array, int rows);
int check_path(int **map, int rows, int cols);
int check_map(char *buffer);
char **update_maze(char **maze, int **map, int rows, int cols);
int maze_solving(char **map, int rows, int cols);

#endif