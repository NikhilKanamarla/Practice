#include <iostream>
#include <cstring>
#include <ctime>
#include <iomanip>
using namespace std;

// class name has capital 
class Practice {
   //accessible outside the class but within the program
   public:
      // object variables and methods
      int timeInHours;
      string listOfTopics[10];
      int checkIf10000Hours (int value) {
         if (value >= 10000)
         {
            return 1;
         }
         else {
            return 0;
         } 
      }
      int var;
      //static means global variable is restricted to the class where it is declared
      static string globalVar;
      void func();
      void func2();
      string name(string name2);
      int add(int *num1, int *num2);
      int multiply(int &num1, int &num2);
      int modul(int calc);
      void arrayModify(double value[], int value2);
      
      
};

class Practice2{
   public:
      int time;
      string languages;
      void test();
      void recievePrint(string value);
      int doCalc(int value);
      string getSecret();
      void setSecret(string secre);
      Practice2(int time1, string languages2);
   // not acessible outside of class 
   // usually keep varibles private and use public method getters and setters
   private:
      string secret;
      int age;
   // not acessible outside of class but can be accessed through inheritance 
   protected:
      int inheritanceMoney;
      int ageOfDeath;

};

//inherited class of practice with certain access level
class Practice3: public Practice {
   public: 
      int cleaningHours;
      bool workIsDone;
      Practice3(int cleaningHours1, bool workIsDone1) ;
      
};
// end of a class declaration must have a semicolen 

//practicing data hiding 
class Practice4 {
   private: 
   int phoneNumber;
   string address;

   public:
   void setPhoneNumber(int num);
   int getPhoneNumber();
   void setAddress(string ad);
   string getAddress();
};

// class constructor defined with classname :: methodname(also classname)
Practice2 :: Practice2(int time1, string languages2) {
   int time = time1;
   string languages = languages2;
}


Practice3 :: Practice3(int cleaningHours1, bool workIsDone1) {
   int cleaningHours = cleaningHours1;
   bool workIsDone = workIsDone1;
   
}

// class resolution operator used to define a class function
// return type class name :: method name()
void Practice ::func()
{
   // static local variable will keep it's value even after the method is run
   static int maintain = 0;
   maintain++;
   cout << "the value from the method: " << maintain << endl;
}

// local static variable maintains value even after run
void Practice :: func2()
{
   static string keepValue = "hello";
   keepValue += "extra";
   cout << "the value from the 2nd method: " << keepValue << endl;
}

// include a data type if you want to return a value, method variable needs a data type too
// call by value means the value of the variable sent in cannot be changed only copied
string Practice :: name(string name2)
{
   return name2;
}

int Practice :: modul(int calc)
{
   return calc = calc % 2;
}

// call by pointer allows you to use the memory address of the var and change the value
// call by pointer method variables have a * symbol
int Practice :: add(int *num1, int *num2)
{
   *num1 += 2;
   *num2 += 2;
   return *num1;
}

// pass by reference allows you to use the memory address of he var and change the value
// pass by reference only needs the & symbol on the method variable
int Practice :: multiply(int &num1, int &num2)
{
   num1 *= 2;
   num2 *= 2;
   return num2;
}

// pass one dimensional arrays but use an unsized array
void Practice :: arrayModify(double value[], int value2)
{
   for (int i = 0; i < value2; i++)
   {
      cout << value[i] << endl;
   }
}

// calling method from class
void Practice2 :: test() {
   cout << "the method works" << endl;
}

// calling method and sending value
void Practice2 :: recievePrint(string value) {
   cout << value << " that's the value" << endl;
}

// giving class variables values outside the constructor
void Practice2 :: setSecret(string secre) {
secret = secre;
}

string Practice2 :: getSecret() {
return secret;
}

// calling method and modifying value
int Practice2 :: doCalc(int value){
   int value2 = value*2+5/3%5;
   return value2;
}

void Practice4 :: setPhoneNumber(int num) {
   phoneNumber = num;
} 

int Practice4 :: getPhoneNumber() {
   return phoneNumber;
}

void Practice4 :: setAddress(string ad) {
   address = ad;
}

string Practice4 :: getAddress() {
   return address;
}

// main() is where program execution begins.
// allows a comment to be made which is ignored by the complier
int main()
{
   cout << "Hello World" << endl; // prints Hello World
   // class object
   Practice version1;
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
   int storage2 = version1.modul(calc);
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
         version1.func2();
      }

   
   // while loop runs until condtion is false
   // ! operator reverses the boolean condtion 
   while (!(condition <= 0)) {
      // calls the method 
      version1.func();
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


   string storage = version1.name(name2);
   int num1 = 1;
   int num2 = 5;
   cout << "value of the first number: " << num1 <<endl;
   cout << "value of the second number: " << num2 << endl;
   // use & symbol to indicate that the method can change the value through call by pointer 
   int num3 = version1.add(&num1, &num2);
   cout << "value of the first number: " << num1 <<endl;
   cout << "value of the second number: " << num2 << endl;

   cout << "value of the first number: " << num1 <<endl;
   cout << "value of the second number: " << num2 << endl;
   // use & symbol to indicate that the method can change the value through call by pointer 
   int num4 = version1.multiply(num1, num2);
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
   double ipPartialAddress [3] = {184.30, 37.180, 210.76};

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

   version1.arrayModify(ipPartialAddress, amount2);
   
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

   
   version1.timeInHours = 1;
   int log = version1.timeInHours;

   cout << "I have been working for: " << log << " hours" << endl;

   int log2 = version1.checkIf10000Hours(log);

   if (log2 == 1){
      cout << "you have reached 10,00 hours"<< endl;
   } else if (log2 == 0) {
      cout << "you have not reached 10,000 hours" << endl;
   } else {
      cout << "incorrect value";
   }

   // commit files in github desktop app
   cout << "I am using github desktop" << endl;

   Practice2 object2(1,"C++");

   object2.time = 2;
   cout << object2.time << endl;
   object2.languages = "C++";
   object2.recievePrint("hello world");
   int storage3 = object2.doCalc(5);
   cout << "computed value " << storage3 << endl; 
   object2.setSecret("I don't like hot weather");
   string exportedValue =object2.getSecret();

   cout << "using a getter and setter " << exportedValue << endl;

   Practice3 object3(2,true);

   cout << object3.cleaningHours << endl;

   //using inherited methods
   object3.checkIf10000Hours(100);

   object3.var = 5;

   int stored = object3.var;

   cout << stored << endl;

   string two2d [4] [4]= {{"Hello","World","this", "Nikhil"},{"I", "am", "tired", "generally"},{"why", "review", "c++","?"}, {"because", "I", "have" ,"to"}};
   int stores2d = sizeof(two2d)/sizeof(two2d[0][0]);
   cout << stores2d << endl;

   for(int i =0; i < stores2d/4; i++) {
      for(int x =0; x < stores2d/4; x++) {
         cout << two2d[i][x];
      }
      cout << endl;
   }

   string name3;

   cout << "what is your name? ";

   //used to input values in the terminal and store in a variable
   // run in terminal with g++ -o output name 
   // run in terminal with ./output 
   //cin >> name3;

   cout << "your name is: " << name3 << endl;

   Practice4 object4;

   object4.setPhoneNumber(6351013);
   int printNum = object4.getPhoneNumber();
   cout << "Here is the phone number " << printNum << endl;

   object4.setAddress("Hockessin DE");
   string tempPrint = object4.getAddress();

   cout << "Here is the address " <<  tempPrint << endl;
   // common syntax to end the main method 
   return 0;
}
