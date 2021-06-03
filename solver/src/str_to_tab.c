/*
** EPITECH PROJECT, 2021
** gameoflife
** File description:
** str_to_tab.c
*/

#include <string.h>
#include <stdlib.h>
#include "my.h"

int count_rows(char const *buffer)
{
    unsigned int nb_rows = 0;

    for (int i = 0; buffer[i] != '\0'; i += 1)
        if (buffer[i] == '\n')
            nb_rows += 1;
    return (nb_rows);
}

int count_cols(char const *buffer)
{
    unsigned int i = 0;

    for (i = 0; buffer[i] != '\n'; i += 1);
    i += 1;
    return (i);
}

int count_word(char *str, char *filter)
{
    char *token = NULL;
    int i = 0;

    token = strtok(str, filter);
    while (token != NULL) {
        i++;
        token = strtok(NULL, filter);
    }
    return (i);
}

int check_size(char *str, char filter)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        if (str[i] == filter)
            j++;
        i++;
    }
    j++;
    return (j);
}

char **str_to_tab(char *str, char *filter)
{
    char *duplicate = strdup(str);
    int size = count_word(duplicate, filter);
    char *token;
    char **tab = malloc(sizeof(char *) * (size + 1));
    int i = 0;

    token = strtok(str, filter);
    while (token != NULL) {
        tab[i] = malloc(sizeof(char) * strlen(token) + 1);
        tab[i] = strdup(token);
        i++;
        token = strtok(NULL, filter);
    }
    tab[i] = NULL;
    free(duplicate);
    return (tab);
}