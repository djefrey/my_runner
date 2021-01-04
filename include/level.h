/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** level
*/

#ifndef LEVEL_H_
#define LEVEL_H_

#include "my_runner.h"

const enum texture TEXTURE_LIST[] = {STONE_TEXT,
                                    GRASS_TEXT,
                                    DIRT_TEXT,
                                    FIRE_TEXT,
                                    COIN_TEXT};

const enum object_type OBJECT_LIST[] = {BLOCK,
                                        BLOCK,
                                        BLOCK,
                                        FIRE,
                                        COIN};

const update_fct_t UPDATE_LIST[] = {&update_block,
                                    &update_block,
                                    &update_block,
                                    &update_fire,
                                    &update_emerald};

#endif /* !LEVEL_H_ */