let name = readLine()

print("You like \(name!)")

var x:Int = 0
var y:Int = 3
var z:Int = 5

repeat {
    if x<y {
        print(x)
        x = x + 1
    }
} while (x<z)