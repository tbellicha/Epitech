/*
** EPITECH PROJECT, 2020
** my_print_digits
** File description:
** 
*/

void my_putchar(char c);

int my_print_digits(void)
{
    for (int number = 0; number < 10; number++) {
        my_putchar(number + 48);
    }
    return (0);
}
