#!/usr/bin/python3

from sys import *
from math import *

def f(x, a0, a1, a2, a3, a4):
    return (a4 * x ** 4 + a3 * x ** 3 + a2 * x ** 2 + a1 * x + a0)

def f_d(x, a1, a2, a3, a4):
    return (4 * a4 * x ** 3 + 3 * a3 * x ** 2 + 2 * a2 * x + a1)

def newton(a0, a1, a2, a3, a4, n):
    x = 0.5
    fd = f_d(x, a1, a2, a3, a4)
    format_str = "x = %." + str(n) + "f"
    print ("x =", x)

    if (fd == 0):
        fd = f(x, a0, a1, a2, a3, a4)
    while (abs(f(x, a0, a1 ,a2, a3, a4) / fd) >= 10 ** -n):
        fd = f_d(x, a1, a2, a3, a4)
        if (fd == 0):
            fd = f(x, a0, a1, a2, a3, a4)
        x = x - f(x, a0, a1 ,a2, a3, a4) / fd
        print(format_str % x)
