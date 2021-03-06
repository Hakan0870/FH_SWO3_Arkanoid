#pragma once

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "resources.h"
#include "game.h"
#include <stdio.h>
#include <stdlib.h>


void make_blocks_easy(struct Block block[COLS][ROWS]);
void make_blocks_medium(struct Block block[COLS][ROWS]);
void make_blocks_hard(struct Block block[COLS][ROWS]);
void draw_blocks(struct Block block[COLS][ROWS]);
