#ifndef ARRAYS_H
#define ARRAYS_H

#include <fstream>
#include <string>
#include <iostream>
#include <iterator>
using namespace std;

const int SIZE = 60;

const int MAX_PRINTABLE_ASCII = '~';
const int MIN_PRINTABLE_ASCII = ' ';
const int ASCII_PRINTABLE_RANGE = MAX_PRINTABLE_ASCII - MIN_PRINTABLE_ASCII + 1;



// Requires: n must be > 0
// Modifies: nothing
// Effects: prints a right triangle
//  with a parameter of 3 gives
// Note: no spaces at the end of lines
//*
//**
//***
void printRight(int n) {
    if (n > 0)
    {
        for (int i = n; i > 0; i--)
        {
            int x = i;
            while (x <= n)
            {
                cout << n;
                x++;
            }
            cout << endl;
        }
    }
}

// Requires: n must be > 0
// Modifies: nothing
// Effects: prints a right triangle upside down
//   with a parameter of 3 gives
// Note: no spaces at the end of lines
//***
// **
//  *
void printRight_upsideDown_rightJustified(int n) {
    if (n > 0)
    {
        for (int i = 0; i < n; i++)
        {
            int x = i;
            while (x < n)
            {
                cout << n;
                x++;
            }
            cout << endl;
        }
    }
}


// Requires: The size of array arr is size && size > 0 && size <= SIZE
// Modifies: Nothing
// Effects:  Prints the elements of the array to the monitor
//           Prints an endl at the end
//
//           e.g., If array a contains {'A','%','8'} then the following code:
//
//                 printArray(a,3);
//                 cout << "Hello";
//     will print:
//                 A%8
//                 Hello
// Note that there must be no space after the last element('8') in the above example
void printArray(const char arr[], int size) {
    if (size > 0 && size <= SIZE)
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i];
        }
        cout << endl;
    }

}


// Requires: The size of array arr is rows x cols && rows > 0 && rows <= SIZE
//                                                && cols > 0 && cols <= SIZE
//
//           i.e., Even though array arr is allocated with SIZE rows, columns,
//                 it is a partially filled array
// Modifies: Nothing
// Effects:  Prints the elements of the array
//             one row per line
//           Prints an endl at the end
//
//           e.g., If array arr contains {{'A','3','@'}{'#','\','9'}}
//                  then the following code:
//
//                 printArray(arr,2,3);
//                 cout << "Hello";
//          will print:
//                 A3@
//                 #\9
//                 Hello
// Note: that there must be no spaces after '3' and '\' above
// Calls: printArray(const char arr[], int size);
void printArray(const char arr[][SIZE], int rows, int cols) {

     if (rows > 0 && rows <= SIZE && cols > 0 && cols <= SIZE)
     {
         for (int i = 0; i < rows; i++)
         {
             for (int x = 0; x < cols; x++)
             {
                 cout << arr[i][x];
             }
             cout << endl;
         }
    }
}

// Requires: The size of array arr is size && size > 0 && size <= SIZE
// Modifies: The array arr
// Effects:  Adds val to each character in the array
//           If the array is: how now brown cow
//           and val = 5,
//           then result is:  mt|%st|%gwt|s%ht|
// Note:     Make sure the character remains in the ' ' MIN_PRINTABLE_ASCII
//           to '~' MAX_PRINTABLE_ASCII range (inclusive)
//           all printable characters are between this range
//           If character < MIN_PRINTABLE_ASCII, then add ASCII_PRINTABLE_RANGE
//           If character > MAX_PRINTABLE_ASCII, then subtract ASCII_PRINTABLE_RANGE
//            to put back within range,  repeat as needed
//           all printable characters are between this range
//           ' ' is the 1st printable character (ASCII 32)
//           '~' is the last printable character (ASCII 126)
// Note:     Do not do the addition on char's. It could cause an overflow
// Look into above 
void add(char arr[], int size, int val) {
     

    char addVal = (char)val;
     if (size > 0 && size <= SIZE)
    {
        for(int i = 0; i < size; i++) {
            arr[i] += addVal;
            while (arr[i] < MIN_PRINTABLE_ASCII) {
                arr[i] += ASCII_PRINTABLE_RANGE;
            }
            while (arr[i] > MAX_PRINTABLE_ASCII) {
                arr[i] -= ASCII_PRINTABLE_RANGE;
            }
            cout << (arr[i]);
        }
        cout << endl;
    }
}


