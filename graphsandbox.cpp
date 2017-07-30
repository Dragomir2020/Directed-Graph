#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>

#include "DirectedGraph.cpp"

using namespace std;


int main(int argc, char* argv[]){
    DirectedGraph<string> hello(3);
	hello.insertVertex("A");
	hello.insertVertex("B");
	cout << "Full: " << hello.isFull() << endl;
	hello.insertVertex("B");
	cout << "Full: " << hello.isFull() << endl;
	hello.insertVertex("D");
	cout << "Full: " << hello.isFull() << endl;
	cout << "NumVertices: " << hello.numberVertices() << endl;
	return 0;
}
