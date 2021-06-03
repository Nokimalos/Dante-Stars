/*
** EPITECH PROJECT, 2021
** dante
** File description:
** read the file that contain the map
*/

#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include "my.h"

void free_map(char **map)
{
    for (int i = 0; map[i] != NULL; i += 1)
        free(map[i]);
    free(map);
}

char *read_map(char const *filepath)
{
    char *map_read;
    int fd = 0;
    int rd = 0;
    int map_size = 0;
    struct stat st;

    if (stat(filepath, &st) == -1)
        return (NULL);
    map_size = st.st_size;
    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return (NULL);
    if ((map_read = malloc(sizeof(char) * map_size + 1)) == NULL)
        return (NULL);
    rd = read(fd, map_read, map_size);
    if (strlen(map_read) == 0)
        return (NULL);
    map_read[rd] = '\0';
    return (map_read);
}