package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var sc = bufio.NewScanner(os.Stdin)

func scanInt() int {
	sc.Scan()
	i, err := strconv.Atoi(sc.Text())
	if err != nil {
		panic(err)
	}
	return i
}

func scanString() string {
	sc.Scan()
	return sc.Text()
}

// Go(1.14.1)
func main() {
	sc.Split(bufio.ScanWords)
	r := scanInt()
	fmt.Println(r)
}
