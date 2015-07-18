.SILENT:
.PHONY: all check_bii configure build test clean
default: all

all: test

bii:
	bii init -L

find: bii
	bii find

configure: bii
	bii cpp:configure

build: bii
	bii build

test: bii
	bii test

coverage: bii
	bii cpp:configure -DFRACKDB_COVERAGE=ON
	bii build --target coverage -- -s

clean: bii
	bii clean
