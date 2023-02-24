#include <ctype.h>
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "data.h"
#include "input.h"
#include "output.h"
#include "terminal.h"

void die(const char *s) {
    write(STDERR_FILENO, "\x1b[2J]", 4);
    write(STDERR_FILENO, "\x1b[H]", 3);
    perror(s);
    exit(EXIT_FAILURE);
}

void enableRawMode() {
    if(tcgetattr(STDIN_FILENO, &E.orig_termios) == -1) {
        die("tcgetattr");
    }

    atexit(disableRawMode);

    struct termios raw = E.orig_termios;
    raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | IXON);
    raw.c_oflag &= ~(OPOST);
    raw.c_cflag |= (CS8);
    raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
    raw.c_cc[VMIN] = 0;
    raw.c_cc[VTIME] = 1;

    if(tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1) {
        die("tcsetattr");
    }
}

void disableRawMode() {
    if(tcsetattr(STDIN_FILENO, TCSAFLUSH, &E.orig_termios) == -1) {
        die("tcsetattr");
    }
}

char editorReadKey() {
    int nread;
    char c;
    while((nread = read(STDIN_FILENO, &c, 1)) != 1) {
        if(nread == -1 && errno != EAGAIN) {
            die("read");
        }
    }
    return c;
}

bool getCursorPosition(int *rows, int *cols) {
    char buf[32];
    unsigned int i = 0;
    if(!output_write(DEVICE_STATUS_REPORT_ACTIVE_POSITION)) {
        return false;
    }
    for(; i < sizeof(buf) - 1; i++) {
        if(!input_read_byte(&buf[i]) || buf[i] == 'R') {
            break;
        }
    }
    buf[i] = '\0';
    if(buf[0] != '\x1b' || buf[1] != '[') {
        return false;
    }
    return sscanf(&buf[2], "%d;%d", rows, cols) == 2;
}

bool getWindowSize(int *rows, int *cols) {
    struct winsize ws;
    if(1 || ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1 || ws.ws_col == 0) {
        if(!output_write("\x1b[999C\x1b[999B")) {
            return false;
        }
        return getCursorPosition(rows, cols);
    }
    *cols = ws.ws_col;
    *rows = ws.ws_row;
    return true;
}

