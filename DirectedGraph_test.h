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

class DirectedGraphRemoveEdge : public CxxTest::TestSuite {
public:
	
	void testRemoveEdge1() {
	      DirectedGraph<string> a(2);
	      a.insertVertex("D");
	      a.insertVertex("E");
	      a.insertEdge("D","E");
	      a.insertEdge("E","D");
	      a.removeEdge("E","D");
	      TS_ASSERT_EQUALS(a.numberVertices(), 2);
	      TS_ASSERT_EQUALS(a.totalEdges(), 1);
	      TS_ASSERT_EQUALS(a.vertexEdges("D"), 1);
		  TS_ASSERT_EQUALS(a.vertexEdges("E"), 0);
	}
	void testRemoveEdge2() {
	      DirectedGraph<string> a(2);
	      a.insertVertex("D");
	      a.insertVertex("E");
	      a.insertEdge("D","E");
	      a.insertEdge("E","D");
	      a.removeEdge("E","D");
		  a.insertEdge("E","D");
	      TS_ASSERT_EQUALS(a.numberVertices(), 2);
	      TS_ASSERT_EQUALS(a.totalEdges(), 2);
	      TS_ASSERT_EQUALS(a.vertexEdges("D"), 1);
		  TS_ASSERT_EQUALS(a.vertexEdges("E"), 1);
	}
	void testRemoveEdge3() {
	      DirectedGraph<int> a(50);
		  for(int i=0; i<40; i++){
		  	a.insertVertex(i);
			a.insertVertex(i+1);
			a.insertEdge(i,i+1);
		  }
		  for(int i=0; i<40; i++){
		  	a.removeEdge(i,i+1);
		  }
	      TS_ASSERT_EQUALS(a.numberVertices(), 41);
	      TS_ASSERT_EQUALS(a.totalEdges(), 0);
	      for(int i=0; i<40; i++){
		  	TS_ASSERT_EQUALS(a.vertexEdges(i), 0);
		  }
	}
	
};

class DirectedGraphRemoveNode : public CxxTest::TestSuite {
public:
	
	void testRemoveNode0() {
		DirectedGraph<string> a(5);
		a.insertVertex("A");
		a.insertVertex("B");
		a.insertVertex("C");
		a.insertVertex("D");
		a.insertEdge("A","B");
		a.insertEdge("A","D");
		a.insertEdge("C","A");
		a.insertEdge("C","B");
		a.insertEdge("B","D");
		//Now remove vertex
		a.removeVertex("D");
        TS_ASSERT_EQUALS(a.numberVertices(), 3);
        TS_ASSERT_EQUALS(a.totalEdges(), 3);
        TS_ASSERT_EQUALS(a.vertexEdges("A"), 1);
	    TS_ASSERT_EQUALS(a.vertexEdges("C"), 2);
		TS_ASSERT_EQUALS(a.vertexEdges("B"), 0);
	}
	void testRemoveNode1() {
		DirectedGraph<string> a(5);
		a.insertVertex("A");
		a.insertVertex("B");
		a.insertVertex("C");
		a.insertEdge("A","B");
		a.insertEdge("A","C");
		a.insertEdge("C","A");
		a.insertEdge("C","B");
		a.insertEdge("B","C");
		a.insertEdge("B","A");
		a.removeVertex("A");
        TS_ASSERT_EQUALS(a.numberVertices(), 2);
        TS_ASSERT_EQUALS(a.totalEdges(), 2);
		TS_ASSERT_THROWS_ANYTHING(a.removeVertex("A"));
        TS_ASSERT_EQUALS(a.vertexEdges("C"), 1);
	    TS_ASSERT_EQUALS(a.vertexEdges("B"), 1);
	}
	void testRemoveNode2() {
		DirectedGraph<string> a(3);
		a.insertVertex("A");
		a.insertVertex("B");
		a.insertVertex("C");
		a.removeVertex("A");
		a.removeVertex("B");
		a.removeVertex("C");
        TS_ASSERT_EQUALS(a.numberVertices(), 0);
        TS_ASSERT_EQUALS(a.totalEdges(),0);
		TS_ASSERT_THROWS_ANYTHING(a.removeVertex("A"));
        TS_ASSERT_THROWS_ANYTHING(a.vertexEdges("C"));
	    TS_ASSERT_THROWS_ANYTHING(a.vertexEdges("B"));
	}
	
};

class DirectedGraphAssignment: public CxxTest::TestSuite {
public:
	
	void testAssignment0() {
		DirectedGraph<string> a(3);
		DirectedGraph<string> b(4);
		a = b;
		TS_ASSERT_EQUALS(a.maxVertices(), 4);
	}
	void testAssignment1() {
		DirectedGraph<string> a(3);
		DirectedGraph<string> b(4);
		b.insertVertex("A");
		a = b;
		TS_ASSERT_EQUALS(a.numberVertices(), 1);
	}
	void testAssignment2() {
		DirectedGraph<int> a(100);
		DirectedGraph<int> b(100);
		b.insertVertex(0);
		for(int i=0; i<99; i++){
			b.insertVertex(i+1);
			b.insertEdge(i,i+1);
		}
		//Copy constructor
		a = b;
        TS_ASSERT_EQUALS(a.numberVertices(), 100);
        TS_ASSERT_EQUALS(a.totalEdges(),99);
	}
	
};


#endif
