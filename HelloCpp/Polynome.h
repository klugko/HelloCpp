#pragma once

#include <vector>
#include "Monome.cpp"

using namespace std;

class Polynome
{
private:
	vector<Monome> monomes;

public:
	void addMonome(const Monome& monome) {
		monomes.push_back(monome);
	}

	Polynome derive() const {
		
	}

	Polynome operator+(const Polynome& p) const {
		
	}

	Polynome operator-(const Polynome& p) const {

	}

	void printPolynome() const {

	}
};

