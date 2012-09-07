#ifndef __CSV_PARSER_H__
#define __CSV_PARSER_H__

#include <iostream>
#include <fstream>

using namespace std;

class csv_parser
{
private:
  ifstream csv_file;
  
public:
  csv_parser(string filename);
  string get_line(int line_number);
};

#endif
