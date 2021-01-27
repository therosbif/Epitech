/*
** EPITECH PROJECT, 2019
** sort int array
** File description:
** sorts in array
*/

void my_sort_int_array(int *array, int size)
{
    int c;
    char sorted = 1;

    while (sorted) {
        sorted = 0;
        for (int i = 0 ; i < size - 1; i++) {
            if (array[i] > array[i + 1]) {
                c = array[i];
                array[i] = array[i + 1];
                array[i + 1] = c;
                sorted = 1;
            }
        }
    }
}
