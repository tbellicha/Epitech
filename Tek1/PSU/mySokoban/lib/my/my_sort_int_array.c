/*
** EPITECH PROJECT, 2020
** my_sort_in_array
** File description:
** desc
*/

void my_swap_int_array(int *number1, int *number2)
{
    int tempo;

    if (*number1 > *number2) {
        tempo = *number1;
        *number1 = *number2;
        *number2 = tempo;
    }
}

void my_sort_int_array(int *array, int size)
{
    for (int i = 0; i < size; i++) {
        for (int k = 0; k < size - 1 - i; k++) {
            my_swap_int_array (&array[k], &array[k + 1]);
        }
    }
}
