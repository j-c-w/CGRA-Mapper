#include "CGRA.h"
#include "DFG.h"
#include "Options.h"
#include "Mapper.h"
#include "RustConversion.h"
#include "Rewriter.h"
#include "MapResult.h"

MapResult *doMap(Options *options, Parameters *params, CGRA *cgra, Mapper *mapper, list<DFG *> *generated_dfgs, int II) {
    MapResult *winning_res = new MapResult(true, -1, -1, nullptr);
    int dfg_no = 0;
    for (DFG *dfg : *generated_dfgs)
    {
        if (options->DebugMappingLoop)
        {
            cout << "Starting mapper for new DFG (Number " << ++dfg_no << ")" << endl;
            cout << "DFG is : " << dfg->asString() << endl;
        }
        // Rejoin the edges if they were split --- note
        // that this is currently just wasted computation
        // time if we didn't use egraphs.
        // anyway, suspect it's negligable.
        dfg->rejoinCycles();

        MapResult *res = mapper->heuristicMap(cgra, dfg, II, params->isStaticElasticCGRA, options->PrintMappingFailures);

        if ((winning_res->failed() || (res->II() < winning_res->II())) && !res->failed())
        {
            delete winning_res;
            winning_res = res;
        }
        if (options->DebugMappingLoop)
        {
            cout << "DFG Number " << dfg_no << " had II " << res->II() << endl;
        }
    }

    return winning_res;
}

// This doesn't return anything, because it prints it out to stdout.
// But it would probably be more useful if it did.
void runMapping(CGRA *cgra, DFG *dfg, Parameters *params, Options *options) {
    Mapper *mapper = new Mapper();

    // Show the count of different opcodes (IRs).
    errs() << "==================================\n";
    errs() << "[show opcode count]\n";
    dfg->showOpcodeDistribution();

    // Generate the DFG dot file.
    errs() << "==================================\n";
    errs() << "[generate JSON for DFG]\n";
    dfg->generateJSON();

    // Initialize the II.
    int ResMII = mapper->getResMII(dfg, cgra);
    errs() << "==================================\n";
    errs() << "[ResMII: " << ResMII << "]\n";
    int RecMII = mapper->getRecMII(dfg);
    errs() << "==================================\n";
    errs() << "[RecMII: " << RecMII << "]\n";
    int II = ResMII;
    if (II < RecMII)
        II = RecMII;

    if (!params->doCGRAMapping)
    {
        errs() << "==================================\n";
        return;
    }
    // Heuristic algorithm (hill climbing) to get a valid mapping within
    // a acceptable II.
    // Jackson's Code Starts Here:
    // Get the winning DFG.
    MapResult *mapResult;
    cout << "Options settings are " << options->UseRewriter << "\n";

    list<DFG *> *generated_dfgs;
    if (options->UseGreedy)
    {
        cout << "Using Greedy Only Mode\n";
        generated_dfgs = rewrite_with_graphs(options, cgra, dfg);

        mapResult = doMap(options, params, cgra, mapper, generated_dfgs, II);
    }
    else if (options->UseEGraphs)
    {
        cout << "Using EGraphs Only Mode\n";
        generated_dfgs = rewrite_with_egraphs(options, cgra, dfg);
        mapResult = doMap(options, params, cgra, mapper, generated_dfgs, II);
    }
    else if (options->UseRewriter)
    {
        cout << "Using FlexC Rewriter Mode\n";
        // call the copy constructor
        DFG copied_dfg(*dfg); // need to copy before this changes the DFG.
        // Try the normal rewriter first.
        generated_dfgs = rewrite_with_graphs(options, cgra, dfg);
        mapResult = doMap(options, params, cgra, mapper, generated_dfgs, II);

        if (mapResult->failed()) {
            cout << "Falling back to EGraphs\n";
            // try again with egraphs.
            generated_dfgs = rewrite_with_egraphs(options, cgra, &copied_dfg);
            mapResult = doMap(options, params, cgra, mapper, generated_dfgs, II);
        } else {
            cout << "Initial Greedy Pass Succeeded\n";
        }
    }
    else
    {
        // if we aren't using the rewriter, just create
        // a singleton list.
        generated_dfgs = new list<DFG *>;
        generated_dfgs->push_back(dfg);
        mapResult = doMap(options, params, cgra, mapper, generated_dfgs, II);
    }

    // Create a failed mapping result as default.

    // Partially exhaustive search to try to map the DFG onto
    // the static elastic CGRA.

    // Show the mapping and routing results with JSON output.
    if (mapResult->failed())
        errs() << "[Mapping:fail]\n";
    else
    {
        mapper->showSchedule(cgra, mapResult->winningDFG(), mapResult, params->isStaticElasticCGRA);
        errs() << "==================================\n";
        errs() << "[Mapping:success]\n";
        errs() << "==================================\n";
        mapper->generateJSON(cgra, mapResult->winningDFG(), mapResult, params->isStaticElasticCGRA);
        errs() << "[Output Json]\n";
    }
    errs() << "==================================\n";
    errs() << "Done File: " << dfg->getSourceFileName() << "\n";

}