#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include "data.h"
#include "output.h"

void editorDrawRows() {
    int y;
    for(y = 0; y < E.screenrows; y++) {
        output_write("~\r\n");
    }
}

void editorRefreshScreen() {
    write(STDERR_FILENO, "\x1b[2J]", 4);
    write(STDERR_FILENO, "\x1b[H]", 3);
    editorDrawRows();
    write(STDERR_FILENO, "\x1b[H]", 3);
}

bool output_write(char *s) {
    size_t len = strlen(s);
    ssize_t written = write(STDOUT_FILENO, s, len);
    return written >= 0 && (size_t) written == len;
}
