// This loads a DFG from the DFG Json format used in compiler gym.
// It tries to schedule that DFG to the parameters here.
#include <string>
#include <iostream>
#include <algorithm>
#include "Options.h"
#include "MapAlgorithms.h"

int main(int argc, char **argv) {
    TClapOptions *topts = setupOptionsTClap(argc, argv);
    Options *opts = topts->options;
    Parameters *params = new Parameters(opts->Params);

    DFG *dfg = new DFG(topts->dfg_file);
    CGRA *cgra = params->getCGRA(opts);

    cout << "Running mapping for DFG " << dfg->asString() << "\n";

    runMapping(cgra, dfg, params, opts);
}