//*********************************************
// eightDigitRunner.cpp
// 包括八数码问题各算法的和简单交互界面实现
//********************************************
#include "head.h"
#include <iostream>
#include <math.h>

using namespace std;
eightDigitNodeFactory factory;

#define NUM_OF_LOOP 10000
#define NUM_OF_REBOOT 7
#define BEGIN_TEMP 500000
#define STOP_TEMP 1

void mostSteepClimbing();
void firstSeclectionClimbing();
void randomRebootClimbing();
void simulatedAnnealing();

int main() {
	int choice = 3;
	do {
		/*cout << endl;
		cout << "The Eight Digit Problem:" << endl;
		cout << "   0 -- most steep climbing" << endl;
		cout << "   1 -- first selection climbing" << endl;
		cout << "   2 -- random reboot climbing" << endl;
		cout << "   3 -- stimulated annealing" << endl;
		cout << "please input your choice: ";
		cin >> choice;
		*/

		//debug
		choice = 3;


		if (choice == -1) break;
		switch (choice) {
		case 0:
			mostSteepClimbing();
			break;
		case 1:
			firstSeclectionClimbing();
			break;
		case 2:
			randomRebootClimbing();
			break;
		case 3:
			simulatedAnnealing();
			break;
		default:
			break;
		}

		//debug
		return 0;

	} while (true);
	return 0;
}

void mostSteepClimbing() {
	int sumOfsuccess = 0, sumOfFailure = 0;
	double theSumOfCostOfSearchOfSuccess = 0, theSumLengthOfSolutionOfSuccess = 0;
	for (int i = 0; i < NUM_OF_LOOP; i++) {
		bool success = false;
		int cost = 0, lenOfRoute = 0;
		eightDigitNode curState = factory.getARandomNode();
		eightDigitNode tmp = curState;
		while (true) {
			// if satisfied, then break
			if (factory.evaluate(curState) == 0) {
				success = true;
				break;
			}

			lenOfRoute++;
			cost += factory.getBestNextNode(tmp);
			if (factory.evaluate(tmp) >= factory.evaluate(curState)) {
				break;
			}
			else {
				curState = tmp;
			}
		}

		if (success) {
			sumOfsuccess++;
			theSumOfCostOfSearchOfSuccess += cost;
			theSumLengthOfSolutionOfSuccess += lenOfRoute;
		}
		else {
			sumOfFailure++;
		}

		// output
		//cout << "case " << i << "  cost: " << cost << " " << "lengthOfSolution: " << lenOfRoute << " ";
		printf("case\t%5d\tcost:\t%2d\tlengthOfSolution:\t%2d\t", i, cost, lenOfRoute);
		if (success) {
			cout << "success ";
		}
		else {
			cout << "failure ";
		}
		cout << endl;
	}
	cout << "Sum of success: " << sumOfsuccess << endl;
	cout << "Sum of failure " << sumOfFailure << endl;
	cout << "Rate of success " << sumOfsuccess / ((double)(sumOfFailure + sumOfsuccess)) << endl;
	cout << "The average solution length of success:" << theSumLengthOfSolutionOfSuccess / NUM_OF_LOOP << endl;
	cout << "The average cost of search of success:" << theSumOfCostOfSearchOfSuccess / NUM_OF_LOOP << endl;
	return;
}

