/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-stumper5-tanguy.bellicha
** File description:
** tests
*/

#include <criterion/criterion.h>
#include "hangman.h"

int check_errors(int ac);
int check_multiple_word_per_line(char *str);
int check_length_of_words(char **array);

Test(check_errors, not_enough_arguments)
{
    int nb = 0;

    cr_assert_eq(check_errors(nb), 0);
}

Test(check_errors, too_much_arguments)
{
    int nb = 6;

    cr_assert_eq(check_errors(nb), 0);
}

Test(check_errors, without_tries)
{
    int nb = 2;

    cr_assert_eq(check_errors(nb), 1);
}

Test(check_errors, with_tries)
{
    int nb = 3;

    cr_assert_eq(check_errors(nb), 1);
}

Test(check_multiple_word_per_line, no_several_words_on_line)
{
    char *str = "Idk\nSi\nC'est\nBon";
    cr_assert_eq(check_multiple_word_per_line(str), 1);
}

Test(check_multiple_word_per_line, with_several_words_on_line)
{
    char *str = "Là\nC'est\nPas Bon";
    cr_assert_eq(check_multiple_word_per_line(str), 0);
}

Test(check_length_of_words, words_with_length)
{
    char **array = malloc(sizeof(char *) * 5);

    array[0] = "La";
    array[1] = "longueur";
    array[2] = "est";
    array[3] = "bonne";
    array[4] = NULL;
    cr_assert_eq(check_length_of_words(array), 1);
}

Test(check_length_of_words, word_with_no_length)
{
    char **array = malloc(sizeof(char *) * 7);

    array[0] = "La";
    array[1] = "longueur";
    array[2] = "n'est";
    array[3] = "pas";
    array[4] = "bonne";
    array[5] = "";
    array[6] = NULL;
    cr_assert_eq(check_length_of_words(array), 0);
}