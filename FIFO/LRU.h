#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "ReplacementAlgorithm.h"
#include "RunningFrame.h"

using namespace std;

class LRU : public ReplacementAlgorithm {
private:
	int indicatingPosition = 0;

	int memorySize;
	vector<int> accessSequence;

public:
	LRU(vector<int> accessSequence, int memorySize);

	vector<RunningFrame> run();
	string getTitle();
};