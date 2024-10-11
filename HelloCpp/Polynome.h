#pragma once

#include <vector>
#include "Monome.cpp"


class Polynome {
private:
    vector<Monome> monomes; 

public:
    void addMonome(const Monome& m) {
        for (auto& monome : monomes) {
            if (monome.getDegre() == m.getDegre()) {
                monome = monome + m;  
                return;
            }
        }
        monomes.push_back(m);
    }

    Polynome derive() const {
        Polynome derivee;
        for (const auto& monome : monomes) {
            Monome m_der = monome.derive();
            if (m_der.getCoefficient() != 0) { 
                derivee.addMonome(m_der);
            }
        }
        return derivee;
    }

    void printPolynome() const {
        if (monomes.empty()) {
            cout << "0" << endl;
            return;
        }
        for (size_t i = 0; i < monomes.size(); ++i) {
            if (i > 0 && monomes[i].getCoefficient() > 0) {
                cout << " + ";
            }
            monomes[i].printMonome();
        }
        cout << endl;
    }

    Polynome operator+(const Polynome& p) const {
        Polynome result = *this;
        for (const auto& monome : p.monomes) {
            result.addMonome(monome);
        }
        return result;
    }

    Polynome operator-(const Polynome& p) const {
        Polynome result = *this;
        for (const auto& monome : p.monomes) {
            result.addMonome(Monome(-monome.getCoefficient(), monome.getDegre()));
        }
        return result;
    }
};