// Requires: The size of array arr is rows x cols && rows > 0 && rows <= SIZE
//                                                && cols > 0 && cols <= SIZE
// Modifies: The array arr
// Effects:  Adds val to each character in the array
//           If the array is the following:
//                     (note there are some spaces at the end of lines)
//           how
//           now
//           brown
//           cow
// with val = 5, the result would be
//           mt|%%
//           st|%%
//           gwt|s
//           ht|%%
// Note: Make sure the new character remains in the MIN_PRINTABLE_ASCII to
//           MAX_PRINTABLE_ASCII range (inclusive)
//           all printable characters are between this range
// Calls: void add(char arr[], int size, int val);
// Note:     Do not do the addition on char's. It could cause an overflow
void add(char arr[][SIZE], int rows, int cols, int val) {
    
    char addVal = (char)val;
    if (rows > 0 && rows <= SIZE && cols > 0 && cols <= SIZE)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int x = 0; x < cols; x++)
            {
                arr[i][x] += addVal;
                while (arr[i][x] < MIN_PRINTABLE_ASCII)
                {
                    arr[i][x] += ASCII_PRINTABLE_RANGE;
                }
                while (arr[i][x] > MAX_PRINTABLE_ASCII)
                {
                    arr[i][x] -= ASCII_PRINTABLE_RANGE;
                }
                cout << arr[i][x];
            }
            cout << endl;
        }
        }
    
}
 

// Requires: The size of array arr is size && size > 0 && size <= SIZE
// Modifies: The array arr
// Effects:  Rotates the array by one element to the left
//           e.g., Array:  abcde when rotated left becomes: bcdea
// use for loop and while loop technique to find array length 
// setup if conditonal to contain all of the following code 
// use for loop to assign all values from orginal array to a temp array
// swap first index of temp array with last index (size-1) of the orginal array 
// for loop has first index of orginal array = first-1 index of temp array
void rotateLeft(char arr[], int size) {
    
    if ( size > 0 && size <= SIZE)
    {
        char temp[size];
        for (int i = 0; i < size; i++)
        {
            temp[i] = arr[i];
        }
        arr[size - 1] = temp[0];
        for (int i = 1; i < size; i++)
        {
            arr[i - 1] = temp[i];
        }
        for (int i = 0; i < size; i++)
        {
            cout << arr[i];
        }
        cout << endl;
    }
}

// Requires: The size of array arr is rows x cols && rows > 0 && rows <= SIZE
//                                                && cols > 0 && cols <= SIZE
// Modifies: The array arr
// Effects:  Rotates each row of the array by one element to the left
//           e.g., Array
//            abc
//            def
//            ghi
//          Result is:
//            bca
//            efd
//            hig
// Calls: void rotateLeft(char arr[], int size);
// use for nested loop and while loop technique to find array length 
// setup if conditonal to contain all of the following code 
// use for nested loop to assign all values from orginal array to a temp array
// use for loop to swap first index (column) of each row in temp array with last index (column) (size-1) of each row in the orginal array 
// nested for loop starts from i=1 has first index of orginal array = first-1 index of temp array to swap the columns of the middle rows 
void rotateLeft(char arr[][SIZE], int rows, int cols) {

    if(rows > 0 && rows <= SIZE && cols > 0 && cols <= SIZE) {
        char temp [rows] [cols]; 
        for (int i = 0; i < rows; i++)
        {
            for (int x = 0; x < cols; x++)
            {
                temp [i][x] = arr[i][x];
            }
        }

        for(int i = 0; i < rows; i++) {
            arr[i][cols-1] = temp [i] [0];
        }

        for (int i = 0; i < rows; i++)
        {
            for (int x = 1; x < cols; x++)
            {
                arr[i][x - 1] = temp[i][x];
            }
        }
        for (int i = 0; i < rows; i++)
        {
            for (int x = 0; x < cols; x++)
            {
                cout << arr[i][x];
            }
            cout << endl;
        }
    }
}


