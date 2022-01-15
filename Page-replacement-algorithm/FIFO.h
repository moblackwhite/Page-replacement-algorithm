#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "ReplacementAlgorithm.h"
#include "RunningFrame.h"

using namespace std;

class FIFO : public ReplacementAlgorithm {
private:
	int indicatingPosition = 0;

	vector<int> accessSequence;
	int memorySize;
public:
	FIFO(vector<int> accessSequence, int memorySize);

	vector<RunningFrame> run();
	string getTitle();
};