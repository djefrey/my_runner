/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** leaderboard header
*/

#ifndef LEADERBOARD_H_
#define LEADERBOARD_H_

#include "my_list.h"

typedef struct {
    char *filepath;
    list_t *list;
} leaderboard_t;

leaderboard_t *load_leaderboard(char *path);
void destroy_leaderboard(leaderboard_t *lb);
void add_entry_to_leaderboard(leaderboard_t *lb, const char *name, int score);
void write_leaderboard_file(leaderboard_t *lb);

#endif /* !LEADERBOARD_H_ */
