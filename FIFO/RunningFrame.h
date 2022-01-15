#pragma once
#include <vector>

#define NULL_DATA -1

using namespace std;

class RunningFrame {
private:
	int currentPage;
	int memorySize;
	vector<int>* data;
	bool pageMissing = false;
	bool pageReplaccement = false;

public:
	
	RunningFrame(int currentPage, int memorySize);
	
	int getCurrentPage();

	int getMemorySize();
	
	vector<int>* getData();

	bool isPageMissing();
	void setPageMissing(bool pageMissing);

	bool isPageReplaccement();
	void setPageReplaccement(bool pageReplaccement);

};