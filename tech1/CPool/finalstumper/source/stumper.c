/*
** EPITECH PROJECT, 2019
** stumper
** File description:
** final stumper
*/

#include <unistd.h>
#include "my.h"

void rush3(char *buff);

int main()
{
    char buff[6000];
    int offset = 0;
    int len = read(0, buff, 3000);

    while (len) {
        offset += len;
	len = read(0, buff + offset, 3000 - offset);
    }
    buff[offset] = '\0';
    if (len < 0)
        return (84);
    rush3(buff);
    return (0);
}
