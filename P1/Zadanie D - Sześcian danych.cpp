// Lukasz Rudnik

// source.cpp to ten sam kod 1:1

#include <iostream>
using namespace std;

long long Determinant ( long long matrix [] [ 33 ], int n ){
    matrix [ 0 ] [ 0 ] = 1;
    int sign = 1;
    int temp;
    int index;

    for ( int k = 1; k <= n - 1; k++ ){
        for ( int i = k + 1; i <= n; i++ ){
            for ( int j = k + 1; j <= n; j++ ){
                /*
                for ( int a = 1; a <= n; a++ ){
                    for ( int b = 1; b <= n; b++ )
                        cout << matrix [ a ] [ b ] << " ";
                    cout << endl;
                    }
                cout << endl;
                */
                if ( matrix [ k ] [ k ] == 0 ){ // jak mamy zero na przekatnej to szukamy wiersza do zamiany
                    sign *= -1;
                    index = k + 1;
                    while ( index <= n ){ // szukamy takiego wiersza
                        //cout << endl << index << " - " << matrix [ index ] [ k - 1 ] << endl;
                        if ( matrix [ index ] [ k ] != 0 )
                            break;
                        index++;
                        }
                    if ( index > n ) // jesli nie znalazlo to wyznacznik = 0
                        return 0;
                    for ( int a = 1; a <= n;  a++ ){
                        temp = matrix [ index ] [ a ];
                        matrix [ index ] [ a ] = matrix [ k ] [ a ];
                        matrix [ k ] [ a ] = temp;
                        }
                    }
                matrix [ i ] [ j ] = ( matrix [ i ] [ j ] * matrix [ k ] [ k ] - matrix [ i ] [ k ] * matrix [ k ] [ j ] ) / matrix [ k - 1 ] [ k - 1 ];
                }
            matrix [ i ] [ k ] = 0;
            }
        }
    return matrix [ n ] [ n ] * sign;
    }

