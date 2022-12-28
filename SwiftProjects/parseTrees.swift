var x:Int = 0
var y:Int = 5
var z:Int = 3

repeat {
    if (x<y) {
        print(x)
        x = x + 1
    }
} while (x<z)


var myDictionary:[Int:String] = [1:"Gold", 2:"Silver", 3:"Bronze"]
print("What place did you finish in the race?")
var place = readLine()
var thePlace = myDictionary[Int(place!)!]
print("You get the \(thePlace!)!")


// var arr: [Int] = [1,2,3]
// var arr2: [Int] = [4,5,6]
// Jeff:
//  for elem in arr
//  {
//  for elem2 in arr2
//  {
//  if (elem == 3 && elem2 == 5)
//  {
//  break Jeff
//  }
//  print(elem, elem2)
//  }
//  }