/*
** EPITECH PROJECT, 2020
** my_print_comb2
** File description:
** 
*/

void my_putchar(char c);

void print_result(int pos1, int pos2, int pos3, int pos4)
{
    my_putchar (pos1 + 48);
    my_putchar (pos2 + 48);
    my_putchar (' ');
    my_putchar (pos3 + 48);
    my_putchar (pos4 + 48);
    if (pos1 == 9 && pos2 == 8 && pos3 == 9 && pos4 == 9) {

    } else {
        my_putchar (',');
        my_putchar (' ');
    }
}

void my_function_calcul(int pos1, int pos2, int pos3, int pos4)
{
    while (pos1 <= 9 && pos2 <= 9 && pos3 <= 9 && pos4 <= 9) {
        print_result (pos1, pos2, pos3, pos4);
        if (pos2 >= 9 && pos3 >= 9 && pos4 >= 9) {
            pos1++;
            pos2 = -1;
        }
        if (pos3 >= 9 && pos4 >= 9) {
            pos2++;
            pos3 = pos1;
            pos4 = pos2;
        }
        if (pos4 >= 9) {
            pos3++;
            pos4 = 0;
        } else {
            pos4 ++;
        }
    }
}

int my_print_comb2(void)
{
    int pos1 = 0;
    int pos2 = 0;
    int pos3 = 0;
    int pos4 = 1;

    my_function_calcul (pos1, pos2, pos3, pos4);
    return (0);
}
