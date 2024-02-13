/*
** EPITECH PROJECT, 2020
** my_show_word_array
** File description:
** 
*/

int my_show_word_array(char * const *tab)
{
    int i;

    while (tab[i] != 0) {
        my_putstr(tab[i]);
        my_putchar('\n');
        i++;
    }
    return (0);
}
