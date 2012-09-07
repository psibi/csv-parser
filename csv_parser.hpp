#include <iostream>
#include <fstream>

class csv_parser
{
private:
  ifstream csv_file;
  
public:
  csv_parser(string filename);
  string get_line(int line_number);
};

  
