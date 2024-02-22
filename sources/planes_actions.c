/*
** EPITECH PROJECT, 2024
** planes actions
** File description:
** planes actions my radar
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/simu.h"

void planes_print(sfRenderWindow *window, simu_sruct *simu,
    PlaneNode **curr)
{
    PlaneNode *current_p = *curr;

    if (simu->sprites_bol == 1) {
        sfRenderWindow_drawSprite(window, current_p->sprite, NULL);
    }
    if (simu->hitboxes_bol == 1)
        sfRenderWindow_drawRectangleShape(window, current_p->hb, NULL);
}

int prep_move(sfRenderWindow *window, simu_sruct *simu,
    PlaneNode **adPlLis, PlaneNode **curr)
{
    PlaneNode *current_p = *curr;

    planes_print(window, simu, curr);
    return move_planes(window, simu, curr, adPlLis);
}

void plane_del_nxt(PlaneNode **current_p, PlaneNode **prev,
    PlaneNode *next, PlaneNode **adPlLis)
{
    if (*prev == NULL)
        *current_p = *adPlLis;
    else {
        (*prev)->next = next;
        *current_p = (*prev)->next;
    }
}

void plane_loop(sfRenderWindow *window, simu_sruct *simu,
    PlaneNode **adPlLis, TowersNode **adToLis)
{
    PlaneNode *current_p = *adPlLis;
    PlaneNode *prev = NULL;
    PlaneNode *next = NULL;
    int mv = 0;
    float seconds = sfTime_asSeconds(sfClock_getElapsedTime(simu->clock));

    while (current_p != NULL) {
        next = current_p->next;
        if (seconds >= current_p->delay) {
            collision_detect(current_p, simu, adPlLis, adToLis);
            mv = prep_move(window, simu, adPlLis, &current_p);
        }
        if (mv == 1) {
            plane_del_nxt(&current_p, &prev, next, adPlLis);
        } else {
            prev = current_p;
            current_p = next;
        }
    }
}
