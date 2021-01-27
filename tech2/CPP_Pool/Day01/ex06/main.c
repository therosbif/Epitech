/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD01-jack.goodall
** File description:
** main
*/

#include "menger.h"
#include "drawing.h"
#include "bitmap.h"

void initialize_image(size_t size, unsigned int *buffer, unsigned int **img)
{
    memset(buffer, 0, size * size * sizeof(*buffer));
    for (size_t i = 0; i < size; i++)
        img[i] = buffer + i * size;
}

void create_image(size_t size,
    unsigned int *buffer, unsigned int **img, const int level)
{
    initialize_image(size , buffer , img);
    menger(size, level, 0, 0, img);
}

void create_bitmap_from_buffer(const char *name,
    size_t size, unsigned int *buffer)
{
    int fd = open(strcat(strdup(name), ".bmp"),
        O_CREAT | O_TRUNC | O_WRONLY, 0644);

    write_bmp_header(fd, size);
    write_bmp_info_header(fd, size);
    write(fd, buffer, size * size * sizeof(*buffer));
    close(fd);
}

int main(int argc, char const *argv[])
{
    if (error_check(argc, argv))
        return 84;
    menger_face(argv[1], atoi(argv[2]), atoi(argv[3]));
    return 0;
}
