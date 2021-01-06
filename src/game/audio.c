/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** sound managment
*/

#include <SFML/Audio.h>
#include <stdlib.h>
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
    list_t *sounds = audio->sounds;
    list_t *sbfs = audio->buffers;
    list_t *sound_tmp;
    list_t *sbf_tmp;

    sfMusic_destroy(audio->music);
    while (sbfs && sounds) {
        sound_tmp = sounds->next;
        sbf_tmp = sbfs->next;
        sfSound_destroy((sfSound*) sounds->data);
        sfSoundBuffer_destroy((sfSoundBuffer*) sbfs->data);
        sounds = sound_tmp;
        sbfs = sbf_tmp;
    }
}

audio_t *create_audio(void)
{
    audio_t *audio = malloc(sizeof(audio_t));
    sfMusic *music;

    if (!audio)
        return (NULL);
    music = sfMusic_createFromFile("./assets/audio/music.ogg");
    if (!music) {
        sfMusic_destroy(music);
        return (NULL);
    }
    sfMusic_setLoop(music, sfTrue);
    audio->music = music;
    for (int i = 0; i < NB_SOUND; i++) {
        if (load_sound(SOUND_LIST[NB_SOUND - i - 1], audio)) {
            destroy_audio(audio);
            return (NULL);
        }
    }
    return (audio);
}