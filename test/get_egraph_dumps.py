import argparse
import json

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    # single file argument
    parser.add_argument("number", help="which index to parse")
    args = parser.parse_args()

    with open(args.number + ".stdout_filtered") as f:
        lines = f.readlines()
        passed = False
        orig = None
        targ = None

        for line in lines:
            if "Placed extracted files " in line:
                orig = line.split(' ')[4].strip()
                targ = line.split(' ')[6].strip()

            if "Mapping:success" in line:
                passed = True

    if passed:
        output = {}
        output['original'] = orig
        output['target'] = targ
        output['architecture_c_file'] = args.number + '.file1'
        output['compile_c_flie'] = args.number + '.file2'

        print("Passed")

        with open(args.number + ".output.json", 'w') as f:
            # write outptu into output.json
            json.dump(output, f)
    else:
        print("Did not pass")
