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
    TS_ASSERT_THROWS_ANYTHING(a.insertVertex("C"););
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
	  TS_ASSERT_THROWS_ANYTHING(a.insertVertex(3););
  }
  void test7(){
	  DirectedGraph<int> a(2);
	  a.insertVertex(1);
	  a.insertVertex(1);
	  a.insertVertex(2);
	  TS_ASSERT_EQUALS(a.numberVertices(), 2);
	  TS_ASSERT_EQUALS(a.maxVertices(), 2);
  }
  
};



class DirectedGraphInsertEdge : public CxxTest::TestSuite {
public:
	
	void testInsertEdge0() {
  	  DirectedGraph<string> a(4);
  	  a.insertVertex("A");
  	  a.insertVertex("B");
  	  a.insertEdge("A","B");
	  TS_ASSERT_EQUALS(a.edgeExists("A","B"), 1);
	}
    void testInsertEdge1(){
  	  DirectedGraph<string> a(2);
  	  TS_ASSERT_THROWS_ANYTHING(a.insertEdge("A","B"););
    }
    void testInsertEdge2(){
  	  DirectedGraph<string> a(2);
  	  a.insertVertex("A");
  	  TS_ASSERT_THROWS_ANYTHING(a.insertEdge("A","B"););
    }
    void testInsertEdge3(){
  	  DirectedGraph<string> a(2);
  	  a.insertVertex("B");
  	  TS_ASSERT_THROWS_ANYTHING(a.insertEdge("A","B"););
    }
    void testInsertEdge4(){
  	  DirectedGraph<string> a(2);
  	  a.insertVertex("A");
  	  a.insertVertex("B");
  	  a.insertEdge("A","B");
  	  TS_ASSERT_EQUALS(a.totalEdges(), 1);
  	  TS_ASSERT_EQUALS(a.vertexEdges("A"), 1);
    }
    void testInsertEdge5(){
  	  DirectedGraph<string> a(4);
  	  a.insertVertex("A");
  	  a.insertVertex("B");
  	  a.insertVertex("C");
  	  a.insertEdge("A","B");
  	  a.insertEdge("A","C");
  	  a.insertEdge("B","C");
  	  TS_ASSERT_EQUALS(a.totalEdges(), 3);
  	  TS_ASSERT_EQUALS(a.vertexEdges("A"), 2);
    }
    //Do I really want all these assertions being thrown
    void testInsertEdge6(){
  	  DirectedGraph<string> a(4);
  	  a.insertVertex("A");
  	  a.insertVertex("B");
  	  a.insertVertex("C");
  	  a.insertEdge("A","B");
  	  TS_ASSERT_THROWS_ANYTHING(a.insertEdge("A","B"););
  	  a.insertEdge("A","C");
  	  TS_ASSERT_THROWS_ANYTHING(a.insertEdge("A","C"););
  	  a.insertEdge("B","C");
  	  TS_ASSERT_EQUALS(a.totalEdges(), 3);
  	  TS_ASSERT_EQUALS(a.vertexEdges("A"), 2);
    }
	
};

class DirectedGraphEdgeExists : public CxxTest::TestSuite {
public:
	
	void testEdgeExists0() {
  	  DirectedGraph<string> a(4);
  	  a.insertVertex("A");
  	  a.insertVertex("B");
  	  a.insertEdge("A","B");
	  TS_ASSERT_EQUALS(a.edgeExists("A","B"), 1);
	}
	
};

class DirectedGraphComplete : public CxxTest::TestSuite {
public:
	
	void testComplete0() {
  	  DirectedGraph<string> a(2);
  	  a.insertVertex("A");
  	  a.insertVertex("B");
  	  a.insertEdge("A","B");
	  a.insertEdge("B","A");
	  TS_ASSERT_EQUALS(a.completeGraph(), 1);
	}
	void testComplete1() {
  	  DirectedGraph<string> a(4);
  	  a.insertVertex("A");
  	  a.insertVertex("B");
  	  a.insertEdge("A","B");
	  a.insertEdge("B","A");
	  TS_ASSERT_EQUALS(a.completeGraph(), 1);
	}
	void testComplete2() {
  	  DirectedGraph<string> a(4);
  	  a.insertVertex("A");
  	  a.insertVertex("B");
	  a.insertVertex("C");
  	  a.insertEdge("A","B");
	  a.insertEdge("A","C");
	  a.insertEdge("B","A");
	  a.insertEdge("B","C");
	  a.insertEdge("C","A");
	  a.insertEdge("C","B");
	  TS_ASSERT_EQUALS(a.completeGraph(), 1);
	}
	void testComplete3() {
  	  DirectedGraph<string> a(4);
  	  a.insertVertex("A");
  	  a.insertVertex("B");
	  a.insertVertex("C");
  	  a.insertEdge("A","B");
	  a.insertEdge("A","C");
	  a.insertEdge("B","A");
	  a.insertEdge("B","C");
	  a.insertEdge("C","A");
	  TS_ASSERT_EQUALS(a.completeGraph(), 0);
	}
};

class DirectedGraphClear : public CxxTest::TestSuite {
public:
	
	void testClear0() {
    	  DirectedGraph<string> a(2);
    	  a.insertVertex("A");
    	  a.insertVertex("B");
		  a.insertEdge("A","B");
		  a.insertEdge("B","A");
		  TS_ASSERT_EQUALS(a.numberVertices(), 2);
		  TS_ASSERT_EQUALS(a.totalEdges(), 2);
		  TS_ASSERT_EQUALS(a.vertexEdges("A"), 1);
		  TS_ASSERT_EQUALS(a.isFull(), 1);
		  TS_ASSERT_EQUALS(a.completeGraph(), 1);
		  a.clearGraph();
		  TS_ASSERT_EQUALS(a.numberVertices(), 0);
		  TS_ASSERT_EQUALS(a.totalEdges(), 0);
		  TS_ASSERT_THROWS_ANYTHING(a.vertexEdges("A"));
		  TS_ASSERT_EQUALS(a.isFull(), 0);
		  TS_ASSERT_EQUALS(a.completeGraph(), 1);
	}
	
};

class DirectedGraphCopy : public CxxTest::TestSuite {
public:
	
	void testCopy0() {
  	      DirectedGraph<string> a(2);
  	      a.insertVertex("A");
  	      a.insertVertex("B");
	      a.insertEdge("A","B");
		  a.insertEdge("B","A");
		  DirectedGraph<string> b(a);
		  TS_ASSERT_EQUALS(b.numberVertices(), 2);
		  TS_ASSERT_EQUALS(b.totalEdges(), 2);
		  TS_ASSERT_EQUALS(b.vertexEdges("A"), 1);
		  TS_ASSERT_EQUALS(b.isFull(), 1);
		  TS_ASSERT_EQUALS(b.completeGraph(), 1);
	}
	void testCopy1() {
  	      DirectedGraph<string> a(2);
		  DirectedGraph<string> b(a);
		  TS_ASSERT_EQUALS(b.numberVertices(), 0);
		  TS_ASSERT_EQUALS(b.totalEdges(), 0);
		  TS_ASSERT_EQUALS(b.maxVertices(), 2);
	}
	void testCopy2() {
		  DirectedGraph<string> a(2);
		  a.insertVertex("D");
		  a.insertVertex("E");
		  DirectedGraph<string> b(a);
	      TS_ASSERT_EQUALS(b.numberVertices(), 2);
	      TS_ASSERT_EQUALS(b.totalEdges(), 0);
	}
	
};


#endif
