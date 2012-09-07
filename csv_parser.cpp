#include "csv_parser.hpp"

csv_parser::csv_parser(string filename)
  {
    csv_file.open(filename.c_str());
    if (!csv_file.is_open())
        perror(("Error while opening file " + filename).c_str());
  }
  
string csv_parser::get_line(int line_number)
  {
    string line;
    for (int i=0;i<line_number;i++)
      {
	getline(csv_file,line);
      }
    if (csv_file.bad())
      perror("Error while Reading");
    return line;
  }

int main()
{
  csv_parser demo("freak");
  string a = demo.get_line(3);
  cout<<a<<"\n";
}

