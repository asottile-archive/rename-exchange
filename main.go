package main

import (
	"fmt"
	"log"
	"os"
	"strings"

	"golang.org/x/sys/unix"
)

func hasHelp(args []string) bool {
	for _, arg := range args {
		if strings.HasPrefix(arg, "-") {
			return true
		}
	}
	return false
}

func main() {
	if hasHelp(os.Args[1:]) {
		fmt.Printf("usage: %s PATH1 PATH2\n", os.Args[0])
		os.Exit(0)
	} else if len(os.Args) != 3 {
		fmt.Print("error: expected two arguments\n\n")
		fmt.Printf("usage: %s PATH1 PATH2\n", os.Args[0])
		os.Exit(1)
	}

	err := unix.Renameat2(
		unix.AT_FDCWD,
		os.Args[1],
		unix.AT_FDCWD,
		os.Args[2],
		unix.RENAME_EXCHANGE,
	)
	if err != nil {
		log.Fatal(err)
	}
}
