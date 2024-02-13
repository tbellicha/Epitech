/*
** EPITECH PROJECT, 2020
** my_evil_str
** File description:
** 
*/

int my_strlen (char const *str);

char *my_evil_str (char *str)
{
    char tempo;
    int cur_letter = 0;
    int length;

    length = my_strlen(str) - 1;
    while (cur_letter < length) {
        tempo = str[cur_letter];
        str[cur_letter] = str[length];
        str[length] = tempo;
        cur_letter = cur_letter + 1;
        length = length - 1;
    }
    return (str);
}
