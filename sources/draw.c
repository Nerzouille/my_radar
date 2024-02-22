/*
** EPITECH PROJECT, 2023
** draw
** File description:
** my_radar draw
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/simu.h"

static void sprite_button(simu_sruct *simu)
{
    if (simu->s_press == 0 && simu->sprites_bol == 0)
        simu->sprites_bol = 1;
    else if (simu->s_press == 0 && simu->sprites_bol == 1)
        simu->sprites_bol = 0;
    simu->s_press = 1;
}

static void hitboxes_button(simu_sruct *simu)
{
    if (simu->l_press == 0 && simu->hitboxes_bol == 0)
        simu->hitboxes_bol = 1;
    else if (simu->l_press == 0 && simu->hitboxes_bol == 1)
        simu->hitboxes_bol = 0;
    simu->l_press = 1;
}

void what_do_i_print(simu_sruct *simu)
{
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        sprite_button(simu);
    } else
        simu->s_press = 0;
    if (sfKeyboard_isKeyPressed(sfKeyL)) {
        hitboxes_button(simu);
    } else
        simu->l_press = 0;
}

int static to_delet(PlaneNode **adPlLis, PlaneNode *current_p)
{
    if (current_p->traj_x == current_p->traj_tot || current_p->collide == 1) {
        del_plane(adPlLis, current_p->id);
        return 1;
    }
    return 0;
}

int move_planes(sfRenderWindow *window, simu_sruct *simu,
    PlaneNode **curr, PlaneNode **adPlLis)
{
    PlaneNode *current_p = *curr;

    current_p->traj_x++;
    sfRectangleShape_setPosition(current_p->hb,
    (sfVector2f){sfSprite_getPosition(current_p->sprite).x + current_p->move.x,
    sfSprite_getPosition(current_p->sprite).y + current_p->move.y});
    sfSprite_setPosition(current_p->sprite,
    (sfVector2f){sfSprite_getPosition(current_p->sprite).x + current_p->move.x,
    sfSprite_getPosition(current_p->sprite).y + current_p->move.y});
    if (to_delet(adPlLis, current_p) == 1)
        return 1;
    return 0;
}

static void print_timer(sfRenderWindow *window, simu_sruct *simu, int seconds)
{
    return;
}

void print_basics(sfRenderWindow *window, simu_sruct *simu,
    TowersNode *current_t)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, simu->bg_sprite, NULL);
    while (current_t != NULL) {
        if (simu->sprites_bol == 1)
            sfRenderWindow_drawSprite(window, current_t->sprite, NULL);
        if (simu->hitboxes_bol == 1)
            sfRenderWindow_drawCircleShape(window, current_t->radius, NULL);
        current_t = current_t->next;
    }
}

int draw(sfRenderWindow *window, simu_sruct *simu,
    PlaneNode **adPlLis, TowersNode **adToLis)
{
    what_do_i_print(simu);
    print_basics(window, simu, *adToLis);
    plane_loop(window, simu, adPlLis, adToLis);
    sfRenderWindow_display(window);
    if (*adPlLis == NULL) {
        return 1;
    }
    return 0;
}
