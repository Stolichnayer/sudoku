# sudoku
A 9x9 sudoku checker and solver program written in C.

Run executable with "-check" or "-solve" argument.

<ul>
  <li> "-check" operation:
    checks if the 9x9 sudoku of user input is correct. If it's not, it prints the column or row that is invalid.
    Number 0 is not considered as a mistake, but as a not yet completed number. </li>
  
  <li> "-solve" operation:
  completes a non-finished 9x9 sudoku (where 0 is an empty space) </li>
</ul>
  
  
For example ("-check" operation):
  
  input: 
  
      3 6 9 5 4 2 7 1 8          
      5 7 2 8 9 1 4 6 3
      4 8 1 3 6 7 2 9 5
      8 3 6 7 1 9 5 4 2
      1 9 4 2 8 5 6 3 7
      2 5 7 4 3 6 1 8 9
      9 4 5 1 7 3 8 2 6
      6 2 8 9 5 4 3 7 1
      7 1 3 6 2 8 9 5 4

  output:
  
     OK
     
  input:
  
      3 6 9 0 4 0 0 0 0
      0 0 0 0 9 0 0 0 3
      0 0 0 3 0 0 0 0 0
      0 3 6 7 1 9 0 4 2
      1 9 4 2 0 0 0 0 7
      0 5 0 4 3 0 0 8 0
      9 0 5 0 0 0 8 0 6
      6 0 8 0 0 4 3 7 1
      7 1 0 6 0 0 9 0 0
     
   output:
      
      OK
      
   input:   
   
      3 3 4 6 7 8 9 1 2
      6 7 2 1 9 5 3 4 8
      1 9 8 3 4 2 5 6 7
      8 5 9 7 6 1 4 2 3
      4 2 6 8 5 3 7 9 1
      7 1 3 9 2 4 8 5 6
      9 6 1 5 3 7 2 8 4
      2 8 7 4 1 9 6 3 5
      3 4 5 2 8 6 1 7 9
      
   output:
   
      Invalid row 1
      Invalid column 1
      Invalid block 1
      
For example ("-solve" operation):
  
  input: 
  
      0 3 4 6 7 0 9 1 0
      6 7 2 1 9 5 3 4 8
      1 9 8 3 4 0 5 0 7
      8 5 9 7 6 1 4 2 3
      4 2 0 8 5 3 7 9 0
      7 1 3 9 2 0 8 0 6
      9 6 1 5 3 7 2 8 4
      2 8 7 4 1 9 6 3 5
      3 4 0 2 8 0 1 0 0

  output:
  
      5 3 4 6 7 8 9 1 2
      6 7 2 1 9 5 3 4 8
      1 9 8 3 4 2 5 6 7
      8 5 9 7 6 1 4 2 3
      4 2 6 8 5 3 7 9 1
      7 1 3 9 2 4 8 5 6
      9 6 1 5 3 7 2 8 4
      2 8 7 4 1 9 6 3 5
      3 4 5 2 8 6 1 7 9
      
  input: 
  
      3 3 4 6 7 8 9 1 2
      6 7 2 1 9 5 3 4 8
      1 9 8 3 4 2 5 6 7
      8 5 9 7 6 1 4 2 3
      4 2 6 8 5 3 7 9 1
      7 1 3 9 2 4 8 5 6
      9 6 1 5 3 7 2 8 4
      2 8 7 4 1 9 6 3 5
      3 4 5 2 8 6 1 7 9


  output:
  
      No solution.
      
  input: 
  
      0 0 0 0 0 0 0 1 2
      6 7 2 1 9 5 3 4 8
      1 9 8 3 4 2 5 6 7
      8 5 9 7 6 1 4 2 3
      4 2 6 8 5 3 7 9 1
      7 1 3 9 2 4 8 5 6
      9 6 1 5 3 7 2 8 4
      2 8 7 4 1 9 6 3 5
      3 4 5 2 8 6 1 1 9


  output:
  
      No solution.


