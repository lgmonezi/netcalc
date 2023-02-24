#ifndef NETCALC_KILO_TERMINAL_H
#define NETCALC_KILO_TERMINAL_H

#define DEVICE_STATUS_REPORT_ACTIVE_POSITION "\x1b[6n"

#include <stdbool.h>

void die(const char *s);

void enableRawMode();
void disableRawMode();
char editorReadKey();
bool getCursorPosition(int *rows, int *cols);
bool getWindowSize(int *rows, int *cols);

#endif //NETCALC_KILO_TERMINAL_H
