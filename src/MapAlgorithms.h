#ifndef MAP_ALGORITHMS_H
#define MAP_ALGORITHMS_H

#include "CGRA.h"
#include "Options.h"
#include "DFG.h"
#include <iostream>
#include <sstream>

void runMapping(CGRA *cgra, DFG *dfg, Parameters *params, Options *options);
#endif