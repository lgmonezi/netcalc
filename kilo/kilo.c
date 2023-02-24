#include "data.h"
#include "input.h"
#include "output.h"
#include "terminal.h"

void initEditor() {
    if(getWindowSize(&E.screenrows, &E.screencols)) {
        die("getWindowSize");
    }
}

int main(void) {
    enableRawMode();
    initEditor();
    for(;;) {
        editorRefreshScreen();
        editorProcessKeyPress();
    }
}