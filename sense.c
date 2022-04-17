#include <stdio.h>
#include <stdlib.h>

#include "sense.h"

static void update(void *self)
{
  Sense *selfS = (Sense *)self;

  selfS->svA++;
}

static int getA(void *self)
{
  Sense *selfS = (Sense *)self;

  return selfS->svA;
}

static int getAByB(void *self)
{
  Sense *selfS = (Sense *)self;

  return selfS->svA*selfS->svB;
}

Sense * SenseNew(sensorType st, int a, int b)
{
  Sense *new = (Sense *)calloc(1, sizeof(Sense));
  //Sense new;

  new->update = update;
  new->getA = getA;
  new->getAByB = getAByB;
  new->st = st;
  new->svA = a;
  new->svB = b;

  return new;
}
