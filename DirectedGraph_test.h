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

class DirectedGraphtest : public CxxTest::TestSuite {
public:

  void test0() {
    DirectedGraph<string> a(2);
    TS_ASSERT_EQUALS(a.maxVertices(), 2);
  }
  
  void test1() {
    DirectedGraph<string> a(2);
	a.insertVertex("A");
    TS_ASSERT_EQUALS(a.numberVertices(), 1);
  }
  
  void test2() {
    DirectedGraph<string> a(2);
	a.insertVertex("A");
	a.insertVertex("B");
    TS_ASSERT_EQUALS(a.numberVertices(), 2);
  }
  
  void test3() {
    DirectedGraph<string> a(2);
	a.insertVertex("A");
	a.insertVertex("B");
	a.insertVertex("C");
    TS_ASSERT_EQUALS(a.numberVertices(), 2);
  }
  
  void test4(){
	  DirectedGraph<int> a(2);
	  TS_ASSERT_EQUALS(a.numberVertices(), 0);
	  TS_ASSERT_EQUALS(a.maxVertices(), 2);
  }
  
  void test5(){
	  DirectedGraph<int> a(2);
	  a.insertVertex(1);
	  TS_ASSERT_EQUALS(a.numberVertices(), 1);
	  TS_ASSERT_EQUALS(a.maxVertices(), 2);
  }
  
  void test6(){
	  DirectedGraph<int> a(2);
	  a.insertVertex(1);
	  a.insertVertex(2);
	  a.insertVertex(3);
	  TS_ASSERT_EQUALS(a.numberVertices(), 2);
	  TS_ASSERT_EQUALS(a.maxVertices(), 2);
  }
  void test7(){
	  DirectedGraph<int> a(2);
	  a.insertVertex(1);
	  a.insertVertex(1);
	  TS_ASSERT_EQUALS(a.numberVertices(), 1);
	  TS_ASSERT_EQUALS(a.maxVertices(), 2);
  }
  //TEST insertEdge
  void test8(){
	  DirectedGraph<string> a(2);
	  a.insertEdge("A","B");
	  TS_ASSERT_EQUALS(a.maxVertices(), 2);
  }
  void test9(){
	  DirectedGraph<string> a(2);
	  a.insertEdge("A","B");
	  //TS_ASSERT_EQUALS(a.vertexEdges("A"), 0);
	  TS_ASSERT_EQUALS(a.maxVertices(), 2);
  }
  void test10(){
	  DirectedGraph<string> a(2);
	  a.insertVertex("A");
	  a.insertVertex("B");
	  a.insertEdge("A","B");
	  //TS_ASSERT_EQUALS(a.vertexEdges("A"), 0);
	  //TS_ASSERT_EQUALS(a.vertexEdges("A"), 1);
	  TS_ASSERT_EQUALS(a.maxVertices(), 2);
  }
  
};

class DirectedGraphRemove : public CxxTest::TestSuite {
public:
  
  void Remove1() {
    DirectedGraph<string> a(10);
    TS_ASSERT_EQUALS(a.numberVertices(), 2);
  }
  
};

#endif
