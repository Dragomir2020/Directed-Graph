/////////////////////////////
//FILE NAME: DirectedGraph.cpp//
/////////////////////////////

////////////////
//Contributers//
////////////////

///////////////////////////////////////////////

// NAME                   DATE           CHANGE
// Dillon Dragomir        08-28-2017     Initial Commit
// Dillon Dragomir        09-01-2017     Implement more member functions and unit tests
// Dillon Dragomir        09-01-2017     Add copy constructor and assignment operator
// Dillon Dragomir        09-20-2017     Try to resolve memory leaks in assignment 

///////////////////////////////////////////////

////////////////
//DEPENDANCIES//
////////////////

#include "DirectedGraph.h"
#include <cstddef>
#include <stdexcept>
#include <vector>

//Remove
#include <iostream>

//Constructor
template<class T>
DirectedGraph<T>::DirectedGraph(unsigned int maxVertices){
	//Constructor
	max_vertices = maxVertices;
	table = new item_t<T>[maxVertices];
	//Set all elements to NULL and state EMPTY
	for(int i = 0; i < max_vertices; i++){
		table[i].data = NULL;
		table[i].state = EMPTY;
		table[i].number_edges = 0;
	}
	// Initalize size to zero
	number_vertices = 0;
	total_edges = 0;
}
//Deconstructor
template<class T>
DirectedGraph<T>::~DirectedGraph() {
	//Call clear
	clearGraph();
	delete[] table;
	table = NULL;
}
//Copy Constructor
template<class T>
DirectedGraph<T>::DirectedGraph(const DirectedGraph& other){
	//Not correct just initalizing values to NULL
	//These set to zero will catch error if copy constructor logic is broken
	total_edges = 0;//other.total_edges;
	number_vertices = 0;//other.number_vertices;
	max_vertices = other.max_vertices;
	table = new item_t<T>[max_vertices];
	//Set all elements to NULL and state EMPTY
	for(int i = 0; i < max_vertices; i++){
	   if((other.table[i]).state == EMPTY){
		   table[i].data = NULL;
		   table[i].state = EMPTY;
		   table[i].number_edges = 0;
	   }else if (other.table[i].state == OCCUPIED ){
		   number_vertices++;
		   table[i].number_edges = 0;
		   table[i].vertex = (other.table[i]).vertex;
		   //Convert linked bag to vector
   		   vector<T> bagContents  = ((other.table[i]).data)->toVector();
		   //Create new linked bag to copy to
		   LinkedBag<T>* A = new LinkedBag<T>();
   		   for(int j = 0; j < bagContents.size(); j++){
			   //Push back new elements
   		       A->push_back(bagContents[j]);
			   //Add to the size
			   table[i].number_edges += 1;
			   total_edges++;
   		   }
		   (table[i].data) = A;
		   (table[i].state) = OCCUPIED;
	   }else if (other.table[i].state == REMOVED ){
		   number_vertices++;
		   table[i].vertex = (other.table[i]).vertex;
		   //Create new linked bag to copy to
		   LinkedBag<T>* A = new LinkedBag<T>();
		   (table[i].data) = A;
		   (table[i].state) = REMOVED;
		   table[i].number_edges = 0;
	   }
	}
}

