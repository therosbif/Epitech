#!/usr/bin/python3

from sys import *
from math import *

def my_func(x, a0, a1, a2, a3, a4):
    return (a4 * x ** 4 + a3 * x ** 3 + a2 * x ** 2 + a1 * x + a0)

def dico(a0, a1, a2, a3, a4, n):
    a = 0
    b = 1
    m = (a + b) / 2
    format_str1 = "x = %." + str(n) + "f"
    format_str2 = "x = %." + str(n) + "g"

    while (b - a > 10 ** -n):
        m = (a + b) / 2
        if (my_func(a, a0, a1, a2, a3, a4) * my_func(m, a0, a1, a2, a3, a4) <= 0):
            b = m
        else:
            a = m
        if (len(str(m)) - 2 >= n):
            print(format_str1 % m)
        else:
            print(format_str2 % m)
