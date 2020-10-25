package main

import "fmt"

func fibonacci(int n){
    list :=[n]int
    list[0] = 0
    list[1] = 1
    for i := 2; i <= n; i++ {
        list[i] = append(list[i], list[i-1]+list[i-2])
    }
    fmt.Println(list)
}

func main(){
    var n int
    fmt.Println("Enter a number")
    fmt.Scanln(&n)
    fibonacci(n)
}
