#include "Season.hpp"

//#include "Club.hpp"


Season::Season(string seasonName, string fileClub) {

	ifstream inStreamSeason;

	inStreamSeason.open((fileClub + stringPath("/") + seasonName).c_str());

	while (!inStreamSeason.eof()) {


		Level* actualLevel = new Level(inStreamSeason, seasonName, fileClub);


		this->levels.push_back(actualLevel);
	}

	inStreamSeason.close();
}
