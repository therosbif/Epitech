/*
** EPITECH PROJECT, 2019
** sort int array
** File description:
** sorts in array
*/

void my_swap(int *a, int *b);

int is_sorted(int *array, int size)
{
    for (int i = 1; i < size; i++) {
        if (array[i -1] > array[i])
            return 0;
    }
    return 1;
}

void my_sort_int_array(int *array, int size)
{
    while (!is_sorted(array, size)) {
        for (int i = 1; i < size; i++) {
            if (array[i - 1] > array[i])
                my_swap(&(array[i - 1]), &(array[i]));
        }
    }
}
