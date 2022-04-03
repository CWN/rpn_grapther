#include <stdio.h>
#include "display.h"

void display_clear(struct display *display) {
    for (int j = 0; j < DISPLAY_HEIGHT; j++) {
        for (int i = 0; i < DISPLAY_WIDTH; i++) {
            (*display).grid[i][j] = 0;
        }
    }
}

void display_print(struct display *display) {
    for (int j = 0; j < DISPLAY_HEIGHT; j++) {
        for (int i = 0; i < DISPLAY_WIDTH; i++) {
            if ((*display).grid[i][j] == 1) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}