
# Directed-Graph  [![Build Status](https://travis-ci.org/Dragomir2020/Directed-Graph.svg?branch=master)](https://travis-ci.org/Dragomir2020/Directed-Graph)    [![Coverage Status](https://coveralls.io/repos/github/Dragomir2020/Hash-Table/badge.svg?branch=master)](https://coveralls.io/github/Dragomir2020/Hash-Table?branch=master)


- Directed Graph Implemented in c++
- Templated class to accept int and strings
## Install cxxtest
- go to https://sourceforge.net/projects/cxxtest/files/cxxtest/
- install folder in directory with code
- Already included in directory and not necessary unless most current version is required
## Make File
- Open make file and change directory path to path where code cxxtest exists
## Install valgrind
- sudo apt-get install valgrind
## Compile Code
- make
- compiles sample code in graphsandbox
- Use this as guide when using header
## Test Code
- make test
## Check for Memory Leaks
- valgrind ./testrunner
## Clean Directory of Compiled Files
- make clean
- must do this to recompile code using make test

# TODO
- Implement member functions
- Write more tests in DirectedGraph_test.h
