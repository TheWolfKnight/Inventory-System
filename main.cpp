
#include <iostream>
#include <string>
#include "Models/Item.cpp"
using namespace std;

void printHelp() {
  cout << "Please give your login!" << endl;
  cout << "FORMAT:" << endl;	
  cout << "Inventory-System {username} {password}" << endl;
  return;
}

int main( int argc, char** argv ) {
  Item::ItemHandle ih = Item::ItemHandle();

  cout << ih.to_string() << endl;

  return 0;
}
