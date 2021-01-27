/*
** EPITECH PROJECT, 2019
** sort params
** File description:
** sorts args
*/

int main(int argc, char **argv)
{
    char *c;
    char sorted = 1;

    while (sorted) {
        sorted = 0;
        for (int i = 0 ; i < argc - 1; i++) {
            if (my_strcmp(argv[i], argv[i + 1]) > 0) {
                c = argv[i];
                argv[i] = argv[i + 1];
                argv[i + 1] = c;
                sorted = 1;
            }
        }
    }
    for (int i = 0 ; i < argc ; i++) {
        my_putstr(argv[i]);
        my_putchar('\n');
    }
    return (0);
}
