/*
** EPITECH PROJECT, 2020
** B-CPE-101-NAN-1-1-evalexpr-tanguy.bellicha
** File description:
** postfix
*/

#include "my.h"
#include <stdlib.h>
#define is_num(x) (x >= '0' && x <= '9')? 1 : 0
#define is_sum(s) (s == '+' || s == '-')? 1 : 0
#define is_fact(f) (f == '*' || f == '/' || f == '%')? 1 : 0

typedef struct postfix_struct
{
    int type;
    int num;
    char operator;
} pf_struct;

int calcul_result(pf_struct *postfix)
{
    int ix = 0;
    int ir = -1;
    int a = 0;
    int b = 0;
    int *res = (int *)malloc(sizeof(int) * 128);

    while (postfix[ix].type != -1) {
        if (postfix[ix].type == 1) {
            switch (postfix[ix].operator) {
                case '+':
                    a = res[ir--];
                    b = res[ir--];
                    res[++ir] = b + a;
                    break;
                case '-':
                    a = res[ir--];
                    b = res[ir--];
                    res[++ir] = b - a;
                    break;
                case '*':
                    a = res[ir--];
                    b = res[ir--];
                    res[++ir] = b * a;
                    break;
                case '/':
                    a = res[ir--];
                    b = res[ir--];
                    res[++ir] = b / a;
                    break;
                case '%':
                    a = res[ir--];
                    b = res[ir--];
                    res[++ir] = b % a;
                    break;
            }
        } else
            res[++ir] = postfix[ix].num;
        ++ix;
    }
    return (res[ir]);
}

pf_struct *infix_to_postfix(char *ptr_s)
{
    int i = 0;
    int ip = -1;
    int io = -1;
    pf_struct *post = malloc(sizeof(pf_struct) * 128);
    char *oper = malloc(sizeof(char *) * 128);

    while (ptr_s[i]) {
        if (is_num(ptr_s[i])) {
            post[++ip].num = my_getnbr(&ptr_s[i]);
            post[ip].type = 0;
            while (is_num(ptr_s[i + 1]))
                i++;
        }
        if (is_sum(ptr_s[i])) {
            while (io > -1 && (is_sum(oper[io]) || is_fact(oper[io]))) {
                post[++ip].operator = oper[io--];
                post[ip].type = 1;
            }
            oper[++io] = ptr_s[i];
        }
        if (is_fact(ptr_s[i])) {
            while (io > -1 && is_fact(oper[io])) {
                post[++ip].operator = oper[io--];
                post[ip].type = 1;
            }
            oper[++io] = ptr_s[i];
        }
        if (ptr_s[i] == '(')
            oper[++io] = ptr_s[i];
        if (ptr_s[i] == ')') {
            while (io > -1 && oper[io] != '(') {
                post[++ip].operator = oper[io--];
                post[ip].type = 1;
            }
            io--;
        }
        i++;
    }
    while (io > -1) {
        post[++ip].operator = oper[io--];
        post[ip].type = 1;
    }
    post[++ip].type = -1;
    return (post);
}

int eval_expr(char const *str)
{
    char *p;

    p = (char *)malloc(sizeof(char) * my_strlen(str));
    my_strcpy(p, str);
    return (calcul_result(infix_to_postfix(p)));
}

int main(int ac, char **av)
{
    if (ac == 2) {
        my_put_nbr(eval_expr(av[1]));
        my_putchar('\n');
        return (0);
    }
    return (84);
}
