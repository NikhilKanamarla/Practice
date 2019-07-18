#!/usr/bin/python
import os
import threading
import sys

#class declaration names should be capital
class Practice:
    #constructor for class 
    def __init__(self,timeSpent,concepts,langauge):
        self.timeSpent = timeSpent
        self.concepts = concepts
        self.langauge = langauge
    #all methods must have self variable 
    def printName(self,str):
        print(str)
        return 

    def calc(self, value):
        value = value *2
        print (value)
        return value 

    def modify(self, value):
        value.append([2,3,4,5,6,7,8,9])
        print value
        return 

    def multiValues(self,storage3,list4):
        print storage3
        print list4
        return 
#inherited classed get all the methods 
class Practice2(Practice):
    def __init__(self, childVar):
        self.childVar = childVar
    
    def child(self):
        print "calling child method"
    
    #override parent class methods by redefining in subclass
    def modify(self,value):
        value.append([1,2])
        print value
        return 

# main method declaration
if __name__ == '__main__':
    print "hello world"
    # variable declaration
    name = "Nikhil"
    age = 18
    #list are the arrays of python but can hold multiple data types
    list = [name,age, "apollo","NASA", "classical music", 2.0, 2019, 'N','K']
    #prints entire list
    print list
    #modify list at any time
    list [0] = "Hello"
    #prints first element
    print list[0] 
    #prints selection of elements 
    print list[0:4]
    #dictionary of values 
    dict = {"storage1": 100, "storage2": 200, "storage3": 300}
    print dict["storage1"]
    print dict.keys()
    print dict.values()
    if (list[0] == "Hello"):
        print "list has been modified"
    elif (list[0]== "hello"):
        print "list has been modified"
    else: 
        print "list has not been modified"
    counter = 0
    while (counter < 10):
        counter = counter + 1
        print "while loop is still executing"
    list.append("world")
    for x in list:
        if (list[0] != 0):
            print list[0]
    #nested list
    list2 = [["Nikhil", "Kanamarla", 18, 2], ["Umich", 2023, "CS"]]
    list2.insert(2, ["High level language", "Chillhop", "July"])
    list2 [2] [0] = "I am not a fan"
    list2.insert(3, ["Hello", "World"])
    del list2 [3]
    for row in list2:
        for col in row:
            print (row)
    for row in range(len(list2)):
        for col in range(len(list2[row])):
            print (list2 [row] [col])
        print
    var2019 = "year is 2019"
    # Find the length of a list using len
    print len(list)
    #Find the length of a 2d list multiply rows by cols 
    print (len(list2)*len(list2[0]))
    #tuples are read only lists 
    tuple1 = (1,2,3,4,5,6,7)
    print(tuple1)
    #check how many values in a list or tuple 
    if(6 in tuple1):
        print("true")
    for x in tuple1:
        print x
    objectTry = Practice(1,"methods","python")
    objectTry.printName("Angel")
    #Python methods are pass by value for variables 
    storage = 5
    objectTry.calc(storage)
    print storage
    #returning variable will you to keep the changes made in the method 
    storage2 = objectTry.calc(5)
    print storage2
    #Python methods are pass by reference if appending methods
    list3 = [1,2,3,4,5,6,7,8]
    objectTry.modify(list3)
    print list3
    storage3 = 6
    list4 = ["a","b"]
    objectTry.multiValues(list4, storage3)
    #inheritance in python classes
    object2 = Practice2("child")
    object2.child()
    object2.calc(5)
    list5 = [1, 2, 3, 4, 5, 6, 7, 8]
    object2.modify(list5)
    list6 = ["Hello", "World", "Michigan"]
    list7 = [["Hello", "World", "Michigan"], ["Hello1", "World1", "Michigan1"]]
    #x is iterating variable and list 6 is the list
    for x in range(len(list6)):
        #access individual elements in list
        print list6[x] 
    #x is iterating row variable and list 6 is the list
    for x in range(len(list6)):
        #z is iterating col variable and list 6[x] is the row of the list
        for z in range(len(list6[x])):
            print list6 [x] [z]
    


    