#!/usr/bin/python
import os
import threading
import sys
import doctest
import math
import exceptions

class Practice:
    def __init__(self, var1, var2):
        self.var1 = var1
        self.var2 = var2
    def printer(self, item):
        print item
    def calc(self,num):
        num = num * 2
        return num
class Practice2(Practice):
    def __init__(self, name, age):
        self.name = name
        self.age = age
    def sendAge(self):
        return self.age
    def sendName(self):
        return self.name
    #overriding methods
    def printer(self, item):
        print "2nd", item


if __name__ == '__main__':
    hello = "Nikhil"
    list = [1,2,3,4]
    for x in list:
        print x
    print list [3]
    num1 = 1
    num2 = 2
    num3 = num1 + num2
    if True:
        print num3
    elif True:
        print "hello"
    else:
        print "last"
    for x in range(len(list)):
        print "numbers ", list [x]
    list2D = [[1,2,3,4],["NK","Soar","Tech","H"]]
    #prints each row 
    for x in range(len(list2D)):
      print list2D [x]
    #prints each element
    for x in list2D:
        for y in x:
            print y
    x = 5
    while x < 10:
        x = x + 1
    print "done"
    #updating lists 
    list [0] = 9000
    #deleting a part of a list
    del list2D [0]
    list2D.append(["Hello", "World", "this", "is", "Nikhil"])
    for x in list2D:
        print x
    list2 = [1,2,3,4]
    list3 = [4,5,6,7]
    print cmp(list2,list3)
    max = max(list3)
    print max 
    count = list2.count(1)
    print "number of times it occurs ", count
    list2.remove(1)
    for x in range(len(list2)):
        print list2 [x]
    list.sort()
    list3 = [["Nikhil", "Kanamarla", "the", "world", "cool"], [1,2,3,4,5], [2.0,3.0,4.50,5.0]]
    #2D array traversal 
    for x in range(len(list3)):
        for z in range(len(list3[x])):
            print list3 [x] [z]

    #dictionaries 
    dict = {"Nikhil": 19, "NK": 19, "Chris": 17}
    dict ["NK"] = 20
    del dict ["Chris"]

    #objects
    object1 = Practice(2,3)
    object1.printer(max)
    numRe = object1.calc(max)
    print numRe

    object2 = Practice2("Nikhil", 19)
    name = object2.name
    age = object2.age
    print name, age 
    object2.printer(list2)

    #IO
    file = open("text.txt")
    print "is it closed", file.closed
    str = file.read(2)
    print str
    #file.write("I was here")
    file.close()

    #execeptions
    try:
        file2 = open("test")
    except IOError:
        print "couldn't be printed"
    else:
        print "worked fine"
    