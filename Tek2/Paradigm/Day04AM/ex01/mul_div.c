/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD04am-tanguy.bellicha
** File description:
** mul_div
*/

void mul_div_long(int a, int b, int *mul, int *div)
{
    *mul = a * b;
    if (b == 0)
        *div = 42;
    else
        *div = a / b;
}

void mul_div_short(int *a, int *b)
{
    int a2 = *a;
    int b2 = *b;

    *a = (a2 * b2);
    if (b2 == 0)
        *b = 42;
    else
        *b = a2 / b2;
}
