#include <iostream>
#include <string>
#include <fstream>
#include "person.h"
#include "bst.h"


using namespace std;

int main() {
	bst<int> t;
    t.insert(5); //root
    t.insert(3);
    t.insert(8);
    t.insert(1);
    t.insert(4);
    t.insert(6);
    t.insert(9);
    cout << "inorder" << endl;
    t.displayInOrder();
    cout << "preorder" << endl;
    t.displayPreOrder();
    cout << "postorder" << endl;
    t.displayPostOrder();
    t.clear();
    t.displayInOrder();
    return 0;
}