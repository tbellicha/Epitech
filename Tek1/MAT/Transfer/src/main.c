/*
** EPITECH PROJECT, 2021
** B-MAT-200-NAN-2-1-106bombyx-johan.chrillesen
** File description:
** main
*/

#include "my.h"

int check_errors(int argc, char **argv)
{
    if (argc == 1)
        return (85);
    if (argc == 2) {
        if (!my_strcmp(argv[1], "-h")) {
            my_printf("USAGE\n\t./107transfer [num den]*\n");
            my_printf("DESCRIPTION\n\tnum\tpolynomial numerator defined by its coefficients\n");
            my_printf("\tden\tpolynomial numerator defined by its coefficients\n");
            return (1);
        }
        return (85);
    }
    if (argc % 2 == 0)
        return (85);
    for (int i = 1; i < argc; i++)
        for (int j = 0; argv[i][j]; j++)
            if ((argv[i][j] != '.') && (argv[i][j] != '*') && !(argv[i][j] >= '0' && argv[i][j] <= '9') && (argv[i][j] != '-'))
                return (85);
    return (0);
}

double compute_product(char *str, double x)
{
    double result = 0.0;

    for (int i = my_strlen(str); i > -1; i--) {
        while (str[i] != '*' && i > -1)
            i--;
        result = (result * x) + atof(&str[i + 1]);
    }
    return (result);
}

void my_transfer(int argc, char **argv)
{
    double result = 0.0;
    double num = 0.0;
    double den = 0.0;

    for (double x = 0.000; x < 1.001; x += 0.001) {
        result = 1.0;
        num = 0.0;
        den = 0.0;
        for (int i = 1; i < argc; i += 2) {
            num = compute_product(argv[i], x);
            den = compute_product(argv[i + 1], x);
            if (den == 0.0)
                exit(84);
            result *= (num / den);
        }
        printf("%.3f -> %.5f\n", x, result);
    }
}

int main(int argc, char **argv)
{
    int ret = check_errors(argc, argv);
    double result = 1.0;

    if (ret)
        return (ret - 1);
    my_transfer(argc, argv);
    return (0);
}