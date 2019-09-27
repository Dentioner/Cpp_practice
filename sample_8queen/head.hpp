#pragma once
//*****************************************************
// eightQueue.hpp
// 包括八皇后问题的eightQueueNode类和eightQueueNodeFactory的实现
//*****************************************************
#include <iostream>
#include <stdlib.h> 
#include <time.h> 

class eightQueueNode {
public:
	int arr[8];
	eightQueueNode(int a, int b, int c, int d, int e, int f, int g, int h) {
		arr[0] = a;
		arr[1] = b;
		arr[2] = c;
		arr[3] = d;
		arr[4] = e;
		arr[5] = f;
		arr[6] = g;
		arr[7] = h;
	}
	eightQueueNode(const eightQueueNode& node) {
		arr[0] = node.arr[0];
		arr[1] = node.arr[1];
		arr[2] = node.arr[2];
		arr[3] = node.arr[3];
		arr[4] = node.arr[4];
		arr[5] = node.arr[5];
		arr[6] = node.arr[6];
		arr[7] = node.arr[7];
	}
	~eightQueueNode() {}
	bool operator==(const eightQueueNode& node) {
		return (this->arr[0] == node.arr[0]) && (this->arr[1] == node.arr[1]) && (this->arr[2] == node.arr[2])
			&& (this->arr[3] == node.arr[3]) && (this->arr[4] == node.arr[4]) && (this->arr[5] == node.arr[5])
			&& (this->arr[6] == node.arr[6]) && (this->arr[7] == node.arr[7]);
	}
};

class eightQueueNodeFactory {
private:
	int ranNum() {
		return rand() % 8;
	}

	bool isTheArrayAllTrue(bool isAllCheck[64]) {
		for (int i = 0; i < 64; i++) {
			if (isAllCheck[i] == false) {
				return false;
			}
		}
		return true;
	}

public:
	eightQueueNodeFactory() {
		srand((unsigned)time(NULL));
	}

	eightQueueNode getARandomNode() {
		return eightQueueNode(ranNum(), ranNum(), ranNum(), ranNum(), ranNum(), ranNum(), ranNum(), ranNum());
	}

	int evaluate(const eightQueueNode& node) {
		int numOfAttack = 0;
		for (int i = 0; i < 7; i++) {
			for (int j = i + 1; j < 8; j++) {
				if (node.arr[i] == node.arr[j] || (node.arr[i] - node.arr[j]) == (i - j) || (node.arr[i] - node.arr[j]) == (j - i)) {
					numOfAttack++;
				}
			}
		}
		return numOfAttack;
	}

	int getBestNextNode(eightQueueNode& node) {
		eightQueueNode ans = node;
		eightQueueNode tmp = node;
		int costOfSearch = 0;
		for (int i = 0; i < 64; i++) {
			tmp = node;
			tmp.arr[i / 8] = i % 8;
			if (evaluate(tmp) < evaluate(ans)) {
				ans = tmp;
			}
			else if (evaluate(tmp) == evaluate(ans)) {
				if (rand() / double(RAND_MAX) > 0.5) {
					ans = tmp;
				}
			}
		}
		node = ans;
		return 56;
	}

	// the input node is confirmed to be not the best
	int getNextBetterNode(eightQueueNode& node) {
		bool isAllCheck[64];
		for (int i = 0; i < 64; i++) isAllCheck[i] = false;

		eightQueueNode tmp = node;
		int costOfSearch = 1;
		while (evaluate(tmp) >= evaluate(node)) {
			// 子节点全部搜索过，都比当前差
			if (isTheArrayAllTrue(isAllCheck)) return costOfSearch;
			// 初始化，找下一邻居
			tmp = node;
			int a = rand() % 64;
			isAllCheck[a] = true;
			tmp.arr[a / 8] = a % 8;
			costOfSearch++;
			if (tmp == node) {
				continue;
			}
		}
		node = tmp;
		return costOfSearch;
	}

	int getARandomNeighbour(eightQueueNode& node) {
		eightQueueNode tmp = node;
		int cost = 0;
		while (node == tmp) {
			cost++;
			int a = rand() % 64;
			tmp.arr[a / 8] = a % 8;
		}
		node = tmp;
		return cost;
	}
};