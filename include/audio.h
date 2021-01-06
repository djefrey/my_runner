/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** audio
*/

#ifndef AUDIO_H_
#define AUDIO_H_

#include <SFML/Audio.h>

enum sound {DAMAGE_SOUND,
            COIN_SOUND};

typedef struct {
    sfMusic *music;
    list_t *sounds;
    list_t *buffers;
} audio_t;

audio_t *create_audio(void);
void destroy_audio(audio_t *audio);
void play_sound(audio_t *audio, enum sound id);

#endif /* !AUDIO_H_ */
