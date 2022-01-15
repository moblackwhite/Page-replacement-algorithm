#include "FIFO.h"

vector<RunningFrame> FIFO::run() {
	// 1. init frames
	vector<RunningFrame> _frames;
	_frames.push_back(RunningFrame(NULL_DATA, memorySize));	// Sentinel
	for (size_t i = 0; i < accessSequence.size(); i++) {
		_frames.push_back(RunningFrame(accessSequence[i], memorySize));
	}

	// Simulation run
	bool hit;
	for (size_t index = 1; index < _frames.size(); index++) {
		hit = false;

		// copy pre data and check hit
		for (size_t j = 0; j < memorySize; j++) {

			_frames[index].getData()->at(j) = _frames[index - 1].getData()->at(j);
			if (_frames[index].getData()->at(j) == _frames[index].getCurrentPage()) {
				hit = true;
			}
		}

		if (hit) {
			continue;
		}

		// No hit 
		_frames[index].setPageMissing(true);
		if (_frames[index].getData()->at(indicatingPosition) != NULL_DATA) {
			_frames[index].setPageReplaccement(true);
		}
		_frames[index].getData()->at(indicatingPosition) = _frames[index].getCurrentPage();

		// move next
		indicatingPosition = (indicatingPosition + 1) % memorySize;
	}


	vector<RunningFrame> frames(_frames.begin() + 1, _frames.end());
	return frames;
}

FIFO::FIFO(vector<int> accessSequence, int memorySize) {
	this->accessSequence = accessSequence;
	this->memorySize = memorySize;
}

std::string FIFO::getTitle() {
	return "FIFO";
}