// Requires: The size of array arr is size && size > 0 && size <= SIZE
// Modifies: The array arr
// Effects:  Rotates the array by one element to the right
//           e.g., Array: abcdef   when rotated right becomes: fabcde
// use for loop and while loop technique to find array length 
// setup if conditonal to contain all of the following code 
// use for loop to assign all values from orginal array to a temp array
// swap first index of orginal array with last index (size-1) of the temp array 
// for loop starts from size and decrements 
// for loop has last index of orginal array = last-1 index of temp array
void rotateRight(char arr[], int size) {
    if(size > 0 && size <= SIZE) {
        char temp[size];
        for (int i = 0; i < size; i++)
        {
            temp[i] = arr[i];
        }
        arr[0] = temp[size-1];

        for (int i = size; i > 0; i--) {
            arr[i] = temp[i-1];
        }
        for (int i = 0; i < size; i++)
        {
                cout << arr[i];
            
        }
        cout << endl;
    }
}

// Requires: The size of array arr is rows x cols && rows > 0 && rows <= SIZE
//                                                && cols > 0 && cols <= SIZE
// Modifies: The array arr
// Effects:  Rotates each row of the array by one element to the right
//           e.g., Array
//            abc
//            def
//            ghi
//          Result is:
//            cab
//            fde
//            igh
// Calls: void rotateRight(char arr[], int size);
// use for nested loop and while loop technique to find array length
// setup if conditonal to contain all of the following code
// use for nested loop to assign all values from orginal array to a temp array
// use for loop to swap first index (column) of each row in orginal array with last index (column) (size-1) of each row in the temp array
// nested for loop starts from i=size has last index of orginal array = last-1 index of temp array to swap the columns of the middle rows
void rotateRight(char arr[][SIZE], int rows, int cols) {

    if ( rows > 0 && rows <= SIZE && cols > 0 && cols <= SIZE) {
        char temp2[rows][cols];
        for (int i = 0; i < rows; i++)
        {
            for (int x = 0; x < cols; x++)
            {
                temp2[i][x] = arr[i][x];
                
            }
        }

        for(int i = 0; i < rows; i++ ) {
            arr[i][0] = temp2[i][cols - 1];
        }

        for (int i = 0; i < rows; i++)
        {
            for (int x = cols; x > 0; x--)
            {
                arr[i][x] = temp2[i][x - 1];
            }
        }
        for (int i = 0; i < rows; i++)
        {
            for (int x = 0; x < cols; x++)
            {
                cout << arr[i][x];
            }
            cout << endl;
        }
    }
}

// Requires: The size of array arr is size && size > 0 && size <= SIZE
// Modifies: The array arr
// Effects:  Reverses the ordering of elements within the array
//           e.g., Array: abcdef when reversed becomes: fedcba
// fill a temp array with values from char arr with a for loop run backward starting from i = size to i= 0  temp [size-i] = arr[i]
// run a for loop forwards and put all values of temp array into char arr
void reverse(char arr[], int size) {

    if(size > 0 && size <=SIZE) {
        char temp [size];
        for(int i = size; i >= 0; i--) {
            temp[(size-1)-i] = arr[i];
        }
        for(int i = 0; i < size; i++) {
            arr[i] = temp[i];
            cout << arr[i];
        }
        cout << endl;
    }
}

