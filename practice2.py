#!/usr/bin/python
import os
import threading
import sys
import doctest
import math 


class Test:
    #private member variables
    __year = 0
    __gpa = 0.0

    #pass in self 
    def __init__(self, name, age):
        #use self to call class members  
        self.name = name
        self.age = age

    def setYear(self, year1):
        self.__year = year1

    def getYear(self):
        return self.__year

    def setGPA(self, num):
        self.__gpa = num
    
    def getGPA(self):
        return self.__gpa
    
    def calcGPA(self, grade1, grade2, grade3):
        ''' returns gpa average
        >>> calcGPA(4,4,4)
        4
        '''
        store = (grade1 + grade2 + grade3)/3
        return store


if __name__ == '__main__':
    doctest.testmod()
    print ("hello")
    #create an object and call class constructor
    object1 = Test(18, "Nikhil")
    object1.setYear(1)
    temp = object1.getYear()
    object1.setGPA(3.5)
    temp2 = object1.getGPA()
    print (temp, temp2)
    #one dimensionsal list
    list = [5,4,3,2,1, "international student", "spy"]
    #2d list
    list2 = [[5,4,3,2,1], ["hello", "world", "I" , "am", "Macintosh"]]
    # array iterates through list
    for index in range(len(list)):
        print (list[index])
    #2d for loop iteration 
    for index in range(len(list2)):
        for index2 in range(len(list2[index])):
            if (list2[index] [index2] == 1):
                print("end of row")
            print (list2[index][index2])
    #dictionary is organized by keys and values
    dict = {"Monday": "Calc", "Tuesday": "CS, English, UROP", "Wednesday": "english, math"}             
    print(dict["Tuesday"])
    print(dict.keys())
    print (dict.values())
    print (dict)
    
    for word in dict:
        print(word)
    #tuples have immutable values
    tuple1 = (3,4,5, "Monday", "Tuesday", "Wednesday")
    tuple2 = ("girl")
    tuple3 = ("boy")
    #the only way to change tuples is to add them but they have to be string
    tuple4 = tuple3 + tuple2
    print(tuple4)
    #in keyword allows you to search a list 
    if ("spy" in list):
        print ("word found")
    
    store2 = object1.calcGPA(3,4,5)
   
    print (store2)
    #print one same line using comma
    print ("one line"),
    print ("second line",)
    #print multiple items
    print (list), (list2)

    store = math.ceil(4.5)
    print(store)
    #you can print with single quotes too
    print('this works too')
    print (type(store))
    #input can be used for reading in values 
    #f = input("enter")
    #cast to an int 
    #print (int(f))
    x = round(4.5)
    print (x)

    if x <= 4:
        print ("excutes")
    elif x==4:
        print ("file")
    else:
        print("I dunno")

    x = 3
    if (x > 2):
        print ("Greater")
        if (x == 3):
            print("equal")
        else: 
            print ("Not equal")
    else:
        print("Less")
    
    listOfDifTypes = [1,3,"f", "u","iclicker"]
    print(listOfDifTypes[0:3])
    listOfDifTypes.append("EECS183")

    