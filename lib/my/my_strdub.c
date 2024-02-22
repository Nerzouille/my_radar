/*
** EPITECH PROJECT, 2023
** my_strdub
** File description:
** my_strdub stand lib
*/

#include "my.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
    int size = my_strlen(src);
    char *dest;
    int i = 0;

    dest = malloc(sizeof(char) * size + 1);
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
