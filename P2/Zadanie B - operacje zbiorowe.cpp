// Lukasz Rudnik

#include <iostream>
using namespace std;

int StrToInt ( int one, int two, int three, int four, int five ){
    return ( one - 48 ) * 16 + ( two - 48 ) * 8 + ( three - 48 ) * 4 + ( four - 48 ) * 2 + ( five - 48 );
    }

void Add ( int val, int* rep ){
    *rep = *rep | ( 1 << val );
    }

void Remove ( int val, int* rep ){
    *rep = *rep & ~( 1 << val );
    }

void Insert ( char* str, int* rep ){
    if ( *str != 0 ){
        if ( *str != ' ' ){
            Add ( StrToInt ( *str, *( str + 1 ), *( str + 2 ), *( str + 3 ), *( str + 4 ) ), rep );
            Insert ( str + 5, rep );
            }
        else
            Insert ( str + 1, rep );
        }
    }

void Emplace ( char* str, int* rep ){
    *rep = 0;
    Insert ( str, rep );
    }

void Erase ( char* str, int* rep ){
    if ( *str != 0 ){
        if ( *str != ' ' ){
            Remove ( StrToInt ( *str, *( str + 1 ), *( str + 2 ), *( str + 3 ), *( str + 4 ) ), rep );
            Erase ( str + 5, rep );
            }
        else
            Erase ( str + 1, rep );
        }
    }


bool Emptiness ( int rep ){
    return !rep;
    }

bool Nonempty ( int rep ){
    return rep;
    }

void PrintAux ( int val, char* str ){
    *( str + 4 ) = ( val % 2 ) + 48;
    val /= 2;
    *( str + 3 ) = ( val % 2 ) + 48;
    val /= 2;
    *( str + 2 ) = ( val % 2 ) + 48;
    val /= 2;
    *( str + 1 ) = ( val % 2 ) + 48;
    val /= 2;
    *( str ) = ( val % 2 ) + 48;
    }

