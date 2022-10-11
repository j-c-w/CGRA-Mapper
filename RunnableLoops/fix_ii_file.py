import argparse

def generate_pairs(input_file):
    # Input file lines are groups of 8 lines
    # Read those in, get out the IIs and filenames
    # then put those into a list.
    with open(input_file) as f:
        lines = f.readlines()
        groups = []

        reduced_lines = []
        for line in lines:
            if line.startswith('II') or line.startswith('Done File:'):
                reduced_lines.append(line)
        
        i = 0
        while i < len(reduced_lines) - 1:
            if reduced_lines[i].startswith('II') and reduced_lines[i + 1].startswith('Done File:'):
                groups.append([reduced_lines[i], reduced_lines[i + 1]])
                i += 2
            else:
                print("Line ", reduced_lines[i], reduced_lines[i + 1], 'has not match')
                i += 1

    results = []
    for group in groups:
        # Get the II:
        ii = None
        filename = None
        for line in group:
            if line.startswith('II'):
                ii = int(line.strip().split(' ')[1])
            if 'Done File: ' in line:
                filename = line.strip().split(' ')[2][7:-4] # delete prefixed kernel_ and postfixed .cpp

        if filename is None or ii is None:
            print ("Group", group, "does not ahve all fields, skipping...")
        else:
            results.append((filename, ii))
    return results

if __name__ == "__main__":
    parser = argparse.ArgumentParser()

    parser.add_argument('input_file')
    parser.add_argument('output_file')
    args = parser.parse_args()

    pairs = generate_pairs(args.input_file)
    results = []
    for pair in pairs:
        results.append(str(pair[0]).strip() + ", " + str(pair[1]).strip() + '\n')
    with open(args.output_file, 'w') as f:
        f.writelines(results)

    args = parser.parse_args()