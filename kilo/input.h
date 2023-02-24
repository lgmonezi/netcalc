#ifndef NETCALC_KILO_INPUT_H
#define NETCALC_KILO_INPUT_H

#define CTRL_KEY(k) ((k) & 0x1F)

#include <stdbool.h>

bool input_read_byte(char *c);

void editorProcessKeyPress();

#endif //NETCALC_KILO_INPUT_H
