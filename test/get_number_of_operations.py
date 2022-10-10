import argparse

# Compute the number of distinct operations available on an accelerator.
# There are various things that might be in this set that we don't
# consider as accelerator operations becuase they are llvm-specific
# and so are outside the scope of this work.
# (this list is the same one duplicated elsewhere in this project)
free_ops = [
    'ret', 'fptosi', 'bitcast', 'store', 'phi',
    'load', 'extractelement', 'getelementptr', 'insertelement',
    'sitofp', 'Constant', 'trunc'
]
def include(i):
    if i in free_ops:
        return False
    elif i.startswith('const'):
        return False
    return True

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("available_ops", help="contains the contents of the 'Available ops' line in the stdout")

    args = parser.parse_args()
    ops = args.available_ops.split(' ')[3:]
    count = 0
    for op in ops:
        op = op.replace('{', '')
        op = op.replace('}', '')
        op = op.replace(',', '')
        op = op.replace('"', '')
        if include(op):
            count += 1
    print (count)