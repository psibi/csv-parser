#include "csv_parser.hpp"

csv_parser::csv_parser(string filename)
  {
    csv_file.open(filename.c_str());
    if (!csv_file.is_open())
        perror(("Error while opening file " + filename).c_str());
  }
  
string csv_parser::get_line(int line_number)
  {
    csv_file.clear(); //Clear State
    csv_file.seekg(0,ios::beg);
    string line;
    for (int i=0;i<line_number;i++)
      {
	getline(csv_file,line);
      }
    if (csv_file.bad())
      perror("Error while Reading");
    return line;
  }

int csv_parser::total_lines()
{
  csv_file.clear(); //Clear State
  csv_file.seekg(0,ios::beg);
  int no_lines = 0;
  string line;
  while (!csv_file.eof())
    {
      getline(csv_file,line);
      no_lines = no_lines + 1;
    }
  return no_lines;
}

int csv_parser::fields(string line)
{
  string::iterator it;
  int num_of_comma = 0;
  for (it=line.begin();it<line.end();it++)
    {
      if (*it==',')
	num_of_comma = num_of_comma + 1;
    }
  return num_of_comma+1;
}

string csv_parser::get_value(int row,int column)
{
  string line = get_line(row);
  int total_columns = fields(line);
  int total_fields = 0;
  string::iterator it;
  string value;
  if (column>total_columns || row>total_lines())
    {
      cout<<"Error: Specified column or row is greater than total number of columns or row present in the file.\n";
      exit(1);
    }

  //Todo: Add special case for first column and last column.
  
  for (it=line.begin();it<line.end();it++)
    {
      if (*it==',')
	{
	  total_fields = total_fields + 1;
	  if (total_fields == column - 1)
	    {
	      if (it<line.end())
		it++;
	      while (*it!=',')
		{
		  value += *it;
		  if (it<line.end())
		    it++;
		}
	      return value;
	      
	    }
	}
    }
}

int main()
{
  csv_parser demo("freak");
  /*string a = demo.get_line(3);
  int b=demo.fields(a);
  string ra = demo.get_value(2,2);*/
  string fa = demo.get_value(5,4);
  //int no=demo.total_lines();
  cout<<"val"<<fa<<endl;
}

