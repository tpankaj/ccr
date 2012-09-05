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
#include <boost/thread/thread.hpp>
#include <boost/chrono.hpp>
#include <boost/lexical_cast.hpp>

#include "Game.hpp"
#include "Level.hpp"
#include "LevelManager.hpp"

Game::Game(std::string inputDataDir) :
	dataDir(inputDataDir),
	levelManager(inputDataDir)
{

}

void Game::start()
{
	for (;;) {
		// Get Command
		std::cout << "ccr> ";
		std::string commandStr;
		getline(std::cin, commandStr);
		if (std::cin.eof()) {
			std::cout <<"exit" << std::endl;
			break;
		}
		std::vector<std::string> command = explode(commandStr);

		// Parse Command
		if (command.empty())
			continue;
		else if (command.at(0) == "ls") {
			listLevels(command);
		}
		else if (command.at(0) == "play") {
			playLevel(command);
		}
		else if (command.at(0) == "exit" || command.at(0) == "quit")
			break;
		else
			commandNotFound(command);
	}
}

void Game::listLevels(std::vector<std::string> argv)
{
	if (argv.size() == 1) {
		listLevels("Easy", 0);
		listLevels("Medium", 1);
		listLevels("Hard", 2);
		listLevels("Extreme", 3);
	} else {
		for (unsigned i = 1; i < argv.size(); ++i) {
			if (argv.at(i) == "easy")
				listLevels("Easy", 0);
			else if (argv.at(i) == "medium")
				listLevels("Medium", 1);
			else if (argv.at(i) == "hard")
				listLevels("Hard", 2);
			else if (argv.at(i) == "extreme")
				listLevels("Extreme", 3);
			else
				std::cout << "ls: cannot access " + argv.at(i) + ": No such difficulty" << std::endl;
		}
	}
}

void Game::listLevels(std::string difficultyStr, int difficulty)
{
	std::cout << difficultyStr << " Levels:" << std::endl;
	for (unsigned i = 0; i < levelManager.getLevelList().at(difficulty).size(); ++i)
		std::cout << "    " << i << ") " << levelManager.getLevelList().at(difficulty).at(i).at(0) << std::endl;;
}

void Game::playLevel(std::vector<std::string> argv)
{
	int difficulty;
	int levelNum;

	if (argv.size() != 3) {
		std::cout << "play: invalid arguments" << std::endl;
		return;
	}

	if (argv.at(1) == "easy") {
		difficulty = 0;
	} else if (argv.at(1) == "medium") {
		difficulty = 1;
	} else if (argv.at(1) == "hard") {
		difficulty = 2;
	} else if (argv.at(1) == "extreme") {
		difficulty = 3;
	} else {
		std::cout << "play: " << difficulty << ": No such difficulty" << std::endl;
		return;
	}

	try {
		levelNum = boost::lexical_cast<int>(argv.at(2));
	}
	catch (...) {
		std::cout << "play: invalid arguments" << std::endl;
		return;
	}

	if (levelNum >= levelManager.getLevelList().at(difficulty).size()) {
		std::cout << "play: " << levelNum << ": No such level" << std::endl;
		return;
	}

	runLevel(difficulty, levelNum);
}

void Game::runLevel(int difficulty, int levelNum)
{
	Level level =  levelManager.getLevel(difficulty, levelNum);
	std::cout << level.getName();
	switch (difficulty) {
	case 0:
		std::cout << " Easy";
		break;
	case 1:
		std::cout << " Medium";
		break;
	case 2:
		std::cout << " Hard";
		break;
	case 3:
		std::cout << " Extreme";
		break;
	}
	std::cout <<std::endl;

	std::cout << "Type each command within " << (double)level.getTimeout() / 1000.0 << " second";
	if (level.getTimeout() > 1000)
		std::cout << "s";
	std::cout <<":" << std::endl;
	boost::this_thread::sleep(boost::posix_time::milliseconds(1000));
	std::cout << "3..." << std::endl;
	boost::this_thread::sleep(boost::posix_time::milliseconds(1000));
	std::cout << "2..." << std::endl;
	boost::this_thread::sleep(boost::posix_time::milliseconds(1000));
	std::cout << "1..." << std::endl;
	boost::this_thread::sleep(boost::posix_time::milliseconds(1000));
	std::cout <<"GO!" << std::endl;

	int score = 0;

	for (unsigned i = 0; i < level.getCommandList().size(); ++i) {
		std::cout << level.getCommandList().at(i) << std::endl;
		std::string input;
		boost::chrono::system_clock::time_point startTime = boost::chrono::system_clock::now();
		getline(std::cin, input);
		boost::chrono::duration<double> typeTime = boost::chrono::system_clock::now() - startTime;
		if (boost::chrono::duration_cast<boost::chrono::milliseconds>(typeTime).count() <= level.getTimeout() && level.getCommandList().at(i) == input)
			score += 50 * level.getCommandList().at(i).size();
	}

	std::cout << "Score: " << score << std::endl;
}

void Game::commandNotFound(std::vector<std::string> argv)
{
	std::cout <<"ccr: " << argv.at(0) << ": command not found" <<std::endl;
}

std::vector<std::string> Game::explode(std::string input)
{
	std::vector<std::string> explodedInput;
	std::string inputSubStr = "";

	for (unsigned i = 0; i < input.size(); ++i) {
		if (input.at(i) == ' ') {
			explodedInput.push_back(inputSubStr);
			inputSubStr = "";
		} else if (i == input.size() -1) {
			inputSubStr += input.at(i);
			explodedInput.push_back(inputSubStr);
			inputSubStr = "";
		} else {
			inputSubStr += input.at(i);
		}
	}

	return explodedInput;
}
