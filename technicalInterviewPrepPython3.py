import sys
import threading
import os
from collections import deque, Counter, OrderedDict
import heapq
import string


if __name__ == '__main__':
    newItem = deque()
    newItem.append(1)
    newItem.popleft()
    #gets counts of an item in a dictionary 
    items = [1,2,3,3,4,2,7,9,0]
    dictCOunts = Counter(items)
    print(dictCOunts)
    hashmap = dict()
    hashmap[1] = [1,0]
    hashmap[1][1] = hashmap[1][1] + 1
    hashmap.pop(1)
    print(hashmap.get(1,-1))

    LRUcache = OrderedDict()
    LRUcache[0] = 1
    #move to end to signify most used
    LRUcache.move_to_end(0,last=True)
    #pop from front (least used)
    LRUcache.popitem(last=False)