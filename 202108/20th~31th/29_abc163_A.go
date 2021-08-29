package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var sc = bufio.NewScanner(os.Stdin)

func scanInt() float64 {
	sc.Scan()
	f32, err := strconv.ParseFloat(sc.Text(), 64)
	if err != nil {
		panic(err)
	}
	return f32
}

const pi float64 = 3.1415926

// Go(1.14.1)
func main() {
	sc.Split(bufio.ScanWords)
	r := scanInt()
	ans := 2 * r * pi
	fmt.Println(ans)
}
