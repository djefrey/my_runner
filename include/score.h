/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** digits
*/

#ifndef DIGITS_H_
#define DIGITS_H_

#include <SFML/Graphics.h>

#define NBR_DIGITS 12

#define DIGIT_SIZE 18
#define DIGIT_PADDING 9

#define BUFFER_WIDTH (NBR_DIGITS * (DIGIT_SIZE + DIGIT_PADDING + 1))
#define BUFFER_HEIGHT ((DIGIT_SIZE) * 2 + 2)

#define DIGIT_COLOR sfGreen

/*
** -- 0 --
**|       |
**1       2
**|       |
** -- 3 --
**|       |
**4       5
**|       |
** -- 6 --
*/

const unsigned char DIGITS[10][7] = {{1, 1, 1, 0, 1, 1, 1},
                                    {0, 0, 1, 0, 0, 1, 0},
                                    {1, 0, 1, 1, 1, 0, 1},
                                    {1, 0, 1, 1, 0, 1, 1},
                                    {0, 1, 1, 1, 0, 1, 0},
                                    {1, 1, 0, 1, 0, 1, 1},
                                    {1, 1, 0, 1, 1, 1, 1},
                                    {1, 0, 1, 0, 0, 1, 0},
                                    {1, 1, 1, 1, 1, 1, 1},
                                    {1, 1, 1, 1, 0, 1, 1}};

#endif /* !DIGITS_H_ */