void Print ( int rep, char* str ){
    int first = 1;
    int i = 0;
    int val = 31;

    if ( rep == 0 ){
        *str = 'e';
        *( str + 1 ) = 'm';
        *( str + 2 ) = 'p';
        *( str + 3 ) = 't';
        *( str + 4 ) = 'y';
        *( str + 5 ) = 0;
        }
    else{
        if ( rep & ( 1 << val ) ){
            if ( ! first ){
                *( str + i ) = ' ';
                i++;
                }
            PrintAux ( val, str + i );
            first = 0;
            i += 5;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            if ( ! first ){
                *( str + i ) = ' ';
                i++;
                }
            PrintAux ( val, str + i );
            first = 0;
            i += 5;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            if ( ! first ){
                *( str + i ) = ' ';
                i++;
                }
            PrintAux ( val, str + i );
            first = 0;
            i += 5;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            if ( ! first ){
                *( str + i ) = ' ';
                i++;
                }
            PrintAux ( val, str + i );
            first = 0;
            i += 5;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            if ( ! first ){
                *( str + i ) = ' ';
                i++;
                }
            PrintAux ( val, str + i );
            first = 0;
            i += 5;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            if ( ! first ){
                *( str + i ) = ' ';
                i++;
                }
            PrintAux ( val, str + i );
            first = 0;
            i += 5;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            if ( ! first ){
                *( str + i ) = ' ';
                i++;
                }
            PrintAux ( val, str + i );
            first = 0;
            i += 5;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            if ( ! first ){
                *( str + i ) = ' ';
                i++;
                }
            PrintAux ( val, str + i );
            first = 0;
            i += 5;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            if ( ! first ){
                *( str + i ) = ' ';
                i++;
                }
            PrintAux ( val, str + i );
            first = 0;
            i += 5;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            if ( ! first ){
                *( str + i ) = ' ';
                i++;
                }
            PrintAux ( val, str + i );
            first = 0;
            i += 5;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            if ( ! first ){
                *( str + i ) = ' ';
                i++;
                }
            PrintAux ( val, str + i );
            first = 0;
            i += 5;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            if ( ! first ){
                *( str + i ) = ' ';
                i++;
                }
            PrintAux ( val, str + i );
            first = 0;
            i += 5;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            if ( ! first ){
                *( str + i ) = ' ';
                i++;
                }
            PrintAux ( val, str + i );
            first = 0;
            i += 5;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            if ( ! first ){
                *( str + i ) = ' ';
                i++;
                }
            PrintAux ( val, str + i );
            first = 0;
            i += 5;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            if ( ! first ){
                *( str + i ) = ' ';
                i++;
                }
            PrintAux ( val, str + i );
            first = 0;
            i += 5;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            if ( ! first ){
                *( str + i ) = ' ';
                i++;
                }
            PrintAux ( val, str + i );
            first = 0;
            i += 5;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            if ( ! first ){
                *( str + i ) = ' ';
                i++;
                }
            PrintAux ( val, str + i );
            first = 0;
            i += 5;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            if ( ! first ){
                *( str + i ) = ' ';
                i++;
                }
            PrintAux ( val, str + i );
            first = 0;
            i += 5;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            if ( ! first ){
                *( str + i ) = ' ';
                i++;
                }
            PrintAux ( val, str + i );
            first = 0;
            i += 5;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            if ( ! first ){
                *( str + i ) = ' ';
                i++;
                }
            PrintAux ( val, str + i );
            first = 0;
            i += 5;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            if ( ! first ){
                *( str + i ) = ' ';
                i++;
                }
            PrintAux ( val, str + i );
            first = 0;
            i += 5;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            if ( ! first ){
                *( str + i ) = ' ';
                i++;
                }
            PrintAux ( val, str + i );
            first = 0;
            i += 5;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            if ( ! first ){
                *( str + i ) = ' ';
                i++;
                }
            PrintAux ( val, str + i );
            first = 0;
            i += 5;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            if ( ! first ){
                *( str + i ) = ' ';
                i++;
                }
            PrintAux ( val, str + i );
            first = 0;
            i += 5;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            if ( ! first ){
                *( str + i ) = ' ';
                i++;
                }
            PrintAux ( val, str + i );
            first = 0;
            i += 5;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            if ( ! first ){
                *( str + i ) = ' ';
                i++;
                }
            PrintAux ( val, str + i );
            first = 0;
            i += 5;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            if ( ! first ){
                *( str + i ) = ' ';
                i++;
                }
            PrintAux ( val, str + i );
            first = 0;
            i += 5;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            if ( ! first ){
                *( str + i ) = ' ';
                i++;
                }
            PrintAux ( val, str + i );
            first = 0;
            i += 5;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            if ( ! first ){
                *( str + i ) = ' ';
                i++;
                }
            PrintAux ( val, str + i );
            first = 0;
            i += 5;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            if ( ! first ){
                *( str + i ) = ' ';
                i++;
                }
            PrintAux ( val, str + i );
            first = 0;
            i += 5;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            if ( ! first ){
                *( str + i ) = ' ';
                i++;
                }
            PrintAux ( val, str + i );
            first = 0;
            i += 5;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            if ( ! first ){
                *( str + i ) = ' ';
                i++;
                }
            PrintAux ( val, str + i );
            first = 0;
            i += 5;
            }
        *( str + i ) = 0;
        }
    }

bool Member ( char* str, int rep ){
    if ( *str != 0 ){
        if ( *str != ' ' ){
            int val = StrToInt ( *str, *( str + 1 ), *( str + 2 ), *( str + 3 ), *( str + 4 ) );
            return rep & ( 1 << val );
            }
        else
            Member ( str + 1, rep );
        }
    }

bool Disjoint ( int repOne, int repTwo ){
    return !( repOne & repTwo );
    }

bool Conjunctive ( int repOne, int repTwo ){
    return repOne & repTwo;
    }

bool Equality ( int repOne, int repTwo ){
    if ( repOne == repTwo )
        return true;
    else
        return false;
    }

bool Inclusion ( int repOne, int repTwo ){
    if ( ( repOne & repTwo ) == repOne )
        return true;
    else
        return false;
    }

