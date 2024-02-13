/*
** EPITECH PROJECT, 2022
** MyTeams - LibMy Excerpt
** File description:
** Tests the my_cbuffer_write function
*/

#include "cbuffer.h"

#include <criterion/criterion.h>

Test(my_cbuffer_write_front, empty_buf)
{
    char data[11] = "ABCDEFGHIJ";
    my_cbuffer_t buf = {data, 10, 0, 0, 0};

    my_cbuffer_write_front(&buf, "test", 4);
    cr_assert_str_eq(data, "ABCDEFtest");
    cr_assert_eq(buf.cap, 10);
    cr_assert_eq(buf.len, 0);
    cr_assert_eq(buf.tail, 0);
    cr_assert_eq(buf.head, 0);
}

Test(my_cbuffer_write_front, contiguous_to_contiguous)
{
    char data[11] = "ABCDefgHIJ";
    my_cbuffer_t buf = {data, 10, 3, 4, 7};

    my_cbuffer_write_front(&buf, "test", 4);
    cr_assert_str_eq(data, "testefgHIJ");
    cr_assert_eq(buf.cap, 10);
    cr_assert_eq(buf.len, 3);
    cr_assert_eq(buf.tail, 4);
    cr_assert_eq(buf.head, 7);
}

Test(my_cbuffer_write_front, contiguous_to_split)
{
    char data[11] = "ABCdefgHIJ";
    my_cbuffer_t buf = {data, 10, 4, 3, 7};

    my_cbuffer_write_front(&buf, "test", 4);
    cr_assert_str_eq(data, "estdefgHIt");
    cr_assert_eq(buf.cap, 10);
    cr_assert_eq(buf.len, 4);
    cr_assert_eq(buf.tail, 3);
    cr_assert_eq(buf.head, 7);
}

Test(my_cbuffer_write_front, split_to_split)
{
    char data[11] = "abCDEFGHij";
    my_cbuffer_t buf = {data, 10, 4, 8, 2};

    my_cbuffer_write_front(&buf, "test", 4);
    cr_assert_str_eq(data, "abCDtestij");
    cr_assert_eq(buf.cap, 10);
    cr_assert_eq(buf.len, 4);
    cr_assert_eq(buf.tail, 8);
    cr_assert_eq(buf.head, 2);
}

Test(my_cbuffer_write_back, empty_buf)
{
    char data[11] = "ABCDEFGHIJ";
    my_cbuffer_t buf = {data, 10, 0, 0, 0};

    my_cbuffer_write_back(&buf, "test", 4);
    cr_assert_str_eq(data, "testEFGHIJ");
    cr_assert_eq(buf.cap, 10);
    cr_assert_eq(buf.len, 0);
    cr_assert_eq(buf.tail, 0);
    cr_assert_eq(buf.head, 0);
}

Test(my_cbuffer_write_back, contiguous_to_contiguous)
{
    char data[11] = "ABcdefGHIJ";
    my_cbuffer_t buf = {data, 10, 4, 2, 6};

    my_cbuffer_write_back(&buf, "test", 4);
    cr_assert_str_eq(data, "ABcdeftest");
    cr_assert_eq(buf.cap, 10);
    cr_assert_eq(buf.len, 4);
    cr_assert_eq(buf.tail, 2);
    cr_assert_eq(buf.head, 6);
}

Test(my_cbuffer_write_back, contiguous_to_split)
{
    char data[11] = "ABCDefgHIJ";
    my_cbuffer_t buf = {data, 10, 3, 4, 7};

    my_cbuffer_write_back(&buf, "test", 4);
    cr_assert_str_eq(data, "tBCDefgtes");
    cr_assert_eq(buf.cap, 10);
    cr_assert_eq(buf.len, 3);
    cr_assert_eq(buf.tail, 4);
    cr_assert_eq(buf.head, 7);
}

Test(my_cbuffer_write_back, split_to_split)
{
    char data[11] = "abCDEFGHij";
    my_cbuffer_t buf = {data, 10, 4, 8, 2};

    my_cbuffer_write_back(&buf, "test", 4);
    cr_assert_str_eq(data, "abtestGHij");
    cr_assert_eq(buf.cap, 10);
    cr_assert_eq(buf.len, 4);
    cr_assert_eq(buf.tail, 8);
    cr_assert_eq(buf.head, 2);
}
