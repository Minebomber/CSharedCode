# CSharedCode
A collection of shared code that my c projects use  
Usually referenced as:

`#include "../shared/a_header.h"`


## Sources

* **`file_reading`**

   A collection of functions that are used to read a files data line by line.
  
    * `fr_read_lines_from_file(FILE*, char**)`:
  
      Takes a file pointer and uses the `char**` to store all characters from a file.
      Returns the size of the `char*` (for iteration).
  
    * `fr_num_lines(char*, int)`:
    
      Takes a `char*` of file data, along with it's size
      Returns the number of newlines counted
      
    * `fr_line_from_array(int, char*, int, char**)`:
    
      Takes a line number, file data char array, char array size, and 
  
