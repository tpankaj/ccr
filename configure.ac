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

AC_PREREQ([2.65])
AC_INIT([Command Command Revolution], [0.1], [tushar.s.pankaj@gmail.com], [ccr], [about:blank])
AC_CONFIG_SRCDIR([src])
AC_CONFIG_HEADERS([src/config.h])
AM_INIT_AUTOMAKE([dist-xz])

AC_LANG([C++])
AC_PROG_CC
AC_PROG_CXX
AC_PROG_INSTALL
AC_PROG_LIBTOOL

BOOST_REQUIRE([1.34.1])
BOOST_THREADS
BOOST_CHRONO
BOOST_FILESYSTEM

AC_CONFIG_FILES([Makefile src/Makefile])
AC_OUTPUT
