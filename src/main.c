#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "fonctions.h"








int main() {
    // les premières parenthèses définissent la longueur du tableau, les secondes définissent la taille des chaînes écrites
    char cartes[53][10] = 
    {
        "2trefle",
        "3trefle",
        "4trefle",
        "5trefle",
        "6trefle",
        "7trefle",
        "8trefle",
        "9trefle",
        "10trefle",
        "Jtrefle",
        "Qtrefle",
        "Ktrefle",
        "Atrefle",
        "2carreau",
        "3carreau",
        "4carreau",
        "5carreau",
        "6carreau",
        "7carreau",
        "8carreau",
        "9carreau",
        "10carreau",
        "Jcarreau",
        "Qcarreau",
        "Kcarreau",
        "Acarreau",
        "2pique",
        "3pique",
        "4pique",
        "5pique",
        "6pique",
        "7pique",
        "8pique",
        "9pique",
        "10pique",
        "Jpique",
        "Qpique",
        "Kpique",
        "Apique",
        "2coeur",
        "3coeur",
        "4coeur",
        "5coeur",
        "6coeur",
        "7coeur",
        "8coeur",
        "9coeur",
        "10coeur",
        "Jcoeur",
        "Qcoeur",
        "Kcoeur",
        "Acoeur",
    };

    char cartesTurn[53][10] = {

    };
    char cartesRiver[53][10] = {

    };

    char cartesbonnes[53][10] = 
    {
        "10trefle",
        "Jtrefle",
        "Qtrefle",
        "Ktrefle",
        "Atrefle",
        "10carreau",
        "Jcarreau",
        "Qcarreau",
        "Kcarreau",
        "Acarreau",
        "10pique",
        "Jpique",
        "Qpique",
        "Kpique",
        "Apique",
        "10coeur",
        "Jcoeur",
        "Qcoeur",
        "Kcoeur",
        "Acoeur",
    };

    char blind [3][15] = {
        "Small Blind",
        "Big Blind",
        "DEALER"
    };


    srand ( time(NULL) );

    // Creation du flop, turn et river

    struct flop flopTest; // Flop
    struct turn turnCard; // Turn
    struct river riverCard; // River




    // Variables de definition du pot

    int pot = 0;
    int potJoueurReel = 0;
    int potBot1 = 0;
    int potBot2 = 0;

    // Definition des trois joueurs

    struct joueur joueurReel;
    struct joueur bot1;
    struct joueur bot2;
    
    // Variables pour savoir si un joueur call ou fold

    int varJoueurReel = 0;
    int varBot1 = 0;
    int varBot2 = 0;

    



    // Creation du joueur reel


    // definition des cartes du joueur reel

    joueurReel.carte1 = rand() % 52;
    joueurReel.carte2 = rand() % 52;
    while ( joueurReel.carte1 == joueurReel.carte2){
        joueurReel.carte2 = rand() % 52;
    }

    // Definition du solde du joueur reel

    joueurReel.solde = 1000;
    
    // Definition du role du joueur reel

    joueurReel.blindNumber = 0;
    strcpy ( joueurReel.blindJoueur , blind[joueurReel.blindNumber] );


    // Definition de la main du joueur

    strcpy ( joueurReel.mainJoueur[0] , cartes[joueurReel.carte1] );
    strcpy ( joueurReel.mainJoueur[1] , cartes[joueurReel.carte2] );
    



    // Creation du bot1 


    // definition des cartes du bot1

    bot1.carte1 = rand() % 52;
    bot1.carte2 = rand() % 52;

    while ( bot1.carte1 == joueurReel.carte1 || bot1.carte1 == joueurReel.carte2 || bot1.carte1 == bot1.carte2 || bot1.carte2 == joueurReel.carte1 || bot1.carte2 == joueurReel.carte2 ){
        bot1.carte1 = rand() % 52;
        bot1.carte2 = rand() % 52;
    }

    // Definition du solde du bot1

    bot1.solde = 1000;
    
    // Definition du role du bot1

        bot1.blindNumber = joueurReel.blindNumber + 1;
    
    strcpy ( bot1.blindJoueur , blind[bot1.blindNumber] );
     
    


    // Definition de la main du bot1

    strcpy ( bot1.mainJoueur[0] , cartes[bot1.carte1] );
    strcpy ( bot1.mainJoueur[1] , cartes[bot1.carte2] );


    




    // Creation du bot2


    // definition des cartes du bot2

    bot2.carte1 = rand() % 52;
    bot2.carte2 = rand() % 52;

    while ( bot2.carte1 == bot1.carte1 || bot2.carte1 == bot1.carte2 || bot2.carte1 == bot2.carte2 || bot2.carte2 == bot1.carte1 || bot2.carte2 == bot1.carte2 ){
        bot1.carte1 = rand() % 52;
        bot1.carte2 = rand() % 52;
    }

    // Definition du solde du bot2

    bot2.solde = 1000;
    
    // Definition du role du bot2

    bot2.blindNumber = joueurReel.blindNumber + 2;
    
    strcpy ( bot2.blindJoueur , blind[bot2.blindNumber] );
     
    


    // Definition de la main du bot2

    strcpy ( bot2.mainJoueur[0] , cartes[bot2.carte1] );
    strcpy ( bot2.mainJoueur[1] , cartes[bot2.carte2] );


    // Distribution d'argent selon le role de chaque joueur

    // joueurReel

    if (!strcmp(joueurReel.blindJoueur,"Small Blind")){
        potJoueurReel = 50;
        joueurReel.solde = joueurReel.solde - potJoueurReel;
    } else if (!strcmp(joueurReel.blindJoueur,"Big Blind")){
        potJoueurReel = 100;
        joueurReel.solde = joueurReel.solde - potJoueurReel;
    }

    // bot1

    if (!strcmp(bot1.blindJoueur,"Small Blind")){
        potBot1 = 50;
        bot1.solde = bot1.solde - potBot1;
    } else if (!strcmp(bot1.blindJoueur,"Big Blind")){
        potBot1 = 100;
        bot1.solde = bot1.solde - potBot1;
    }

    // bot2

    if (!strcmp(bot2.blindJoueur,"Small Blind")){
        potBot2 = 50;
        bot2.solde = bot2.solde - potBot2;
    } else if (!strcmp(bot2.blindJoueur,"Big Blind")){
        potBot2 = 100;
        bot2.solde = bot2.solde - potBot2;
    }

    // Le pot prend les valeur des pots de tout joueurs

    pot = potBot1 + potBot2 + potJoueurReel;


    printf("\n\nVotre main est : [%s] [%s]. \n\n\nVotre role est : %s.\n\n\nVotre solde est de : %d.\n\n\n", joueurReel.mainJoueur[0],joueurReel.mainJoueur[1],joueurReel.blindJoueur,joueurReel.solde);



    // Definition du FLOP


    flopTest.carte1 = rand() % 52;
    flopTest.carte2 = rand() % 52;
    flopTest.carte3 = rand() % 52;

    while (flopTest.carte1 == flopTest.carte2 || flopTest.carte1 == flopTest.carte3 || flopTest.carte2 == flopTest.carte3 
            || flopTest.carte1 == joueurReel.carte1 || flopTest.carte1 == joueurReel.carte2 || flopTest.carte2 == joueurReel.carte1
            ||  flopTest.carte2 == joueurReel.carte2 || flopTest.carte1 == bot1.carte1 || flopTest.carte1 == bot1.carte2 || flopTest.carte2 == bot1.carte1
            ||  flopTest.carte2 == bot1.carte2 || flopTest.carte1 == bot2.carte1 || flopTest.carte1 == bot2.carte2 || flopTest.carte2 == bot2.carte1
            ||  flopTest.carte2 == bot2.carte2) {
        flopTest.carte1 = rand() % 52;
        flopTest.carte2 = rand() % 52;
        flopTest.carte3 = rand() % 52;
    }

    strcpy ( flopTest.cartesFlop[0] , cartes[flopTest.carte1] );
    strcpy ( flopTest.cartesFlop[1] , cartes[flopTest.carte2] );
    strcpy ( flopTest.cartesFlop[2] , cartes[flopTest.carte3] );


    // Definition de la Turn

    
    turnCard.carte4 = rand() % 52;

    while (turnCard.carte4 == joueurReel.carte1 || turnCard.carte4 == joueurReel.carte2 || turnCard.carte4 == flopTest.carte1 || turnCard.carte4 == flopTest.carte2 || turnCard.carte4 == flopTest.carte3
             || turnCard.carte4 == bot1.carte1 || turnCard.carte4 == bot1.carte2 
             || turnCard.carte4 == bot2.carte1 || turnCard.carte4 == bot2.carte2) {
        turnCard.carte4 = rand() % 52;
    }

    strcpy ( cartesTurn[0] , cartes[turnCard.carte4] );

    // Definition de la River

    
    riverCard.carte5 = rand() % 52;

    while (riverCard.carte5 == joueurReel.carte1 || riverCard.carte5 == joueurReel.carte2 || riverCard.carte5 == flopTest.carte1 || riverCard.carte5 == flopTest.carte2 || riverCard.carte5 == flopTest.carte3
             || riverCard.carte5 == bot1.carte1 || riverCard.carte5 == bot1.carte2 
             || riverCard.carte5 == bot2.carte1 || riverCard.carte5 == bot2.carte2 || riverCard.carte5 == turnCard.carte4) {
        riverCard.carte5 = rand() % 52;
    }

    strcpy ( cartesRiver[0] , cartes[turnCard.carte4] );

    
    // Options disponibles pour le joueur humain lorsqu'il un solde inferieur au solde d'au moin un bot

    char optionChoosen[10];
    int raise = 0;

    // Premier tour

    int j;
    printf("You've got three options : Call, Fold, or raise.\n\n");
    scanf("%s", optionChoosen);
    if (!strcmp(optionChoosen,"call")){
        joueurReel.solde = joueurReel.solde - 50;
        pot = pot + 50;
        sleep(2);
        varJoueurReel = 1;
        printf("Le bot1 call.\n\n");
        varBot1 = 1; // 1 si le joueur call, 2 s'il fold
        sleep(2);
        printf("Le bot2 call.\n\n");
        pot = pot + 100;
        varBot2 = 1; // 1 si le joueur call, 2 s'il fold
        sleep(2);
    } else if (!strcmp(optionChoosen,"fold")) {
        sleep(2);
        printf("Vous avez abondonner.\n\n");
        sleep(1);
        printf("Le bot1 call.\n\n");
        varBot1 = 1; // 1 si le joueur call, 2 s'il fold
        sleep(2);
        printf("Le bot2 call.\n\n");
        pot = pot + 100;
        varBot2 = 1; // 1 si le joueur call, 2 s'il fold
        sleep(2);
    } else if (!strcmp(optionChoosen,"raise")) {
        printf("Veuillez entrer le montant de votre raise : \n\n");
        scanf("%d", &raise);
        joueurReel.solde = joueurReel.solde - raise;
        pot = pot + raise;
        for(j=0;j=18;j++){
            if (raise < bot1.solde/2 && ( strcmp(bot1.mainJoueur[0], cartesbonnes[j]) || strcmp(bot1.mainJoueur[1], cartesbonnes[j])) ){
                varBot1 = 1;
                sleep(2);
                printf("bot1 calls.\n\n");
                bot1.solde = bot1.solde - raise;
                pot = pot + raise;
                break;
            } else {
                varBot1 = 2;
                sleep(2);
                printf("bot1 Folds.\n\n");
                break;
            }   
        }
        for(j=0;j=18;j++){
            if (raise < bot2.solde/2 && ( strcmp(bot2.mainJoueur[0], cartesbonnes[j]) || strcmp(bot2.mainJoueur[1], cartesbonnes[j]))){
                varBot2 = 1;
                sleep(2);
                printf("bot2 calls.\n\n");
                bot2.solde = bot2.solde - raise;
                pot = pot + raise;
                break;
            } else {
                varBot2 = 2;
                sleep(2);
                printf("bot2 Folds.\n\n");
                break;
            }    
        }
    }
    
    // cartes du FLOP

    // Verification qu'au moins deux joueurs sont en train de jouer

    if ((varJoueurReel==1 && varBot1==1) || (varJoueurReel==1 && varBot2==1) || (varBot2==1 && varBot1==1)) {
        sleep(2);
        printf("\n\nVoici les cartes du flop : [%s][***][***][***][***]\n\n", flopTest.cartesFlop[0]);
        sleep(2);
        printf("\n\nVoici les cartes du flop : [%s][%s][***][***][***]\n\n", flopTest.cartesFlop[0], flopTest.cartesFlop[1]);
        sleep(2);
        printf("\n\nVoici les cartes du flop : [%s][%s][%s][***][***]\n\n", flopTest.cartesFlop[0], flopTest.cartesFlop[1], flopTest.cartesFlop[2]);
        sleep(2);
        printf("Votre solde est de : %d.\n\n", joueurReel.solde);
        sleep(1);
        printf("Le pot est de : %d.\n\n", pot);
        sleep(1);

    } else {
        printf("Vous avez gagner le pot.\n\n");
        joueurReel.solde = joueurReel.solde + raise + pot;
        printf("Votre solde est de : %d.\n\n", joueurReel.solde);
    }

    
    // TURN
    if(strcmp(optionChoosen,"fold")){
            printf("You've got three options : Check, Fold, or raise.\n\n");    
            scanf("%s", optionChoosen);
    }
        

    if (!strcmp(optionChoosen,"check")){
        sleep(2);
        varJoueurReel = 1;
        printf("Le bot1 check.\n\n");
        varBot1 = 1; // 1 si le joueur call, 2 s'il fold
        sleep(2);
        printf("Le bot2 check.\n\n");
        varBot2 = 1; // 1 si le joueur call, 2 s'il fold
        sleep(2);
    } else if(!strcmp(optionChoosen,"raise")){
        printf("Veuillez entrer le montant de votre raise : \n\n");
        scanf("%d", &raise);
        joueurReel.solde = joueurReel.solde - raise;
        pot = pot + raise;
        for(j=0;j=18;j++){
            if (raise < bot1.solde/2 && ( strcmp(bot1.mainJoueur[0], cartesbonnes[j]) || strcmp(bot1.mainJoueur[1], cartesbonnes[j])) ){
                varBot1 = 1;
                sleep(2);
                printf("bot1 calls.\n\n");
                bot1.solde = bot1.solde - raise;
                pot = pot + raise;
                break;
            } else {
                varBot1 = 2;
                sleep(2);
                printf("bot1 Folds.\n\n");
                break;
            }   
        }
        for(j=0;j=18;j++){
            if (raise < bot2.solde/2 && ( strcmp(bot2.mainJoueur[0], cartesbonnes[j]) || strcmp(bot2.mainJoueur[1], cartesbonnes[j]))){
                varBot2 = 1;
                sleep(2);
                printf("bot2 calls.\n\n");
                bot2.solde = bot2.solde - raise;
                pot = pot + raise;
                break;
            } else {
                varBot2 = 2;
                sleep(2);
                printf("bot2 Folds.\n\n");
                break;
            }    
        }
    }

    // Carte de la turn

    if ((varJoueurReel==1 && varBot1==1) || (varJoueurReel==1 && varBot2==1) || (varBot2==1 && varBot1==1)) {
        sleep(2);
        printf("\n\nVoici la turn : [%s][%s][%s][%s][***]\n\n", flopTest.cartesFlop[0], flopTest.cartesFlop[1], flopTest.cartesFlop[2],cartesTurn[0]);
        printf("Votre solde est de : %d.\n\n", joueurReel.solde);
        sleep(1);
        printf("Le pot est de : %d.\n\n", pot);
        sleep(1);
    } else {
        printf("Vous avez gagner le pot.\n\n");
        joueurReel.solde = joueurReel.solde + pot;
        printf("Votre solde est de : %d.\n\n", joueurReel.solde);
    }

    // RIVER

    if(strcmp(optionChoosen,"fold")){
        printf("You've got three options : Check, Fold, or raise.\n\n");
        scanf("%s", optionChoosen); 
    }


    if (!strcmp(optionChoosen,"check")){
        sleep(2);
        varJoueurReel = 1;
        printf("Le bot1 check.\n\n");
        varBot1 = 1; // 1 si le joueur call, 2 s'il fold
        sleep(2);
        printf("Le bot2 check.\n\n");
        varBot2 = 1; // 1 si le joueur call, 2 s'il fold
        sleep(2);
    } else if(!strcmp(optionChoosen,"raise")){
        printf("Veuillez entrer le montant de votre raise : \n\n");
        scanf("%d", &raise);
        joueurReel.solde = joueurReel.solde - raise;
        pot = pot + raise;
        for(j=0;j=18;j++){
            if (raise < bot1.solde/2 && ( strcmp(bot1.mainJoueur[0], cartesbonnes[j]) || strcmp(bot1.mainJoueur[1], cartesbonnes[j])) ){
                varBot1 = 1;
                sleep(2);
                printf("bot1 calls.\n\n");
                bot1.solde = bot1.solde - raise;
                pot = pot + raise;
                break;
            } else {
                varBot1 = 2;
                sleep(2);
                printf("bot1 Folds.\n\n");
                break;
            }   
        }
        for(j=0;j=18;j++){
            if (raise < bot2.solde/2 && ( strcmp(bot2.mainJoueur[0], cartesbonnes[j]) || strcmp(bot2.mainJoueur[1], cartesbonnes[j]))){
                varBot2 = 1;
                sleep(2);
                printf("bot2 calls.\n\n");
                bot2.solde = bot2.solde - raise;
                pot = pot + raise;
                break;
            } else {
                varBot2 = 2;
                sleep(2);
                printf("bot2 Folds.\n\n");
                break;
            }    
        }
    }

    // Carte de la River

    if ((varJoueurReel==1 && varBot1==1) || (varJoueurReel==1 && varBot2==1) || (varBot2==1 && varBot1==1)) {
        sleep(2);
        printf("\n\nVoici la river : [%s][%s][%s][%s][%s]\n\n", flopTest.cartesFlop[0], flopTest.cartesFlop[1], flopTest.cartesFlop[2], cartesTurn[0], cartesRiver[0]);
        sleep(1);
        printf("Votre solde est de : %d.\n\n", joueurReel.solde);
        sleep(1);
        printf("Le pot est de : %d.\n\n", pot);
        sleep(1);
    } else {
        printf("Vous avez gagner le pot.\n\n");
        joueurReel.solde = joueurReel.solde + pot;
        printf("Votre solde est de : %d.\n\n", joueurReel.solde);
    }

    // FINAL ROUND

    if(strcmp(optionChoosen,"fold")){
        printf("You've got three options : Check, Fold, or raise.\n\n");
        scanf("%s", optionChoosen);
    }


    if (!strcmp(optionChoosen,"check")){
        sleep(2);
        varJoueurReel = 1;
        printf("Le bot1 check.\n\n");
        varBot1 = 1; // 1 si le joueur call, 2 s'il fold
        sleep(2);
        printf("Le bot2 check.\n\n");
        varBot2 = 1; // 1 si le joueur call, 2 s'il fold
        sleep(2);
    } else if(!strcmp(optionChoosen,"raise")){
        printf("Veuillez entrer le montant de votre raise : \n\n");
        scanf("%d", &raise);
        joueurReel.solde = joueurReel.solde - raise;
        pot = pot + raise;
        for(j=0;j=18;j++){
            if (raise < bot1.solde/2 && ( strcmp(bot1.mainJoueur[0], cartesbonnes[j]) || strcmp(bot1.mainJoueur[1], cartesbonnes[j])) ){
                varBot1 = 1;
                sleep(2);
                printf("bot1 calls.\n\n");
                bot1.solde = bot1.solde - raise;
                pot = pot + raise;
                break;
            } else {
                varBot1 = 2;
                sleep(2);
                printf("bot1 Folds.\n\n");
                break;
            }   
        }
        for(j=0;j=18;j++){
            if (raise < bot2.solde/2 && ( strcmp(bot2.mainJoueur[0], cartesbonnes[j]) || strcmp(bot2.mainJoueur[1], cartesbonnes[j]))){
                varBot2 = 1;
                sleep(2);
                printf("bot2 calls.\n\n");
                bot2.solde = bot2.solde - raise;
                pot = pot + raise;
                break;
            } else {
                varBot2 = 2;
                sleep(2);
                printf("bot2 Folds.\n\n");
                break;
            }    
        }
    }

    // Demonstration des cartes du final round

    if ((varJoueurReel==1 && varBot1==1) || (varJoueurReel==1 && varBot2==1) || (varBot2==1 && varBot1==1)) {
        if(varJoueurReel==1){
            sleep(1);
            printf("Vos cartes sont : [%s][%s]\n\n", joueurReel.mainJoueur[0], joueurReel.mainJoueur[1]);
        }
        if(varBot1==1){
            sleep(1);
            printf("Les cartes du bot1 sont : [%s][%s]\n\n", bot1.mainJoueur[0], bot1.mainJoueur[1]);
        }
        if(varBot2==1){
            sleep(1);
            printf("Les cartes du bot2 sont : [%s][%s]\n\n", bot2.mainJoueur[0], bot2.mainJoueur[1]);
        }
        printf("Votre solde est de : %d.\n\n", joueurReel.solde);
        sleep(1);
        printf("Le pot est de : %d.\n\n", pot);
        sleep(1);
    } else {
        printf("Vous avez gagner le pot.\n\n");
        joueurReel.solde = joueurReel.solde + pot;
        printf("Votre solde est de : %d.\n\n", joueurReel.solde);
    }
   



    // Comparaison des combinaisons de tout les joueurs
    // ** Fonctionnalités à coder selon les envies **


    // Carte haute

    // Paire 

    // Double Paire

    // Brelan

    // Quinte

// Couleur

// char extractions[7][3];

// int compteur = 0;
// int r = 0;
// int m = 0;
// extraire(joueurReel.mainJoueur[0], extractions[0]);
// extraire(joueurReel.mainJoueur[1], extractions[1]);
// extraire(flopTest.cartesFlop[0], extractions[2]);
// extraire(flopTest.cartesFlop[1], extractions[3]);
// extraire(flopTest.cartesFlop[2], extractions[4]);
// extraire(cartesTurn[0], extractions[5]);
// extraire(cartesRiver[0], extractions[6]);

// for (int i = 0; i < 7; i++) {
//     compteur = 1;  // Reset compteur to 1 for each new card

//     for (int j = i + 1; j < 7; j++) {
//         if (strcmp(extractions[i], extractions[j])) {
//             compteur++;
//             printf("%d\n\n", compteur);
//         }
//     }

//     if (compteur >= 5) {
//         printf("La combinaison obtenue est : une couleur.");
//         break;
//     }
// }

// if (compteur < 5) {
//     printf("Vous n'avez pas de couleur.");
// }

    









    return 0;

}