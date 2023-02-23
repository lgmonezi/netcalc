#ifndef NETCALC_KILO_DATA_H
#define NETCALC_KILO_DATA_H

#include <termios.h>

typedef struct {
    int screenrows;
    int screencols;
    struct termios orig_termios;
} EditorConfig;

extern EditorConfig E;

#endif //NETCALC_KILO_DATA_H