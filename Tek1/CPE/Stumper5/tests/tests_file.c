/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-stumper5-tanguy.bellicha
** File description:
** tests
*/

#include <criterion/criterion.h>
#include "hangman.h"

char *file_to_string(const char *pathname);

Test(file_to_string, invalid_file)
{
    char *filepath = "invalid_path";

    cr_assert_eq(file_to_string(filepath), NULL);
}