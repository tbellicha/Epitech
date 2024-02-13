/*
** EPITECH PROJECT, 2020
** B-PSU-100-NAN-1-1-myprintf-tanguy.bellicha
** File description:
** test_my_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../includes/bsprintf.h"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, test_percent_i, .init = cr_redirect_stdout)
{
    my_printf("%i %i %+i %+i", 28, -28, 28, -28);
    cr_assert_stdout_eq_str("28 -28 +28 -28");
}

Test(my_printf, test_percent_d, .init = cr_redirect_stdout)
{
    my_printf("%d %d %+d %+d", 42, -42, 42, -42);
    cr_assert_stdout_eq_str("42 -42 +42 -42");
}

Test(my_printf, test_percent_c, .init = cr_redirect_stdout)
{
    my_printf("%c %c %c", 'k', '8', 72);
    cr_assert_stdout_eq_str("k 8 H");
}

Test(my_printf, test_percent_s, .init = cr_redirect_stdout)
{
    my_printf("%s", "Hey guys");
    cr_assert_stdout_eq_str("Hey guys");
}

Test(my_printf, test_percent_S, .init = cr_redirect_stdout)
{
    my_printf("%S %S %S", "\n", "Hey guys", "t\boto");
    cr_assert_stdout_eq_str("\\012 Hey guys t\\010oto");
}

Test(my_printf, test_percent_percent, .init = cr_redirect_stdout)
{
    my_printf("%%");
    cr_assert_stdout_eq_str("%");
}

Test(my_printf, test_percent_o, .init = cr_redirect_stdout)
{
    my_printf("%o %o %o %#o %#o %#o", 8, 78, 465316, 8, 78, 465316);
    cr_assert_stdout_eq_str("10 116 1614644 010 0116 01614644");
}

Test(my_printf, test_percent_x, .init = cr_redirect_stdout)
{
    my_printf("%x %x %x %#x %#x %#x", 4, 79, 465316, 4, 79, 465316);
    cr_assert_stdout_eq_str("4 4f 719a4 0x4 0x4f 0x719a4");
}

Test(my_printf, test_percent_X, .init = cr_redirect_stdout)
{
    my_printf("%X %X %X %#X %#X %#X", 4, 79, 465316, 4, 79, 465316);
    cr_assert_stdout_eq_str("4 4F 719A4 0X4 0X4F 0X719A4");
}

Test(my_printf, test_percent_b, .init = cr_redirect_stdout)
{
    my_printf("%b %b %b", 4, 22, 465316);
    cr_assert_stdout_eq_str("100 10110 1110001100110100100");
}

Test(my_printf, test_percent_u, .init = cr_redirect_stdout)
{
    my_printf("%u %u", 22, -8);
    cr_assert_stdout_eq_str("22 4294967288");
}