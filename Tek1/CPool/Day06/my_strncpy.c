/*
** EPITECH PROJECT, 2020
** my_strncopy
** File description:
** 
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;

    i = 0;
    while (src[i] && i < n) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = 0;
    return (dest);
}