// Requires: arr1 to have size1 >= index1 + len  && size1 > 0 && size1 <= SIZE
//           arr2 to have size2 >= index2 + len && size2 > 0 && size2 <= SIZE
//           index1 must be within range of arr1
//           len >= 0
//           index1 + len - 1 must be within range of arr1
//           index2 must be within range of arr2
//           index2 + len - 1 must be within range of arr2
// Modifies: The array arr1 and array arr2
// Effects:  Swap elements of arr1 and elements of arr2 according to the following
//           elements of arr1 from arr1[index1] to arr1[index1+len-1] are swapped with
//           elements of arr2 from arr2[index2] to arr2[index2+len-1] inclusive
// Example:  if arr1 is: 123456 index1 = 0, len = 3
//              arr2 is: 789012 index2 = 3
//           the result is:
//           arr1 is: 012456       arr2 is: 789123
// if condtional for each arr1 and arr2, that tests if the index1 && index1 + len-1 are not null values. Then increment variable 
// run two for loops for temp1 and temp2
// setup a for loop and while loop to do the swap of each arr i = index1 to i <= index1+len-1 then swap arr1 indexes with temp2 indexes. repeat     
void swapRange(char arr1[], int size1, int index1,
               char arr2[], int size2, int index2, int len) {
    

    if ( arr1[index1] != 0 && arr1[index1 + len - 1] != 0 && arr2[index2] != 0 && arr2[index2 + len - 1] != 0 && size1 >= (index1 + len) && size1 > 0 && size1 <= SIZE && size2 >= (index2 + len) && size2 > 0 && size2 <= SIZE && len >= 0) {
        char temp1 [size1];
        for (int i =0; i < size1; i++) {
            temp1[i] = arr1[i];
        }
        char temp2[size2];
        for (int i = 0; i < size2; i++)
        {
            temp2[i] = arr2[i];
        }
        int x = index2;
        while(x <= index2+len-1) {
        for(int i = index1; i <= index1+len-1; i++) {

            arr1[i] = temp2[x];
            x++;
        }
        }

        int z = index1;
        while (z <= index1 + len-1) {
        for (int i = index2; i <= index2 + len - 1; i++)
        {
            arr2[i] = temp1[z];
            z++;
        }
        }
        for(int i =0; i < size1; i++) {
            cout << arr1[i];
        }
        cout << endl;
        for (int i = 0; i < size2; i++)
        {
            cout << arr2[i];
        }
        cout << endl;
        }
    }

// Requires: The size of array arr is size &&  size > 0 && size <= SIZE && len > 0
// Modifies: The array arr
// Effects:  Exchanges len number of characters with the next len
//           number of characters continueing across the row.
//           If there isn't enough characters to do the exchange,
//           then exchange nothing.
// Example:  if the array is: batman$robin and len is 6, then batman is
//           exchanged with $robin resulting in: $robinbatman
//           if len is 3, then bat will exchange with man and
//              $ro will exchange with bin resulting in: manbatbin$ro
//           if len is 5, then batma will exchange with n$rob
//              resulting in: n$robbatmain
//           if len is 8, the exchange is not possible so do nothing
// Note: be careful you don't go outside bounds of the array on this one
// Calls: swapRange
// use old for loop method to find size of array and then setup if condtional with rest of code
// if conditonal checks if size >= len*2 and contains rest of code
// create a two temp arrays with first set of characters up to len and the next len set of characters
// setup a for loop and while loop to swap the first set of characters in array arr with the second temp array 
// setup a for loop and while loop to swap the second set of characters in array arr with the first temp array
void swapWithinOneRow(char arr[], int size, int len){
 
    if (size >= (len * 2) && size > 0 && size <= SIZE && len > 0)
    {
        char temp1[size];
        for (int i = 0; i < size; i++)
        {
            temp1[i] = arr[i];
        }
        char temp2[size];
        for (int i = 0; i < size; i++)
        {
            temp2[i] = arr[i];
        }
        
        int counter = 0;
        for(int i = 0; i < size-len; i++) {
             if (counter==len) {
                i+=len;
                counter = 0;
            }
            counter++;

            if(i+len < size) {
            arr[i] = temp2[i+len];
            arr[i+len] = temp1[i];
            }
            
        }
        

        for(int i =0; i <size; i++) {
            cout << arr[i];
        }
        cout << endl;
    }
    
}

