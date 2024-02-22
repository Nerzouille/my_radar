/*
** EPITECH PROJECT, 2024
** plane collisions
** File description:
** plane collisions my radar
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/simu.h"

int plane_in_safe_area(PlaneNode *current_p, TowersNode **adToLis)
{
    TowersNode *current_t = *adToLis;
    sfVector2f plane_Pos = sfRectangleShape_getPosition(current_p->hb);
    sfVector2f area_Pos;
    float dist_x;
    float dist_y;

    while (current_t != NULL) {
        area_Pos = (sfVector2f){current_t->corx, current_t->cory};
        dist_x = my_abs(plane_Pos.x - area_Pos.x);
        dist_y = my_abs(plane_Pos.y - area_Pos.y);
        if (dist_x <= 10 + current_t->rad && dist_y <= 10 + current_t->rad)
            return 1;
        current_t = current_t->next;
    }
    return 0;
}

int does_planes_collide(float *dist,
    PlaneNode *current_p, PlaneNode *current_col)
{
    if (dist[0] <= 10 + 10 && dist[1] <= 10 + 10) {
        current_p->collide = 1;
        current_col->collide = 1;
        return 1;
    }
    return 0;
}

int plane_collide(PlaneNode *current_p, PlaneNode **adPlLis, simu_sruct *simu)
{
    PlaneNode *current_col = *adPlLis;
    sfVector2f plane_Pos = sfRectangleShape_getPosition(current_p->hb);
    sfVector2f collider_Pos;
    float dist[2];
    int collision = 0;
    float seconds = sfTime_asSeconds(sfClock_getElapsedTime(simu->clock));

    while (current_col != NULL) {
        if (current_p->id != current_col->id && seconds >= current_col->delay){
            collider_Pos = sfRectangleShape_getPosition(current_col->hb);
            dist[0] = my_abs(plane_Pos.x - collider_Pos.x);
            dist[1] = my_abs(plane_Pos.y - collider_Pos.y);
            collision = does_planes_collide(dist, current_p, current_col);
        }
        current_col = current_col->next;
    }
    return collision;
}

void collision_detect(PlaneNode *current_p, simu_sruct *simu,
    PlaneNode **adPlLis, TowersNode **adToLis)
{
    if (plane_in_safe_area(current_p, adToLis))
        sfRectangleShape_setOutlineColor(current_p->hb, sfGreen);
    else if (plane_collide(current_p, adPlLis, simu))
        sfRectangleShape_setOutlineColor(current_p->hb, sfRed);
    else
        sfRectangleShape_setOutlineColor(current_p->hb, sfWhite);
}
