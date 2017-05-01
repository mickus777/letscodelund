#ifndef JS_MARKOV_H_
#define JS_MARKOV_H_

#include <array>
#include <vector>
#include <map>

namespace markov {

// A state data type (a sequence of symbols)
template<typename SymbolType, int order>
using state = std::array<SymbolType, order>;


// A table of probabilities from states to the following symbol
template<typename SymbolType, int order>
class probability_table {
public:
	using state = state<SymbolType, order>;
	using probabilities = std::vector<std::pair<SymbolType, double>>;

	void add_state(const state& s, const probabilities& p) {
		table[s] = p;
	}

	// From a state, generate a random following symbol
	SymbolType generate_symbol(const state& s) const {
		auto itr = table.find(s);

		if (itr == table.end()) {
			return SymbolType();
		}

		double chance = rand() / (double)RAND_MAX;

		auto& probabilities = (*itr).second;
		double sum = 0.0;
		int i = 0;
		while (chance > sum + probabilities[i].second) {
			sum += probabilities[i++].second;
		}
		return probabilities[i].first;
	}

private:

	std::map<state, probabilities> table;
};

// Goes through a sequence of symbols and generates a probability table
template<typename SymbolType, typename InputIterator, int order>
void train(InputIterator begin, InputIterator end, probability_table<SymbolType, order>& result) {

	// A 'sample' is a state followed by a symbol
	using sample = std::array<SymbolType, order + 1>;
	using state = state<SymbolType, order>;

	// Collect all samples into an array
	std::vector<sample> all_samples;

	sample current_sample;

	if (std::distance(begin, end) < order + 1) {
		return;
	}

	for (int i = 0; i < order + 1; ++i) {
		current_sample[i] = *begin++;
	}
	all_samples.push_back(current_sample);

	while (begin != end) {
		for (int i = 0; i < order; ++i) {
			current_sample[i] = current_sample[i + 1];
		}
		current_sample[order] = *begin++;
		all_samples.push_back(current_sample);
	}

	// Sort the samples
	std::sort(all_samples.begin(), all_samples.end());

	// Help function to get the state fom a sample
	auto state_from_sample = [](const sample& s) -> state {
		state result;
		for (int i = 0; i < order; ++i) {
			result[i] = s[i];
		}
		return result;
	};

	// Go through all the sorted samples, and calculate probabilities
	// for each state.
	auto itr = all_samples.begin();

	while (itr != all_samples.end()) {
		sample first_sample = *itr;
		state current_state = state_from_sample(first_sample);

		std::map<SymbolType, int> transition_count;
		int total_count = 0;

		while (itr != all_samples.end() && state_from_sample(*itr) == current_state) {

			SymbolType symbol = (*itr)[order];
			++transition_count[symbol];
			++total_count;

			++itr;
		}

		probability_table<SymbolType, order>::probabilities probabilities;

		for (auto jtr = transition_count.begin(); jtr != transition_count.end(); ++jtr) {
			double probability = (*jtr).second / (double)total_count;
			probabilities.push_back(std::make_pair((*jtr).first, probability));
		}

		result.add_state(current_state, probabilities);
	}
}

}

#endif // JS_MARKOV_H_