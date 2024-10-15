#include <iostream>
#include "Polynome.h"
#include "Monome.h"


using namespace std;


class DateHeure
{
private:
    int jour, mois, annee, heure, minute, seconde;
public:
    // constructeur par defaut
    DateHeure(): jour(1), mois(1), annee(2000), heure(0), minute(0), seconde(0) {}

    // constructeur avec paramètres
    DateHeure(int j, int m, int a, int h, int mn, int s):
        jour(j), mois(m), annee(a), heure(h), minute(mn), seconde(s){}

    // constructeur par recopie
    DateHeure(const DateHeure& d):
    jour(d.jour), mois(d.mois), annee(d.annee), heure(d.heure), minute(d.minute), seconde(d.seconde) {}

    // afficher une date en format français
    void afficherDate() const {
        cout << jour << "/" << mois << "/" << annee << " " << heure << ":" << minute << ":" << seconde << endl;
    }

    // convertir un date en seconde
    long dateToSeconde() const {
        long totalSeconde = ((annee * 365 + mois * 30 + jour * 24) * 86400) + heure * 3600 + minute * 60 + seconde;
        return totalSeconde;
    }

    // convertir des secondes en date 
    void secondeToDate(long totalSeconde) {
        annee = totalSeconde / (365 * 86400);
        totalSeconde %= 365 * 86400;
        mois = totalSeconde / (30 * 86400);
        totalSeconde %= 30 * 86400;
        jour = totalSeconde / 86400;
        totalSeconde %= 86400;
        heure = totalSeconde / 3600;
        totalSeconde %= 3600;
        minute = totalSeconde / 60;
        seconde = totalSeconde % 60;

    }

    // soustraire deux date
    long operator-(const DateHeure& d) const {
        return std::abs(dateToSeconde() - d.dateToSeconde());
   }


    DateHeure operator-(long secondes) const{
        long totalSeconde = dateToSeconde() - secondes;
        DateHeure result;
        result.secondeToDate(totalSeconde);

        return result;

    }
};



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
