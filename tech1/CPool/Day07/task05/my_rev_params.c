/*
** EPITECH PROJECT, 2019
** rev params
** File description:
** reverse order of parrams
*/

int main(int argc, char **argv)
{
    for (argc-- ; argc >= 0 ; argc--) {
        my_putstr(argv[argc]);
        my_putchar('\n');
    }
    return (0);
}
