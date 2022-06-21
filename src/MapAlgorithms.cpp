#include "CGRA.h"
#include "DFG.h"
#include "Options.h"
#include "Mapper.h"
#include "RustConversion.h"
#include "Rewriter.h"
#include "MapResult.h"

// This doesn't return anything, because it prints it out to stdout.
// But it would probably be more useful if it did.
void runMapping(Function &t_F, CGRA *cgra, DFG *dfg, Parameters *params, Options *options) {
    Mapper *mapper = new Mapper();

    // Show the count of different opcodes (IRs).
    errs() << "==================================\n";
    errs() << "[show opcode count]\n";
    dfg->showOpcodeDistribution();

    // Generate the DFG dot file.
    errs() << "==================================\n";
    errs() << "[generate dot for DFG]\n";
    dfg->generateDot(&t_F, params->isTrimmedDemo);

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
    DFG *winning_dfg;

    list<DFG *> *generated_dfgs;
    if (options->UseRewriter)
    {
        generated_dfgs = rewrite_with_graphs(cgra, dfg, options->DebugRustConversion);
    }
    else if (options->UseEGraphs)
    {
        generated_dfgs = rewrite_with_egraphs(cgra, dfg, options->DebugRustConversion);
    }
    else
    {
        // if we aren't using the rewriter, just create
        // a singleton list.
        generated_dfgs = new list<DFG *>;
        generated_dfgs->push_back(dfg);
    }

    // Create a failed mapping result as default.
    MapResult *winning_res = new MapResult(true, -1, -1);
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
            winning_dfg = dfg;
        }
        if (options->DebugMappingLoop)
        {
            cout << "DFG Number " << dfg_no << " had II " << res->II() << endl;
        }
    }
    II = winning_res->II();
    /// end jackson's code.

    // Partially exhaustive search to try to map the DFG onto
    // the static elastic CGRA.

    // Show the mapping and routing results with JSON output.
    if (winning_res->failed())
        errs() << "[Mapping:fail]\n";
    else
    {
        mapper->showSchedule(cgra, winning_dfg, winning_res, params->isStaticElasticCGRA);
        errs() << "==================================\n";
        errs() << "[Mapping:success]\n";
        errs() << "==================================\n";
        mapper->generateJSON(cgra, winning_dfg, winning_res, params->isStaticElasticCGRA);
        errs() << "[Output Json]\n";
    }
    errs() << "==================================\n";
}