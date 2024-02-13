/*
** EPITECH PROJECT, 2025
** stump5
** File description:
** Created by hjulien,
*/

#include "hangman.h"

int count_words_dico(dico_t *dico)
{
    int i = 0;

    for (; dico->array_words[i]; i++);
    return (i);
}

dico_t *load_dico(int ac, char **av)
{
    char *file_content = NULL;
    dico_t *dico = malloc(sizeof(dico_t));

    if (!dico)
        exit(84);
    file_content = file_to_string(av[1]);
    dico->tries = 10;
    if (ac == 3)
        dico->tries = my_getnbr(av[2]);
    if (!file_content || !check_multiple_word_per_line(file_content))
        exit(84);
    dico->array_words = my_str_to_word_tab(file_content, '\n');
    if (!dico->array_words)
        exit(84);
    if (!check_length_of_words(dico->array_words))
        exit(84);
    dico->nb_words = count_words_dico(dico);
    return (dico);
}

game_t *game_init(int ac, char **av)
{
    game_t *game = malloc(sizeof(game_t));

    if (!game)
        return (NULL);
    game->dico = load_dico(ac, av);
    game->word = game->dico->array_words[rand() % game->dico->nb_words];
    game->hidden_word = my_calloc_char(my_strlen(game->word) + 1, '*');
    if (!game->word || !game->hidden_word)
        return (NULL);
    game->hidden_word[my_strlen(game->word)] = 0;
    game->win = false;
    return (game);
}