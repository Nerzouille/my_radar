/*
** EPITECH PROJECT, 2023
** tower list
** File description:
** tower list my radar
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <math.h>
#include "../include/my.h"
#include "../include/simu.h"
#include <stdlib.h>

void tower_zone(TowersNode *newTower)
{
    sfCircleShape_setRadius(newTower->radius, newTower->rad);
    sfCircleShape_setOutlineThickness(newTower->radius, 1);
    sfCircleShape_setOutlineColor(newTower->radius, sfWhite);
    sfCircleShape_setPosition(newTower->radius,
    (sfVector2f){newTower->corx + 25 - newTower->rad - 1,
    newTower->cory + 25 - newTower->rad - 1});
    sfCircleShape_setFillColor(newTower->radius, sfColor_fromRGBA(0, 0, 0, 0));
}

void add_tower(TowersNode **first, sfTexture *texture, temp_plane *datas)
{
    static int id_tower = 0;
    TowersNode *newTower = malloc(sizeof(TowersNode));

    newTower->id = id_tower;
    newTower->sprite = sfSprite_create();
    sfSprite_setTexture(newTower->sprite, texture, sfTrue);
    sfSprite_setScale(newTower->sprite, (sfVector2f){0.1, 0.1});
    newTower->corx = datas->depx;
    newTower->cory = datas->depy;
    newTower->rad = datas->arrx;
    newTower->radius = sfCircleShape_create();
    sfSprite_setPosition(newTower->sprite,
        (sfVector2f){newTower->corx, newTower->cory});
    tower_zone(newTower);
    newTower->next = *first;
    *first = newTower;
}
