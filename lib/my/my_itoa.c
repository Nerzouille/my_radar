/*
** EPITECH PROJECT, 2023
** my itoa
** File description:
** my int to array (string)
*/

#include <stdlib.h>

void my_itoa(int nb, char *arr, int len)
{
    int i = len - 1;

    if (nb == 0)
        arr[i] = '0';
    for (i; nb != 0; i--) {
        arr[i] = nb % 10 + '0';
        nb /= 10;
    }
    arr[len] = '\0';
}

// void my_itoa(int nb, char *arr)
// {
//     int i = 0;
//     do {
//         arr[i] = nb % 10 + '0';
//         nb /= 10;
//         i++;
//     } while (nb != 0);
//     arr[i] = '\0';
// }
