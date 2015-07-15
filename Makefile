.SILENT:
.PHONY: all check_bii configure build test clean
default: all

all: test

check_bii:
	`which bii 2>/dev/null` || (echo "Biicode must be installed" && exit 1)

.bii_init: check_bii
	bii setup:cpp && bii init -L && touch .bii_init

configure: .bii_init
	bii cpp:configure

build: configure
	bii build

test: build
	bii test

clean: check_bii
	bii clean
