#ifndef SENSE_A_H
#define SENSE_A_H

#include "sense.h"

// Specify the base here
typedef struct {
  Sense super;
  void (*incB)(void *self);

  int svC;
} SenseA;

SenseA *SenseANew(sensorType st, int a, int b, int c);

#endif
