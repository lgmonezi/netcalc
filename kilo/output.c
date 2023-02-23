#include <unistd.h>
#include "data.h"

void editorDrawRows() {
    int y;
    for(y = 0; y < E.screenrows; y++) {
        write(STDOUT_FILENO, "~\r\n", 3);
    }
}

void editorRefreshScreen() {
    write(STDERR_FILENO, "\x1b[2J]", 4);
    write(STDERR_FILENO, "\x1b[H]", 3);
    editorDrawRows();
    write(STDERR_FILENO, "\x1b[H]", 3);
}