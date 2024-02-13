/*
** EPITECH PROJECT, 2020
** my_sort_in_array
** File description:
** 
*/

void my_swap_int_array (int *number1, int *number2) {
    if (*number1 > *number2) {
        int tempo = *number1;
        
        *number1 = *number2;
        *number2 = tempo;
    }
}

void my_sort_int_array (int *array, int size)
{
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size - 1 - i; j++){
            my_swap_int_array (&array[j], &array[j + 1]);
        }
    }
}
