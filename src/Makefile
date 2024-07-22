CC = g++
CPPFLAGS = --std=c++17 --language=c++ -Wall -Werror -Wextra
TESTFLAGS = -lgtest
GCOV_FLAGS = -fprofile-arcs -ftest-coverage -lgcov
TESTFILES = ../tests/main_test.cpp ../tests/functional_tests/*.cpp
LIBFILES = ./containers/*

all: test
	./test

test: clean
	$(CC) $(CPPFLAGS) $(TESTFILES) $(TESTFLAGS) -o test

clean:
	rm -f ./test

check:
	@cppcheck --enable=all --suppress=missingIncludeSystem $(LIBFILES) $(TESTFILES)
# @clang-format -n -style=google $(LIBFILES) $(TESTFILES)

leaks:
	@valgrind --tool=memcheck --leak-check=yes --leak-check=full --show-leak-kinds=all ./test