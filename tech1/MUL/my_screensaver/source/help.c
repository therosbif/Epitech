/*
** EPITECH PROJECT, 2019
** CGP_my_screensaver_bootstrap_2019
** File description:
** help
*/

#include <stdio.h>
#include <stdlib.h>

void disp_usage(void)
{
    printf("animation rendering in a CSFML window.\n");
    printf("USAGE\n");
    printf("  ./my_screensaver [OPTIONS]\n");
    printf("  animation_idanimation_id    ID of the animation (1-2).\n");
    printf("OPTIONS\n");
    printf("  -d      print the description of all the animations and quit.\n");
    printf("  -h      print the usage and quit.\n");
    exit(0);
}

void description(void)
{
    printf("1 (snakes) :\n");
    printf("    3 colored snakes make their way randomly around the screen\n");
    printf("2 (shapes) :\n");
    printf("    colored polygons appear randomy on the screen\n");
    exit(0);
}