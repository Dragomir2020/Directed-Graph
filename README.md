
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
- DirectedGraph(unsigned int maxVertices); //Constructor
- DirectedGraph(const DirectedGraph& other); //Copy constructor
- bool isEmpty() const; //checks whether graph is empty
- unsigned int numberVertices() const; //Returns number of vertices
- unsigned int maxVertices() const; //Returns max number of vertices
- unsigned int numberEdges() const; //Returns number of edges
- bool isFull() const; //Returns true if table is full meaning max number of vertices
- bool edgeExists(T vertOne, T vertTwo) const; //Returns true if edge exists for given vertex
- bool completeGraph() const; //Returns true if all vertices must have N-1 edges
- void insertVertex(T thing); //Inserts vertex
- void insertEdge(T vertOne, T vertTwo); //Inserts from vertex 1 to 2
- void removeEdge(T vertOne, T vertTwo); //Checks whether edge exists between vertex 1 and 2
- void removeVertex(T thing); //Removes vertex and any given edges
- void clearTable(); //Clears all vertices

# TODO
- Implement member functions in DirectedGraph.cpp
- Write more tests in DirectedGraph_test.h
