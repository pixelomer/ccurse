all: ccurse
ccurse: main.cc
	$(CXX) -std=c++11 -Wall -Wextra -Wpedantic -Werror -O3 -o $@ $^

.PHONY: all
