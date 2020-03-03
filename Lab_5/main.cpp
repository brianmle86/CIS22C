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
    t.display();
    cout << endl << endl;
    cout << t.root->data << endl;
    cout << t.root->left->data << endl;
    cout << t.root->left->left->data << endl;
    cout << t.root->left->right->data << endl;
    cout << t.root->right->data << endl;
    cout << t.root->right->left->data << endl;
    cout << t.root->right->right->data << endl;
    return 0;
}