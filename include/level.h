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
                                    COIN_TEXT,
                                    PISTON_TEXT};

const enum object_type OBJECT_LIST[] = {BLOCK,
                                        BLOCK,
                                        BLOCK,
                                        FIRE,
                                        COIN,
                                        PISTON};

const update_fct_t UPDATE_LIST[] = {&update_block,
                                    &update_block,
                                    &update_block,
                                    &update_fire,
                                    &update_emerald,
                                    &update_piston_base};

#endif /* !LEVEL_H_ */