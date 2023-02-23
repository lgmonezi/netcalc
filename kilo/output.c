#include <unistd.h>

void editorRefreshScreen() {
    write(STDERR_FILENO, "\x1b[2J]", 4);
}
