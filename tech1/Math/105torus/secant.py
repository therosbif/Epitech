#!/usr/bin/python3

def f(x, a0, a1, a2, a3, a4):
    return (a4 * x ** 4 + a3 * x ** 3 + a2 * x ** 2 + a1 * x + a0)

def secant(a0, a1, a2, a3, a4, n):
    format_str1 = "x = %." + str(n) + "f"
    format_str2 = "x = %." + str(n) + "g"
    prev_x = 0
    x = 1
    d = f(x, a0, a1, a2, a3, a4) - f(prev_x, a0, a1, a2, a3, a4)
    if (d == 0):
        d = prev_x * f(x, a0, a1, a2, a3, a4) - x * f(prev_x, a0, a1, a2, a3, a4)
    xn = (prev_x * f(x, a0, a1, a2, a3, a4) - x * f(prev_x, a0, a1, a2, a3, a4)) / d

    while (abs(f(xn, a0, a1, a2, a3, a4)) > 10 ** -n):
        d = f(x, a0, a1, a2, a3, a4) - f(prev_x, a0, a1, a2, a3, a4)
        if (d == 0):
            d = prev_x * f(x, a0, a1, a2, a3, a4) - x * f(prev_x, a0, a1, a2, a3, a4)
        xn = (prev_x * f(x, a0, a1, a2, a3, a4) - x * f(prev_x, a0, a1, a2, a3, a4)) / d
        prev_x = x
        if (len(str(xn)) - 2 >= n):
            print(format_str1 % xn)
        else:
            print(format_str2 % xn)
        x = xn
