#include <stdio.h>

#include "sense_a.h"
#include "sense.h"

// Normally the peripherals would be loaded from a config or XMacro, but that's beyond the scope of this example 
#define NUM_SENSE 3
Sense *sensorList[NUM_SENSE];

int main() 
{
  // Sensor inits, put sensor pointers in an array for iterated management
  sensorList[0] = SenseNew(TYPE_NONE, 9, 5);
  sensorList[1] = SenseNew(TYPE_NONE, 2, 7);
  sensorList[2] = (Sense *)SenseANew(TYPE_A, 2, 7, 25);

  for (int cycle = 0; cycle < 3; cycle++) {
    printf("=========Cycle %d=========\n", cycle);

    // Common update function names for different sensor's update functions without aliasing issues
    for (int i = 0; i < NUM_SENSE; i++) {
      sensorList[i]->update(sensorList[i]);

      // Specifying a type in the base class lets you if/switch special cases for certain objects
      if (sensorList[i]->st == TYPE_A) {
        SenseA *s = ((SenseA *)sensorList[i]);
        s->incB(s);
      }
    }

    // Sensor gets
    for (int i = 0; i < NUM_SENSE; i++) {
      printf("A: %d\tB: %d\n", sensorList[i]->getA(sensorList[i]), sensorList[i]->svB);
    }
  }

  return 0;
}
