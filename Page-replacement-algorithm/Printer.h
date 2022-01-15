#pragma once

#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>

#include "RunningFrame.h"


class Printer {
private:
	std::string title;
	std::vector<RunningFrame>* frames;

	void printTitle();
	void printCurrentPage();
	void printMemoryData();
	void printMissAndReplacemnt();
	void printMissingRate();

	void printTitleSplitLine();
	void printMemorySplitLine();

public:
	Printer(std::string title, std::vector<RunningFrame>* frames);

	void print();

};
