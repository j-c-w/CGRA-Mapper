cat param.json <<EOF
{
  "kernel"              : "_Z6kernelPiS_S_",
  "targetFunction"      : false,
  "targetNested"        : true,
  "targetLoopsID"       : [0, 1],
  "doCGRAMapping"       : true,
  "row"                 : 4,
  "column"              : 4,
  "precisionAware"      : true,
  "heterogeneity"       : true,
  "isTrimmedDemo"       : true,
  "heuristicMapping"    : true,
  "bypassConstraint"    : 4,
  "isStaticElasticCGRA" : false,
  "ctrlMemConstraint"   : 200,
  "regConstraint"       : 8,
  "optLatency"          : {
                            "store": 2
                          },
  "optPipelined"        : ["store"],
  "additionalFunc"      : {
                            "store": [4]
                          },

  "operations":
{
"0": {
"0": ["load", "store"],
"1": ["add", "sub"],
"2": ["icmp"],
"3": ["and", "or", "nor", "xor", "lsh", "lshr", "ashr"],
"4": ["add", "sub"],
"5": ["load", "store"]
},
"1": {
"0": ["load", "store"],
"1": ["add", "sub"],
"2": ["mul"],
"3": ["add", "sub", "icmp"],
"4": ["add", "sub"],
"5": ["load", "store"]
},
"2": {
"0": ["load", "store"],
"1": ["add", "sub", "icmp"],
"2": ["add", "sub", "icmp", "and", "or", "nor", "xor", "lsh", "lshr", "ashr", "mul"],
"3": ["add", "sub", "icmp", "and", "or", "nor", "xor", "lsh", "lshr", "ashr", "mul"],
"4": ["mul"],
"5": ["load", "store"]
},
"3": {
"0": ["load", "store"],
"1": ["mul"],
"2": ["add", "sub", "icmp", "and", "or", "nor", "xor", "lsh", "lshr", "ashr", "mul"],
"3": ["add", "sub", "icmp", "and", "or", "nor", "xor", "lsh", "lshr", "ashr", "mul"],
"4": ["add", "sub", "and", "or", "nor", "xor", "lsh", "lshr", "ashr"],
"5": ["load", "store"]
},
"4": {
"0": ["load", "store"],
"1": ["add"],
"2": ["add", "sub", "and", "or", "nor", "xor", "lsh", "lshr", "ashr"],
"3": ["mul"],
"4": ["add", "sub"],
"5": ["load", "store"]
},
"5": {
"0": ["load", "store"],
"1": ["add"],
"2": ["and", "or", "nor", "xor", "lsh", "lshr", "ashr"],
"3": ["icmp"],
"4": ["add", "sub"],
"5": ["load", "store"]
}
}
}
EOF

cat kernel.cpp <<EOF
// Source is: /home/alex/.local/share/compy-Learn/1.0/libav/content/libavcodec/apedec.c

#include <stdint.h>
#include <stdio.h>


int
fn (int cf, int symbol, uint16_t * counts)
{
	for (int i = 0; i < cf; i ++) {
		counts[i] = counts[i] + 10;
	}
}
EOF

./compile.sh kernel.cpp
./run.sh ../build/src/libmapperPass.so kernel.bc --use-egraphs --params-file param.json
