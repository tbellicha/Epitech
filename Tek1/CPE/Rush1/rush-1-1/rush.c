/*
** EPITECH PROJECT, 2020
** rush-1-1
** File description:
** 
*/

void my_putchar (char c);

void display_corner (int corner)
{
    switch (corner) {
        case 1:
            my_putchar ('o');
            break;

        case 2:
            my_putchar ('o');
            my_putchar ('\n');
            break;
    }
}

void display_horizontal (int x)
{
    for (int i = 0; i < x; i++) {
        my_putchar ('-');
    }
}

void display_vertical (int x, int y, int nb)
{
    for (int i = 0; i < y; i++) {
        my_putchar ('|');
        for (int j = 0; j < x; j++) {
            my_putchar (' ');
        }
        if (nb == 2)
            my_putchar ('|');
        my_putchar ('\n');
    }
}

void vertical_line (int x, int y)
{
    display_corner (2);
    display_horizontal (x - 2);
    if (y > 2)
        display_vertical (0, y - 2, 1);
    if ( x != 1 && y != 1)
        display_corner (2);
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
        display_corner (1);
        display_horizontal (x - 2);
        display_corner (2);
        if (y > 2)
            display_vertical (x - 2, y - 2, 2);
    }
    else if (x == 1)
        vertical_line (x, y);
    if (y > 1) {
        display_corner (1);
        display_horizontal (x - 2);
        if (x > 1)
            display_corner (2);
    }
    if (x <= 0 || y <= 0)
        error();
}
