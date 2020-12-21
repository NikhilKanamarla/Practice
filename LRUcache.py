class LRUCache:
    
    def __init__(self, capacity: int):
        self.capacity = capacity 
        self.hashMap = dict()
        self.queue = []

    def get(self, key: int) -> int:
        returnValue = self.hashMap.get(key,-1)
        if(len(self.queue) == self.capacity and returnValue != -1):
            self.queue.pop(0)
            self.queue.append(key)
        return returnValue

    def put(self, key: int, value: int) -> None:
        #check if key exists and update value
        check = self.hashMap.get(key,-1)
        if(check != -1): 
            self.hashMap[key] = value
            if(len(self.queue) == self.capacity):
                self.queue.pop(0)
        else:
            if(len(self.hashMap) < self.capacity and len(self.queue) < self.capacity):
                self.hashMap[key] = value
                self.queue.append(key)
            else:
                keyLeastCommon = self.queue[0]
                self.queue.pop(0)
                self.hashMap.pop(keyLeastCommon)
                self.hashMap[key] = value
                self.queue.append(key)