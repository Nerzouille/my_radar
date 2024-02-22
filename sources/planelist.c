/*
** EPITECH PROJECT, 2023
** plane list
** File description:
** plane list my radar
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <math.h>
#include "../include/my.h"
#include "../include/simu.h"
#include <stdlib.h>

int del_plane(PlaneNode **first, int id)
{
    PlaneNode *prev = NULL;
    PlaneNode *temp = *first;

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return 84;
    if (temp == *first)
        *first = temp->next;
    else
        prev->next = temp->next;
    free(temp);
    return 0;
}

void planes_hb(PlaneNode *newPlane, float *arc)
{
    newPlane->hb = sfRectangleShape_create();
    sfRectangleShape_setSize(newPlane->hb, (sfVector2f){20, 20});
    sfRectangleShape_setOutlineThickness(newPlane->hb, 1);
    sfRectangleShape_setOutlineColor(newPlane->hb, sfWhite);
    sfRectangleShape_setFillColor(newPlane->hb, sfColor_fromRGBA(0, 0, 0, 0));
    sfRectangleShape_rotate(newPlane->hb, *arc);
    sfRectangleShape_setPosition(newPlane->hb,
        (sfVector2f){newPlane->depx, newPlane->depy});
}

sfVector2f pix_len(PlaneNode *newPlane)
{
    int x_len = newPlane->arrx - newPlane->depx;
    int y_len = newPlane->arry - newPlane->depy;
    double vect_len = sqrt(pow(x_len, 2) + pow(y_len, 2));
    float arc = acos(x_len / vect_len) * 180 / 3.141592653589793238462;

    newPlane->collide = 0;
    newPlane->traj_x = 0;
    newPlane->move = (sfVector2f){x_len / vect_len * newPlane->speed,
        y_len / vect_len * newPlane->speed};
    newPlane->traj_tot = x_len / newPlane->move.x;
    if (x_len <= 0 && y_len >= 0)
        vect_len *= -1;
    else
        arc *= -1;
    planes_hb(newPlane, &arc);
    sfSprite_setOrigin(newPlane->sprite, (sfVector2f){10, 10});
    sfSprite_rotate(newPlane->sprite, arc);
}

void add_plane(PlaneNode **first, sfTexture *texture, temp_plane *datas)
{
    static int id = 0;
    PlaneNode *newPlane = malloc(sizeof(PlaneNode));

    newPlane->id = id;
    newPlane->sprite = sfSprite_create();
    sfSprite_setTexture(newPlane->sprite, texture, sfTrue);
    sfSprite_setScale(newPlane->sprite, (sfVector2f){0.07, 0.07});
    newPlane->depx = datas->depx;
    newPlane->depy = datas->depy;
    newPlane->arrx = datas->arrx;
    newPlane->arry = datas->arry;
    newPlane->speed = datas->speed;
    newPlane->delay = datas->delay;
    pix_len(newPlane);
    sfSprite_setPosition(newPlane->sprite,
        (sfVector2f){newPlane->depx, newPlane->depy});
    newPlane->next = *first;
    *first = newPlane;
    id++;
}
