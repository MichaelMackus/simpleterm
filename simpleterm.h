#ifndef SIMPLETERM_H
#define SIMPLETERM_H

// this initializes the screen, turning off line buffering (to enable immediate
// handling of input without hitting return key)
void init();

// this de-initializes the screen, resetting back to previous settings
void deinit();

// clear the screen
void clear();

// move cursor to x, y
void move_cursor(unsigned int x, unsigned int y);

// addch to current position
void addch(const char ch);

// get character input
char getch();

// hide mouse cursor
void hide_cursor();

// show mouse cursor
void show_cursor();

#endif
