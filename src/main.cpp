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

#include "config.h"

#include <cstdlib>
#include <string>
#include <iostream>

#include "Level.hpp"

int main(int argc, char* argv[])
{
	Level level(std::string(DATADIR) + std::string("/shell_slave-the_servitude_easy.level"));

	return EXIT_SUCCESS;
}
