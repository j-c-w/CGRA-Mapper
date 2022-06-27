This folder contains a number of architectures of proposed domain-specific CGRAs.  These CGRAs have been repurposed from exsiting papers, and this file contains the references for those architectures.

Because OpenCGRA uses LLVM, and integrates the loop control into the CGRA, we add the following operations to each of these architectures to enable them to be used with OpenCGRA: zext (zero extend), br (branch), icmp (compare).  Some of these CGRA already have these operations.

revamp.json: From REVAMP: ASystematic Framework for Heterogeneous CGRA Realization (ASPLOS 2022), Figure 5

cca.json, maeri.json: From DSAGEN: Synthesizing Programmable
Spatial Accelerators (ISCA 2020, fig 4).  Note that these accelerators have been modified to turn them into CGRA-like accelerators: the operational specialization is kept as-is in the original work, but the interconnection network has been modified so it fits within the OpenCGRA description framework.  We also add required nodes for loop pipelining, since OpenCGRA requires an add and imcp node to iterate over each loop.