#include "input.h"
#include "output.h"
#include "terminal.h"

int main(void) {
    enableRawMode();
    for(;;) {
        editorRefreshScreen();
        editorProcessKeyPress();
    }
}