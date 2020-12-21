import sys
import threading
import os

if __name__ == '__main__':
    print("hello world")

    val = 20
    name = "Nikhil"
    
    if(val == 20):
        print("age is 20")

    arrayVal = [1,2,3,4,5,6] 

    arrayVal2 = [[1,2,3,4,5,6],[1,2,3,4,5,6]]   

    for index,element in enumerate(arrayVal):
        print(element)
    
    print("nested for loop")
    for index,element in enumerate(arrayVal2):
        for index2,element2 in enumerate(element):
            print(element2)
