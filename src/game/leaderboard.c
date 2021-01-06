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

static int cmp_entries(void *data1, void *data2)
{
    char *str1 = (char*) data1;
    char *str2 = (char*) data2;

    for (str1 += 1; *(str1 - 1) != ' '; str1 += 1);
    for (str2 += 1; *(str2 - 1) != ' '; str2 += 1);
    for (; *str1; str1 += 1, str2 += 1) {
        if (*str1 != *str2)
            return (*str1 - *str2);
    }
    return (0);
}

void write_leaderboard_file(char *path, list_t *lb)
{
    int fd = open("./bonus/level_lb.txt", O_WRONLY | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
    char *str;
    int len;

    if (!fd) {
        write(2, "Failed to open/create leaderboard file\n", 39);
        return;
    }
    while (lb) {
        str = (char*) lb->data;
        len = my_strlen(str);
        write(fd, str, len);
        write(fd, "\n", 1);
        lb = lb->next;
    }
    close(fd);
}

void add_entry_to_leaderboard(list_t **lb, const char *name, int score)
{
    char score_str[13] = {0};
    char *name_w_separator = my_strmerge(name, " ");
    char *entry;

    get_score_str(score_str, score);
    entry = my_strmerge(name_w_separator, score_str);
    if (*lb == NULL)
        create_list(lb, entry);
    else
        my_add_in_sorted_list(lb, entry, &cmp_entries);
    free(name_w_separator);
}

void destroy_leaderboard(list_t *lb)
{
    list_t *tmp;

    while (lb) {
        tmp = lb->next;
        free(lb->data);
        free(lb);
        lb = tmp;
    }
}

list_t *load_leaderboard(char *path)
{
    list_t *list = NULL;
    FILE *file = fopen("./bonus/level_lb.txt", "r");
    char *line = NULL;
    size_t n = 0;
    ssize_t size;

    if (!file)
        return (NULL);
    while ((size = getline(&line, &n, file)) > 0) {
        create_list(&list, line);
        line = NULL;
    }
    my_rev_list(&list);
    fclose(file);
    return (list);
}