// Generates text based on an input file and Markov chains.

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "markov.h"

// Number of characters in a state
const int ORDER = 10;

int main(int argc, char** argv) {

	// Read input from text file specified by argv[1]
	std::string input;
	char ch;

	std::ifstream ifs(argv[1]);
	
	while (ifs.get(ch)) {
		input += ch;
	}

	// Markov chain training
	markov::probability_table<char, ORDER> probability_table;
	markov::train(input.begin(), input.end(), probability_table);

	// Get the start state from argv[2]
	markov::state<char, ORDER> start_state;

	for (int i = 0; i < ORDER; ++i) {
		start_state[i] = argv[2][i];
	}

	// Write a bunch of new states to the file pointed to by argv[3]
	std::ofstream ofs(argv[3]);

	markov::state<char, ORDER> current_state = start_state;

	for (int i = 0; i < 1024; ++i) {
		char next_ch = probability_table.generate_symbol(current_state);

		if (next_ch == char()) {
			break;
		}

		// Go to the next state
		for (int i = 0; i < ORDER-1; ++i) {
			current_state[i] = current_state[i + 1];
		}
		current_state[ORDER - 1] = next_ch;

		ofs << next_ch;
	}

	return EXIT_SUCCESS;
}