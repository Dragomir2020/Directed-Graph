
# Directed-Graph  [![Build Status](https://travis-ci.org/Dragomir2020/Directed-Graph.svg?branch=master)](https://travis-ci.org/Dragomir2020/Directed-Graph)   [![Coverage Status](https://coveralls.io/repos/github/Dragomir2020/Directed-Graph/badge.svg?branch=master)](https://coveralls.io/github/Dragomir2020/Directed-Graph?branch=master)


- Directed Graph Implemented in c++
- Templated class to accept int and strings
- Each vertex is a node
- Nodes have linked lists of vertexes the given vertex points to
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

# Using Directed-Graph
## Member functions
- DirectedGraph(unsigned int maxVertices);
- ~DirectedGraph();
- DirectedGraph(const DirectedGraph& other);
- bool isEmpty() const;
- unsigned int numberVertices() const;
- unsigned int maxVertices() const;
- unsigned int numberEdges() const;
- bool isFull() const;
- bool edgeExists(T vertOne, T vertTwo) const;
- bool completeGraph() const; //All vertices must have N-1 edges
- void insertVertex(T thing);
- void insertEdge(T vertOne, T vertTwo);
- void removeEdge(T vertOne, T vertTwo); //Checks whether edge exists first
- void removeVertex(T thing);
- void clearTable();

# TODO
- Implement member functions in DirectedGraph.cpp
- Write more tests in DirectedGraph_test.h
