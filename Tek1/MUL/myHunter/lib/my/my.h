/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>

typedef struct s_win
{
    int width;
    int height;
    sfRenderWindow *window;
    sfSprite *sprite;
    sfEvent event;
    sfUint8 *pixels;
    sfTexture *texture;
    float	fov;
    float	dist_proj;
} t_win;

typedef struct s_my_framebuffer
{
    sfUint8 *pixels;
    int width;
    int height;
} t_my_framebuffer;

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_getnbr(char const *str);
void analyse_events(sfRenderWindow *, sfEvent, sfSprite *);
void close_window(sfRenderWindow *);
void manage_mouse_click(sfMouseButtonEvent event, sfSprite *sprite);
void move_rect(sfIntRect *, int, int);
sfIntRect create_rect(void);
sfRenderWindow *initialise_window (void);
void close_window(sfRenderWindow *window);
sfVector2f update_position(float positionX, float positionY);
sfIntRect create_rect_horizontal_bot(void);
sfIntRect create_rect_horizontal_middle(void);
sfIntRect create_rect_horizontal_top(void);
void kill_animation(sfSprite *sprite);
sfIntRect create_rect_died(void);
sfIntRect create_rect_falling(void);
sfIntRect create_rect_vertical_bot(void);
sfIntRect create_rect_vertical_middle(void);
sfIntRect create_rect_vertical_top(void);
sfRenderWindow *update_window(sfRenderWindow *window, sfSprite *sprite);
sfIntRect create_rect_top_corner_bot(void);
sfIntRect create_rect_top_corner_middle(void);
sfIntRect create_rect_top_corner_top(void);
sfSprite *create_duck(sfSprite *sprite);

#endif /* !MY_H_ */