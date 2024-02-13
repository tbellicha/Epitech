/*
** EPITECH PROJECT, 2020
** my_sort_int_array
** File description:
** sort int in array
*/

void swap_numbers(int *int_1, int *int_2)
{
    if (*int_1 > *int_2) {
        int stock = *int_1;

        *int_1 = *int_2;
        *int_2 = stock;
    }
}

void my_sort_int_array(int *array, int size)
{
    int i;
    int k;

    for (i = 0; i < size; i++) {
        for (k = 0; k < size - i - 1; k++) {
            swap_numbers(&array[k], &array[k + 1]);
        }
    }
}
