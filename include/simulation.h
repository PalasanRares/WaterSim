#ifndef _SIMULATION_H_
#define _SIMULATION_H_

#include <stdlib.h>

#include "types.h"
#include "utils.h"

using namespace std;

void simulate(byte** matrix, const int& width, const int& height);

void simulateWater(byte** matrix, const int& width, const int& height, const byte& x, const byte& y);

void simulateWood(byte** matrix, const int& width, const int& height, const byte& x, const byte& y);

void simulateSand(byte** matrix, const int& width, const int& height, const byte& x, const byte& y);

void simulateAcid(byte** matrix, const int& width, const int& height, const byte& x, const byte& y);

#endif
