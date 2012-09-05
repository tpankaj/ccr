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
#include <iostream>
#include <fstream>
#include <boost/lexical_cast.hpp>

#include "Level.hpp"

Level::Level(std::string inputFilePath) :
	filePath(inputFilePath)
{
	parseLevel();
}

std::string Level::getName()
{
	return name;
}

std::string Level::getDifficulty()
{
}

int Level::getTimeout()
{
	return timeout;
}

std::vector<std::string> Level::getCommandList()
{
	return commandList;
}

void Level::parseLevel()
{
	std::ifstream levelFile(filePath.c_str());

	// Get Level Name
	getline(levelFile, name);

	// Get Difficulty
	getline(levelFile, difficulty);

	// Get Timeout
	std::string timeoutStr;
	getline(levelFile, timeoutStr);
	timeout = boost::lexical_cast<int>(timeoutStr);

	// Get Command List
	std::string temp;
	while (getline(levelFile, temp))
		commandList.push_back(temp);
	if (commandList.back() == "")
		commandList.pop_back();
}
