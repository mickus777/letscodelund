#ifndef LCL_JS_ASTAR_H
#define LCL_JS_ASTAR_H

#include <queue>
#include <functional>
#include <map>

template<typename NodeType,    // The type of a node in the search graph
	typename CostType,         // What the cost function returns
	typename Heuristic,        // Type of the heuristic function
	typename CostFunction,     // Type of the cost function
	typename IsGoal,           // Type of the function checking if we've reached the goal
	typename Successors>       // Type of the function that gives the successors of a node
std::pair<bool, CostType> AStar(const NodeType& start,
	Heuristic heuristic,
	CostFunction costFunction,
	IsGoal isGoal,
	Successors getSuccessors) {

	std::map<NodeType, CostType> bestCosts;

	using QueueEntry = std::pair<CostType, NodeType>;
	std::priority_queue<QueueEntry, std::vector<QueueEntry>, std::greater<QueueEntry>> Q;

	Q.emplace(heuristic(start), start);

	while (!Q.empty()) {
		QueueEntry next = Q.top();
		Q.pop();

		auto currentNode = next.second;
		auto currentCost = next.first;

		if (isGoal(currentNode)) {
			return std::make_pair(true, currentCost);
		}

		auto itr = bestCosts.find(currentNode);
		if (itr != bestCosts.end() && itr->second <= currentCost) {
			continue;
		}
		else {
			bestCosts[currentNode] = currentCost;
		}

		auto successors = getSuccessors(currentNode);

		auto costToGetToCurrent = currentCost - heuristic(currentNode);
		for (auto& successor : successors) {
			auto successorCost = costToGetToCurrent + costFunction(currentNode, successor) + heuristic(successor);
			Q.push(std::make_pair(successorCost, successor));
		}
	}

	return std::make_pair(false, std::numeric_limits<CostType>::max());
}

#endif // LCL_JS_ASTAR_H
