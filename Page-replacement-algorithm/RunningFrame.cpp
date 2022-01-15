#include "RunningFrame.h"


RunningFrame::RunningFrame(int currentPage, int memorySize) {
	this->currentPage = currentPage;
	this->memorySize = memorySize;

	// init data
	data = new vector<int>();
	for (size_t index = 0; index < this->memorySize; index++) {
		data->push_back(NULL_DATA);
	}
}

int RunningFrame::getCurrentPage() {
	return currentPage;
}

vector<int>* RunningFrame::getData() {
	return data;
}

int RunningFrame::getMemorySize() {
	return memorySize;
}

bool RunningFrame::isPageMissing() {
	return pageMissing;
}
void RunningFrame::setPageMissing(bool pageMissing) {
	this->pageMissing = pageMissing;
}

bool RunningFrame::isPageReplaccement() {
	return pageReplaccement;
}

void RunningFrame::setPageReplaccement(bool pageReplaccement) {
	this->pageReplaccement = pageReplaccement;
}
