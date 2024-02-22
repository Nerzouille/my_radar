/*
** EPITECH PROJECT, 2023
** my str in array
** File description:
** transpose each word of an str on an array
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_start(const char *str, int start)
{
    while (str[start] == ' '
    || str[start] == '\t' || str[start] == '\n') {
        start++;
    }
    return start;
}

int find_end(const char *str, int end)
{
    while (str[end] != ' ' && str[end] != '\t'
    && str[end] != '\n' && str[end] != '\0') {
        end++;
    }
    return end;
}

int word_count(const char *str)
{
    int word_count = 1;

    for (int i = 0; str[i + 1] != '\0'; ++i) {
        if ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
        && (str[i + 1] != ' ' || str[i + 1] != '\t'
        || str[i + 1] != '\n')) {
            word_count++;
        }
    }
    return word_count;
}

char **my_str_in_array(const char *str)
{
    int w_count = 0;
    char **word_array;
    int start = 0;
    int end = 0;
    int i = 0;

    w_count = word_count(str);
    word_array = malloc(sizeof(char *) * (w_count + 1));
    while (str[end] != '\0') {
        start = find_start(str, start);
        end = find_end(str, start);
        word_array[i] = (char *)malloc((end - start + 1) * sizeof(char));
        my_strncpy(word_array[i], &str[start], end - start);
        word_array[i][end - start] = '\0';
        start = end + 1;
        i++;
    }
    word_array[i] = NULL;
    return word_array;
}
