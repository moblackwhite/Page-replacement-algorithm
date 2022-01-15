#pragma once
#include <string>
#include <vector>

#include "RunningFrame.h"

using namespace std;

class ReplacementAlgorithm {
public:
	virtual string getTitle() = 0;
	virtual vector<RunningFrame> run() = 0;
};

