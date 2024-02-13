/*
** EPITECH PROJECT, 2020
** my_rev_params
** File description:
** 
*/

void my_putstr(char const *str);

void my_putchar(char c);

int main(int argc, char *argv[])
{
    int i = 0;
    
    for (i = (argc - 1); i >= 0 ; i--) {
        my_putstr(argv[i]);
        my_putchar('\n');
    }
    return (0);
}
