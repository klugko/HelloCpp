#include <iostream>
#include "Polynome.h"
#include "Monome.h"


using namespace std;


int main() {
    Monome m1(3, 2); // 3X^2
    Monome m2(5, 1); // 5X^1
    Monome m3(2, 0); // 2

    Polynome p;
    p.addMonome(m1);
    p.addMonome(m2);
    p.addMonome(m3);

    cout << "Polynome: ";
    p.printPolynome();

    cout << "Polynome derive: ";
    Polynome p_der = p.derive();
    p_der.printPolynome();

    Polynome p2;
    p2.addMonome(Monome(4, 2));  
    p2.addMonome(Monome(-1, 1)); 

    Polynome somme = p + p2;
    cout << "Somme des polynomes: ";
    somme.printPolynome();

    Polynome difference = p - p2;
    cout << "Difference des polynomes: ";
    difference.printPolynome();

    return 0;
}
