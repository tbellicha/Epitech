/*
** EPITECH PROJECT, 2020
** rush_1_5
** File description:
** 
*/

void my_putchar (char c);

void display_corner (int corner, int new_line, int top_bot)
{
    if (top_bot == 1 && corner == 2)
        corner = 1;
    else if (corner == 1 && top_bot == 0)
        corner = 1;
    else
        corner = 2;
    switch (corner) {
        case 1:
            my_putchar ('A');
            break;

        case 2:
            my_putchar ('C');
            break;
    }
    if (new_line == 1)
        my_putchar ('\n');
}

void display_horizontal (int x, int y, int top_bot)
{
    char c = 'B';

    if (y == 1) {
        for (int i = 0; i < x + 2; i++) {
            my_putchar (c);
        }
    } else {
        display_corner (1, 0, top_bot);
        for (int i = 0; i < x; i++) {
            my_putchar (c);
        }
        display_corner (2, 1, top_bot);
    }
}

void display_spaces (int nb)
{
    for (int i = 0; i < nb; i++)
        my_putchar (' ');
}

void display_vertical (int x, int y, int nb)
{
    char c = 'B';

    if (x == 1) {
        for (int i = 0; i < y + 2; i++) {
            my_putchar (c);
            my_putchar ('\n');
        }
    } else {
        for (int j = 0; j < y; j++) {
            my_putchar (c);
            display_spaces (x - 2);
            my_putchar (c);
            my_putchar ('\n');
        }
    }
}

void error (void)
{
    my_putchar ('I');
    my_putchar ('n');
    my_putchar ('v');
    my_putchar ('a');
    my_putchar ('l');
    my_putchar ('i');
    my_putchar ('d');
    my_putchar (' ');
    my_putchar ('s');
    my_putchar ('i');
    my_putchar ('z');
    my_putchar ('e');
    my_putchar ('\n');
}

void rush (int x, int y)
{
    if (x > 1 && y >= 1) {
        if (x > 1)
            display_horizontal (x - 2, y, 0);
        if (y > 1)
            display_vertical (x, y - 2, 2);
        if (x > 1 && y > 1)
            display_horizontal (x - 2, y, 0);
    }
    if (x == 1 && y == 1)
        my_putchar ('B');
    if (x <= 0 || y <= 0)
        error();
}