void firstSeclectionClimbing() {
	int sumOfsuccess = 0, sumOfFailure = 0;
	double theSumOfCostOfSearchOfSuccess = 0, theSumLengthOfSolutionOfSuccess = 0;
	for (int i = 0; i < NUM_OF_LOOP; i++) {
		bool success = false;
		int cost = 0, lenOfRoute = 0;
		eightDigitNode curState = factory.getARandomNode();
		eightDigitNode tmp = curState;
		while (true) {
			// if satisfied, then break
			if (factory.evaluate(curState) == 0) {
				success = true;
				break;
			}

			lenOfRoute++;
			cost += factory.getNextBetterNode(tmp);
			if (factory.evaluate(tmp) >= factory.evaluate(curState)) {
				break;
			}
			else {
				curState = tmp;
			}
		}

		if (success) {
			sumOfsuccess++;
			theSumOfCostOfSearchOfSuccess += cost;
			theSumLengthOfSolutionOfSuccess += lenOfRoute;
		}
		else {
			sumOfFailure++;
		}

		// output
		//cout << "case " << i << "  cost: " << cost << " " << "lengthOfSolution: " << lenOfRoute << " ";
		printf("case\t%5d\tcost:\t%2d\tlengthOfSolution:\t%2d\t", i, cost, lenOfRoute);
		if (success) {
			cout << "success ";
		}
		else {
			cout << "failure ";
		}
		cout << endl;
	}
	cout << "Sum of success: " << sumOfsuccess << endl;
	cout << "Sum of failure " << sumOfFailure << endl;
	cout << "Rate of success " << sumOfsuccess / ((double)(sumOfFailure + sumOfsuccess)) << endl;
	cout << "The average solution length of success:" << theSumLengthOfSolutionOfSuccess / NUM_OF_LOOP << endl;
	cout << "The average cost of search of success:" << theSumOfCostOfSearchOfSuccess / NUM_OF_LOOP << endl;
	return;
}
void randomRebootClimbing() {
	int sumOfsuccess = 0, sumOfFailure = 0;
	double theSumOfCostOfSearchOfSuccess = 0, theSumLengthOfSolutionOfSuccess = 0;
	for (int i = 0; i < NUM_OF_LOOP; i++) {
		bool success = false;
		int cost = 0, lenOfRoute = 0;
		eightDigitNode curState = factory.getARandomNode();
		eightDigitNode tmp = curState;
		while (true) {
			// if satisfied, then break
			if (factory.evaluate(curState) == 0) {
				success = true;
				break;
			}

			lenOfRoute++;
			cost += factory.getNextBetterNode(tmp);
			if (factory.evaluate(tmp) >= factory.evaluate(curState)) {
				break;
			}
			else {
				curState = tmp;
			}
		}

		if (success) {
			sumOfsuccess++;
			theSumOfCostOfSearchOfSuccess += cost;
			theSumLengthOfSolutionOfSuccess += lenOfRoute;
		}
		else {
			sumOfFailure++;
		}

		// output
		//cout << "case " << i << "  cost: " << cost << " " << "lengthOfSolution: " << lenOfRoute << " ";
		printf("case\t%5d\tcost:\t%2d\tlengthOfSolution:\t%2d\t", i, cost, lenOfRoute);
		if (success) {
			cout << "success ";
		}
		else {
			cout << "failure ";
		}
		cout << endl;
	}
	cout << "Sum of success: " << sumOfsuccess << endl;
	cout << "Sum of failure " << sumOfFailure << endl;
	cout << "Rate of success " << sumOfsuccess / ((double)(sumOfFailure + sumOfsuccess)) << endl;
	cout << "The average solution length of success:" << theSumLengthOfSolutionOfSuccess / NUM_OF_LOOP << endl;
	cout << "The average cost of search of success:" << theSumOfCostOfSearchOfSuccess / NUM_OF_LOOP << endl;
	return;
}
void simulatedAnnealing() {
	int sumOfsuccess = 0, sumOfFailure = 0;
	double theSumOfCostOfSearchOfSuccess = 0, theSumLengthOfSolutionOfSuccess = 0;
	for (int i = 0; i < NUM_OF_LOOP; i++) {
		bool success = false;
		int cost = 0, lenOfRoute = 0;
		double curTemp = BEGIN_TEMP;
		eightDigitNode curState = factory.getARandomNode();
		eightDigitNode tmp = curState;
		while (true) {
			// if satisfied, then break
			if (factory.evaluate(curState) == 0) {
				success = true;
				break;
			}
			else if (curTemp < STOP_TEMP) {
				// 温度过低，则停止
				break;
			}

			// 走一步，则温度下降
			lenOfRoute++;
			curTemp -= 1;
			cost += factory.getARandomNeighbour(tmp);
			int deltaOfEvalutaion = factory.evaluate(tmp) - factory.evaluate(curState);
			if (deltaOfEvalutaion >= 0) {
				// 根据温度差来决定是否接受
				double probility = exp(curTemp / (deltaOfEvalutaion));
				if (rand() / double(RAND_MAX) < deltaOfEvalutaion) {
					curState = tmp;
				}
			}
			else {
				curState = tmp;
			}
		}

		if (success) {
			sumOfsuccess++;
			theSumOfCostOfSearchOfSuccess += cost;
			theSumLengthOfSolutionOfSuccess += lenOfRoute;
		}
		else {
			sumOfFailure++;
		}

		// output
		//cout << "case " << i << "  cost: " << cost << " " << "lengthOfSolution: " << lenOfRoute << " ";
		printf("case\t%5d\tcost:\t%2d\tlengthOfSolution:\t%2d\t", i, cost, lenOfRoute);
		if (success) {
			cout << "success ";
		}
		else {
			cout << "failure ";
		}
		cout << endl;
	}
	cout << "Sum of success: " << sumOfsuccess << endl;
	cout << "Sum of failure " << sumOfFailure << endl;
	cout << "Rate of success " << sumOfsuccess / ((double)(sumOfFailure + sumOfsuccess)) << endl;
	cout << "The average solution length of success:" << theSumLengthOfSolutionOfSuccess / NUM_OF_LOOP << endl;
	cout << "The average cost of search of success:" << theSumOfCostOfSearchOfSuccess / NUM_OF_LOOP << endl;
	return;
}