/*
** EPITECH PROJECT, 2020
** my_print_comb
** File description:
** 
*/

void my_putchar(char c);

void comas_and_space()
{
    my_putchar(',');
    my_putchar(' ');
}

void print_all_pos(int pos1, int pos2, int pos3)
{
    my_putchar (pos1);
    my_putchar (pos2);
    my_putchar (pos3);
}

int my_print_comb(void)
{
    char pos1 = '0';
    char pos2 = '0';
    char pos3 = '0';

    while (pos1 <= '7') {
        while (pos2 <= pos1)
            pos2++;
        while (pos3 <= pos2)
            pos3++;
        print_all_pos(pos1, pos2, pos3);
        if (pos1 != '7')
            comas_and_space();        
        if (pos3 == '9') {
            pos2++;
            pos3 = '0';
        }
        if (pos2 == '9') {
            pos1++;
            pos2 = '0';
        }
        pos3++;
    }
    return (0);
}
