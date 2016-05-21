package main

import (
	"log"

	"github.com/tarm/serial"
	"net/http"
	"net/url"
	"os"
)

func main() {
	// "/dev/cu.usbmodem1421"
	c := &serial.Config{Name: os.Args[2], Baud: 9600}
	s, err := serial.OpenPort(c)
	if err != nil {
		log.Fatal(err)
		return
	}

	for true {
		buf := make([]byte, 128)
		n, err := s.Read(buf)
		if err != nil {
			log.Fatal(err)
			return
		}

		log.Printf("%q", buf[:n])

		resp, err := http.PostForm(os.Args[3], url.Values{"value": buf, "id": {"123-123-123"}})
		if err != nil {
			log.Fatal(err)
			return
		}
	}
}
