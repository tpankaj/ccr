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

#ifndef LevelManager_hpp
#define LevelManager_hpp

#include <vector>
#include <string>

#include "Level.hpp"

class LevelManager
{
public:
	LevelManager(std::string dataDir);
	std::vector<std::vector<std::vector<std::string> > > getLevelList();
	Level getLevel(int difficulty, int level);

private:
	void populateLevelList();
	void addLevel(std::string filePath);
	std::string dataDir;
	std::vector<std::vector<std::vector<std::string> > > levelList;
};

#endif /* LevelManager_hpp */
