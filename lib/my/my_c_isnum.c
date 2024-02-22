/*
** EPITECH PROJECT, 2023
** my char is num
** File description:
** return 1 if char is num
*/

int my_c_isnum(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}
