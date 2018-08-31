package main 

import "bufio"
import "os"
import "fmt"
import "sort"

func main() {
	var n, k, res int
	in := bufio.NewReader(os.Stdin)
	fmt.Fscan(in, &n)
	a := make([]int, n, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}
	sort.Ints(a)

	k = 0
	for i := 0; i < n - 1; i++ {
		a[i] = a[i+1] - a[i]
		k = gcd(k, a[i])
	}

	res = 0
	if (k != 0) {
		for i := 0; i < n - 1; i++ {
		    res += a[i] / k
		}
		res -= n - 1
	}
	
	fmt.Println(res)
}

func gcd(a, b int) int {
    var result int
    if (b == 0) {
        return a
    }
    result = gcd(b, a % b)
    return result
}
