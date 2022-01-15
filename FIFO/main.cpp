#include "FIFO.h"
#include "LRU.h"
#include "OPT.h"

#include "Printer.h"

#define MEMEORY_SIZE 4

using namespace std;

vector<int> accessSequence() {
	return { 3, 1, 3, 4, 5, 6, 3, 1, 4, 6, 3, 2, 3, 6, 4, 5, 2, 6 };
}


int main() {
	auto seq = accessSequence();
	{
		FIFO fifo(seq, MEMEORY_SIZE);
		auto frames = fifo.run();
		Printer printer(fifo.getTitle(), &frames);
		printer.print();
	}
	putchar('\n');
	{
		LRU lru(seq, MEMEORY_SIZE);
		auto frames = lru.run();
		Printer printer(lru.getTitle(), &frames);
		printer.print();
	}
	putchar('\n');
	{
		OPT opt(seq, MEMEORY_SIZE);
		auto frames = opt.run();
		Printer printer(opt.getTitle(), &frames);
		printer.print();
	}
	return 0;
}


