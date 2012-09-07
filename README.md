CSV-Parser in C++
------------------
A CSV Parser in C++ without any bells and whistles.

Usage:
-------

<pre>
//Create object of csv_parser and pass the filename as the argument.
csv_parser csv("demo.txt");

//For getting values according to row number and column number. Remember it starts from (1,1) and not (0,0)
string value = csv.get_value(3,4);

//For getting a particular row in the CSV file
string line = csv.get_line(3);

//For getting number of fields in a particular row.
int total_fields = csv.fields(csv.get_line(3));
</pre>

For demo, see the code demo.cpp under examples folder.

License:
---------
GNU General Public License v3 (GPLv3)

Bug Report:
------------
Issue it here: https://github.com/psibi/csv-parser/issues

