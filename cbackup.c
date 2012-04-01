/*
 * Crimson Backup
 * Copyright (C) 2012 Matt Harris
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "cb.h"
#include <signal.h>

unsigned short ntermsigs;
static void sh_hup(int s);
static void sh_term(int s);

int main(int argc, char **argv)
{
	ntermsigs = 0;
	signal(SIGHUP, sh_hup);
	signal(SIGTERM, sh_term);
	signal(SIGINT, sh_term);
	signal(SIGTSTP, SIG_IGN);

	return(0);
}

void sh_hup(int s)
{

}

void sh_term(int s)
{
	ntermsigs++;
	if (ntermsigs >= 3)
	{
		exit(4);
	}
}
