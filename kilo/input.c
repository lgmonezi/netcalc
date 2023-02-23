#include <stdlib.h>
#include "input.h"
#include "terminal.h"

void editorProcessKeyPress() {
    char c = editorReadKey();
    switch (c) {
        case CTRL_KEY('q'):
            exit(EXIT_SUCCESS);
    }
}