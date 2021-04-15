
#include "Duree.h"
#include <iostream>
#include <iomanip>
using namespace std;

Duree::Duree(int heures, int minutes, int secondes)
{
    m_secondes = secondes;
    m_minutes = minutes;
    m_heures = heures;

    //convertion des secondes > 60 en minutes
    m_minutes += m_secondes / 60; //calcule du surplus de sec en divisent par 60  et rajout des minutes
    m_secondes %= 60;             //reste de secondes

    //convertion des minutes > 60 en heures
    m_heures += m_minutes / 60; //minutes convertible en heures
    m_minutes %= 60;            //reste de minutes
}

void Duree::display(void)
{
    cout
        << setw(3) << m_heures << " heure(s)"
        << setw(3) << m_minutes << " minute(s)"
        << setw(3) << m_secondes << " seconde(s)";
}

bool Duree::estEgal(Duree const &b) const
{
    return (m_heures == b.m_heures &&
            m_minutes == b.m_minutes &&
            m_secondes == b.m_secondes); //Teste si a.m_heure == b.m_heure etc.
}

bool Duree::estPlusPetitQue(Duree const &b) const
{
    if (m_heures < b.m_heures) // Si les heures sont différentes
        return true;
    else if (m_heures == b.m_heures && m_minutes < b.m_minutes) //Si elles sont égales, on compare les minutes
        return true;
    else if (m_heures == b.m_heures && m_minutes == b.m_minutes && m_secondes < b.m_secondes) // Et si elles sont aussi égales, on compare les secondes
        return true;
    else //Si tout est égal, alors l'objet n'est pas plus petit que b
        return false;
}

Duree &Duree::operator+=(const Duree &a)
{

    m_secondes += a.m_secondes;
    //convertion des secondes > 60 en minutes
    m_minutes += m_secondes / 60; //calcule du surplus de sec en divisent par 60  et rajout des minutes
    m_secondes %= 60;             //reste de secondes

    m_minutes += a.m_minutes;
    //convertion des minutes > 60 en heures
    m_heures += m_minutes / 60; //minutes convertible en heures
    m_minutes %= 60;            //reste de minutes

    m_heures += a.m_heures;

    return *this;
}

Duree operator+(Duree const &a, Duree const &b)
{
    Duree copie(a); //On utilise le constructeur de copie de la classe Duree !
    copie += b;     //On appelle la méthode d'addition qui modifie l'objet 'copie'
    return copie;   //Et on renvoie le résultat. Ni a ni b n'ont changé.
}

Duree &Duree::operator+=(const int secondes)
{

    m_secondes += secondes;
    //convertion des secondes > 60 en minutes
    m_minutes += m_secondes / 60; //calcule du surplus de sec en divisent par 60  et rajout des minutes
    m_secondes %= 60;             //reste de secondes

    //convertion des minutes > 60 en heures
    m_heures += m_minutes / 60; //minutes convertible en heures
    m_minutes %= 60;            //reste de minutes

    return *this;
}

Duree operator+(Duree const &duree, int secondes)
{
    Duree copie(duree); //On utilise le constructeur de copie de la classe Duree !
    copie += secondes;  //On appelle la méthode d'addition qui modifie l'objet 'copie'
    return copie;       //Et on renvoie le résultat
}

bool operator==(Duree const &a, Duree const &b)
{
    return a.estEgal(b);
}

bool operator!=(Duree const &a, Duree const &b)
{
    return !(a == b);
}

bool operator<(Duree const &a, Duree const &b)
{
    return a.estPlusPetitQue(b);
}
bool operator>(Duree const &a, Duree const &b)
{
    return !(a.estPlusPetitQue(b));
}
bool operator<=(Duree const &a, Duree const &b)
{
    return (a < b || a == b);
}
bool operator>=(Duree const &a, Duree const &b)
{
    return (a > b || a == b);
}
