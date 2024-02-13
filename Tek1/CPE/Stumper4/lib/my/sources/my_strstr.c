/*
** EPITECH PROJECT, 2020
** my_strstr.c
** File description:
** search a string into a string
*/

int check_to_find(char *str1, char const *str2, int i)
{
    int j = 0;

    while (str2[j]) {
        if (str1[i] != str2[j])
            return (0);
        j++;
        i++;
    }
    return (1);
}

char *check(int i, char *str, const char *to_find)
{
    if (str[i] == to_find[0])
        if (check_to_find(str, to_find, i))
            return (str + i);
    return (str);
}

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;

    if (to_find[i] == '\0')
        return (str);
    while (str[i]) {
        return (check(i, str, to_find));
        i++;
    }
    return (0);
}
