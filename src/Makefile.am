#    This file is part of Command Command Revolution.
#
#    Command Command Revolution is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    Command Command Revolution is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with Command Command Revolution.  If not, see <http://www.gnu.org/licenses/>.

bin_PROGRAMS = ccr
ccr_SOURCES = \
Game.cpp \
Game.hpp \
Level.cpp \
Level.hpp \
LevelManager.cpp \
LevelManager.hpp \
main.cpp
ccr_CXXFLAGS = $(AM_CXXFLAGS) -std=gnu++0x
ccr_CPPFLAGS = $(AM_CPPFLAGS) $(BOOST_CPPFLAGS) -DDATADIR=\"'../data'\"
#ccr_CPPFLAGS = $(AM_CPPFLAGS) $(BOOST_CPPFLAGS) -DDATADIR=\"'$(pkgdatadir)'\"
ccr_LDFLAGS = $(LDFLAGS) $(BOOST_CHRONO_LDFLAGS) $(BOOST_FILESYSTEM_LDFLAGS) $(BOOST_THREAD_LDFLAGS)
ccr_LDADD = $(LDADD) $(BOOST_CHRONO_LIBS) $(BOOST_FILESYSTEM_LIBS) $(BOOST_THREAD_LIBS)
