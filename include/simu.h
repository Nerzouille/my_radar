/*
** EPITECH PROJECT, 2023
** simu
** File description:
** my_radar
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "../include/my.h"

#ifndef SIMU_H_
    #define SIMU_H_

    #include <sys/stat.h>

typedef struct simu {
    int s_press;
    int l_press;
    int sprites_bol;
    int hitboxes_bol;
    char **item_tab;
    sfVideoMode mode;
    sfTexture *bg;
    sfSprite *bg_sprite;
    sfTexture *plane_text;
    sfTexture *tow_text;
    sfClock *clock;
    sfFont *font;
    sfText *time_txt;
} simu_sruct;

typedef struct temp_p {
    int depx;
    int depy;
    int arrx;
    int arry;
    int speed;
    int delay;
} temp_plane;

typedef struct linked_list {
    sfSprite *sprite;
    struct linked_list *next;
    sfVector2f move;
    sfRectangleShape *hb;
    int collide;
    int traj_x;
    int traj_tot;
    int id;
    int depx;
    int depy;
    int arrx;
    int arry;
    int speed;
    int delay;
} PlaneNode;

typedef struct linked_list_t {
    sfSprite *sprite;
    sfCircleShape *radius;
    struct linked_list_t *next;
    int id;
    int corx;
    int cory;
    int rad;
    int arry;
} TowersNode;

void collision_detect(PlaneNode *current_p, simu_sruct *simu,
    PlaneNode **adPlLis, TowersNode **adToLis);
int del_plane(PlaneNode **first, int id);
void plane_loop(sfRenderWindow *window, simu_sruct *simu,
    PlaneNode **adPlLis, TowersNode **adToLis);
int move_planes(sfRenderWindow *window, simu_sruct *simu,
    PlaneNode **curr, PlaneNode **adPlLis);
void add_plane(PlaneNode **first, sfTexture *texture, temp_plane *datas);
void add_tower(TowersNode **first, sfTexture *texture, temp_plane *datas);
void plane_list_assign(simu_sruct *simu,
    PlaneNode **planeList, TowersNode **towerList);
int file_opener(char *argv[], simu_sruct *simu);
int draw(sfRenderWindow *window, simu_sruct *simu,
    PlaneNode **adPlLis, TowersNode **adToLis);
int simu(char *argv[]);

#endif /* !SIMU_H_ */
