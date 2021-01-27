/*
** EPITECH PROJECT, 2019
** print paramms
** File description:
** displays args
*/

int main(int argc, char **argv)
{
    for (int i = 0 ; i < argc ; i++) {
        my_putstr(argv[i]);
        my_putchar('\n');
    }
    return (0);
}
