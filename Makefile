.SILENT:
.PHONY: all check_bii configure build test clean
default: all

all: test

bii:
	bii init -L && touch .bii_init

configure: bii
	bii cpp:configure

build: configure
	bii build

test: build
	bii test

clean: check_bii
	bii clean
