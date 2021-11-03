#pragma once

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>

#include "game.h"

#define grey        al_map_rgb( 192,  192,  192)
#define bg_grey     al_map_rgb(211, 215, 234)
#define red         al_map_rgb(201, 34, 53)
#define white       al_map_rgb(255, 255, 255)
#define black       al_map_rgb(0, 0, 0)

enum level { easy, medium, hard };
int  winWidth;
int winHeight;
int done;
int menu_option;
int pointer_x;
int pointer_y;

ALLEGRO_DISPLAY* window_menu;
ALLEGRO_FONT* font_caption; 
ALLEGRO_FONT* font_header; 