//Assignment Operator
template<class T>
DirectedGraph<T> DirectedGraph<T>::operator= (const DirectedGraph& other){ 
	//Number of vertices could be same but different
	if(other.number_vertices == 0){
		return *this;
	} else if(other.number_vertices > max_vertices){
		//Will not fit in new graph
		throw invalid_argument( "EXCEPTION: Will not fit in graph." );
	} else {
       // Assignment Operator
	   int max = max_vertices;
	   clearGraph();
       total_edges = 0;//other.total_edges;//other.total_edges;
   	   number_vertices = 0;//other.number_vertices;//other.number_vertices;
   	   max_vertices = max;
	   //Set copy over all elements
	   for(int i = 0; i < max_vertices; i++){
	       if((other.table[i]).state == EMPTY){
			   table[i].data = NULL;
			   table[i].state = EMPTY;
			   table[i].number_edges = 0;
		   }else if((other.table[i]).state == REMOVED){
			   number_vertices++;
			   table[i].vertex = (other.table[i]).vertex;
			   table[i].data = NULL;
			   (table[i].state) = REMOVED;
			   table[i].number_edges = 0;
		   }else if((other.table[i]).state == OCCUPIED){
			   number_vertices++;
			   table[i].number_edges = 0;
			   table[i].vertex = (other.table[i]).vertex;
			   //Convert linked bag to vector
	   		   vector<T> bagContents  = ((other.table[i]).data)->toVector();
			   //Create new linked bag to copy to
			   LinkedBag<T>* A = new LinkedBag<T>();
	   		   for(int j = 0; j < bagContents.size(); j++){
				   //Push back new elements
	   		       A->push_back(bagContents[j]);
				   //Add to the size
				   table[i].number_edges += 1;
				   total_edges++;
	   		   }
			   (table[i].data) = A;
			   (table[i].state) = OCCUPIED;
	       }
	   }
	   return *this;
    }
}

// returns true if no vertices or edges
template<class T>
bool DirectedGraph<T>::isEmpty() const{
	return (total_edges == 0) && (number_vertices == 0);
}

//Class needs to resolve problems with accessing vertex when it has not been set.
template<class T>
unsigned int DirectedGraph<T>::vertexEdges(T vertex) const{
	
	int exists = vertexExists(vertex);
	if(exists != -1){
		return table[exists].number_edges;
	}else{
		throw invalid_argument( "EXCEPTION: Vertex does not exist." );
	}
}

// returns number of vertices
template<class T>
unsigned int DirectedGraph<T>::numberVertices() const{
	return number_vertices;
}

//returns maximum number of vertices
template<class T>
unsigned int DirectedGraph<T>::maxVertices() const{
	return max_vertices;
}

// returns number of edges
template<class T>
unsigned int DirectedGraph<T>::totalEdges() const{
	return total_edges;
}

//Returns true if reached max vertices
template<class T>
bool DirectedGraph<T>::isFull() const{
	return (number_vertices == max_vertices);
}

// Returns true if edge exists
template<class T>
bool DirectedGraph<T>::edgeExists(T vertOne, T vertTwo) const{
	//Check to make sure vertecies are valid
	if((vertexExists(vertOne) != -1) && (vertexExists(vertTwo) != -1)){
		int index = vertexExists(vertOne);
		//Must be occupied to have edges
		if(table[index].state == OCCUPIED){
			return (table[index].data)->contains(vertTwo);
		}
	}
	return false;
}

//returns true if all vertices are full
template<class T>
bool DirectedGraph<T>::completeGraph() const{
	//All vertices must have N-1 edges
	bool is_full = 1;
	for(int i=0; i < max_vertices; i++){
		if(table[i].state != EMPTY){
			//Should this be number of vertices-1 or just number of vertices
			is_full = is_full && (table[i].number_edges == (number_vertices-1));
		}
	}
	return is_full;
}

//inserts vertex
//THIS CAN BE IMPLEMENTED WITHOUT isFull
template<class T>
void DirectedGraph<T>::insertVertex(T thing){
	//Insert vertex if it doesnt already exist
	if(isFull()){
		//Throw argument if table is full
		throw invalid_argument( "EXCEPTION: No more vertices." );
	} else if(!isFull()){
		//Loop through and find next available node if not full
		for(int i=0; i<max_vertices; i++){
			if(table[i].state == EMPTY){
				(table[i].vertex) = thing;
				table[i].state = REMOVED;
				number_vertices++;
				break;
			}else if(table[i].vertex == thing){
				//If vertex already exists
				break;
			}
		}
    }
}

