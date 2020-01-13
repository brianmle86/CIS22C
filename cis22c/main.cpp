#include <iostream>
#include "currency.h"
#include "wallet.h"

using namespace std;

int main() {

	Dollar d(4, 56);
	cout << d << endl;
	Wallet w;
	w.add(d); //add in the form (Dollar, 1, 25, coin)
	Dollar f(5, 10);
	Dollar g(3, 22);
	Currency e = f + g;
	Currency currency;
	cout << currency << endl;

}
