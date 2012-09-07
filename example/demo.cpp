/*------ Example Demo----------
Compilation Command: g++ -o demo demo.cpp csv_parser.cpp

                     (OR)

1) g++ -c csv_parser.cpp
2) g++ -c demo.cpp
3) g++ demo.o csv_parser.o -o demo
------------------------------------------------------*/

#include "csv_parser.hpp"

using namespace std;
int main()
{
  csv_parser csv("demo.txt");
  
  //For getting values according to row number and column number. Remember it starts from (1,1) and not (0,0)
  string value = csv.get_value(3,4);
  
  //For getting a particular row in the CSV file
  string line = csv.get_line(3);
  
  //For getting number of fields in a particular row.
  int total_fields = csv.fields(csv.get_line(3));
  
  cout<<"Value in (3,4) :"<<value<<endl;
  cout<<"Row 3: "<<line<<endl;
  cout<<"Total fields in row 3:"<<total_fields<<endl;
}