//Insert Edge
template<class T>
void DirectedGraph<T>::insertEdge(T vertOne, T vertTwo){
	//Insert edge if it doesnt already exist
	if((vertexExists(vertOne) != -1) && (vertexExists(vertTwo) != -1) && (edgeExists(vertOne, vertTwo) == 0)){
		//Means both vertices are valid
		for(int i=0; i < max_vertices; i++){
			if(table[i].vertex == vertOne){
				//Add vertex to linked bag
				if(table[i].state == REMOVED){
					//Create a new linked bag if state == removed
		 		   LinkedBag<T>* A = new LinkedBag<T>();
				   A->add(vertTwo);
		 		   (table[i].data) = A;
		 		   (table[i].state) = OCCUPIED;
				}else if(table[i].state == OCCUPIED){
					//Linked Bag already exists
				    (table[i].data)->add(vertTwo);
			    }
				//Must change number of edges to be data type of Vertex
				table[i].number_edges += 1;
				total_edges++;
				break;
			}
		}
	}else{
		//Throw error if one of the vertex or edges exist
		throw invalid_argument( "EXCEPTION: Vertex DNE or edge alread exists" );
	}
}

//Remove Edge

template<class T>
void DirectedGraph<T>::removeEdge(T vertOne, T vertTwo){
	//Checks whether edge exists first
	if(edgeExists(vertOne, vertTwo)){
		int index = vertexExists(vertOne);
		table[index].data->remove(vertTwo);
		total_edges--;
		table[index].number_edges += -1;
		//Delete linked bag if empty
		if(table[index].number_edges == 0){
	    	(table[index].data)->clear();
			delete table[index].data;
			table[index].data = NULL;
			table[index].state = REMOVED;
		}
	}
}

//Remove vertex
template<class T>
void DirectedGraph<T>::removeVertex(T thing){
	//Checks whether vertex exists then removes it
	int index = vertexExists(thing);
	if(index != -1){
		//First delete vertex
		//Need this because removed doesnt have linked bag
		if(table[index].data != NULL){
    	    (table[index].data)->clear();
		    delete table[index].data;
		    table[index].data = NULL;
			//Since vertex is deleted subtract edges from total
			total_edges = total_edges - table[index].number_edges;
		}
		table[index].state = EMPTY;
		table[index].number_edges = 0;
		number_vertices--;
		
		//next delete all vertcies pointing to vertex
		for(int i=0; i < max_vertices; i++){
			if(table[i].data != NULL){
			    if((table[i].data)->contains(thing)){
				    (table[i].data)->remove(thing);
				    table[i].number_edges--;
					total_edges--;
				    if(table[i].number_edges == 0){
					    delete table[index].data;
					    table[index].data = NULL;
					    table[index].state = REMOVED;
				    }
			    }
		    }
		}
	} else{
		//Vertex DNE
		throw invalid_argument( "EXCEPTION: Vertex DNE or edge alread exists" );
	}
	
}

//Returns location of Vertex
template<class T>
int DirectedGraph<T>::vertexExists(T vertex) const{
	for(int i=0; i < max_vertices; i++){
		if(table[i].state != EMPTY){
		    if(table[i].vertex == vertex){
			    return i;
		    }
	    }
	}
	return -1;
}

//Clears table and deletes memory
template<class T>
void DirectedGraph<T>::clearGraph(){
	//Checks whether vertex exists then removes it
	for(int i=0; i < max_vertices; i++){
		if(table[i].state == OCCUPIED || table[i].state == REMOVED){
			//cout << table[i].data << endl;
			if(table[i].data != NULL){
		    	(table[i].data)->clear();
				delete table[i].data;
				table[i].data = NULL;
		    }
			table[i].state = EMPTY;
			table[i].number_edges = 0;
			//item_t *entry = htable
		}
	}
	number_vertices = 0;
	total_edges = 0;
}


