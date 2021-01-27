/*
** EPITECH PROJECT, 2019
** print comb 2
** File description:
** diff combs of 2 dig numbs
*/

void print_num2(char a, char b, char c, char d)
{
    my_putchar(a);
    my_putchar(b);
    my_putchar(' ');
    my_putchar(c);
    my_putchar(d);
}

void test(char a, char b, char c, char d)
{
    if (a < c || (a == c && b < d)){
        my_putchar(',');
        my_putchar(' ');
        print_num2(a, b, c, d);
    }
}

void cycle(char *a, char *b)
{
    if (*a > '9'){
        *b = *b + 1;
        *a = '0';
    }
}

int my_print_comb2(void)
{
    char a = 48;
    char b = 48;
    char c = 48;
    char d = 50;

    print_num2(48, 48, 48, 49);
    while (a != '9' || b != '9') {
        test(a, b, c, d);
        d++;
        cycle(&d, &c);
        cycle(&c, &b);
        cycle(&b, &a);
    }
    return (0);
}
