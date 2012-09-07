#include "csv_parser.hpp"

csv_parser::csv_parser(std::string filename)
  {
    csv_file.open(filename.c_str());
    if (!csv_file.is_open())
      {
	perror(("Error while opening file " + filename).c_str());
	exit(1);
      }
  }

csv_parser::~csv_parser()
{
  csv_file.close();
}

std::string csv_parser::get_line(int line_number)
  {
    csv_file.clear(); //Clear State
    csv_file.seekg(0,std::ios::beg);
    std::string line;
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
  csv_file.seekg(0,std::ios::beg);
  int no_lines = 0;
  std::string line;
  while (!csv_file.eof())
    {
      getline(csv_file,line);
      no_lines = no_lines + 1;
    }
  return no_lines;
}

int csv_parser::fields(std::string line)
{
  std::string::iterator it;
  int num_of_comma = 0;
  for (it=line.begin();it<line.end();it++)
    {
      if (*it==',')
	num_of_comma = num_of_comma + 1;
    }
  return num_of_comma+1;
}

std::string csv_parser::get_value(int row,int column)
{
  std::string line = get_line(row);
  int total_columns = fields(line);
  int total_fields = 0;
  std::string::iterator it;
  std::string::reverse_iterator rit;
  std::string value;
  if (column>total_columns || row>total_lines())
    {
      std::cout<<"Error: Specified column or row is greater than total number of columns or row present in the file.\n";
      exit(1);
    }

  //Case: For first column in CSV file.
  if (column == 1)
    {
      it=line.begin();
      while (*it!=',')
	{
	  value += *it;
	  it++;
	}
      return value;
    }
  //Case: For last column in CSV file.
  if (column==total_columns)
    {
      rit=line.rbegin();
      while (*rit!=',')
	{
	  value += *rit;
	  rit++;
	}
      return value;
    }
  //For all other cases
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

