#include <cstdlib>
#include <array>
#include <iostream>
#include <string>
#include <sstream>
#include <utility>
#include <algorithm>
#include <vector>
#include "idastar.h"
#include "astar.h"

// This program solves 4x4 puzzles
const auto SIDE_SIZE = 4;
const auto NUM_TILES = SIDE_SIZE * SIDE_SIZE;

using Tile = short;
const Tile EMPTY_TILE = 15;

struct Position {
	int x;
	int y;
};

int manhattanDistance(const Position& position1, const Position& position2) {
	return std::abs(position1.x - position2.x) + std::abs(position1.y - position2.y);
}

// Where is this tile supposed to be?
Position goalFor(Tile tile) {
	return{ tile % SIDE_SIZE, tile / SIDE_SIZE };
}

// What's the minimum cost (manhattan distance) to move this tile
// from its current position to its intended position?
int minCostForTile(Tile tile, Position currentPosition) {
	auto destination = goalFor(tile);
	return manhattanDistance(currentPosition, destination);
}

class Puzzle {
public:
	Puzzle(std::array<Tile, NUM_TILES> tiles) : tiles_(tiles) {}

	bool operator==(const Puzzle& other) const {
		return tiles_ == other.tiles_;
	}

	bool operator<(const Puzzle& other) const {
		return tiles_ < other.tiles_;
	}

	Tile getTile(int x, int y) const {
		return getTile({ x, y });
	}

	Tile getTile(Position pos) const {
		return tiles_[toIndex(pos)];
	}

	// Is this puzzle already solved?
	bool solved() const {
		return std::is_sorted(tiles_.begin(), tiles_.end());
	}

	// Get the configurations which can be reached in one step
	std::vector<Puzzle> neighbours() const {
		auto indexOfEmpty = std::distance(tiles_.begin(), 
			std::find(tiles_.begin(), tiles_.end(), EMPTY_TILE));

		auto positionOfEmpty = goalFor(indexOfEmpty);

		std::vector<Puzzle> result;

		// Can we move the empty space upwards?
		if (positionOfEmpty.y > 0) {
			auto moveUp = tiles_;
			std::swap(moveUp[indexOfEmpty], moveUp[toIndex({positionOfEmpty.x, positionOfEmpty.y - 1})]);
			result.push_back(Puzzle(moveUp));
		}

		// Can we move the empty space down?
		if (positionOfEmpty.y < SIDE_SIZE - 1) {
			auto moveDown = tiles_;
			std::swap(moveDown[indexOfEmpty], moveDown[toIndex({ positionOfEmpty.x, positionOfEmpty.y + 1 })]);
			result.push_back(Puzzle(moveDown));
		}

		// Can we move the empty space left?
		if (positionOfEmpty.x > 0) {
			auto moveLeft = tiles_;
			std::swap(moveLeft[indexOfEmpty], moveLeft[toIndex({ positionOfEmpty.x - 1, positionOfEmpty.y })]);
			result.push_back(Puzzle(moveLeft));
		}

		// Can we move the empty space left?
		if (positionOfEmpty.x < SIDE_SIZE - 1) {
			auto moveRight = tiles_;
			std::swap(moveRight[indexOfEmpty], moveRight[toIndex({ positionOfEmpty.x + 1, positionOfEmpty.y })]);
			result.push_back(Puzzle(moveRight));
		}
		return result;
	}

private:
	static int toIndex(Position pos) {
		return pos.y * SIDE_SIZE + pos.x;
	}

	std::array<Tile, NUM_TILES> tiles_;
};

// Manhattan distance heuristic
int manhattanSum(const Puzzle& puzzle) {
	auto sum = 0;

	for (auto y = 0; y < SIDE_SIZE; ++y) {
		for (auto x = 0; x < SIDE_SIZE; ++x) {
			auto tile = puzzle.getTile(x, y);

			if (tile != EMPTY_TILE) {
				sum += minCostForTile(tile, { x, y });
			}
		}
	}

	return sum;
}

int linearConflicts(const Puzzle& puzzle) {
	auto sum = 0;

	// Find horizontal conflicts
	for (auto y = 0; y < SIDE_SIZE; ++y) {
		for (auto x1 = 0; x1 < SIDE_SIZE - 1; ++x1) {
			auto x1Tile = puzzle.getTile(x1, y);

			if (x1Tile == EMPTY_TILE) continue;

			auto x1Goal = goalFor(x1Tile);

			if (x1Goal.y != y) continue;

			for (auto x2 = x1 + 1; x2 < SIDE_SIZE; ++x2) {
				auto x2Tile = puzzle.getTile(x2, y);

				if (x2Tile == EMPTY_TILE) continue;

				auto x2Goal = goalFor(x2Tile);

				if (x2Goal.y != y) continue;

				if (x2Goal.x < x1Goal.x) {
					sum += 2;
					break;
				}
			}
		}
	}

	// Find vertical conflicts
	for (auto x = 0; x < SIDE_SIZE; ++x) {
		for (auto y1 = 0; y1 < SIDE_SIZE - 1; ++y1) {
			auto y1Tile = puzzle.getTile(x, y1);

			if (y1Tile == EMPTY_TILE) continue;

			auto y1Goal = goalFor(y1Tile);

			if (y1Goal.y != x) continue;

			for (auto y2 = y1 + 1; y2 < SIDE_SIZE; ++y2) {
				auto y2Tile = puzzle.getTile(x, y2);

				if (y2Tile == EMPTY_TILE) continue;

				auto y2Goal = goalFor(y2Tile);

				if (y2Goal.y != x) continue;

				if (y2Goal.y < y1Goal.y) {
					sum += 2;
					break;
				}
			}
		}
	}

	return sum;
}

int heuristic(const Puzzle& puzzle) {
	return manhattanSum(puzzle) + linearConflicts(puzzle);
}

// For the 15 puzzle, any move costs the same
int costFunction(const Puzzle& puzzle1, const Puzzle& puzzle2) {
	return 1;
}

bool isGoal(const Puzzle& puzzle) {
	return puzzle.solved();
}

std::vector<Puzzle> successors(const Puzzle& puzzle) {
	return puzzle.neighbours();
}

template<typename T>
T lexical_cast(const std::string& str) {
	std::istringstream is(str);
	T value;
	is >> value;
	return value;
}

int main() {
	std::array<Tile, NUM_TILES> input;

	for (auto i = 0; i < NUM_TILES; ++i) {
		std::string tileString;
		std::cin >> tileString;

		const auto tile = tileString == "x" ? EMPTY_TILE : lexical_cast<Tile>(tileString) - 1;

		input[i] = tile;
	}

	Puzzle start(input);

	std::cout << IDAStar<Puzzle, int>(start, heuristic, costFunction, isGoal, successors).second << std::endl;

	return EXIT_SUCCESS;
}	
