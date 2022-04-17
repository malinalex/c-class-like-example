#ifndef SENSE_H
#define SENSE_H

// Not good for this enum to live in the base header, but not horrible
// I've previously solved this by having a system that generates unique IDs for each resource at runtime
// but that's beyond the scope of this example
typedef enum {
  TYPE_NONE,
  TYPE_A
} sensorType;

typedef struct {
  void (*update)(void *self);
  int (*getA)(void *self);
  int (*getAByB)(void *self);

  sensorType st;
  int svA;
  int svB;
} Sense;

Sense *SenseNew(sensorType st, int a, int b);

#endif
