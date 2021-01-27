/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD01-jack.goodall
** File description:
** bitmap_header
*/

#include "bitmap.h"

void make_bmp_header(bmp_header_t *header, size_t size)
{
    header->magic = 0x424D;
    #if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
        header->magic = __bswap_16(header->magic);
    #endif
    header->_app1 = 0;
    header->_app2 = 0;
    header->size = size * size * 4 + sizeof(bmp_header_t)
        + sizeof(bmp_info_header_t);
    header->offset = sizeof(bmp_header_t) + sizeof(bmp_info_header_t);
}

void make_bmp_info_header(bmp_info_header_t *header, size_t size)
{
    header->palette_size = 0;
    header->bpp = 32;
    header->compression = 0;
    header->h_resolution = 0;
    header->v_resolution = 0;
    header->size = sizeof(bmp_info_header_t);
    header->height = size;
    header->width = size;
    header->important_colors = 0;
    header->planes = 1;
    header->raw_data_size = size * size * 4;
}
