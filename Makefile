.SILENT:
.PHONY: all check_bii configure-release configure-debug configure-coverage build test clean
default: all

all: test

bii:
	bii init -L

find: bii
	bii find

configure-release: clean bii
	bii cpp:configure -DCMAKE_BUILD_TYPE=RELEASE

configure-debug: clean bii
	bii cpp:configure -DCMAKE_BUILD_TYPE=DEBUG

configure-coverage: clean bii
	bii cpp:configure -DCMAKE_BUILD_TYPE=DEBUG -DFRACKDB_COVERAGE=ON

build: bii configure-release
	bii build

test: bii configure-debug
	bii test

coverage: bii configure-coverage
	bii build --target coverage -- -s

clean: bii
	bii clean
