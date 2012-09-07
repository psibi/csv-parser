/*-------------------------------------------------------------------
# Copyright (C) 2012 Sibi <sibi@psibi.in>
#
# This file is part of csv-parser.
#
# csv-parser is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# csv-parser is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with csv-parser.  If not, see <http://www.gnu.org/licenses/>.
#
# Author:   Sibi <sibi@psibi.in>
--------------------------------------------------------------------*/
#ifndef __CSV_PARSER_H__
#define __CSV_PARSER_H__

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

class csv_parser
{
private:
  std::ifstream csv_file;
  int total_lines();

public:
  csv_parser(std::string filename);
  ~csv_parser();
  std::string get_line(int line_number);//Returns entire line as a string based on line number.
  int fields(std::string line); //Returns Number of fields in the line
  std::string get_value(int row,int column); //Returns the field in the specified row and column.
};

#endif
