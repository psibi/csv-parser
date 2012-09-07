#ifndef __CSV_PARSER_H__
#define __CSV_PARSER_H__

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

class csv_parser
{
private:
  ifstream csv_file;
  
public:
  csv_parser(string filename);
  string get_line(int line_number);
  int fields(string line); //Returns Number of fields in the line
  string get_value(int row,int column); //Returns the field in the specified row and column.
  int total_lines();
};

#endif
