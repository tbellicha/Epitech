/*
** EPITECH PROJECT, 2020
** my_print_alpha
** File description:
** 
*/

void my_putchar(char c);

int my_print_alpha(void)
{
    for (char letter = 'a'; letter <= 'z'; letter++) {
        my_putchar (letter);
    }
    return (0);
}
