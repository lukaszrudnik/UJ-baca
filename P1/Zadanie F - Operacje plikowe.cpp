// Lukasz Rudnik

#include <iostream>
#include <string>
#include <fstream>
using namespace std;


struct SET{
    int numInt;
    string txt;
    char ch;
    struct COMPONENT{
        bool logic;
        unsigned char numCh;
        float real;
        } compOne, compTwo, compThree, compFour;

    };

void Read ( fstream& in, SET& Set ){
    string trash;
    int chHelp;

    in >> Set.numInt;
    getline ( in, trash );

    getline ( in, Set.txt );
    in >> Set.ch;


    in >> Set.compOne.logic >> chHelp >> Set.compOne.real;
    Set.compOne.numCh = chHelp;

    in >> Set.compTwo.logic >> chHelp >> Set.compTwo.real;
    Set.compTwo.numCh = chHelp;

    in >> Set.compThree.logic >> chHelp >> Set.compThree.real;
    Set.compThree.numCh = chHelp;

    in >> Set.compFour.logic >> chHelp >> Set.compFour.real;
    Set.compFour.numCh = chHelp;

    }

void Write ( fstream& out, SET& Set ){
    int chHelp;
    out << Set.numInt << endl << Set.txt << endl << Set.ch << endl;

    out << Set.compOne.logic << " ";
    chHelp = Set.compOne.numCh;
    out << chHelp << " " << Set.compOne.real << endl;

    out << Set.compTwo.logic << " ";
    chHelp = Set.compTwo.numCh;
    out << chHelp << " " << Set.compTwo.real << endl;

    out << Set.compThree.logic << " ";
    chHelp = Set.compThree.numCh;
    out << chHelp << " " << Set.compThree.real << endl;

    out << Set.compFour.logic << " ";
    chHelp = Set.compFour.numCh;
    out << chHelp << " " << Set.compFour.real << endl;

    }

bool Equal ( SET& setOne, SET& setTwo ){
    if ( setOne.numInt != setTwo.numInt )
        return false;
    if ( setOne.txt != setTwo.txt )
        return false;
    if ( setOne.ch != setTwo.ch )
        return false;


    if ( setOne.compOne.logic != setTwo.compOne.logic )
        return false;
    if ( setOne.compOne.numCh != setTwo.compOne.numCh )
        return false;
    if ( setOne.compOne.real != setTwo.compOne.real )
        return false;

    if ( setOne.compTwo.logic != setTwo.compTwo.logic )
        return false;
    if ( setOne.compTwo.numCh != setTwo.compTwo.numCh )
        return false;
    if ( setOne.compTwo.real != setTwo.compTwo.real )
        return false;

    if ( setOne.compThree.logic != setTwo.compThree.logic )
        return false;
    if ( setOne.compThree.numCh != setTwo.compThree.numCh )
        return false;
    if ( setOne.compThree.real != setTwo.compThree.real )
        return false;

    if ( setOne.compFour.logic != setTwo.compFour.logic )
        return false;
    if ( setOne.compFour.numCh != setTwo.compFour.numCh )
        return false;
    if ( setOne.compFour.real != setTwo.compFour.real )
        return false;

    return true;
    }

void SymmetricDifference ( string oneName, string twoName, string helpName ){
    fstream fileOne;
    fstream fileTwo;
    fstream fileHelp;

    // przepisywanie pliku drugiego do pomocniczego
    fileTwo.open ( twoName.c_str(), fstream::in );
    fileHelp.open ( helpName.c_str(), fstream::out );
    string lineOne;
    string lineTwo;
    string lineHelp;
    do  {
        getline ( fileTwo, lineTwo );
        fileHelp << lineTwo << endl;
        if ( fileTwo.eof () )
            break;
        }
    while
        ( true );
    fileTwo.close();
    fileHelp.close();

    // czyszczenie pliku drugiego
    fileTwo.open ( twoName.c_str(), fstream::out | fstream::trunc );
    fileTwo.close();


    fileHelp.open ( helpName.c_str(), fstream::in | fstream::out );

    SET setOne;
    SET setHelp;
    bool occurs;

    do  {
        Read ( fileHelp, setHelp );
        if ( fileHelp.eof () )
            break;
        occurs = false;
        fileOne.open ( oneName.c_str(), fstream::in | fstream::out );
        do  {
            Read ( fileOne, setOne );
            if ( Equal ( setOne, setHelp ) ){
                occurs = true;
                break;
                }
            if ( fileOne.eof () )
                break;
            }
        while
            ( true );
        if ( occurs ){
            fileTwo.open ( twoName.c_str(), fstream::out | fstream::app );
            Write ( fileTwo, setHelp );
            fileTwo.close();
            }
        else{
            fileOne.close();
            fileOne.open ( oneName.c_str(), fstream::out | fstream::app );
            Write ( fileOne, setHelp );
            }
        fileOne.close();
        }
    while
        ( true );


    fileOne.close();
    fileTwo.close();
    fileHelp.close();

    // czyszczenie pliku pomocniczego
   // fileHelp.open ( helpName.c_str(), fstream::out | fstream::trunc );
    //fileHelp.close();
    }



void SortCount ( string a, string b, string c );


void SortInt ( string fileName, string helpOneName, string helpTwoName ){
    fstream file;
    fstream helpOne;
    fstream helpTwo;

    SET setOne;
    SET setTwo;

    bool mode = 0;

    file.open ( fileName.c_str(), fstream::in | fstream::out );


    //for ( int i =0; i<16; i++ ){
    helpOne.open ( helpOneName.c_str(), fstream::out | fstream::app );
    helpTwo.open ( helpTwoName.c_str(), fstream::out | fstream::app );
    do  {
        Read ( file, setOne );
        if ( file.eof () )
            break;
        Read ( file, setTwo );
        if ( mode == 0 ){
            if ( setOne.numInt < setTwo.numInt ){
                Write ( helpOne, setOne );
                }
            else{
                Write ( helpOne, setOne );
                mode = 1;
                }
            }
        else{
            if ( setOne.numInt < setTwo.numInt ){
                Write ( helpTwo, setOne );
                }
            else{
                Write ( helpTwo, setOne );
                mode = 1;
                }
            }

        }
    while
        ( true );
    helpOne.close();
    helpTwo.close();
    helpOne.open ( helpOneName.c_str(), fstream::in );
    helpTwo.open ( helpTwoName.c_str(), fstream::in );
    do  {
        Read ( helpOne, setOne );
        Read ( file, setTwo );
        if ( setOne.numInt < setTwo.numInt ){
            Write ( file, setOne );
            Read ( helpOne, setOne );
        }
        else{
            Write ( file, setTwo );
            Read ( helpOne, setOne );
        }

        if ( helpOne.eof () )
            break;
        }
    while
        ( true );

    helpOne.close();
    helpTwo.close();
   // }
    }


void SortString ( string a, string b, string c );

/*
void Test ( string a, string b, string c ){
    fstream fileOne;
    fstream fileTwo;
    fstream fileHelp;

    SET setOne, setTwo;
    fileOne.open( a.c_str(), fstream::in );
    Read ( fileOne, setOne );
    Read ( fileOne, setTwo );
    fileHelp.open( c.c_str(), fstream::out );
    Write ( fileHelp, setOne );
    Write ( fileHelp, setTwo );

    cout << Equal ( setOne, setOne );

    }



int main (){
    string a = "plik1.txt";
    string b = "plik2.txt";
    string c = "plikhelp.txt";

    SymmetricDifference ( a, b, c );
    //Test ( a, b, c );

    }*/
