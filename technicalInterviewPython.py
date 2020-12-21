import sys
import threading
import os
from collections import deque, Counter
import heapq

def takeFirst(elem):
    return elem[0]

def binarySearch(array, startingIndex, endIndex, searchValue):
    #iterative version with while loop
    while(startingIndex <= endIndex):
        ##find middle index
        middleIndex = (startingIndex + endIndex) // 2
        #find if middle value = search value
        if(array[middleIndex] == searchValue):
            return searchValue
        #find if need to take upper half
        elif(searchValue > array[middleIndex]):
            #array needs to get smaller so add one to middle and make it the start
            startingIndex = middleIndex + 1
        #find if take lower half 
        else:
            #array needs to get smaller so add subtract one from muddle and make it end 
            endIndex = middleIndex - 1
    
    return -1
    

if __name__ == '__main__':
    list =  [10,20,30,40,50]
    #iterate through an array
    for index,element in enumerate(list):
        print("the index is ", index, " the element is ", element)
    #list comprehensions || element -> iteration -> condition
    small_list = [element for element in list if element > 40]
    small_list2 = [element for index,element in enumerate(list) if element > 15]
    print("this a smaller section of a list ", small_list2)
    print("smaller version of list based on condition", small_list)
    #get subsection of list (inclusive start and exlcusive end)
    small_list4 = list[2:4]
    print('smaller section of list using splice ', small_list4)

    #efficient 2D list setup rows and columns 
    arr3 = [[0 for _ in range(2)] for _ in range(3)]
    arr4 = [[0 for _ in range(3)] for _ in range (7)]
    print("2d list ", arr3, arr4)
    arr5 = [[0 for _ in range(10) for _ in range(1)]]
    listCombine = arr3 + arr4

    #constant time operations for lists
    #list access
    lastIndex = arr3[-1]
    print("the value of the last index is ", arr3) 
    #changing valiues
    arr3[0] = 5
    #length
    size = len(arr3)
    #appending and poping from end
    arr3.append(100)
    print('append to end ', arr3)
    arr3.pop()
    print('pop from end ', arr3)

    #linear time operations for lists due to contigous blocks of memory
    #inserting and removing not from last index is linear time
    list2 = [4,3,2,5,10]
    del list2[0]
    list2.insert(0,4)
    #insert (index,value)
    list2.insert(1,3)
    print("linear time insert/delete ", list2)
    #slice
    mini_list = list2[0:3]
    #search
    containment = 5 in mini_list
    print('5 is ', containment)
    #copy 
    otherList = mini_list.copy()
    #max/min
    maxVal = max(list2)
    minVal = min(list2)
    print('the min/max of list2 is ', minVal, " ", maxVal)

    #log linear time operations 
    #sorting default in accending order
    list2.sort()
    print("sorted list in accending order", list2)
    #sort from greatest to least
    list2.sort(reverse=True)
    print("sorted list in decending order ",list2)
    #sort according to some rule
    list3 = [(1,2),(4,5),(100,0)]
    #create functor which takes in one index of values and returns 
    list3.sort(key=takeFirst)
    print("sorted according to some rule ", list3)
    list5 = ['b','d','e','a','z','x','h','n']
    list5.sort()
    print("sorted list of characters ", list5)

    #deque
    #main advantage over list pop/insert in front or back in constant time
    dequeVal = deque([1,2,3,4,5])
    #pop is usually back
    dequeVal.pop()
    #popleft is front
    dequeVal.popleft()
    print("new deque with beginning and end removed ", dequeVal)
    dequeVal.appendleft(1)
    dequeVal.append(5)
    print("restored old deque by appending to end and front ", dequeVal)
    #accessing elements takes linear time most of the time but can get close to O(1)
    element = dequeVal[0]
    print("element from deque takes long time", element)

    #heaps allow access to smallest element in O(1) and insertion/deletion O(log(n)) time and creation of heap takes O(n)
    listHeap = [10,6,3,100]
    #creation
    heapq.heapify(listHeap)
    #pop from front in O(log(n)) time and 
    popped = heapq.heappop(listHeap)
    print('smallest value ', popped)
    heapq.heappush(listHeap,10)
    print("pushing to heap", listHeap)
    #access to smallest value in O(1) time
    smallestVal = listHeap[0]
    heap2 = [3,4,5,6,7,8]
    heapq.heapify(heap2)
    heapq.heappush(heap2, 9)
    list2 = heapq.nlargest(3, heap2)
    for index,element in enumerate(list2):
        print("3 greatest elements ", element)
    print(heapq.nsmallest(3, heap2))


    #hashmaps
    dict = {1:5,3:4,2:5}
    #check if value exists lookup time in O(1)
    store = dict.get(5,'empty')
    store2 = dict.get(7,'empty')
    if(store == 'empty'):
        print("none here")
    #input a key and get value in O(1) time
    value = dict[3]
    print("quick look up time to get this value of ", value)
    #insertion and deletion in O(1) time
    del dict[1]
    dict[1] = 5
    #iterate through dictionary
    for (key,value) in dict.items():
        print("using .items() allows access to ", key, " ", value)
    #check if val in dict in constant time
    present = 5 in dict
    print("is 5 in key of the hash map ", present)
    #counter method returns a dictionary with counts of item
    listToCount = [11,1,4,33,2,2,5,4]
    dictOfCounts = Counter(listToCount)
    print("easy way to get the counts " , dictOfCounts)

    #sets similary to hashmap but no key, value pairs just value
    #sets are unordered, no duplicates, iteration possible but not indexes
    #useful for finding if something exists
    list10 = [1,2,5,6,7,8,10]
    #empty set
    set1 = set()
    #converting a list O((len(list))
    set1 = set(list10)
    #constant time operations
    #insertion,deletion in constant time
    set1.add(100)
    set1.remove(100)
    #constant look up times
    exist = 5 in set1
    print("constant look up time for sets, is 5 here ", exist)
    #union and intersection and difference take up the number of elements in both sets
    set2 = {1,2,3,101,50,75}
    #union means combining both
    set3 = set1.union(set2)
    print("the combined set", set3)
    #intersection is shared values in both
    set4 = set1.intersection(set2)
    print('shared elements in sets include ', set4)
    #difference means elements in one set but not the other
    set5 = set1.difference(set2)
    print("unique elements in set 1 include", set5)
    #iteration is constant and no index access
    for x in set5:
        print("printing elements in set ", x)


    #practice find duplicate element version1
    list = [3,4,10,12,19,1,8,3]
    #O(nlog(n))
    list.sort()
    print("current list ", list)
    prevElement = -1
    #O(n)
    for index,element in enumerate(list):
        if(element == prevElement):
            print('duplicate element found ', element)
        prevElement = element
    #practice find duplicate element version2
    list = [3, 4, 10, 12, 19, 1, 8, 3]
    numOccurencesDict = {}
    #populate dictionary in O(n) time
    for index,element in enumerate(list):
        foundOrNot = numOccurencesDict.get(element,'not found')
        if(foundOrNot == 'not found'):
            numOccurencesDict[element] = 1
        else:
            numOccurencesDict[element] = numOccurencesDict[element] + 1
    #search through dictionary in O(n) time
    for key,value in numOccurencesDict.items():
        if(value > 1):
            print('duplicate item found ', key)
    
    #practice find a value in a unsorted array 
    list = [10,7,5,9,3,25]
    searchValue = 3
    #store value index pairs in a hashmap O(n)
    valIndex = {}
    for index,element in enumerate(list):
        valIndex[element] = index
    #sort the array in O(nlog(n)) 
    list.sort()
    print(list)
    #search the array in O(log(n))
    valueInArray = binarySearch(list,0, len(list)-1,searchValue)
    indexInArray = valIndex[valueInArray]
    print("found index ", indexInArray)
    


