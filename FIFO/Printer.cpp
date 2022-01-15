#include "Printer.h"

using namespace std;

#define PRELEN 16

Printer::Printer(string title, vector<RunningFrame>* frames) {
	this->title = title;
	this->frames = frames;
}


void Printer::printMemorySplitLine() {
	printf("+");
	for (size_t i = 0; i < PRELEN - 2; i++) {
		putchar('-');
	}
	putchar('+');
	for (size_t i = 0; i < frames->size(); i++) {
		printf("---+");
	}
	printf("\n");
}

void Printer::printTitleSplitLine() {
	printf("+");
	for (size_t i = 0; i < PRELEN - 2; i++) {
		putchar('-');
	}
	for (size_t i = 0; i < frames->size(); i++) {
		printf("----");
	}
	putchar('+');
	printf("\n");
}

void Printer::printTitle() {
	printf("|");
	size_t totalSpace = (PRELEN - 2 + frames->size() * 4 - title.length());
	size_t space = totalSpace >> 1;
	
	for (size_t i = 0; i < space; i++) {
		putchar(' ');
	}
	
	cout << title;
	
	for (size_t i = 0; i < totalSpace - space; i++) {
		putchar(' ');
	}


	printf("|\n");
}

void Printer::printCurrentPage() {
	printf("| Current Page:");
	for (size_t index = 0; index < frames->size(); index++) {
		printf("| %d ", (*frames)[index].getCurrentPage());
	}
	cout << "|" << endl;
}

void Printer::printMemoryData() {
	// 2. memory 
	printf("| Memory Data: ");
	for (size_t j = 0; j < (*frames)[0].getMemorySize(); j++) {
		if (j != 0) {
			printf("|              ");
		}
		for (size_t index = 0; index < frames->size(); index++) {
			int d = (*frames)[index].getData()->at(j);
			if (d == NULL_DATA) {
				printf("|   ");
			} else {
				printf("| %d ", d);
			}
		}
		cout << "|" << endl;
	}
}

void Printer::printMissAndReplacemnt() {
	// 3. miss or hit
	printf("| MISS:        ");
	for (size_t index = 0; index < frames->size(); index++) {
		if (frames->at(index).isPageMissing()) {
			printf("|¡Ì ");
		} else {
			printf("|   ");
		}
	}
	cout << "|" << endl;
	printf("| REPLACEMENT: ");
	for (size_t index = 0; index < frames->size(); index++) {
		if (frames->at(index).isPageReplaccement()) {
			printf("|¡Ì ");
		} else {
			printf("|   ");
		}
	}
	cout << "|" << endl;
}

void Printer::printMissingRate() {
	size_t totalSpace = PRELEN - 2 + frames->size() * 4;

	size_t missCount = 0;
	for (auto frame : *frames) {
		if (frame.isPageMissing()) {
			missCount++;
		}
	}
	printf("| Missing Rate:| %.2lf%%", 100.0 * missCount / frames->size());
	for (size_t i = 0; i < totalSpace - 22; i++) {
		putchar(' ');
	}
	printf("|\n");
}

void Printer::print() {
	// Title
	printTitleSplitLine();
	printTitle();
	
	// Current Page
	printMemorySplitLine();
	printCurrentPage();
	
	// Memory Data
	printMemorySplitLine();
	printMemoryData();
	
	// Miss and Replacement
	printMemorySplitLine();
	printMissAndReplacemnt();

	// Miss Rate
	printMemorySplitLine();
	printMissingRate();
	printTitleSplitLine();
}
