/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** sound managment
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include "my.h"
#include "my_list.h"
#include "audio.h"
#include "sound_list.h"

static char load_sound(const char *path, audio_t *audio)
{
    sfSoundBuffer *sbf = sfSoundBuffer_createFromFile(path);
    sfSound *sound = sfSound_create();

    if (!sound || !sbf) {
        if (sbf)
            sfSoundBuffer_destroy(sbf);
        if (sound)
            sfSound_destroy(sound);
        return (1);
    }
    sfSound_setBuffer(sound, sbf);
    sfSound_setVolume(sound, 66);
    create_list(&(audio->sounds), sound);
    create_list(&(audio->buffers), sbf);
    return (0);
}

void play_sound(audio_t *audio, enum sound id)
{
    list_t *list = audio->sounds;

    for (int i = 0; i < (int) id; i++, list = list->next);
    sfSound_play((sfSound*) list->data);
}

void destroy_audio(audio_t *audio)
{
    list_t *sounds;
    list_t *sbfs;
    list_t *sound_tmp;
    list_t *sbf_tmp;

    if (!audio)
        return;
    sounds = audio->sounds;
    sbfs = audio->buffers;
    sfMusic_destroy(audio->music);
    while (sounds && sbfs) {
        sound_tmp = sounds->next;
        sbf_tmp = sbfs->next;
        sfSound_destroy((sfSound*) sounds->data);
        sfSoundBuffer_destroy((sfSoundBuffer*) sbfs->data);
        free(sounds);
        free(sbfs);
        sounds = sound_tmp;
        sbfs = sbf_tmp;
    }
}

static sfMusic *load_music_file(char *level_path)
{
    int len = my_strlen(level_path) - 4;
    char *str = malloc(sizeof(char) * (len + 11));
    sfMusic *music;

    my_strncpy(str, level_path, len);
    my_strcat(str, "_music.ogg");
    music = sfMusic_createFromFile(str);
    free(str);
    return (music);
}

audio_t *create_audio(char *level_path)
{
    audio_t *audio = malloc(sizeof(audio_t));
    sfMusic *music;

    if (!audio)
        return (NULL);
    if (!(music = load_music_file(level_path))) {
        free(music);
        return (NULL);
    }
    audio->music = music;
    audio->sounds = NULL;
    audio->buffers = NULL;
    for (int i = 0; i < NB_SOUND; i++) {
        if (load_sound(SOUND_LIST[NB_SOUND - i - 1], audio)) {
            destroy_audio(audio);
            return (NULL);
        }
    }
    return (audio);
}