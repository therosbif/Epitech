/*
** EPITECH PROJECT, 2019
** tree
** File description:
** fir tree
*/

// width = size*8-1
// first star size*4-1 spaces b4

void tree(int size)
{
    int mid = middle(size) + size / 2 + size % 2;
    int last = 0;
    int li = 1;

    for (int level = 0 ; level < size ; level++) {
        last = leaves(mid, li, level);
        li = last - level / 2 * 2 - 2;
    }
    trunk(size, mid);
}

int middle(int size)
{
    int j = 0;
    int li = 1;

    for (int level = 0 ; level < size ; level++) {
        li = j - level / 2 * 2 - 2;
        for (int row = 0 ; row < level + 4 ; row++) {
            j = 0;
            for (j ; j < li + row * 2 ; j++) {}
        }
    }
    return (j / 2);
}

void trunk(int size, int mid)
{
    for (int k = 0 ; k < size ; k++) {
        for (int spaces = 0 ; spaces < mid - size / 2  ; spaces++)
            my_putchar(' ');
        for (int pipes = 0 ; pipes < 1 + size / 2 * 2 ; pipes++)
            my_putchar('|');
        my_putchar('\n');
    }
}

int leaves(int mid, int li, int level)
{
    int j;

    for (int row = 0 ; row < level + 4 ; row++) {
        j = 0;
        for (int i = 0 ; i < mid - li / 2 - row ; i++)
            my_putchar(' ');
        for (j ; j < li + row * 2 ; j++)
            my_putchar('*');
        my_putchar('\n');
    }
    return (j);
}
