#ifndef LCL_JS_IDASTAR_H
#define LCL_JS_IDASTAR_H

#include <vector>

template<typename NodeType,    // The type of a node in the search graph
	typename CostType,         // What the cost function returns
	typename Heuristic,        // Type of the heuristic function
	typename CostFunction,     // Type of the cost function
	typename IsGoal,           // Type of the function checking if we've reached the goal
	typename Successors>       // Type of the function that gives the successors of a node
std::pair<bool, CostType> IDAStar(const NodeType& start, 
	Heuristic heuristic, 
	CostFunction costFunction, 
	IsGoal isGoal, 
	Successors getSuccessors) {

	// More or less taken straight from Wikipedia, except we keep track of the 
	// puzzles visited in the current call stack (to avoid cycles)

	auto bound = heuristic(start);

	while (true) {
		std::vector<NodeType> history;
		history.push_back(start);
		auto result = search(start, 0, bound, history, heuristic, costFunction, isGoal, getSuccessors);

		if (!result.first && result.second < std::numeric_limits<CostType>::max()) {
			bound = result.second;
		}
		else {
			return result;
		}
	}
}

template<typename NodeType, 
	typename CostType, 
	typename Heuristic, 
	typename CostFunction, 
	typename IsGoal, 
	typename Successors>
std::pair<bool, CostType> search(const NodeType& node, 
		CostType costToGetHere, 
		CostType bound, 
		std::vector<NodeType>& history, 
		Heuristic heuristic, 
		CostFunction costFunction, 
		IsGoal isGoal, 
		Successors getSuccessors) {
	auto guesstimate = costToGetHere + heuristic(node);

	if (guesstimate > bound) {
		return std::make_pair(false, guesstimate);
	}
	
	if (isGoal(node)) {
		return std::make_pair(true, costToGetHere);
	}

	CostType newBound = std::numeric_limits<CostType>::max();
	auto successors = getSuccessors(node);

	for (auto& successor : successors) {
		
		// Avoid cycles at least in the current call stack
		if (std::find(history.rbegin(), history.rend(), successor) != history.rend()) {
			continue;
		}

		history.push_back(successor);
		auto result = search(successor, costToGetHere + costFunction(node, successor), bound, history, heuristic, costFunction, isGoal, getSuccessors);
		history.pop_back();

		if (result.first) {
			return result;
		}
		else if (result.second < newBound) {
			newBound = result.second;
		}
	}

	return std::make_pair(false, newBound);
}

#endif // LCL_JS_IDASTAR_H
