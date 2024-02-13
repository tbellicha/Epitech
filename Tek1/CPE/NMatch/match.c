
/*
** EPITECH PROJECT, 2020
** match
** File description:
** 
*/



int match(char const *s1, char const *s2)
{
    int i = 0;
    int k = 0;
    
    while (s1[i] != 0) {
        while (s1[i] != s2[k]) {
            while (s2[k] == '*')
                k++;
            i++;
        }
        if (s1[i] != s2[k] && s2[k] != '*')
            return (0);
        while (s1[i] == s2[k]) {
            i++;
            k++;
        }
    }
    return (1);
}
