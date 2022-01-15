#include "OPT.h"

vector<RunningFrame> OPT::run() {
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
		if (_frames[index].getData()->at(indicatingPosition) == NULL_DATA) {
			_frames[index].getData()->at(indicatingPosition) = _frames[index].getCurrentPage();
			indicatingPosition = (indicatingPosition + 1) % memorySize;
		} else {
			// set zero
			_frames[index].setPageReplaccement(true);

			// find position
			vector<int> temp(*(_frames[index].getData()));
			if (temp.size() != 1) {
				// make sure don's out of bounds
				if (index + 1 < _frames.size()) {
					for (size_t i = index + 1; i < _frames.size(); i++) {
						int currentPage = _frames[i].getCurrentPage();
						auto itr = find(temp.begin(), temp.end(), currentPage);
						if (itr != temp.end()) {
							temp.erase(itr);
							if (temp.size() == 1) {
								break;
							}
						}
					}
				}
			}
			for (indicatingPosition = 0; indicatingPosition < memorySize; indicatingPosition++) {
				if (_frames[index].getData()->at(indicatingPosition) == temp[0]) {
					break;
				}
			}
			_frames[index].getData()->at(indicatingPosition) = _frames[index].getCurrentPage();
		}
	}


	// TODO
	vector<RunningFrame> frames(_frames.begin() + 1, _frames.end());
	return frames;
}

OPT::OPT(vector<int> accessSequence, int memorySize) {
	this->accessSequence = accessSequence;
	this->memorySize = memorySize;
}

std::string OPT::getTitle() {
	return "OPT";
}