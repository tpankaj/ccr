/*
 *    This file is part of Command Command Revolution.
 *
 *    Command Command Revolution is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    Command Command Revolution is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with Command Command Revolution.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <boost/filesystem.hpp>

#include "Level.hpp"
#include "LevelManager.hpp"

LevelManager::LevelManager(std::string inputDataDir) :
	dataDir(inputDataDir),
	levelList(4)
{
	populateLevelList();
}

std::vector<std::vector<std::vector<std::string> > > LevelManager::getLevelList()
{
	return levelList;
}

Level LevelManager::getLevel(int difficulty, int level)
{
	return Level(levelList.at(difficulty).at(level).at(1));
}

void LevelManager::populateLevelList()
{
	// Get Directory List
	boost::filesystem::path levelDir(dataDir);
	std::vector<boost::filesystem::path> dirList;
	boost::filesystem::directory_iterator endIterator;
	for (boost::filesystem::directory_iterator dirIterator(levelDir); dirIterator != endIterator; ++dirIterator)
		dirList.push_back(*dirIterator);
	std::sort(dirList.begin(), dirList.end());

	for (unsigned i = 0; i < dirList.size(); ++i) {
		if (dirList.at(i).extension().string() == ".level") {
			addLevel(dirList.at(i).stem().string());
		}
	}
}

void LevelManager::addLevel(std::string fileName)
{
	std::ifstream levelFile(std::string(dataDir + "/" + fileName + ".level").c_str());
	std::vector<std::string> level;
	std::string name;
	std::string difficulty;

	getline(levelFile, name);
	getline(levelFile, difficulty);

	level.push_back(name);
	level.push_back(dataDir + "/" + fileName + ".level");

	if (difficulty == "easy")
		levelList.at(0).push_back(level);
	else if (difficulty == "medium")
		levelList.at(1).push_back(level);
	else if (difficulty == "hard")
		levelList.at(2).push_back(level);
	else if (difficulty == "extreme")
		levelList.at(3).push_back(level);
}
