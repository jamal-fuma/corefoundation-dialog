CXX=/usr/bin/g++
LDFLAGS=-framework CoreFoundation
CFLAGS=-arch x86_64
CPPFLAGS=-I./include

NativeOSX.app/Content/MacOS/NativeOSX: build NativeOSX NativeOSX.app
	mv NativeOSX NativeOSX.app/Contents/MacOS/NativeOSX

NativeOSX.app: NativeOSX
	mkdir -pv NativeOSX.app/Contents/MacOS

NativeOSX: build/src_main.o
	${CXX} ${LDFLAGS} ${CFLAGS} -o $@ $<

build/src_main.o : src/main.cpp include/Apple.h
	${CXX} ${CFLAGS} ${CPPFLAGS} -c -o $@ $<

clean:
	rm -rvf NativeOSX.app
	rm -rvf build

build:
	mkdir -pv build

units: NativeOSX.app
	open NativeOSX.app
