#include <iostream>
#include <cstring>
using namespace std;

class practice {
   public:
      int timeInHours;
};
   

//global variable is accessible throught the program
int var = 0;
//static means global variable is restricted to the class where it is declared 
static string globalVar = "only in this class";
void func();
void func2();
string name(string name2);
int add(int *num1, int *num2);
int multiply(int &num1, int &num2);
int modul(int calc);
void arrayModify(double value[], int value2);


// main() is where program execution begins.
// allows a comment to be made which is ignored by the complier 
int main() {
   cout << "Hello World" << endl; // prints Hello World
   // various operators
   int x = 1;
   int y = 2;
   int calc = x*y;
   y*= 2;
   x--;
   double value = 2.0;
   int xd = rand();
   cout << xd << " that's a random value" << endl;
   bool known = true;
   int storage2 = modul(calc);
   cout << "variable value: " << calc << endl;
   cout << "pass by value: " << storage2 << endl;
   const int finalVar = 10;
   const string address = "Delaware"; 
   // const keyword means a variable's name cannot be changed 
   const string name2 = "Nikhil";
   // a local variable wil take precedence over a global variable with the same name 
   int var = 1;
   // cout allows for output and endl adds a line
   cout << "local var takes priority: " << var << endl;
   cout << "modulus operator divides and gives remainder: " << x%y << endl;
   int condition = 10;
   for(int i =0; i < 10; i++) {
         func2();
      }

   
   // while loop runs until condtion is false
   // ! operator reverses the boolean condtion 
   while (!(condition <= 0)) {
      // calls the method 
      func();
      condition--;
      // if conditonal runs once if condition is true
      if(condition == 0) {
         cout << "Done" << endl;
      }
      else if(condition == 1) {
         cout << "Almost done" << endl;
      }
      // executed only when if condtional does not execute 
      else {
         cout << "continue through the program" << endl;
      }
      // nested for loop runs the first loop one time and then all of the second loop and then repeats
      for (int i = 0; i < condition; i++) {
         cout << "the value from the for loop: " << i << endl; 
         for(int x = 0; x < condition; x+=2) {
            cout << "the value from the nested loop " << x << endl;
            if (condition == 1) {
            cout << "this is taking too long" << endl;
            // break statement stops running the loop and moves on in the program
            break;
            }
         }
      }
   }
   int favNum = 64;

//switch statment needs a char or int variable 
   switch(favNum) {
      // each case checks if the value inputted is equal to the value of the case  
      case (64):
      // given equal values execute instructions of case and then break
         cout << "correct" << endl;
         break;
      case (256):
         cout << "incorrect";
         break;
      case (2):
         cout << "incorrect";
         break;
      // executes if all other cases don't run 
      default:
         cout << "wrong input" << endl;
   }
   char favColor = 'B';
   switch (favColor) {
      case ('O'):
         cout << "correct" << endl;
         break;
      case ('R'):
         cout << "Wrong" << endl;
         break;
      case ('B'):
         cout << "Wrong" << endl;
         break;
      default: 
         cout << "input error" << endl;
   }


   string storage = name(name2);
   int num1 = 1;
   int num2 = 5;
   cout << "value of the first number: " << num1 <<endl;
   cout << "value of the second number: " << num2 << endl;
   // use & symbol to indicate that the method can change the value through call by pointer 
   int num3 = add(&num1, &num2);
   cout << "value of the first number: " << num1 <<endl;
   cout << "value of the second number: " << num2 << endl;

   cout << "value of the first number: " << num1 <<endl;
   cout << "value of the second number: " << num2 << endl;
   // use & symbol to indicate that the method can change the value through call by pointer 
   int num4 = multiply(num1, num2);
   cout << "value of the first number: " << num1 <<endl;
   cout << "value of the second number: " << num2 << endl;

   // array declaration with number of elements starting from index 0
   int collection [10];
   int i;
   // for loop fills in elements 
   for (i = 0; i < 10; i++) {
      collection[i] = i;
   }
   i = 0;
   // for loop prints elements 
   while(i < 10) {
      cout << collection[i] << endl;
      i++;
   }

   //declare an array without a number of elements then assign values 
   string blankSlate [] = {"whiteboard", "blackboard", "marker"};

   //declare an array with a set number of elements 
   double ipPartialAddress [] = {184.30, 37.180, 210.76};

   // used to find the size of an array, number of bytes of entire array divided by bytes in a single index 
   int amount = sizeof(blankSlate)/sizeof(blankSlate[0]);

   int amount2 = sizeof(ipPartialAddress)/sizeof(ipPartialAddress[0]);

   cout << amount << endl << amount2 << endl;

   // 2d array goes by rows and columns with each pair of brackets as one row 
   int twoDim [4] [4] = {{0,1,2,3},{3,2,1,0},{1,2,4,6}, {2,4,8,12}};

   int amount3 = sizeof(twoDim)/sizeof(twoDim[0][0]);

   string twoDim2 [2] [5] = {{"hello", "world", "this", "is", "nikhil"}, {"I", "am", "reviewing", "c++", "today"}};

   // nested for loop to print out values of 2d array 
   for (int i = 0; i <= 3; i++) {
         for (int x = 0; x <= 3; x++) {
      cout << twoDim[i][x];
   }
   cout << endl;
   }
   // intializes the i variable and checks for condition and then runs code which is the inside loop
   // second loop has x intialized and checks for condtion and then runs inside loop printing columns 
   // x is incremented at end of inside loop and afterwards a new line is added (new row)
   // i is incremented at end of first loop
   for (int i = 0; i < 2; i++) {
    for (int z = 0; z < 5; z++) {
         cout << twoDim2[i][z];
      }
      cout << endl;
   }

   arrayModify(ipPartialAddress, amount2);
   
   string word1 = "attack";
   string word2 = "cab";
   string word3 = word1 + word2;
   cout << word3 << endl;
   
  
   // pointer variable created using * symbol and memory address of var accessed using & symbol 
   // pointer variable and orginal variable must be same type 
   int *word4 = &amount;
   string *word5 = &word3;

   // to print the memory address of stored in the pointer variable
   cout << "the memory address of word3 " << word5 << endl;

   // to print the value of the memory address stored in the pointer variable
   cout << "the value of word3 " << *word5 << endl;

   int *nullPointer = NULL;
   // prints out the memory address of a nullpointer 
   cout << nullPointer << endl;

   // common syntax to end the main method 
   return 0;
}

void func() {
   // static local variable will keep it's value even after the method is run 
   static int maintain = 0; 
   maintain++; 
   cout << "the value from the method: " << maintain << endl;
   
}

// local static variable maintains value even after run 
void func2() {
   static string keepValue = "hello";
   keepValue+= "extra";
   cout << "the value from the 2nd method: " << keepValue << endl;

}


// include a data type if you want to return a value, method variable needs a data type too
// call by value means the value of the variable sent in cannot be changed only copied
string name( string name2) {
   return name2;
}

int modul(int calc) {
   return calc = calc%2;
}

// call by pointer allows you to use the memory address of the var and change the value 
// call by pointer method variables have a * symbol 
int add(int *num1, int *num2) {
   *num1+=2;
   *num2+=2;
   return *num1;
}

// pass by reference allows you to use the memory address of he var and change the value
// pass by reference only needs the & symbol on the method variable 
int multiply(int &num1, int &num2) {
   num1*=2;
   num2*=2;
   return num2;
}

// pass one dimensional arrays but use an unsized array 
void arrayModify(double value [], int value2) {
for (int i = 0; i < value2; i++) {
   cout << value[i] << endl;
   
}
}
