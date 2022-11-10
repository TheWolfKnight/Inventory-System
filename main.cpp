
#include <iostream>
#include <stdlib.h>
#include <string>
#include "Models/Item.cpp"
#include "Collections/Lists.cpp"

using namespace std;

void printHelp() {
  cout << "Please give your login!" << endl;
  cout << "FORMAT:" << endl;	
  cout << "Inventory-System {username} {password}" << endl;
  return;
}

int main( int argc, char** argv ) {
  Collections::List<string>* h = new Collections::List<string>();
  h->push("Hello world!");
  cout << h->at(0) << endl;
}
