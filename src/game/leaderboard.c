/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** leaderboard
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "my_list.h"
#include "score.h"
#include "leaderboard.h"

void write_leaderboard_file(leaderboard_t *lb)
{
    int fd = open(lb->filepath, O_WRONLY | O_CREAT,
    S_IRWXU | S_IRWXG | S_IRWXO);
    char *str;
    int len;

    if (!fd) {
        write(2, "Failed to open/create leaderboard file\n", 39);
        return;
    }
    for (list_t *list = lb->list; list; list = list->next) {
        str = (char*) list->data;
        len = my_strlen(str);
        write(fd, str, len);
        write(fd, "\n", 1);
    }
    close(fd);
}

void add_entry_to_leaderboard(leaderboard_t *lb, const char *name, int score)
{
    char score_str[13] = {0};
    char *name_w_separator = my_strmerge(name, " ");
    char *entry;

    get_score_str(score_str, score);
    entry = my_strmerge(name_w_separator, score_str);
    if (lb->list == NULL)
        create_list(&(lb->list), entry);
    else
        my_add_in_sorted_list(&(lb->list), entry, &cmp_lb_entries);
    free(name_w_separator);
}

void destroy_leaderboard(leaderboard_t *lb)
{
    list_t *tmp;

    for (list_t *list = lb->list; list; list = tmp) {
        tmp = list->next;
        free(list->data);
        free(list);
    }
    free(lb->filepath);
    free(lb);
}

static FILE *load_lb_file(leaderboard_t *lb, char *level_path)
{
    int len = my_strlen(level_path);
    char *cpy = my_strdup(level_path);
    FILE *file;

    my_strinsert(&cpy, "_lb", len - 4);
    lb->filepath = cpy;
    if (!(file = fopen(lb->filepath, "r")))
        return (NULL);
    return (file);
}

leaderboard_t *load_leaderboard(char *level_path)
{
    leaderboard_t *lb = malloc(sizeof(leaderboard_t));
    FILE *file;
    char *line = NULL;
    size_t n = 0;
    ssize_t size;

    if (!lb)
        return (NULL);
    lb->list = NULL;
    if (!(file = load_lb_file(lb, level_path)))
        return (lb);
    while ((size = getline(&line, &n, file)) > 1) {
        line[size - 1] = 0;
        create_list(&(lb->list), line);
        line = NULL;
    }
    if (lb->list && lb->list->next)
        my_rev_list(&(lb->list));
    fclose(file);
    return (lb);
}