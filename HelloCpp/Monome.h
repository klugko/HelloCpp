#pragma once
#include <iostream>

using namespace std;

class Monome {
private:
    double coefficient;
    int degre;

    Monome(double coef = 0, int def = 0) : coefficient(coef), degre(def) {}

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

    void printMonome() {
        cout << coefficient << "X^" << degre;
    }

    //override operator
    Monome operator+(const Monome& m) const {
        if (degre == m.degre) {
            return Monome(coefficient + m.coefficient, degre);
        }
        else {
            cerr << "Impossible d'additionner car les degrés sont  différents \n";
            return *this;
        }
    }

    Monome operator-(const Monome& m) const {
        if (degre == m.degre) {
            return Monome(coefficient - m.coefficient, degre);

        }
        else {
            cerr << "Impossible de soustraire car les degrés sont différents \n";
            return *this;
        }
    }
};

