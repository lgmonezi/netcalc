#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include "input.h"
#include "terminal.h"

bool input_read_byte(char *c) {
    return read(STDIN_FILENO, c, 1) == 1;
}

void editorProcessKeyPress() {
    char c = editorReadKey();
    switch (c) {
        case CTRL_KEY('q'):
            write(STDERR_FILENO, "\x1b[2J]", 4);
            write(STDERR_FILENO, "\x1b[H]", 3);
            exit(EXIT_SUCCESS);
    }
}