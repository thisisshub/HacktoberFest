  // Writing main function of the program
fun main(args: Array<String>)
{   // take input number from the user
    higherfunction(lambda)
    val num = Integer.valueOf(readLine())
    val factorial= findfact(num)
    println("The factorial of $num is $factorial")
    }

               // function to find factorial
fun findfact(num: Int): Long{
    if(num >=1)
        return num*findfact(num-1)
    else
        return 1
}

               //lambda expression
var lambda={print("Enter the number to find factorial: ")}
//higher order function
fun higherfunction(lmbd: () -> Unit){
    lmbd()
}
