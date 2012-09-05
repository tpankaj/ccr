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

#ifndef Game_hpp
#define Game_hpp

#include <vector>
#include <string>

#include "Level.hpp"
#include "LevelManager.hpp"

class Game
{
public:
	Game(std::string dataDir);
	void start();

private:
	void listLevels(std::vector<std::string> argv);
	void listLevels(std::string difficultyStr, int difficulty);
	void playLevel(std::vector<std::string> argv);
	void runLevel(int difficulty, int level);
	void commandNotFound(std::vector<std::string> argv);
	std::vector<std::string> explode(std::string input);
	std::string dataDir;
	LevelManager levelManager;
};

#endif /* Game_hpp */
