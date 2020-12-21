import sys
import threading
import os
from collections import deque, Counter
import heapq
import string

def binarySearch(array, startIndex, endIndex, target):

    while(startIndex <= endIndex):
        #better version of finding middle 
        middleIndex = (startIndex + endIndex) // 2
        #find middle value
        if(target == array[middleIndex]):
            return middleIndex
        #find upper half
        elif(target > array[middleIndex]):
            startIndex = middleIndex + 1
        #find lower half 
        else:
            endIndex = middleIndex -1

    return -1
        
class LinkedListNode:
    def __init__(self,value=0,next=None,last=None):
        self.value  = value
        self.next = next
        self.last = last
    def getValue(self):
        return self.value
    def setValue(self,item):
        self.value = item        
        

if __name__ == '__main__':
    list2 = ["Hello"]
    print(list2[0][0])
    dictParen = {'(': ')', '{': '}', '[': ']'}
    openParen = list(dictParen.keys())
    print(openParen[0])
    pracDeque = deque()

    #pushing to either side is constant
    pracDeque.appendleft(1)
    pracDeque.append(2)

    for index,element in enumerate(pracDeque):
        print("linear search to access element ", element)
    
    pracDeque.popleft()
    pracDeque.pop()

    list2 = [1,2,3,4,5,6, 10, 15, 20, 45]
    #sort accorindding to some parameter in n * log(n) time from lowest to highest 
    list2.sort()
    print(list2)
    largestElement = list2[-1]
    print('the largest element is ')

    indexOFElm = binarySearch(list2,0,len(list2)-1,15)
    print("search for element in log(n) time ", indexOFElm)
    
    list2 = [3,5,6,1,32,11]
    #min heaps are created in O(n) time 
    heapq.heapify(list2)
    ##access smallest element in constant time
    smallElement = list2[0]
    print('the smallest element is ', smallElement )
    #push/pop in log(n) time 
    #put new element and reorders
    heapq.heappush(list2,5)
    #removes smallest element
    heapq.heappop(list2)
    print('the smallest element is ', list2[0])

    quote = 'Let it be, let it be, let it be'

    # first occurance of 'let it'(case sensitive)
    result = quote.find('let it')
    print("Substring 'let it':", result)

    # find returns -1 if substring not found
    result = quote.find('small')
    print("Substring 'small ':", result)

    # How to use find()
    if (quote.find('be,') != -1):
        print("Contains substring 'be,'")
    else:
        print("Doesn't contain substring")

    #find function works in O(n*m) so useless 
    string2  = 'hello world I am nikhil'
    #substring, start, end and gives index of first occurence or -1 if not found
    search1 = string2.find('hello',0,-1)
    print('first occurence of hello is ', search1)

    #use set to with constant look up times to see if an item exists 
    list3 = [4,3,2,1,34,6,9]

    #O(n) creation times
    quickSearch = set(list3)

    #find if any elements have a difference of two
    pairsOfTuples  = set()
    k = 2
    #search through set in constant time 
    for index,element in enumerate(quickSearch):
        #use constant look up times to find element 
        if element + k in quickSearch:
            tupleSend  = (element, element + k)
            #use constant append time to append to set 
            pairsOfTuples.add(tupleSend)
        search2  = element - k
        if element - k in quickSearch:
            #only get unique tuples because of constant look up times
            tupleSend = (element - k, element)
            pairsOfTuples.add(tupleSend)
    
    for index,element in enumerate(pairsOfTuples):
        print('a pair of a differnece of ', k , " is ", element)
    
    #creating objects of linked lists
    node1 = LinkedListNode(5)
    node2 = LinkedListNode(10,node1)
    node1.next = node2
    node3 = LinkedListNode(15,None,node2)
    node2.next = node3
    #iteration with linked list objects
    while(node1 != None):
        print(node1.getValue())
        #change node object and move to next node
        node1 = node1.next
    








    






