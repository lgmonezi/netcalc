#ifndef NETCALC_KILO_TERMINAL_H
#define NETCALC_KILO_TERMINAL_H

void die(const char *s);

void enableRawMode();

void disableRawMode();

char editorReadKey();

int getWindowSize(int *rows, int *cols);


#endif //NETCALC_KILO_TERMINAL_H