void Union ( int repOne, int repTwo, int* repOut ){
    *repOut =  repOne | repTwo;
    }

void Intersection ( int repOne, int repTwo, int* repOut ){
    *repOut = repOne & repTwo;
    }

void Symmetric ( int repOne, int repTwo, int* repOut ){
    *repOut =  repOne ^ repTwo;
    }

void Difference ( int repOne, int repTwo, int* repOut ){
    *repOut = repOne & ~repTwo;
    }

void Complement ( int rep, int* repOut ){
    *repOut = ~rep;
    }

int Cardinality ( int rep ){
    int card = 0;
    int val = 31;

    if ( !rep ){
        return 0;
        }
    else{
        if ( rep & ( 1 << val ) ){
            card++;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            card++;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            card++;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            card++;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            card++;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            card++;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            card++;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            card++;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            card++;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            card++;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            card++;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            card++;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            card++;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            card++;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            card++;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            card++;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            card++;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            card++;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            card++;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            card++;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            card++;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            card++;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            card++;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            card++;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            card++;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            card++;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            card++;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            card++;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            card++;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            card++;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            card++;
            }
        val--;
        if ( rep & ( 1 << val ) ){
            card++;
            }
        return card;
    }
}

bool LessThan ( int repOne, int repTwo ){
    if ( Cardinality ( repOne ) < Cardinality ( repTwo ) )
        return true;
    else if ( Cardinality ( repOne ) > Cardinality ( repTwo ) )
        return false;
    else{
        if ( repOne == repTwo )
            return false;
        if ( repOne < 0 && repTwo > 0 )
            return false;
        if ( repOne > 0 && repTwo < 0 )
            return true;
        if ( repOne > 0 && repTwo > 0 ){
            if ( repOne > repTwo )
                return false;
            else
                return true;
            }
        else{
            repOne = repOne ^ ( 1 << 31 );
            repTwo = repTwo ^ ( 1 << 31 );
            if ( repOne > repTwo )
                return false;
            else
                return true;
            }
        }
    }

bool LessEqual ( int repOne, int repTwo ){
    if ( LessThan ( repOne, repTwo ) || Equality ( repOne, repTwo ))
        return true;
    else return false;
    }

bool GreatEqual ( int repOne, int repTwo ){
    return !LessThan ( repOne, repTwo );
    }

bool GreatThan ( int repOne, int repTwo ){
    return !LessEqual ( repOne, repTwo );
    }


int main(){
    char strOne [] = "     00001   00001   00010 00000";
    char strTwo [ 1000 ];
    char strThree [] = "   00001  ";
    int rep = 0;
    Insert ( strOne, &rep );
    cout << rep << endl;
    Print ( rep, strTwo );
    cout << strTwo << endl;
    cout << Member ( strThree, rep ) << endl;
    cout << Cardinality ( rep ) << endl;
    Erase ( strThree, &rep );
    cout << Cardinality ( rep ) << endl;

    cout << "----------------------" << endl;
    char strFour [] = "00001 00010 00000 ";
    int repOne;
    int repTwo;
    Emplace ( strOne, &repOne );
    Emplace ( strFour, &repTwo );
    cout << repOne << endl << repTwo << endl;
    cout << LessEqual ( repOne, repTwo ) << endl;

    cout << "----------------------" << endl;
    char strFive [] = "00001 10001 11010 01100 10111 01010 00101 11111 00000 11001 10100 01111 10010 01001 11100 00111 01110 10011 11000 10101";
    Emplace ( strFive, &rep );
    Print ( rep, strTwo );
    cout << strTwo << endl;
    cout << rep << " " << ~rep << endl;
    Complement ( rep, &repTwo );
    Print ( repTwo, strTwo );
    cout << strTwo << endl;

    cout << "----------------------" << endl;
    char aaa [1000];
    char bbb [1000];
    Print ( 2024949077, aaa );
    Print ( 1163229362, bbb );
    cout << aaa << endl << bbb << endl;

    cout << LessThan ( 2024949077, 1163229362 );


}

