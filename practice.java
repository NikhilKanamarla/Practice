import java.io.*;
// class name must match file name
public class practice {
    //class variables
    int dateOfLanding;
    int size;
    String name;
    boolean missionSucess;

// constructor is a method with the same name as the class
// assign inputted values of method variables to class variables 
public practice (int dateOfLanding1, int size1, String name1) {
    dateOfLanding = dateOfLanding1;
    size = size1;
    name = name1;
}

// assigning class variable a value outside of constuctor 
public void setSuccess (boolean mission) {
    missionSucess = mission;
}

//returning a class variable
public boolean getSuccess () {
    return missionSucess;
}


// main method must be in file name class
public static void main(String[] args) {
    System.out.println("Hello world");    
    // local variables
    int age = 18;
    String name = "Nikhil";
    System.out.println(age + " " + name);
    // array 
    int num [] = {1,2,3,4,5,6,7,8,9};
    // for loop needs array.length
    for(int i = 0; i < num.length; i++) {
        System.out.println(num[i]);
    }
    String num2 [] [] = new String [2][2]; 
    num2[0][0] = "My";
    num2[0][1] = "name";
    num2[1][0] = "is";
    num2[1][1] = "Nikhil";
    String data [][] = printAndModify(num2);
    System.out.println(data [1][1]);

    //object declaration with instance variables
    practice Apollo = new practice(1969,10000, "SaturnV");
    //calling method using .
    Apollo.setSuccess(true);
    //returned variable values need to be stored
    boolean missonControl = Apollo.getSuccess();
    System.out.println(missonControl);
    practice artemis = new practice((2024), 10000, "SLS");
    artemis.setSuccess(false);
    boolean trumpNasa = artemis.getSuccess();
    System.out.println(trumpNasa); 

    // variables are pass by value
    String valueSent = "MIT";
    artemis.modifyByValue(valueSent);
    System.out.println(valueSent);
    // Use return statement to get value from method 
    String returnedValue = artemis.modifyByValueAndReturn(valueSent);
    System.out.println(returnedValue);

    //method overloading practice
    int overload = 5;
    double overload2 = 10.0;
    int storeOverload1 = Apollo.methodOverload(overload);
    double storeOverload2 = Apollo.methodOverload(overload2);
    System.out.println("with an int var " + storeOverload1 + " with a double var " + storeOverload2);

}

//method needs variable type and return statment in this case
public static String[][] printAndModify(String array [] []) {
    for(int i = 0; i < array.length; i++) {
        for(int x = 0; x < array.length; x++) {
            System.out.println(array[i][x]);
        }
    }
    array[1][1] = "Michigan Hackathon Alliance";

    return array;
}

//pass-by-value meants that the orginal value of the variable sent in cannot be changed, only copied
public void modifyByValue(String word) {
    word += " I have been to the method";
    System.out.println(word);
}

// variable can be different value if returned 
public String modifyByValueAndReturn(String word) {
    word += " I have been to the method mark 2";
    System.out.println(word);
    return word;
}

// method overloading is when two methods have the same name but different method variables
public int methodOverload(int value) {
    value*=2;
    return value;
}

public double methodOverload(double value) {
        value *= 2;
        return value;
}

}