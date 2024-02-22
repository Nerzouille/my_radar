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
#include <stdlib.h>

int simu_actions(sfRenderWindow *window, simu_sruct *simu, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyQ))
            sfRenderWindow_close(window);
    }
}

void init_wind(sfRenderWindow *window, simu_sruct *simu)
{
    int font_size = 60;

    simu->bg_sprite = sfSprite_create();
    simu->bg = sfTexture_createFromFile("./im/bg.jpg", 0);
    simu->tow_text = sfTexture_createFromFile("./im/tower.png", 0);
    simu->plane_text = sfTexture_createFromFile("./im/plane.png", 0);
    simu->clock = sfClock_create();
    simu->font = sfFont_createFromFile("./fonts/EasyJet.ttf");
    simu->time_txt = sfText_create();
    sfText_setFont(simu->time_txt, simu->font);
    sfText_setCharacterSize(simu->time_txt, font_size);
    sfText_setPosition(simu->time_txt, (sfVector2f){1920 - font_size * 6, 17});
    sfRenderWindow_setFramerateLimit(window, 60);
    sfSprite_setTexture(simu->bg_sprite, simu->bg, sfFalse);
    sfSprite_setScale(simu->bg_sprite, (sfVector2f){1.2, 1.03});
}

void destroy_wind(sfRenderWindow *window, simu_sruct *simu)
{
    sfTexture_destroy(simu->plane_text);
    sfTexture_destroy(simu->tow_text);
    sfSprite_destroy(simu->bg_sprite);
    sfTexture_destroy(simu->bg);
    sfRenderWindow_destroy(window);
}

void end_destroy(sfRenderWindow *window, simu_sruct *simu,
    PlaneNode **adPlLis, TowersNode **adToLis)
{
    PlaneNode *planeList = *adPlLis;
    PlaneNode *temp = NULL;
    TowersNode *towerslist = *adToLis;
    TowersNode *temp_t = NULL;

    while (planeList != NULL) {
        temp = planeList;
        planeList = planeList->next;
        sfSprite_destroy(temp->sprite);
        free(temp);
    }
    while (towerslist != NULL) {
        temp_t = towerslist;
        towerslist = towerslist->next;
        sfSprite_destroy(temp_t->sprite);
        free(temp_t);
    }
    sfText_destroy(simu->time_txt);
    sfFont_destroy(simu->font);
    destroy_wind(window, simu);
}

int simu(char *argv[])
{
    simu_sruct simu = {.mode = {1920, 1080, 32}, .sprites_bol = 1,
        .hitboxes_bol = 0, .l_press = 0, .l_press = 0};
    sfRenderWindow *window = sfRenderWindow_create(simu.mode,
    "My Radar", sfResize | sfClose, 0);
    sfEvent event;
    PlaneNode *planeList = NULL;
    TowersNode *towersList = NULL;

    init_wind(window, &simu);
    file_opener(argv, &simu);
    plane_list_assign(&simu, &planeList, &towersList);
    while (sfRenderWindow_isOpen(window)) {
        if (draw(window, &simu, &planeList, &towersList) == 1)
            break;
        simu_actions(window, &simu, event);
    }
    end_destroy(window, &simu, &planeList, &towersList);
    return 0;
}
