CC = g++
CPPFLAGS = -std=c++17 -Wall -Werror -Wextra
TESTFLAGS = -lgtest
GCOV_FLAGS = -fprofile-arcs -ftest-coverage -lgcov
TESTFILES = ../tests/main_test.cpp ../tests/functional_tests/*.cpp

all: test
	./test

test: clean
	$(CC) $(CPPFLAGS) $(TESTFILES) $(TESTFLAGS) -o test

clean:
	rm -f ./test