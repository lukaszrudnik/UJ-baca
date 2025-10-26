//Lukasz Rudnik
#include <iostream>
using namespace std;

int main(){
    int inputs;
    char playerOne;
    char playerTwo;
    char choiceOne;
    char choiceTwo;
    int strengthOne;
    int strengthTwo;

    int gamesA = 0;
    int gamesB = 0;
    int gamesC = 0;
    int gamesD = 0;
    int winsA = 0;
    int winsB = 0;
    int winsC = 0;
    int winsD = 0;
    int drawsA = 0;
    int drawsB = 0;
    int drawsC = 0;
    int drawsD = 0;
    int lostA = 0; //lost latwiej i czytelniej niz losses
    int lostB = 0;
    int lostC = 0;
    int lostD = 0;

    int outHelp = 0; //zmienna ktora pamieta, czy bylo juz cos wypisywane (by uniknac niepotrzebnego couta)


    cin >> inputs;

    while ( inputs > 0 ){
        inputs = inputs - 1;
        cin >> playerOne >> choiceOne >> strengthOne >> playerTwo >> choiceTwo >> strengthTwo;

        if ( playerOne == 'a' ){
            gamesA = gamesA + 1;
            if (playerTwo == 'b' ){
                gamesB = gamesB + 1;

                if ( choiceOne == choiceTwo ){ // od razu sprawdzanie remisow
                    if ( strengthOne > strengthTwo ){
                        winsA = winsA + 1;
                        lostB = lostB + 1;
                    }
                    if ( strengthOne < strengthTwo ){
                        winsB = winsB + 1;
                        lostA = lostA + 1;
                    }
                    if ( strengthOne == strengthTwo ){
                        drawsA = drawsA + 1;
                        drawsB = drawsB + 1;
                    }
                }

                else{
                    if ( choiceOne == 'K' ){
                        if ( choiceTwo == 'N' || choiceTwo == 'J' ){
                            winsA = winsA + 1;
                            lostB = lostB + 1;
                        }
                        else{
                            winsB = winsB + 1;
                            lostA = lostA + 1;
                        }
                    }
                    if ( choiceOne == 'P' ){
                        if ( choiceTwo == 'K' || choiceTwo == 'S' ){
                            winsA = winsA + 1;
                            lostB = lostB + 1;
                        }
                        else{
                            winsB = winsB + 1;
                            lostA = lostA + 1;
                        }
                    }
                    if ( choiceOne == 'N' ){
                        if ( choiceTwo == 'P' || choiceTwo == 'J' ){
                            winsA = winsA + 1;
                            lostB = lostB + 1;
                        }
                        else{
                            winsB = winsB + 1;
                            lostA = lostA + 1;
                        }
                    }
                    if ( choiceOne == 'J' ){
                        if ( choiceTwo == 'P' || choiceTwo == 'S' ){
                            winsA = winsA + 1;
                            lostB = lostB + 1;
                        }
                        else{
                            winsB = winsB + 1;
                            lostA = lostA + 1;
                        }
                    }
                    if ( choiceOne == 'S' ){
                        if ( choiceTwo == 'N' || choiceTwo == 'K' ){
                            winsA = winsA + 1;
                            lostB = lostB + 1;
                        }
                        else{
                            winsB = winsB + 1;
                            lostA = lostA + 1;
                        }
                    }
                }
            }

            if (playerTwo == 'c' ){
                gamesC = gamesC + 1;

                if ( choiceOne == choiceTwo ){
                    if ( strengthOne > strengthTwo ){
                        winsA = winsA + 1;
                        lostC = lostC + 1;
                    }
                    if ( strengthOne < strengthTwo ){
                        winsC = winsC + 1;
                        lostA = lostA + 1;
                    }
                    if ( strengthOne == strengthTwo ){
                        drawsA = drawsA + 1;
                        drawsC = drawsC + 1;
                    }
                }

                else{
                    if ( choiceOne == 'K' ){
                        if ( choiceTwo == 'N' || choiceTwo == 'J' ){
                            winsA = winsA + 1;
                            lostC = lostC + 1;
                        }
                        else{
                            winsC = winsC + 1;
                            lostA = lostA + 1;
                        }
                    }
                    if ( choiceOne == 'P' ){
                        if ( choiceTwo == 'K' || choiceTwo == 'S' ){
                            winsA = winsA + 1;
                            lostC = lostC + 1;
                        }
                        else{
                            winsC = winsC + 1;
                            lostA = lostA + 1;
                        }
                    }
                    if ( choiceOne == 'N' ){
                        if ( choiceTwo == 'P' || choiceTwo == 'J' ){
                            winsA = winsA + 1;
                            lostC = lostC + 1;
                        }
                        else{
                            winsC = winsC + 1;
                            lostA = lostA + 1;
                        }
                    }
                    if ( choiceOne == 'J' ){
                        if ( choiceTwo == 'P' || choiceTwo == 'S' ){
                            winsA = winsA + 1;
                            lostC = lostC + 1;
                        }
                        else{
                            winsC = winsC + 1;
                            lostA = lostA + 1;
                        }
                    }
                    if ( choiceOne == 'S' ){
                        if ( choiceTwo == 'N' || choiceTwo == 'K' ){
                            winsA = winsA + 1;
                            lostC = lostC + 1;
                        }
                        else{
                            winsC = winsC + 1;
                            lostA = lostA + 1;
                        }
                    }
                }
            }

            if (playerTwo == 'd' ){
                gamesD = gamesD + 1;

                if ( choiceOne == choiceTwo ){
                    if ( strengthOne > strengthTwo ){
                        winsA = winsA + 1;
                        lostD = lostD + 1;
                    }
                    if ( strengthOne < strengthTwo ){
                        winsD = winsD + 1;
                        lostA = lostA + 1;
                    }
                    if ( strengthOne == strengthTwo ){
                        drawsA = drawsA + 1;
                        drawsD = drawsD + 1;
                    }
                }

                else{
                    if ( choiceOne == 'K' ){
                        if ( choiceTwo == 'N' || choiceTwo == 'J' ){
                            winsA = winsA + 1;
                            lostD = lostD + 1;
                        }
                        else{
                            winsD = winsD + 1;
                            lostA = lostA + 1;
                        }
                    }
                    if ( choiceOne == 'P' ){
                        if ( choiceTwo == 'K' || choiceTwo == 'S' ){
                            winsA = winsA + 1;
                            lostD = lostD + 1;
                        }
                        else{
                            winsD = winsD + 1;
                            lostA = lostA + 1;
                        }
                    }
                    if ( choiceOne == 'N' ){
                        if ( choiceTwo == 'P' || choiceTwo == 'J' ){
                            winsA = winsA + 1;
                            lostD = lostD + 1;
                        }
                        else{
                            winsD = winsD + 1;
                            lostA = lostA + 1;
                        }
                    }
                    if ( choiceOne == 'J' ){
                        if ( choiceTwo == 'P' || choiceTwo == 'S' ){
                            winsA = winsA + 1;
                            lostD = lostD + 1;
                        }
                        else{
                            winsD = winsD + 1;
                            lostA = lostA + 1;
                        }
                    }
                    if ( choiceOne == 'S' ){
                        if ( choiceTwo == 'N' || choiceTwo == 'K' ){
                            winsA = winsA + 1;
                            lostD = lostD + 1;
                        }
                        else{
                            winsD = winsD + 1;
                            lostA = lostA + 1;
                        }
                    }
                }
            }
        }

        if ( playerOne == 'b' ){
            gamesB = gamesB + 1;
            if (playerTwo == 'a' ){
                gamesA = gamesA + 1;

                if ( choiceOne == choiceTwo ){
                    if ( strengthOne > strengthTwo ){
                        winsB = winsB + 1;
                        lostA = lostA + 1;
                    }
                    if ( strengthOne < strengthTwo ){
                        winsA = winsA + 1;
                        lostB = lostB + 1;
                    }
                    if ( strengthOne == strengthTwo ){
                        drawsB = drawsB + 1;
                        drawsA = drawsA + 1;
                    }
                }

                else{
                    if ( choiceOne == 'K' ){
                        if ( choiceTwo == 'N' || choiceTwo == 'J' ){
                            winsB = winsB + 1;
                            lostA = lostA + 1;
                        }
                        else{
                            winsA = winsA + 1;
                            lostB = lostB + 1;
                        }
                    }
                    if ( choiceOne == 'P' ){
                        if ( choiceTwo == 'K' || choiceTwo == 'S' ){
                            winsB = winsB + 1;
                            lostA = lostA + 1;
                        }
                        else{
                            winsA = winsA + 1;
                            lostB = lostB + 1;
                        }
                    }
                    if ( choiceOne == 'N' ){
                        if ( choiceTwo == 'P' || choiceTwo == 'J' ){
                            winsB = winsB + 1;
                            lostA = lostA + 1;
                        }
                        else{
                            winsA = winsA + 1;
                            lostB = lostB + 1;
                        }
                    }
                    if ( choiceOne == 'J' ){
                        if ( choiceTwo == 'P' || choiceTwo == 'S' ){
                            winsB = winsB + 1;
                            lostA = lostA + 1;
                        }
                        else{
                            winsA = winsA + 1;
                            lostB = lostB + 1;
                        }
                    }
                    if ( choiceOne == 'S' ){
                        if ( choiceTwo == 'N' || choiceTwo == 'K' ){
                            winsB = winsB + 1;
                            lostA = lostA + 1;
                        }
                        else{
                            winsA = winsA + 1;
                            lostB = lostB + 1;
                        }
                    }
                }
            }

            if (playerTwo == 'c' ){
                gamesC = gamesC + 1;

                if ( choiceOne == choiceTwo ){
                    if ( strengthOne > strengthTwo ){
                        winsB = winsB + 1;
                        lostC = lostC + 1;
                    }
                    if ( strengthOne < strengthTwo ){
                        winsC = winsC + 1;
                        lostB = lostB + 1;
                    }
                    if ( strengthOne == strengthTwo ){
                        drawsB = drawsB + 1;
                        drawsC = drawsC + 1;
                    }
                }

                else{
                    if ( choiceOne == 'K' ){
                        if ( choiceTwo == 'N' || choiceTwo == 'J' ){
                            winsB = winsB + 1;
                            lostC = lostC + 1;
                        }
                        else{
                            winsC = winsC + 1;
                            lostB = lostB + 1;
                        }
                    }
                    if ( choiceOne == 'P' ){
                        if ( choiceTwo == 'K' || choiceTwo == 'S' ){
                            winsB = winsB + 1;
                            lostC = lostC + 1;
                        }
                        else{
                            winsC = winsC + 1;
                            lostB = lostB + 1;
                        }
                    }
                    if ( choiceOne == 'N' ){
                        if ( choiceTwo == 'P' || choiceTwo == 'J' ){
                            winsB = winsB + 1;
                            lostC = lostC + 1;
                        }
                        else{
                            winsC = winsC + 1;
                            lostB = lostB + 1;
                        }
                    }
                    if ( choiceOne == 'J' ){
                        if ( choiceTwo == 'P' || choiceTwo == 'S' ){
                            winsB = winsB + 1;
                            lostC = lostC + 1;
                        }
                        else{
                            winsC = winsC + 1;
                            lostB = lostB + 1;
                        }
                    }
                    if ( choiceOne == 'S' ){
                        if ( choiceTwo == 'N' || choiceTwo == 'K' ){
                            winsB = winsB + 1;
                            lostC = lostC + 1;
                        }
                        else{
                            winsC = winsC + 1;
                            lostB = lostB + 1;
                        }
                    }
                }
            }

            if (playerTwo == 'd' ){
                gamesD = gamesD + 1;

                if ( choiceOne == choiceTwo ){
                    if ( strengthOne > strengthTwo ){
                        winsB = winsB + 1;
                        lostD = lostD + 1;
                    }
                    if ( strengthOne < strengthTwo ){
                        winsD = winsD + 1;
                        lostB = lostB + 1;
                    }
                    if ( strengthOne == strengthTwo ){
                        drawsB = drawsB + 1;
                        drawsD = drawsD + 1;
                    }
                }

                else{
                    if ( choiceOne == 'K' ){
                        if ( choiceTwo == 'N' || choiceTwo == 'J' ){
                            winsB = winsB + 1;
                            lostD = lostD + 1;
                        }
                        else{
                            winsD = winsD + 1;
                            lostB = lostB + 1;
                        }
                    }
                    if ( choiceOne == 'P' ){
                        if ( choiceTwo == 'K' || choiceTwo == 'S' ){
                            winsB = winsB + 1;
                            lostD = lostD + 1;
                        }
                        else{
                            winsD = winsD + 1;
                            lostB = lostB + 1;
                        }
                    }
                    if ( choiceOne == 'N' ){
                        if ( choiceTwo == 'P' || choiceTwo == 'J' ){
                            winsB = winsB + 1;
                            lostD = lostD + 1;
                        }
                        else{
                            winsD = winsD + 1;
                            lostB = lostB + 1;
                        }
                    }
                    if ( choiceOne == 'J' ){
                        if ( choiceTwo == 'P' || choiceTwo == 'S' ){
                            winsB = winsB + 1;
                            lostD = lostD + 1;
                        }
                        else{
                            winsD = winsD + 1;
                            lostB = lostB + 1;
                        }
                    }
                    if ( choiceOne == 'S' ){
                        if ( choiceTwo == 'N' || choiceTwo == 'K' ){
                            winsB = winsB + 1;
                            lostD = lostD + 1;
                        }
                        else{
                            winsD = winsD + 1;
                            lostB = lostB + 1;
                        }
                    }
                }
            }
        }

        if ( playerOne == 'c' ){
            gamesC = gamesC + 1;
            if (playerTwo == 'b' ){
                gamesB = gamesB + 1;

                if ( choiceOne == choiceTwo ){
                    if ( strengthOne > strengthTwo ){
                        winsC = winsC + 1;
                        lostB = lostB + 1;
                    }
                    if ( strengthOne < strengthTwo ){
                        winsB = winsB + 1;
                        lostC = lostC + 1;
                    }
                    if ( strengthOne == strengthTwo ){
                        drawsC = drawsC + 1;
                        drawsB = drawsB + 1;
                    }
                }

                else{
                    if ( choiceOne == 'K' ){
                        if ( choiceTwo == 'N' || choiceTwo == 'J' ){
                            winsC = winsC + 1;
                            lostB = lostB + 1;
                        }
                        else{
                            winsB = winsB + 1;
                            lostC = lostC + 1;
                        }
                    }
                    if ( choiceOne == 'P' ){
                        if ( choiceTwo == 'K' || choiceTwo == 'S' ){
                            winsC = winsC + 1;
                            lostB = lostB + 1;
                        }
                        else{
                            winsB = winsB + 1;
                            lostC = lostC + 1;
                        }
                    }
                    if ( choiceOne == 'N' ){
                        if ( choiceTwo == 'P' || choiceTwo == 'J' ){
                            winsC = winsC + 1;
                            lostB = lostB + 1;
                        }
                        else{
                            winsB = winsB + 1;
                            lostC = lostC + 1;
                        }
                    }
                    if ( choiceOne == 'J' ){
                        if ( choiceTwo == 'P' || choiceTwo == 'S' ){
                            winsC = winsC + 1;
                            lostB = lostB + 1;
                        }
                        else{
                            winsB = winsB + 1;
                            lostC = lostC + 1;
                        }
                    }
                    if ( choiceOne == 'S' ){
                        if ( choiceTwo == 'N' || choiceTwo == 'K' ){
                            winsC = winsC + 1;
                            lostB = lostB + 1;
                        }
                        else{
                            winsB = winsB + 1;
                            lostC = lostC + 1;
                        }
                    }
                }
            }

            if (playerTwo == 'a' ){
                gamesA = gamesA + 1;

                if ( choiceOne == choiceTwo ){
                    if ( strengthOne > strengthTwo ){
                        winsC = winsC + 1;
                        lostA = lostA + 1;
                    }
                    if ( strengthOne < strengthTwo ){
                        winsA = winsA + 1;
                        lostC = lostC + 1;
                    }
                    if ( strengthOne == strengthTwo ){
                        drawsC = drawsC + 1;
                        drawsA = drawsA + 1;
                    }
                }

                else{
                    if ( choiceOne == 'K' ){
                        if ( choiceTwo == 'N' || choiceTwo == 'J' ){
                            winsC = winsC + 1;
                            lostA = lostA + 1;
                        }
                        else{
                            winsA = winsA + 1;
                            lostC = lostC + 1;
                        }
                    }
                    if ( choiceOne == 'P' ){
                        if ( choiceTwo == 'K' || choiceTwo == 'S' ){
                            winsC = winsC + 1;
                            lostA = lostA + 1;
                        }
                        else{
                            winsA = winsA + 1;
                            lostC = lostC + 1;
                        }
                    }
                    if ( choiceOne == 'N' ){
                        if ( choiceTwo == 'P' || choiceTwo == 'J' ){
                            winsC = winsC + 1;
                            lostA = lostA + 1;
                        }
                        else{
                            winsA = winsA + 1;
                            lostC = lostC + 1;
                        }
                    }
                    if ( choiceOne == 'J' ){
                        if ( choiceTwo == 'P' || choiceTwo == 'S' ){
                            winsC = winsC + 1;
                            lostA = lostA + 1;
                        }
                        else{
                            winsA = winsA + 1;
                            lostC = lostC + 1;
                        }
                    }
                    if ( choiceOne == 'S' ){
                        if ( choiceTwo == 'N' || choiceTwo == 'K' ){
                            winsC = winsC + 1;
                            lostA = lostA + 1;
                        }
                        else{
                            winsA = winsA + 1;
                            lostC = lostC + 1;
                        }
                    }
                }
            }

            if (playerTwo == 'd' ){
                gamesD = gamesD + 1;

                if ( choiceOne == choiceTwo ){
                    if ( strengthOne > strengthTwo ){
                        winsC = winsC + 1;
                        lostD = lostD + 1;
                    }
                    if ( strengthOne < strengthTwo ){
                        winsD = winsD + 1;
                        lostC = lostC + 1;
                    }
                    if ( strengthOne == strengthTwo ){
                        drawsC = drawsC + 1;
                        drawsD = drawsD + 1;
                    }
                }

                else{
                    if ( choiceOne == 'K' ){
                        if ( choiceTwo == 'N' || choiceTwo == 'J' ){
                            winsC = winsC + 1;
                            lostD = lostD + 1;
                        }
                        else{
                            winsD = winsD + 1;
                            lostC = lostC + 1;
                        }
                    }
                    if ( choiceOne == 'P' ){
                        if ( choiceTwo == 'K' || choiceTwo == 'S' ){
                            winsC = winsC + 1;
                            lostD = lostD + 1;
                        }
                        else{
                            winsD = winsD + 1;
                            lostC = lostC + 1;
                        }
                    }
                    if ( choiceOne == 'N' ){
                        if ( choiceTwo == 'P' || choiceTwo == 'J' ){
                            winsC = winsC + 1;
                            lostD = lostD + 1;
                        }
                        else{
                            winsD = winsD + 1;
                            lostC = lostC + 1;
                        }
                    }
                    if ( choiceOne == 'J' ){
                        if ( choiceTwo == 'P' || choiceTwo == 'S' ){
                            winsC = winsC + 1;
                            lostD = lostD + 1;
                        }
                        else{
                            winsD = winsD + 1;
                            lostC = lostC + 1;
                        }
                    }
                    if ( choiceOne == 'S' ){
                        if ( choiceTwo == 'N' || choiceTwo == 'K' ){
                            winsC = winsC + 1;
                            lostD = lostD + 1;
                        }
                        else{
                            winsD = winsD + 1;
                            lostC = lostC + 1;
                        }
                    }
                }
            }
        }
        if ( playerOne == 'd' ){
            gamesD = gamesD + 1;
            if (playerTwo == 'b' ){
                gamesB = gamesB + 1;

                if ( choiceOne == choiceTwo ){
                    if ( strengthOne > strengthTwo ){
                        winsD = winsD + 1;
                        lostB = lostB + 1;
                    }
                    if ( strengthOne < strengthTwo ){
                        winsB = winsB + 1;
                        lostD = lostD + 1;
                    }
                    if ( strengthOne == strengthTwo ){
                        drawsD = drawsD + 1;
                        drawsB = drawsB + 1;
                    }
                }

                else{
                    if ( choiceOne == 'K' ){
                        if ( choiceTwo == 'N' || choiceTwo == 'J' ){
                            winsD = winsD + 1;
                            lostB = lostB + 1;
                        }
                        else{
                            winsB = winsB + 1;
                            lostD = lostD + 1;
                        }
                    }
                    if ( choiceOne == 'P' ){
                        if ( choiceTwo == 'K' || choiceTwo == 'S' ){
                            winsD = winsD + 1;
                            lostB = lostB + 1;
                        }
                        else{
                            winsB = winsB + 1;
                            lostD = lostD + 1;
                        }
                    }
                    if ( choiceOne == 'N' ){
                        if ( choiceTwo == 'P' || choiceTwo == 'J' ){
                            winsD = winsD + 1;
                            lostB = lostB + 1;
                        }
                        else{
                            winsB = winsB + 1;
                            lostD = lostD + 1;
                        }
                    }
                    if ( choiceOne == 'J' ){
                        if ( choiceTwo == 'P' || choiceTwo == 'S' ){
                            winsD = winsD + 1;
                            lostB = lostB + 1;
                        }
                        else{
                            winsB = winsB + 1;
                            lostD = lostD + 1;
                        }
                    }
                    if ( choiceOne == 'S' ){
                        if ( choiceTwo == 'N' || choiceTwo == 'K' ){
                            winsD = winsD + 1;
                            lostB = lostB + 1;
                        }
                        else{
                            winsB = winsB + 1;
                            lostD = lostD + 1;
                        }
                    }
                }
            }

            if (playerTwo == 'c' ){
                gamesC = gamesC + 1;

                if ( choiceOne == choiceTwo ){
                    if ( strengthOne > strengthTwo ){
                        winsD = winsD + 1;
                        lostC = lostC + 1;
                    }
                    if ( strengthOne < strengthTwo ){
                        winsC = winsC + 1;
                        lostD = lostD + 1;
                    }
                    if ( strengthOne == strengthTwo ){
                        drawsD = drawsD + 1;
                        drawsC = drawsC + 1;
                    }
                }

                else{
                    if ( choiceOne == 'K' ){
                        if ( choiceTwo == 'N' || choiceTwo == 'J' ){
                            winsD = winsD + 1;
                            lostC = lostC + 1;
                        }
                        else{
                            winsC = winsC + 1;
                            lostD = lostD + 1;
                        }
                    }
                    if ( choiceOne == 'P' ){
                        if ( choiceTwo == 'K' || choiceTwo == 'S' ){
                            winsD = winsD + 1;
                            lostC = lostC + 1;
                        }
                        else{
                            winsC = winsC + 1;
                            lostD = lostD + 1;
                        }
                    }
                    if ( choiceOne == 'N' ){
                        if ( choiceTwo == 'P' || choiceTwo == 'J' ){
                            winsD = winsD + 1;
                            lostC = lostC + 1;
                        }
                        else{
                            winsC = winsC + 1;
                            lostD = lostD + 1;
                        }
                    }
                    if ( choiceOne == 'J' ){
                        if ( choiceTwo == 'P' || choiceTwo == 'S' ){
                            winsD = winsD + 1;
                            lostC = lostC + 1;
                        }
                        else{
                            winsC = winsC + 1;
                            lostD = lostD + 1;
                        }
                    }
                    if ( choiceOne == 'S' ){
                        if ( choiceTwo == 'N' || choiceTwo == 'K' ){
                            winsD = winsD + 1;
                            lostC = lostC + 1;
                        }
                        else{
                            winsC = winsC + 1;
                            lostD = lostD + 1;
                        }
                    }
                }
            }

            if (playerTwo == 'a' ){
                gamesA = gamesA + 1;

                if ( choiceOne == choiceTwo ){
                    if ( strengthOne > strengthTwo ){
                        winsD = winsD + 1;
                        lostA = lostA + 1;
                    }
                    if ( strengthOne < strengthTwo ){
                        winsA = winsA + 1;
                        lostD = lostD + 1;
                    }
                    if ( strengthOne == strengthTwo ){
                        drawsD = drawsD + 1;
                        drawsA = drawsA + 1;
                    }
                }

                else{
                    if ( choiceOne == 'K' ){
                        if ( choiceTwo == 'N' || choiceTwo == 'J' ){
                            winsD = winsD + 1;
                            lostA = lostA + 1;
                        }
                        else{
                            winsA = winsA + 1;
                            lostD = lostD + 1;
                        }
                    }
                    if ( choiceOne == 'P' ){
                        if ( choiceTwo == 'K' || choiceTwo == 'S' ){
                            winsD = winsD + 1;
                            lostA = lostA + 1;
                        }
                        else{
                            winsA = winsA + 1;
                            lostD = lostD + 1;
                        }
                    }
                    if ( choiceOne == 'N' ){
                        if ( choiceTwo == 'P' || choiceTwo == 'J' ){
                            winsD = winsD + 1;
                            lostA = lostA + 1;
                        }
                        else{
                            winsA = winsA + 1;
                            lostD = lostD + 1;
                        }
                    }
                    if ( choiceOne == 'J' ){
                        if ( choiceTwo == 'P' || choiceTwo == 'S' ){
                            winsD = winsD + 1;
                            lostA = lostA + 1;
                        }
                        else{
                            winsA = winsA + 1;
                            lostD = lostD + 1;
                        }
                    }
                    if ( choiceOne == 'S' ){
                        if ( choiceTwo == 'N' || choiceTwo == 'K' ){
                            winsD = winsD + 1;
                            lostA = lostA + 1;
                        }
                        else{
                            winsA = winsA + 1;
                            lostD = lostD + 1;
                        }
                    }
                }
            }
        }
    }


    if ( gamesA > 0 ){
        cout << "gracz a" << endl;
        outHelp = 1;
        if ( winsA > 0 ){
            cout << "    wygrane: " << ( winsA * 100.0 / gamesA ) << "%" << endl;
        }
        if ( drawsA > 0 ){
            cout << "    remisy: " << ( drawsA * 100.0 / gamesA ) << "%" << endl;
        }
        if ( lostA > 0 ){
            cout << "    przegrane: " << ( lostA * 100.0 / gamesA ) << "%" << endl;
        }
    }
    if ( gamesB > 0 ){
        if ( outHelp == 1 )
            cout << endl;
        cout << "gracz b" << endl;
        outHelp = 1;
        if ( winsB > 0 ){
            cout << "    wygrane: " << ( winsB * 100.0 / gamesB ) << "%" << endl;
        }
        if ( drawsB > 0 ){
            cout << "    remisy: " << ( drawsB * 100.0 / gamesB ) << "%" << endl;
        }
        if ( lostB > 0 ){
            cout << "    przegrane: " << ( lostB * 100.0 / gamesB ) << "%" << endl;
        }
    }
    if ( gamesC > 0 ){
        if ( outHelp == 1 )
            cout << endl;
        cout << "gracz c" << endl;
        outHelp = 1;
        if ( winsC > 0 ){
            cout << "    wygrane: " << ( winsC * 100.0 / gamesC ) << "%" << endl;
        }
        if ( drawsC > 0 ){
            cout << "    remisy: " << ( drawsC * 100.0 / gamesC ) << "%" << endl;
        }
        if ( lostC > 0 ){
            cout << "    przegrane: " << ( lostC * 100.0 / gamesC ) << "%" << endl;
        }
    }
    if ( gamesD > 0 ){
        if ( outHelp == 1 )
            cout << endl;
        cout << "gracz d" << endl;
        if ( winsD > 0 ){
            cout << "    wygrane: " << ( winsD * 100.0 / gamesD ) << "%" << endl;
        }
        if ( drawsD > 0 ){
            cout << "    remisy: " << ( drawsD * 100.0 / gamesD ) << "%" << endl;
        }
        if ( lostD > 0 ){
            cout << "    przegrane: " << ( lostD * 100.0 / gamesD ) << "%" << endl;
        }
    }
}
