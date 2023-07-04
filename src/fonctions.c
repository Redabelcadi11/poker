#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "fonctions.h"

    // Fonction pour extraire le symbole(couleur) de chaque carte

    void extraire(char *caractere, char *extraction) {
        if (caractere[1] == '0') {
            strcpy(extraction, caractere + 2);
        } else {
            strcpy(extraction, caractere + 1);
        }
    }

