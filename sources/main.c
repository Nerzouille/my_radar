/*
** EPITECH PROJECT, 2023
** main
** File description:
** my_radar main
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "../include/my.h"
#include "../include/simu.h"

int help_txt(void)
{
    char *help_t = "Introducing the my_radar project, an air traffic simulatio"
    "n.\nPass file containing aircraft and control tower data as parameter to "
    "observe the magic.\nYou can press the \"S\" key to show or hide the spri"
    "tes.\nThe same goes for hitboxes by pressing \"L\".\n\nYou can press \"q"
    "\" at any moment to quit the simulation\n";

    my_putstr(help_t);
    return 0;
}

int argso(int argc, char **argv)
{
    if (argc == 1 || argc > 2) {
        return 84;
    }
    if (my_strcmp("-h", argv[1]) == 0) {
        help_txt();
        return 1;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    int err_hand = argso(argc, argv);

    if (err_hand != 0)
        return err_hand;
    simu(argv);
    return 0;
}
