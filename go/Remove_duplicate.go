package main

import (
	"fmt"
)

func appendCategory(a []string, b []string) []string {

	check := make(map[string]int)
	d := append(a, b...)
	res := make([]string,0)
	for _, val := range d {
		check[val] = 1
	}

	for letter, _ := range check {
		res = append(res,letter)
	}

	return res
}

func main() {
	a := []string{"x", "y", "z"}
	b := []string{"x", "p", "q"}
	c := appendCategory(a, b)
	fmt.Println(c)

}
