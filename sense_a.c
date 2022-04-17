#include <stdio.h>
#include <stdlib.h>

#include "sense_a.h"

static void update(void *self)
{
  SenseA *selfS = (SenseA *)self;

  selfS->super.svA--;
}

static void incB(void *self)
{
  SenseA *selfS = (SenseA *)self;

  selfS->super.svB++;
}

/* These functions can also be written this way, just decide which is clearer and be consistent
static void update(void *self)
{
  Sense *selfS = (Sense *)self;

  selfS->svA--;
}

static void incB(void *self)
{
  Sense *selfS = (Sense *)self;

  selfS->svB++;
}*/

SenseA *SenseANew(sensorType st, int a, int b, int c)
{
  SenseA *new = (SenseA *)calloc(1, sizeof(SenseA));

  // Create base
  new->super = *SenseNew(st, a, b);
  // Override a base fxn
  new->super.update = update;

  new->incB = incB;
  new->svC = c;

  return new;
}