// Requires: The size of array arr is rows x cols && rows > 0 && rows <= SIZE
//                                                && cols > 0 && cols <= SIZE
// Modifies: The array arr
// Effects:  Will swap the row with index 0 with row index 1,
//                         row with index 2 with row index 3, etc
//           If n is odd, the last row will not be swapped
// Example:  if the array is
//         a b c
//         d e f
//         g h i
//       the result will be
//         d e f
//         a b c
//         g h i
// Calls: swapRange
// use for loop method to find size of array and then setup if condtional with all following code
//make a nested for loop for a temp array 
//make a nested for loop that swaps each row arr [i] [x] = temp [i+1] [x] and arr[i+1] [x] = temp [i] [x]
// above nested for loop should increment each row by 2 after each iteration
// make a nested for loop to print  
void swapRows(char arr[][SIZE], int rows, int cols) {

    if( rows > 0 && rows <= SIZE && cols > 0 && cols <= SIZE ) {
        char temp [rows] [cols];
        for(int i = 0; i < rows; i++) {
            for(int x = 0; x < cols; x++) {
                temp [i] [x] = arr [i] [x];
            }
        }
        for (int i =0; i < rows-1; i+=2) {
            for (int x =0; x < cols; x++) {
                arr[i][x] = temp[i + 1][x];
                arr[i + 1][x] = temp[i][x];
            }
        }
        for (int i = 0; i < rows; i++)
        {
            for (int x = 0; x < cols; x++)
            {
                cout << arr[i][x];
            }
            cout << endl;
        }
    }
}



int main()
{
    const char arr2[SIZE] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    int amount = sizeof(arr2) / sizeof(arr2[0]);
    const char arr[][SIZE] = {{'n', 'i', 'k', 'h', 'i', 'l'}, {'n', 'i', 'k', 'h', 'i', 'l'}};
    char arr3[] = { 'h', 'o', 'w', ' ', 'n', 'o', 'w', ' ', 'b', 'r', 'o', 'w', 'n', ' ', 'c', 'o', 'w',' ', 'h', 'o', 'w', ' ', 'n', 'o', 'w', ' ', 'b', 'r', 'o', 'w', 'n', ' ', 'c', 'o', 'w'};
    int amount2 = sizeof(arr3) / sizeof(arr3[0]);
    char arr4 [][SIZE] = {{'h','o','w',' ',' '}, {'n','o','w',' ',' '}, {'b','r','o','w','n'}, {'c','o','w',' ',' '}};
    char arr5 [] = {'a','b','c','d','e'};
    char arr6 [] [SIZE] = {{'a','b','c'}, {'d','e','f'}, {'g','h','i'}};
    char arr7 [] = {'a','b','c','d','e','f'};
    char arr8[][SIZE] = {{'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}};
    char arr9[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    char arr10[] = {'1','2','3','4','5','6'};
    char arr11[] = {'7','8','9','0','1','2'};
    char test2[][SIZE] = { {'1', '2', '3', '4', '5', '6'},{'7', '8', '9', '0', '1', '2'}};
    char arr12[] = {'b', 'a', 't', 'm', 'a', 'n', '$', 'r', 'o', 'b', 'i', 'n'};
    char arr13[][SIZE] = {{'a', 'b', 'c', 'd'}, {'d', 'e', 'f', 'g'}, {'g', 'h', 'i', 'j'}, {'1', '2', '3', '4'}, {'5', '6', '7', '8'}};
    char arrTest[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    int amount3 = sizeof(arrTest) / sizeof(arrTest[0]);
    printRight(5);                           // works in all situations
    printRight_upsideDown_rightJustified(5); // works in all situations
    printArray(arr2, 60);                    // works in all situations
    printArray(arr, 2, 6);          // works in all situations
    add(arr3,amount2,5);                                  // works in all situations
    add(arr4, 4, 5, 5); // works in all situations
    rotateLeft(arr5, 5);      // works in all situations
    rotateLeft(arr6, 3, 3); // works in all situations
    rotateRight(arr7,6);  // works in all situations
    rotateRight(arr8, 3, 3); // works in all situations
    reverse(arr9,6);          // works in all situations
    swapRange(arr10, 6, 0, arr11, 6, 0, 2); // works in all situations
    swapWithinOneRow(arr12, 12, 5); // works in all situations
    swapRows(test2, 2, 6); // works in all situations

    return 0;
}

#endif
