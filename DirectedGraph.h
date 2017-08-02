#ifndef DIRECTEDGRAPH_H
#define DIRECTEDGRAPH_H

#include <iostream>
#include <stdexcept>

#include "LinkedBag.cpp"

using namespace std;


enum node_state {EMPTY, OCCUPIED, REMOVED};

template <class T>
struct item_t {
	T vertex;
	unsigned int number_edges;
	LinkedBag<T> *data;
	node_state state;
};

template <class T>
class DirectedGraph {

public:
	DirectedGraph(unsigned int maxVertices);

	~DirectedGraph();

	DirectedGraph(const DirectedGraph& other);
	
	DirectedGraph<T> operator= (const DirectedGraph& other);

	bool isEmpty() const;

	unsigned int numberVertices() const;
	
	unsigned int maxVertices() const;
	
	unsigned int totalEdges() const;
	
	unsigned int vertexEdges(T vertex) const;
	
	int vertexExists(T vertex) const; //Return -1 if DNE

	bool isFull() const;
	
	bool edgeExists(T vertOne, T vertTwo) const;
	
	bool completeGraph() const; //All vertices must have N-1 edges

	void insertVertex(T thing);
	
	void insertEdge(T vertOne, T vertTwo);

	void removeEdge(T vertOne, T vertTwo); //Checks whether edge exists first
	
	void removeVertex(T thing);

	void clearGraph();
	
//Private data types and member functions
private:
	unsigned int number_vertices;
	unsigned int total_edges;
	unsigned int max_vertices;
	item_t<T>* table;
};


#endif
