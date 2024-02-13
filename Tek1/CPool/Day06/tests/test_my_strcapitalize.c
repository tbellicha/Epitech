/*
** EPITECH PROJECT, 2020
** test_my_strcapitalize
** File description:
** 
*/

#include <criterion/criterion.h>

char my_strcapitalize(char *str);

Test (my_strcapitalize, capitalization_first_char)
{
    char str[] = "hey, how are you? 42WORds forty-two; fifty+one";
    
    my_strcapitalize(str);
    cr_assert_str_eq(str, "Hey, How Are You? 42words Forty-Two; Fifty+One");
}

Test (my_strcapitalize, capitalization_first_char_with_special_char)
{
    char str[] = "tHiS iS 4 TeSt :";

    my_strcapitalize(str);
    cr_assert_str_eq(str, "This Is 4 Test :");
}

Test (my_strcapitalize, capitalization_first_char_of_a_string)
{
    char str[] = "i don't know";

    my_strcapitalize(str);
    cr_assert_str_eq(str, "I Don'T Know");
}
