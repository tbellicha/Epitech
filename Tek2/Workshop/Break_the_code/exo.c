/*
** EPITECH PROJECT, 2022
** Break_the_code
** File description:
** exo
*/

#include <stdlib.h>
#include <stdio.h>

int main(int arcg, char* argv)
{
    char *str = strdup("B 828,R 688,R 867,R 810,R 720,R 236,R 223,R 900,G 544,G 312,G 879,B 616,B 646,B 898,R 155,R 255,G 296,G 469,Y 000,G 726,G 347,G 330,B 436,B 139,B 129,B 395,B 687,B 844,R 601,R 524,R 548,R 238,R 231,G 251,G 013,G 664,G 928,G 996,B 598,B 855,B 354,B 926,B 645,B 771,B 188,B 025,B 437,B 323,R 419,R 573,R 948,R 925,R 279,R 776,R 601,R 369,R 892,R 742,R 839,R 967,G 246,G 543,G 890,G 454,G 577,G 563,G 548,G 595,G 758,G 869,G 313,G 989,B 786,B 806,B 755,B 017,B 965,B 548,B 414,R 423,G 877,B 815,R 106,G 477,B 728,R 488,G 969,B 209,R 177,G 315,B 091,R 660,G 226,B 462,G 064,R 644,G 274,B 096,R 314,G 966,B 933,B 731,B 542,G 584,R 683,R 571,R 126,G 666,B 978,B 535,G 827,G 031,G 889,B 213,B 636,B 924,R 873,R 465,R 122,R 603,R 769,G 860,B 100,G 706,R 616,G 713,B 989,R 869,G 378,B 899,G 681,R 553,G 178,B 191,R 289,G 567,B 126,R 326,G 587,B 234,R 351,G 524,B 516,R 692,G 311,B 677,R 580,R 274,R 985,R 926,R 488,R 462,G 044,G 842,G 868,G 357,G 588,G 943,G 426,B 157,B 542,B 743,B 361,B 599,B 311,G 075,R 403,B 835,G 789,R 894,G 310,B 709,R 301,G 273,G 165,G 919,G 589,B 836,B 321,R 007,R 431,R 308,R 335,G 667,G 976,G 445,B 738,B 332,B 407,B 019,R 983,R 507,R 009,R 115,R 408,B 818,B 247,B 432,B 575,R 252,R 942");
    int colorR = 0;
    int colorG = 0;
    int colorB = 0;
    int colorY = 0;

    for (int i = 0; str[i] != '\0'; i += 6) {
        if (str[i] == 'R') {
            colorR += atoi(&str[i + 2]);
            printf("atoi : %d\n", atoi(&str[i + 2]));
        }
        if (str[i] == 'G')
            colorG += atoi(&str[i + 2]);
        if (str[i] == 'B')
            colorB += atoi(&str[i + 2]);
        if (str[i] == 'Y')
            colorY += atoi(&str[i + 2]);
    }
    printf("%d\n", colorR);
    printf("%d\n", colorG);
    printf("%d\n", colorB);
    printf("%d\n", colorY);
}