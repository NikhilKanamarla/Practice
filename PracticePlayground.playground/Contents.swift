import UIKit
// just some basic review
var str = "Hello, playground"
print (str)
var hello = "Hello World"
print (hello)
var age = 18
if(age == 18) {
    print("my age is ", age)
} else {
    print("your still a minor")
}
let name = "Nikhil"
var num = 5*2/3%5
print(num)
while (num < 5) {
    num = num + 1
    print("Still going")
}
var buildingNames: [String] = ["EECS Building", "Bob Byester Building", "Mason Hall"]

for index in buildingNames {
    print (index)
}

class eecs183 {
    // declare variable and include type
    var numMeet: Int
    var grade: Int
    init(numMeet: Int, grade: Int) {
        self.numMeet = numMeet
        self.grade = grade
    }
    func setGrade(grade1:Int) {
        grade = grade1
    }
    // -> type indicates return type
    func getGrade() -> Int {
        return grade
    }
}




