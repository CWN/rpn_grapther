#ifndef DISPLAY_H
#define DISPLAY_H

#define DISPLAY_WIDTH 80
#define DISPLAY_HEIGHT 25
#define DISPLAY_HALF_HEIGHT 12
#define DISPLAY_CENTER_Y 13

struct display {
    int grid[DISPLAY_WIDTH][DISPLAY_HEIGHT];
};

void display_clear(struct display *display);
void display_print(struct display *display);

#endif //DISPLAY_H
