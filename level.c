/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** level
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my_runner.h"
#include "my_list.h"

static void read_line(char *line, int len, int y, infos_t *infos)
{
    object_t *obj;

    for (int i = 0; i < len; i++, line += 1) {
        if (*line == '1')
            obj = create_object(infos, BLOCK, BLOCK_TEXT, &update_block);
        else if (*line == '2')
            obj = create_object(infos, SPIKE, SPIKE_TEXT, &update_block);
        else
            continue;
        set_position(obj, i * 64, y * 64);
    }
}

int load_level(char *filepath, infos_t *infos)
{
    FILE *file = fopen(filepath, "r");
    char *buff = NULL;
    size_t len = 0;
    ssize_t nread = 0;

    if (file == NULL) {
        write(2, "Level file not found\n", 21);
        return (1);
    }
    for (int i = 0; (nread = getline(&buff, &len, file)) >= 0; i++)
        read_line(buff, nread, i, infos);
    free(buff);
    fclose(file);
    return (0);
}