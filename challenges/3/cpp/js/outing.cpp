#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

//  Used as markers during search for components
const int NO_COMPONENT = -1;
const int PENDING_COMPONENT = 0;

class Person {
public:
	Person(int buddy)
		: buddy_(buddy), component_(NO_COMPONENT) {}

	int getComponent() const {
		return component_;
	}

	void setComponent(int component) {
		component_ = component;
	}

	int getBuddy() const {
		return buddy_;
	}

private:
	int buddy_;
	int component_;
};

// Does a depth first search to give nodes their components
// If the search finds nodes that already have an assigned component, we will
// let that one propagate, otherwise we will use the suggestedComponent.
bool dfsComponent(vector<Person>& people, int index, int suggestedComponent) {
	auto& currentPerson = people[index];

	if (currentPerson.getComponent() == PENDING_COMPONENT) { // cycle detected, start assigning
		currentPerson.setComponent(suggestedComponent);
		return true;
	}
	else if (currentPerson.getComponent() == NO_COMPONENT) { // unvisited, set as pending and continue the search
		currentPerson.setComponent(PENDING_COMPONENT);
		
		auto result = dfsComponent(people, currentPerson.getBuddy(), suggestedComponent);
		people[index].setComponent(people[currentPerson.getBuddy()].getComponent());
		return result;
	}
	else { // already marked by an earlier search, don't change
		return false;
	}
}

// Finds the components in the graph of people
// Returns number of components
int componentize(vector<Person>& people) {

	auto nextComponent = 1;

	for (auto i = 0u; i < people.size(); ++i) {
		if (dfsComponent(people, i, nextComponent)) {
			++nextComponent;
		}
	}

	return nextComponent - 1;
}

// Calculates the number of people in a component's cycle
int measureCycleLength(const vector<Person>& people, int startIndex) {
	vector<int> markers(people.size(), -1);
	auto next = 0;
	auto current = startIndex;

	while (markers[current] == -1) {
		markers[current] = next++;
		current = people[current].getBuddy();
	}

	return next - markers[current];
}

// Knapsack algorithm with memoization.
//
// componentIndex     the next component to make a choice for
// components         a vector of (size, cycle length)-pairs
// cache              previously computed results (-1 means not yet calculated)
int knapsack(int componentIndex, int numberOfSeatsLeft, const vector<pair<int, int>>& components, vector<vector<int>>& cache) {
	auto& cachedValue = cache[componentIndex][numberOfSeatsLeft];
	if (cachedValue != -1) {
		return cachedValue;
	}

	auto currentComponent = components[componentIndex];
	auto componentSize = currentComponent.first;
	auto componentMinimum = currentComponent.second;

	if (componentIndex == components.size() - 1) {
		if (numberOfSeatsLeft >= componentMinimum) {
			cachedValue = min(numberOfSeatsLeft, componentSize);
		}
		else {
			cachedValue = 0;
		}
	}
	else {
		auto best = knapsack(componentIndex + 1, numberOfSeatsLeft, components, cache);
		if (numberOfSeatsLeft >= componentMinimum) {
			for (int i = componentMinimum; i <= min(numberOfSeatsLeft, componentSize); ++i) {
				auto candidate = i + knapsack(componentIndex + 1, numberOfSeatsLeft - i, components, cache);
				if (candidate > best) {
					best = candidate;
				}
			}
		}
		cachedValue = best;
	}

	return cachedValue;
}

int calculateOuting(int numberOfSeats, const vector<pair<int, int>>& components) {
	// Initialize cache
	vector<vector<int>> cache(components.size() + 1, vector<int>(numberOfSeats + 1, -1));

	return knapsack(0, numberOfSeats, components, cache);
}

int main(void) {

	auto numberOfPeople = 0;
	auto numberOfSeats = 0;

	cin >> numberOfPeople >> numberOfSeats;

	vector<Person> people;

	for (auto i = 0; i < numberOfPeople; ++i) {
		auto buddy = 0;
		cin >> buddy;
		people.emplace_back(buddy - 1);
	}

	auto numberOfComponents = componentize(people);

	cout << "Number of components: " << numberOfComponents << endl;

	map<int, int> cycleLengths;
	map<int, int> componentSizes;

	for (auto i = 0; i < numberOfPeople; ++i) {
		auto& person = people[i];
		auto component = person.getComponent();

		componentSizes[component]++;

		if (cycleLengths.find(component) == cycleLengths.end()) {
			cycleLengths[component] = measureCycleLength(people, i);
		}
	}

	vector<pair<int, int>> components;

	for (auto itr = cycleLengths.begin(); itr != cycleLengths.end(); ++itr) {
		auto component = itr->first;
		components.emplace_back(componentSizes[component], cycleLengths[component]);
	}

	cout << "Number of people that can go on the outing: " << calculateOuting(numberOfSeats, components) << endl;
	return EXIT_SUCCESS;
}
