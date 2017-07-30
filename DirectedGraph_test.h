#ifndef DIRECTEDGRAPH_TEST_H
#define DIRECTEDGRAPH_TEST_H

#include "DirectedGraph.cpp"
#include <stdexcept>
#include <string>
// Needed for space removal.
#include <sstream>
#include <algorithm>
#include <cxxtest/TestSuite.h>
#include <ctime>

using namespace std;

// This requires CxxTest to be installed!
// For this CPPVideos example, navigate your terminal to CPPVideos and type:
// git submodule add https://github.com/CxxTest/cxxtest.git
// This will add the public CxxTest repository INSIDE the current repo.
// The current Makefile in this directory assumes cxxtest is a folder one
// level down.

class DirectedGraphInsertSizeCap : public CxxTest::TestSuite {
public:

  void testEmpty() {
    DirectedGraph<string> a(2);
    TS_ASSERT_EQUALS(a.maxVertices(), 2);
  }
  
  void insertOne() {
    DirectedGraph<string> a(2);
	a.insertVertex("A");
    TS_ASSERT_EQUALS(a.numberVertices(), 1);
  }
  
  void insertTwo() {
    DirectedGraph<string> a(2);
	a.insertVertex("A");
	a.insertVertex("B");
    TS_ASSERT_EQUALS(a.numberVertices(), 2);
  }
  
  void insertThree() {
    DirectedGraph<string> a(2);
	a.insertVertex("A");
	a.insertVertex("B");
	a.insertVertex("C");
    TS_ASSERT_EQUALS(a.numberVertices(), 2);
  }
  
};

class DirectedGraphRemove : public CxxTest::TestSuite {
public:
  
  void insertThree() {
    DirectedGraph<string> a(2);
	a.insertVertex("A");
	a.insertVertex("B");
	a.insertVertex("C");
    TS_ASSERT_EQUALS(a.numberVertices(), 2);
  }
  
};

#endif
