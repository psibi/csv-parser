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
