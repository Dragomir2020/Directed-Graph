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
	
	//This code doesnt leverage previously written functions
	/*
	for(int i=0;i<max_vertices;i++){
		if(table[i].vertex == vertex && table[i].state != OCCUPIED){
			return (table[i].data)->getCurrentSize();
		}
		if((i == 1 + max_vertices) && table[i].vertex != vertex){
			throw invalid_argument( "EXCEPTION: Vertex does not exist." );
		}
	}
	return 0;*/
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
		if(table[i].state == EMPTY){
			break;
		}
		is_full = is_full && (table[i].number_edges == (number_vertices-1));
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
//STILL NEEDS IMPLEMENTED
template<class T>
void DirectedGraph<T>::removeEdge(T vertOne, T vertTwo){
	//Checks whether edge exists first
}

//Remove vertex
//STILL NEEDS IMPLEMENTED
template<class T>
void DirectedGraph<T>::removeVertex(T thing){
	//Checks whether vertex exists then removes it
}

//Returns location of Vertex
template<class T>
int DirectedGraph<T>::vertexExists(T vertex) const{
	for(int i=0; i < max_vertices; i++){
		if(table[i].state == EMPTY){
			//Break if all vertices are looped through
			return -1;
		} else if(table[i].vertex == vertex){
			return i;
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


//Assignment Operator
/*
template<class T>
DirectedGraph<T> DirectedGraph<T>::operator= (const DirectedGraph& other){ 
	if(table == other.table){
		return *this;
	} else {
       // Assignment Operator
	   clear_table();
       hashfn = other.hashfn;
	   the_capacity = other.the_capacity;
	   //Set copy over all elements
	   for(int i = 0; i < the_capacity; i++){
	       if((other.table[i]).state == EMPTY || (other.table[i]).state == REMOVED){
			//Do Nothing
		   }else if((other.table[i]).state == OCCUPIED){
		      vector<T> bagContents  = ((other.table[i]).data)->toVector();
		      for(int i = 0; i < bagContents.size(); i++){
			      //cout << bagContents[i] << endl;
		          insert(bagContents[i]);
		      }
	       }
	   }
	   return *this;
    }
}
//Find
template<class T>
bool HashTable<T>::find(T thing) const{
	unsigned int hash_value = ((*hashfn)(thing))%the_capacity;
	if(table[hash_value].state == OCCUPIED){
	    // Check whether value exists in linked bag at index of hash_value
	    return (table[hash_value].data)->contains(thing);
	} else{
		return false;
	}
}
//Size
template<class T>
unsigned int HashTable<T>::size() const{
	//Find size of hash table
	return the_size;
}
//Capacity
template<class T>
unsigned int HashTable<T>::capacity() const{
	//Return Hash table capacity
	return the_capacity;
}
//Is the table full
template<class T>
bool HashTable<T>::isFull() const{
	//Check whether table is full
	for(int i = 0; i < the_capacity; i++){
	      if(table[i].state == EMPTY || table[i].state == REMOVED){
	      	return false;
	      }	
	}
	return true;
}
//Insert new element into table
template<class T>
void HashTable<T>::insert(T thing){
    //If found check next parameter
	if(!find(thing)){
		//Use hash function to get index
		unsigned int hash_value = ((*hashfn)(thing))%the_capacity;
		//If Empty Create linked bag and push back element
		if(table[hash_value].state == EMPTY){
		     // Add value to linked bag
			//Loop through items in linked bag
			LinkedBag<T>* A = new LinkedBag<T>();
			A->push_back(thing);
			(table[hash_value].data) = A;
			table[hash_value].state = OCCUPIED;
			the_size++;
	    //If occupied insert new element
		}else if(table[hash_value].state == OCCUPIED || table[hash_value].state == REMOVED){
			(table[hash_value].data)->push_back(thing);
			table[hash_value].state = OCCUPIED;
			the_size++;
		}
	//Throw logic error if table is full
	} else if(isFull()){
		throw logic_error("Table is full");
	}
	
}


template<class T>
void HashTable<T>::remove(T thing){
	if(!find(thing)){
		//DNE
	} else if(the_size != 0){
		unsigned int hash_value = ((*hashfn)(thing))%the_capacity;
		table[hash_value].data->remove(thing);
		the_size--;
		if(table[hash_value].data->getCurrentSize() == 0){
			table[hash_value].state = REMOVED;
		}
	}

}

*/
