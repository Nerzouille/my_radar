/*
** EPITECH PROJECT, 2023
** plane list
** File description:
** plane list my radar
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include "../include/my.h"
#include "../include/simu.h"

void tower_list_assign(simu_sruct *simu, int i,
    TowersNode **towerList, temp_plane *temp_plane)
{
    if (simu->item_tab[i][0] == 'T') {
        temp_plane->depx = my_getnbr(simu->item_tab[i + 1]);
        temp_plane->depy = my_getnbr(simu->item_tab[i + 2]);
        temp_plane->arrx = my_getnbr(simu->item_tab[i + 3]);
        i += 3;
        add_tower(towerList, simu->tow_text, temp_plane);
    }
}

void plane_list_assign(simu_sruct *simu,
    PlaneNode **planeList, TowersNode **towerList)
{
    temp_plane temp_plane;

    for (int i = 0; simu->item_tab[i] != NULL; i++) {
        if (simu->item_tab[i][0] == 'A') {
            temp_plane.depx = my_getnbr(simu->item_tab[i + 1]);
            temp_plane.depy = my_getnbr(simu->item_tab[i + 2]);
            temp_plane.arrx = my_getnbr(simu->item_tab[i + 3]);
            temp_plane.arry = my_getnbr(simu->item_tab[i + 4]);
            temp_plane.speed = my_getnbr(simu->item_tab[i + 5]);
            temp_plane.delay = my_getnbr(simu->item_tab[i + 6]);
            i += 6;
            add_plane(planeList, simu->plane_text, &temp_plane);
        }
        tower_list_assign(simu, i, towerList, &temp_plane);
    }
}

int file_opener(char *argv[], simu_sruct *simu)
{
    int file = open(argv[1], O_RDONLY);
    int len_v;
    struct stat len_s;
    char *item_list;

    stat(argv[1], &len_s);
    len_v = len_s.st_size;
    item_list = malloc(sizeof(char) * len_v + 1);
    read(file, item_list, len_v);
    item_list[len_v] = '\0';
    simu->item_tab = my_str_in_array(item_list);
    free(item_list);
    close(file);
    return 0;
}
