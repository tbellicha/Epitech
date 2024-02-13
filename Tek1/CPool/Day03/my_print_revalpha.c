/*
** EPITECH PROJECT, 2020
** my_print_revalpha
** File description:
** 
*/

void my_putchar(char c);

int my_print_revalpha(void)
{
    for (char letter = 'z'; letter >= 'a'; letter--) {
        my_putchar (letter);
    }
    return (0);
}
