#pragma once
#pragma once
#include <iostream>
#include <vector>

using namespace std;


class Monome {
private:
    double coefficient;
    int degre;

public:
    Monome(double coef = 0, int deg = 0) : coefficient(coef), degre(deg) {}

    double getCoefficient() const {
        return coefficient;
    }

    int getDegre() const {
        return degre;
    }

    Monome derive() const {
        if (degre == 0) {
            return Monome(0, 0);
        }
        return Monome(coefficient * degre, degre - 1);
    }

    void printMonome() const {
        if (coefficient != 0) {
            cout << coefficient << "X^" << degre;
        }
    }

    Monome operator+(const Monome& m) const {
        if (degre == m.degre) {
            return Monome(coefficient + m.coefficient, degre);
        }
        else {
            cerr << "Erreur: Les degrés sont différents" << endl;
            return *this;
        }
    }

    Monome operator-(const Monome& m) const {
        if (degre == m.degre) {
            return Monome(coefficient - m.coefficient, degre);
        }
        else {
            cerr << "Erreur: Les degrés sont différents" << endl;
            return *this;
        }
    }
};