int main (){

    int n;
    long long cube [ 32 ] [ 32 ] [ 32 ];

    int l;
    int v;
    int p;
    int h;
    int w;
    int d;
    int e;
    int r;
    char k;
    int i;

    int lMin;
    int lMax;
    int vMin;
    int vMax;
    int pMin;
    int pMax;
    int prism;
    int tetrahedron;
    int aTetAbs;
    int bTetAbs;
    int cTetAbs;
    int octal;
    long long matrix [ 33 ] [ 33 ];

    cin >> n;
    for ( int d = 0; d < n; d++ )
        for ( int h = 0; h < n; h++ )
            for ( int w = 0; w < n; w ++ )
                cin >> cube [ h ] [ w ] [ d ];
/*
    for ( int d = 0; d < n; d++ ){
        for ( int h = 0; h < n; h++ ){
            for ( int w = 0; w < n; w ++ ){
                cout << cube [ h ] [ w ] [ d ] << " ";
                }
            cout << endl;
            }
        cout << " ------------- " << endl;
        }
*/
/*
    for ( int a = 1; a <= n; a++ )
        for ( int b = 1; b <= n; b++ )
            cin >> matrix [ a ] [ b ];
    cout << Determinant ( matrix, n );
*/

    char operation = 0;
    while ( operation != 'E' ){
        cin >> operation;
        if ( operation == 'C' ){
            cin >> l >> v >> p >> h >> w >> d;

            // koretka krawedzi wzgledem srodka szescianu danych
            if ( l >= n/2 )
                h = -h;
            if ( v >= n/2 )
                w = -w;
            if ( p >= n/2 )
                d = -d;

            // wyznaczanie minimalnych i maksymalnych wspolrzednych prostopadloscianu
            if ( l < l + h ){
                lMin = l;
                lMax = l + h;
                }
            else{
                lMin = l + h;
                lMax = l;
                }

            if ( v < v + w ){
                vMin = v;
                vMax = v + w;
                }
            else{
                vMin = v + w;
                vMax = v;
                }

            if ( p < p + d ){
                pMin = p;
                pMax = p + d;
                }
            else{
                pMin = p + d;
                pMax = p;
                }


            // przechodzac po szescianie danych sprawdzamy czy punkt nalezy do prostopadloscianu
            prism = 0;
            for ( int c = 0; c < n; c++ )
                for ( int a = 0; a < n; a++ )
                    for ( int b = 0; b < n; b ++ )
                        if ( ( a >= lMin && a <= lMax ) && ( b >= vMin && b <= vMax ) && ( c >= pMin && c <= pMax ) )
                            prism += cube [ a ] [ b ] [ c ];
            cout << prism << endl;
            }
        else if ( operation == 'T' ){
            cin >> l >> v >> p >> e;
            h = e;
            w = e;
            d = e;

            // koretka krawedzi wzgledem srodka szescianu danych
            if ( l >= n/2 )
                h = -h;
            if ( v >= n/2 )
                w = -w;
            if ( p >= n/2 )
                d = -d;

            // wyznaczanie minimalnych i maksymalnych wierzcholkow czworoscianu
            if ( l < l + h ){
                lMin = l;
                lMax = l + h;
                }
            else{
                lMin = l + h;
                lMax = l;
                }

            if ( v < v + w ){
                vMin = v;
                vMax = v + w;
                }
            else{
                vMin = v + w;
                vMax = v;
                }

            if ( p < p + d ){
                pMin = p;
                pMax = p + d;
                }
            else{
                pMin = p + d;
                pMax = p;
                }
//cout << "---" << lMin << " " << lMax << " | "<< vMin << " " << vMax << " | "<< pMin << " " << pMax << "---" << endl;
            // przechodzac po szescianie danych sprawdzamy czy punkt nalezy do malego szescianuj
            tetrahedron = 0;
            for ( int c = 0; c < n; c++ )
                for ( int a = 0; a < n; a++ )
                    for ( int b = 0; b < n; b ++ )
                        if ( ( a >= lMin && a <= lMax ) && ( b >= vMin && b <= vMax ) && ( c >= pMin && c <= pMax ) ){
                            //cout << "( " << a << " " << b << " " << c << " ) nalezy do malego cube" << endl;
                            aTetAbs = a - l;
                            if ( aTetAbs < 0 )
                                aTetAbs *= -1;
                            bTetAbs = b - v;
                            if ( bTetAbs < 0 )
                                bTetAbs *= -1;
                            cTetAbs = c - p;
                            if ( cTetAbs < 0 )
                                cTetAbs *= -1;

                            if ( aTetAbs + bTetAbs + cTetAbs <= e ){
                                //cout << "( " << a << " " << b << " " << c << " ) nalezy do czworoscian" << endl;
                                tetrahedron += cube [ a ] [ b ] [ c ];
                                }
                        }
            cout << tetrahedron << endl;

            }

        if ( operation == 'O' ){
            cin >> l >> v >> p >> r;
            h = r;
            w = r;
            d = r;

            // koretka krawedzi wzgledem srodka szescianu danych
            if ( l >= n/2 )
                h = -h;
            if ( v >= n/2 )
                w = -w;
            if ( p >= n/2 )
                d = -d;

            // wyznaczanie minimalnych i maksymalnych wierzcholkow oktalu
            if ( l < l + h ){
                lMin = l;
                lMax = l + h;
                }
            else{
                lMin = l + h;
                lMax = l;
                }

            if ( v < v + w ){
                vMin = v;
                vMax = v + w;
                }
            else{
                vMin = v + w;
                vMax = v;
                }

            if ( p < p + d ){
                pMin = p;
                pMax = p + d;
                }
            else{
                pMin = p + d;
                pMax = p;
                }

            // przechodzac po szescianie danych sprawdzamy czy punkt nalezy do malego szescianu
            octal = 0;
            for ( int c = 0; c < n; c++ )
                for ( int a = 0; a < n; a++ )
                    for ( int b = 0; b < n; b ++ )
                        if ( ( a >= lMin && a <= lMax ) && ( b >= vMin && b <= vMax ) && ( c >= pMin && c <= pMax ) )
                            if ( ( ( a - l ) * ( a - l ) + ( b - v ) * ( b - v ) + ( c - p ) * ( c - p ) ) <= r*r )
                                octal += cube [ a ] [ b ] [ c ];

            cout << octal << endl;
            }
        if ( operation == 'D' ){
            cin >> k >> i;
            if ( k == 'l' )
                for ( int a = 1; a <= n; a++ )
                    for ( int b = 1; b <= n; b++ )
                        matrix [ a ] [ b ] = cube [ i ] [ b - 1 ] [ a - 1 ];
            else if ( k == 'v' )
                for ( int a = 1; a <= n; a++ )
                    for ( int b = 1; b <= n; b++ )
                        matrix [ a ] [ b ] = cube [ a - 1 ] [ i ] [ b - 1 ];
            else if ( k == 'p' )
                for ( int a = 1; a <= n; a++ )
                    for ( int b = 1; b <= n; b++ )
                        matrix [ a ] [ b ] = cube [ a - 1 ] [ b - 1 ] [ i ];

           /* for ( int a = 1; a <= n; a++ ){
                for ( int b = 1; b <= n; b++ )
                    cout << matrix [ a ] [ b ] << " ";
                cout << endl;
                }*/

            cout << Determinant ( matrix, n ) <<  endl;

            }
        }

    }
