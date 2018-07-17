#include "simpleterm.h"

#ifndef _WIN32

#define STDIN_FILENO 1

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>

struct termios old_tio;
struct termios new_tio;

// initialize non-buffered input
// see: http://shtrom.ssji.net/skb/getc.html
void init()
{
    /* get the terminal settings for stdin */
	tcgetattr(STDIN_FILENO,&old_tio);

	/* we want to keep the old setting to restore them a the end */
	new_tio=old_tio;

	/* disable canonical mode (buffered i/o) and local echo */
	new_tio.c_lflag &=(~ICANON & ~ECHO);

	/* set the new settings immediately */
	tcsetattr(STDIN_FILENO,TCSANOW,&new_tio);
}

void deinit()
{
    /* restore the former settings */
	tcsetattr(STDIN_FILENO,TCSANOW,&old_tio);
}

void clear()
{
    // see: https://stackoverflow.com/questions/2347770/how-do-you-clear-the-console-screen-in-c#
    printf("\e[2J"); // simple version
    // printf("\033[2J\033[1;1H"); // complex version
}

void move_cursor(unsigned int x, unsigned int y)
{
	printf("\033[%d;%dH", y, x);
}

void addch(const char ch)
{
    printf("%c", ch);
}

char getch()
{
    return getchar();
}

// see: https://unix.stackexchange.com/questions/3759/how-to-stop-cursor-from-blinking
// see: https://unix.stackexchange.com/questions/220330/hide-and-unhide-cursor-with-tput
void hide_cursor()
{
    system("tput civis");
}

void show_cursor()
{
    system("tput cvvis");
}

// TODO colors
// see: http://www.linuxhowtos.org/Tips%20and%20Tricks/ansi_escape_sequences.htm

// cool ANSI codes (in python): http://www.lihaoyi.com/post/BuildyourownCommandLinewithANSIescapecodes.html

#else

// poor windows :(

// see: https://stackoverflow.com/questions/30126490/how-to-hide-console-cursor-in-c
void hide_cursor()
{
    // TODO
}

#endif

int main()
{
    // simple main file to test

    init();
    hide_cursor();
    clear();

    char input = ' ';
    while (input != 'q')
    {
        move_cursor(40, 10);
        char *text = "Hello World!";
        while (text != NULL && *text != '\0')
        {
            addch(*text);
            ++text;
        }

        if (input != ' ')
        {
            move_cursor(40, 12);
            text = "Entered : ";
            while (text != NULL && *text != '\0')
            {
                addch(*text);
                ++text;
            }
            addch(input);
        }

        move_cursor(40, 20);
        text = "Enter char: ";
        while (text != NULL && *text != '\0')
        {
            addch(*text);
            ++text;
        }

        input = getch();
    }

    show_cursor();
    move_cursor(0, 0);
    clear();
    deinit();

    return 0;
}
