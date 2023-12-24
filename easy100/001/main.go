package main

import "fmt"

func main() {
	var a, b int
	fmt.Scan(&a, &b)
	var ans, taps int = 0, 1
	for taps < b {
		taps += a - 1
		ans++
	}
	fmt.Println(ans)
}
