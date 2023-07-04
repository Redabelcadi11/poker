#ifndef H_FONCTIONS_H
#define H_FONCTIONS_H

void extraire(char *caractere, char *extraction);

struct joueur {
    char mainJoueur[2][10];
    int carte1;
    int carte2;
    int solde;
    char blindJoueur[15];
    int blindNumber;
};

struct flop {
    int carte1;
    int carte2;
    int carte3;
    char cartesFlop[10][10];
};

struct turn {
    int carte4;
    char cartesTurn[10][10];
};

struct river {
    int carte5;
    char cartesRiver[10][10];
};

#endif
