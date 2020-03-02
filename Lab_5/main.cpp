
#include <iostream>
#include <string>
#include <fstream>
#include "person.h"
#include "bst.h"


using namespace std;

int main() {
	bst<int> t;
    t.insert(20);
    t.insert(25);
    t.insert(15);
    t.insert(10);
    t.insert(30);
    t.display();
    t.remove(20);
    t.display();
    t.remove(25);
    t.display();
    t.remove(30);
    t.display();
    return 0;
}