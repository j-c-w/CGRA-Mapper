import matplotlib.pyplot as plt
import argparse
import plot_case_studies as utils

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('cca')
    parser.add_argument('maeri')
    parser.add_argument('revamp')
    parser.add_argument('sc_cgra')

    args = parser.parse_args()

    cca = utils.load_data()
    maeri = utils.load_data()
    revamp = utils.load_data()
    sc_cgra = utils.load_data()