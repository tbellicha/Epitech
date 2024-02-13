/*
** EPITECH PROJECT, 2020
** B-PSU-100-NAN-1-1-myls-tanguy.bellicha
** File description:
** my_get
*/

#include "my.h"

int my_get_total_blocks(char ***ls, int lines)
{
    int res = 0;

    while (lines-- > 0)
        res += my_getnbr(ls[lines][7]);
    return (res);
}

char *get_perms(struct stat stat)
{
    char *perms = malloc(sizeof(char));
    int i = 1;

    if (S_ISDIR(stat.st_mode))
        perms[0] = 'd';
    else if (S_ISLNK(stat.st_mode))
        perms[0] = 'l';
    else
        perms[0] = '-';
    perms[i++] = stat.st_mode & S_IRUSR ? 'r' : '-';
    perms[i++] = stat.st_mode & S_IWUSR ? 'w' : '-';
    perms[i++] = stat.st_mode & S_IXUSR ? 'x' : '-';
    perms[i++] = stat.st_mode & S_IRGRP ? 'r' : '-';
    perms[i++] = stat.st_mode & S_IWGRP ? 'w' : '-';
    perms[i++] = stat.st_mode & S_IXGRP ? 'x' : '-';
    perms[i++] = stat.st_mode & S_IROTH ? 'r' : '-';
    perms[i++] = stat.st_mode & S_IWOTH ? 'w' : '-';
    perms[i++] = stat.st_mode & S_IXOTH ? 'x' : '-';
    perms[i] = 0;
    return (perms);
}

char *get_time(char *str)
{
    char *res;
    int a = 0;

    res = malloc(sizeof(char) * 19);
    while (a < 12) {
        res[a] = str[a + 4];
        a++;
    }
    res[a] = 0;
    return (res);
}