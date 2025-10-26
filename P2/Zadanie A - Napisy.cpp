// Lukasz Rudnik
#include <iostream>
#include <string>

using namespace std;

string FormatujNapis ( string str, string argOne, string argTwo, string argThree ){
    int strSize = str.size();
    string strOut = "";
    string strAux;
    char c;
    int n;
    int m;

    int j = 0;
    int i = 0;
    while ( i < strSize ){
        while ( i < strSize && str [ i ] != '{' ){
            strOut += str [ i ];
            i++;
            }

        if ( i < strSize && str [ i ] == '{' ){
            if ( str [ i + 1 ] == 'p' ){
                n = str [ i + 3 ] - 48;
                c = str [ i + 5 ];

                j = 0;
                while ( j < n ){
                    strOut += c;
                    j++;
                    }
                i += 7;
                }

            else if ( str [ i + 1 ] == 'u' ){
                n = str [ i + 3 ] - 48;
                i += 5 + n;
                }
            else if ( str [ i + 1 ] == 'U' ){
                n = str [ i + 3 ] - 48;
                strOut.resize( strOut.size() - n );
                i += 5;
                }
            else if ( str [ i + 1 ] == 'w' ){
                n = str [ i + 3 ] - 48;
                if ( n == 1 )
                    strOut += argOne;
                else if ( n == 2 )
                    strOut += argTwo;
                else if ( n == 3 )
                    strOut += argThree;
                i += 5;
                }
            else if ( str [ i + 1 ] == 'W' ){
                n = str [ i + 3 ] - 48;
                m = str [ i + 5 ] - 48;

                if ( n == 1 )
                    strAux = argOne;
                else if ( n == 2 )
                    strAux = argTwo;
                else if ( n == 3 )
                    strAux = argThree;

                while ( strAux.size() < m )
                    strAux += ' ';
                strAux.resize ( m );

                strOut += strAux;

                i += 7;
                }

            }
        }

    return strOut;
    }

/////////////////////////////////////

string NajwiekszeSlowo ( string str ){
    int strSize = str.size();
    string maxWord = "";
    string curWord = "";

    int i = 0;
    while ( i < strSize ){
        while ( i < strSize && str [ i ] == ' ' )
            i++;
        curWord = "";

        while ( i < strSize && str [ i ] != ' ' ){
            curWord += str [ i ];
            i++;
            }

        if ( curWord > maxWord )
            maxWord = curWord;

        i++;
        }

    return maxWord;
    }

//////////////////////////////////////////////////

string UsunSlowo ( string str, int num ){
    if ( num == 0 )
        return str;
    int strSize = str.size();
    string strOut = str;

    int curNum = 0;
    int i = 0;
    while ( i < strSize ){
        while ( i < strSize && str [ i ] == ' ' )
            i++;
        curNum++;
        if ( curNum < num ){
            while ( i < strSize && str [ i ] != ' ' )
                i++;
            }
        if ( curNum == num ){
            strOut.resize( i );
            //cout << endl << '"' << strOut << '"' << endl;
            while ( i < strSize && str [ i ] != ' ' )
                i++;
            curNum++;
            }
        if ( curNum > num )
            while ( i < strSize ){
                strOut += str [ i ];
                i++;
                }
        i++;
        }

    return strOut;
    }

//////////////////////////////////////////////////

string NormalizujNapis ( string str ){
    int strSize = str.size();
    string strOut = "";

    bool firstWord = false;
    int i = 0;
    while ( i < strSize ){
        while ( i < strSize && !firstWord && str [ i ] == ' ' ){
            i++;
            }
        if ( !firstWord )
            firstWord = true;

        while ( i < strSize &&  ( str [ i ] != ' ' && str [ i ] != ',' && str [ i ] != '.' ) ){
            strOut += str [ i ];
            i++;
            }

        if ( i < strSize && str [ i ] == ' ' ){
            while ( i < strSize && str [ i ] == ' ' )
                i++;
            if ( str [ i ] != ',' && str [ i ] != '.' && strOut [ strOut.size() - 1 ] != ' ' )
                strOut += ' ';
            }

        if ( i < strSize && ( str [ i ] == ',' || str [ i ] == '.' ) ){
            strOut += str [ i ];
            strOut += ' ';
            i++;
            }
        }

    // korekta spacji na koncu
    strSize = strOut.size();
    while ( strOut [ strSize - 1 ] == ' ' ){
        strOut.resize( strSize - 1 );
        strSize--;
        }

    return strOut;
    }


int main(){

    //cout << '"' << NajwiekszeSlowo ( "Smok Wawelski ryczy ku uciesze gawiedzi" ) << '"' << endl;
    //cout << '"' << UsunSlowo ( "Smok Wawelski ryczy ku uciesze gawiedzi", 2) << '"' << endl;
    //cout << "\"   Oto Ala .   Ma   kota     ,lecz nie    ma  psa  .    \"" << endl;
    //cout << '"' << NormalizujNapis ( "   Oto Ala .   Ma   kota     ,lecz nie    ma  psa  .    " ) << '"' << endl;

    cout << "\"" << FormatujNapis ( "ABCD{p:5:x}X Y Z", "abc", "cdef", "xyz" ) << "\"" << endl;

    cout << "\"" << FormatujNapis ( "ABCD{u:3}X Y Z", "abc", "cdef", "xyz" ) << "\"" << endl;

    cout << "\"" << FormatujNapis ( "ABCD{U:2}X Y Z", "abc", "cdef", "xyz" ) << "\"" << endl;

    cout << "\"" << FormatujNapis ( "ABCD{w:2}X Y Z", "abc", "cdef", "xyz" ) << "\"" << endl;

    cout << "\"" << FormatujNapis ( "ABCD{W:2:3}X Y Z", "abc", "cdef", "xyz" ) << "\"" << endl;

    cout << "\"" << FormatujNapis ( "ABCD{W:2:5}X Y Z", "abc", "cdef", "xyz" ) << "\"" << endl;

    cout << "\"" << FormatujNapis ( "A{p:4:a}le {w:1}tra nudny t{w:1}t. {u:3}UsuCam{U:2}{W:2:3}{W:3:3}.", "eks", "zy", "niebyt") << "\"" << endl;


    }
