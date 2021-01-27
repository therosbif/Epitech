/*
** EPITECH PROJECT, 2019
** add sub
** File description:
** infinadd
*/

#include <stdlib.h>
#include "my.h"
#include "struct_opps.h"

int my_put_in_list(digits **list, char data);

void addup(digits **result, char *num1, char *num2)
{
    int len1 = my_strlen(num1) - 1;
    int len2 = my_strlen(num2) - 1;
    int rem = 0;

    for (char sum = 0; len1 >= 0 || len2 >= 0 ; len1--, len2--) {
        num1[len1] = (len1 < 0) ? 48 : num1[len1];
        num2[len2] = (len2 < 0) ? 48 : num2[len2];
        sum = (num1[len1] - 48) + (num2[len2] - 48) + rem;
        rem = 0;
        if (sum >= 10) {
            rem = 1;
            sum -= 10;
        }
        my_put_in_list(result, sum + 48);
    }
    if (rem)
        my_put_in_list(result, '1');
}

void my_sub(digits **result, char *num1, char *num2)
{
    int len1 = my_strlen(num1) - 1;
    int len2 = my_strlen(num2) - 1;
    int rem = 0;

    for (; len1 >= 0 || len2 >= 0 ; len1--, len2--) {
        num1[len1] = (len1 < 0) ? 48 : num1[len1];
        num2[len2] = (len2 < 0) ? 48 : num2[len2];
        num2[len2] += rem;
        rem = 0;
        if (num1[len1] < num2[len2]) {
            rem = 1;
            num1[len1] += 10;
        }
        my_put_in_list(result, num1[len1] - num2[len2] + 48);
    }
}

int subtract(digits **result, char *num1, char *num2)
{
    char *n1 = (GET_SIGN(num1) == -1) ? num1 + 1 : num1;
    char *n2 = (GET_SIGN(num2) == -1) ? num2 + 1 : num2;
    int len1;
    int len2;
    char sign = 1;

    for ( ; n1[0] == '0' ; n1++);
    for ( ; n2[0] == '0' ; n2++);
    len1 = my_strlen(n1);
    len2 = my_strlen(n2);
    if (len2 > len1 || (len1 == len2 && my_strcmp(n2, n1) > 0)) {
        if (GET_SIGN(num2) == -1)
            sign = -1;
        my_sub(result, n2, n1);
    }
    else {
        if (GET_SIGN(num1) == -1)
            sign = -1;
        my_sub(result, n1, n2);
    }
    return (sign);
}