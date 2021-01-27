/*
** EPITECH PROJECT, 2019
** print comb
** File description:
** combination of 3 different numbers 
*/

void print_num(char a, char b, char c)
{
    my_putchar(a);
    my_putchar(b);
    my_putchar(c);
}

void testvalid(char a, char b, char c)
{
    if (a < b && b < c){
        my_putchar(',');
        my_putchar(' ');
        print_num(a, b, c);
    }
}
    
int my_print_comb(void)
{
    char a = 48;
    char b = 49;
    char c = 51;

    print_num(a, b, 50);
    while (a < '8') {
        testvalid(a, b, c);
        if (c == '9'){
            b++;
            c = '0';
        }
        if (b == '9'){
            a++;
            b = '0';
        }
        c++;
    }
    return (0);
}
