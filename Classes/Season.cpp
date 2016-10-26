#include "Season.hpp"

Season::Season(ifstream &in) {

	string tmpString;
	getline(in, tmpString);

	ifstream inStreamSeason;

	inStreamSeason.open(tmpString.c_str());

	while (!inStreamSeason.eof()) {

		Level* actualLevel = new Level(inStreamSeason);
	}
}