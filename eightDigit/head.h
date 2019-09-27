#pragma once
//***************************************************************
// eightDigit.hpp
// 包括八数码问题的eightDigitNode类和eightDigitFactory类的实现
// **************************************************************
#include <iostream>
#include <stdlib.h> 
#include <time.h> 
#include <math.h>

#define LOOP_OF_SHUFFLE 50

class eightDigitNode {
public:
	int arr[9];
	int blank_x = 2, blank_y = 2;
	eightDigitNode() {
		for (int i = 0; i < 8; i++) { arr[i] = i + 1; }
		arr[8] = 0;
	}
	~eightDigitNode() {}
	eightDigitNode(const eightDigitNode& node) {
		arr[0] = node.arr[0];
		arr[1] = node.arr[1];
		arr[2] = node.arr[2];
		arr[3] = node.arr[3];
		arr[4] = node.arr[4];
		arr[5] = node.arr[5];
		arr[6] = node.arr[6];
		arr[7] = node.arr[7];
		arr[8] = node.arr[8];
		blank_x = node.blank_x;
		blank_y = node.blank_y;
	}
	bool operator==(const eightDigitNode& node) {
		for (int i = 0; i < 8; i++) {
			if (arr[i] != node.arr[i]) return false;
		}
		return true;
	}

	bool goLeft() {
		if (blank_y == 0) {
			return false;
		}
		else {
			arr[blank_x * 3 + blank_y] = arr[blank_x * 3 + blank_y - 1];
			arr[blank_x * 3 + blank_y - 1] = 0;
			blank_y--;
			return true;
		}
	}

	bool goRight() {
		if (blank_y == 2) {
			return false;
		}
		else {
			arr[blank_x * 3 + blank_y] = arr[blank_x * 3 + blank_y + 1];
			arr[blank_x * 3 + blank_y + 1] = 0;
			blank_y++;
			return true;
		}
	}

	bool goUp() {
		if (blank_x == 0) {
			return false;
		}
		else {
			arr[blank_x * 3 + blank_y] = arr[(blank_x - 1) * 3 + blank_y];
			arr[(blank_x - 1) * 3 + blank_y] = 0;
			blank_x--;
			return true;
		}
	}

	bool goDown() {
		if (blank_x == 2) {
			return false;
		}
		else {
			arr[blank_x * 3 + blank_y] = arr[(blank_x + 1) * 3 + blank_y];
			arr[(blank_x + 1) * 3 + blank_y] = 0;
			blank_x++;
			return true;
		}
	}
};

class eightDigitNodeFactory {
private:
	int getManhattanDistian(const int& src, const int& target) {
		return abs(src % 3 - target % 3) + abs(src / 3 - target / 3);
	}
	int getNumOfWrongNumber(const eightDigitNode& node) {
		int res = 0;
		for (int i = 0; i < 8; i++) {
			if (node.arr[i] != i + 1) res++;
		}
		if (node.arr[8] != 0) res++;
		return res;
	}
	bool getANeighbourNode(int direction, eightDigitNode& node) {
		switch (direction) {
		case 0: return node.goLeft();
		case 1: return node.goUp();
		case 2: return node.goRight();
		default:
			return node.goDown();
		}
	}

	bool isTheArrayAllTrue(bool isAllCheck[4]) {
		for (int i = 0; i < 4; i++) {
			if (isAllCheck[i] == false) {
				return false;
			}
		}
		return true;
	}

public:
	eightDigitNodeFactory() {
		srand((unsigned)time(NULL));
	}

	eightDigitNode getARandomNode() {
		eightDigitNode output;
		int timesOfShuffle = rand() % LOOP_OF_SHUFFLE;
		while (timesOfShuffle--) {
			while (!getANeighbourNode(rand() % 4, output));
		}
		return output;
	}

	int evaluate(const eightDigitNode& node) {
		eightDigitNode tmp;
		int distanceToTargetState = 0;
		for (int i = 0; i < 9; i++) {
			int j = 0;
			while (tmp.arr[j] != node.arr[i]) { j++; }
			distanceToTargetState += getManhattanDistian(i, j);
		}
		return distanceToTargetState + 3 * getNumOfWrongNumber(node);
	}

	int getBestNextNode(eightDigitNode& node) {
		eightDigitNode tmp = node, ans = node;
		for (int i = 0; i < 4; i++) {
			tmp = node;
			if (getANeighbourNode(i, tmp) && evaluate(tmp) < evaluate(ans)) {
				ans = tmp;
			}
			else if (evaluate(tmp) == evaluate(ans)) {
				if (rand() / double(RAND_MAX) > 0.5) {
					ans = tmp;
				}
			}
		}
		node = ans;
		return 4;
	}

	int getNextBetterNode(eightDigitNode& node) {
		bool isAllCheck[4];
		for (int i = 0; i < 4; i++) { isAllCheck[i] = false; }

		eightDigitNode tmp = node;
		int costOfSearch = 1;
		while (evaluate(tmp) >= evaluate(node)) {
			// 子节点全部搜索过，都比当前差
			if (isTheArrayAllTrue(isAllCheck)) return costOfSearch;
			// 初始化，找下一邻居
			tmp = node;
			int a = rand() % 4;
			isAllCheck[a] = true;
			getANeighbourNode(a, tmp);
			costOfSearch++;
			if (tmp == node) {
				continue;
			}
		}
		node = tmp;
		return costOfSearch;
	}

	int getARandomNeighbour(eightDigitNode& node) {
		int costOfSearch = 0;
		eightDigitNode tmp = node;
		while (!getANeighbourNode(rand() % 4, tmp)) {
			costOfSearch++;
			tmp = node;
		}
		node = tmp;
		return costOfSearch;
	}
};