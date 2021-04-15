#include <iostream>
#include "Duree.h"
using namespace std;


int main()
{
    Duree duree1(1, 45, 28);
    Duree resultat;

    resultat = duree1 + 10;

    cout << "=" << endl;
    resultat.display();

    return 0;
}

