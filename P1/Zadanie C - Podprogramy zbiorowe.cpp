// Lukasz Rudnik

// source cpp po prostu nie ma maina

#include <iostream>
using namespace std;

int Size ( int a [] ){
    int i = 0;
    while ( a [ i ] != -1 )
        i = i + 1;
    return i;
    }

/////////////////////////////////////////////////////////////////

void Sort ( int a [] ){
    int aSize = 0;
    int i;
    int j;
    int temp;

    while ( a [ aSize ] != -1 ){
        aSize = aSize + 1;
        }
    if ( aSize > 1 ){
        i = 0;
        while ( i < aSize - 1 ){
            j = 0;
            while ( j < aSize - 1 ){
                if ( a [ j ] > a [ j + 1 ] ){
                    temp = a [ j + 1 ];
                    a [ j + 1 ] = a [ j ];
                    a [ j ] = temp;
                    }
                j = j + 1;
                }
            i = i + 1;
            }
        }
    }

/////////////////////////////////////////////////////////////////

void Add ( int n, int a [] ){
        bool add;
        int i;

        if ( n >= 1 && n <= 4095 ){
            add = true;
            i = 0;
            while ( a [ i ] != -1 ){
                if ( a [ i ] == n )
                    add = false;
                i = i + 1;
                }
            if ( add == true ){
                a [ i ] = n;
                a [ i + 1 ] = -1;
                }
            }
        Sort ( a );
    }

/////////////////////////////////////////////////////////////////

void AddS ( int n, int a [] ){
        bool add;
        int i;

        if ( n >= 1 && n <= 4095 ){
            add = true;
            i = 0;
            while ( a [ i ] != -1 ){
                if ( a [ i ] == n )
                    add = false;
                i = i + 1;
                }
            if ( add == true ){
                a [ i ] = n;
                a [ i + 1 ] = -1;
                }
            }
    }

/////////////////////////////////////////////////////////////////

bool Element ( int n, int a [] ){
    bool element = false;
    int i;

    if ( n >= 1 && n <= 4095 ){
        i = 0;
        while ( a [ i ] != -1 ){
            if ( a [ i ] == n )
                element = true;
            i = i + 1;
            }
        }
    return element;
    }

/////////////////////////////////////////////////////////////////

bool Subset ( int a [], int b [] ){
    bool subset;
    int i;

    if ( Size ( a ) > Size ( b ) )
        subset = false;
    else{
        subset = true;
        i = 0;
        while ( a [ i ] != -1 ){
            if ( Element ( a [ i ], b ) == false )
                subset = false;
            i = i + 1;
            }
        }

    return subset;
    }

/////////////////////////////////////////////////////////////////

void Create ( int nSize, int n [], int a []){
    a [ 0 ] = -1; // dodajemy do zbioru pustego
    int i = 0;
    while ( i < nSize ){
        Add ( n [ i ], a );
        i = i + 1;
        }
    Sort ( a );
    }

/////////////////////////////////////////////////////////////////

void Complement ( int a [], int c [] ){
    int i = 1;
    c [ 0 ] = -1;

    while ( i <= 4095 ){ // testy dla 25
        if ( Element ( i, a ) == false )
            AddS ( i, c );
        i = i + 1;
        }
    Sort ( c );
    }

/////////////////////////////////////////////////////////////////

void Union ( int a [], int b [], int u [] ){
    int i = 0;
    u [ 0 ] = -1;

    while ( a [ i ] != -1 ){
        AddS ( a [ i ], u );
        i = i + 1;
        }
    i = 0;
    while ( b [ i ] != -1 ){
        AddS ( b [ i ], u );
        i = i + 1;
        }
    Sort ( u );
    }

/////////////////////////////////////////////////////////////////

void Intersection ( int a [], int b [], int I [] ){ // duze I bo male jest do iteracji
    int i = 0;
    I [ 0 ] = -1;
    while ( a [ i ] != -1 ){
        if ( Element ( a [ i ], b ) == true )
            AddS ( a [ i ], I );
        i = i + 1;
        }
    Sort ( I );
    }

/////////////////////////////////////////////////////////////////

void Difference ( int a [], int b [], int d [] ){
    int i = 0;
    d [ 0 ] = -1;
    while ( a [ i ] != -1 ){
        if ( Element ( a [ i ], b ) == false )
            AddS ( a [ i ], d );
        i = i + 1;
        }
    Sort ( d );
    }

/////////////////////////////////////////////////////////////////

void Symmetric ( int a [], int b [], int s [] ){
    int i = 0;
    s [ 0 ] = -1;
    while ( a [ i ] != -1 ){
        if ( Element ( a [ i ], b ) == false )
            AddS ( a [ i ], s );
        i = i + 1;
        }
    i = 0;
    while ( b [ i ] != -1 ){
        if ( Element ( b [ i ], a ) == false )
            AddS ( b [ i ], s );
        i = i + 1;
        }
    Sort ( s );
    }

/////////////////////////////////////////////////////////////////

bool Equal ( int a [], int b [] ){
    if ( Size ( a ) == Size ( b ) && Subset ( a, b ) == true )
        return true;
    else
        return false;
    }

/////////////////////////////////////////////////////////////////

bool Empty ( int a [] ){
    if ( a [ 0 ] == -1 )
        return true;
    else
        return false;
    }

/////////////////////////////////////////////////////////////////

bool Nonempty ( int a [] ){
    if ( a [ 0 ] == -1 )
        return false;
    else
        return true;
    }

/////////////////////////////////////////////////////////////////

double Arithmetic ( int a [] ){
    int i = 0;
    double sum = 0;
    if ( Empty ( a ) == true ){
        sum = 0;
        return sum;
        }
    else{
        while ( a [ i ] != -1 ){
            sum = sum + a [ i ];
            i = i + 1;
            }
        return sum * 1.0 / Size ( a );
        }
    }

/////////////////////////////////////////////////////////////////

double Harmonic ( int a [] ){
    if ( Empty ( a ) == true ){
        return 1;
        }
    else{
        int i = 0;
        double sum = 0;
        while ( a [ i ] != -1 ){
            sum = sum + ( 1.0 / a [ i ] );
            i = i + 1;
            }
        return Size ( a ) / sum;
        }
    }

/////////////////////////////////////////////////////////////////

void MinMax ( int a [], int* minimal, int& maximal ){
    if ( Nonempty ( a ) == true ){
        *minimal = 4096;
        maximal = -1;
        int i = 0;
        while ( a [ i ] != -1 ){
            if ( a [ i ] < *minimal )
                *minimal = a [ i ];
            if ( a [ i ] > maximal )
                maximal = a [ i ];

            i = i + 1;
            }
        }
    }

/////////////////////////////////////////////////////////////////

void Cardinality ( int a [], int* cardinality ){
    *cardinality = Size ( a );
    }

/////////////////////////////////////////////////////////////////

void Properties ( int a [], char text [], double& arithmetic, double* harmonic, int& minimal, int* maximal, int& cardinality ){
    int i = 0;
    while ( text [ i ] != 0 ){
        if ( text [ i ] == 'a' )
            arithmetic = Arithmetic ( a );
        else if ( text [ i ] == 'h' )
            *harmonic = Harmonic ( a );
        else if ( text [ i ] == 'm' ){

            if ( Nonempty ( a ) == true ){
                minimal = 4096;
                *maximal = -1;
                int j = 0;
                while ( a [ j ] != -1 ){
                    if ( a [ j ] < minimal )
                        minimal = a [ j ];
                    if ( a [ j ] > *maximal )
                        *maximal = a [ j ];

                    j = j + 1;
                    }
                }

            }
        else if ( text [ i ] == 'c' )
            cardinality = Size ( a );
        i = i + 1;
        }
    }

/////////////////////////////////////////////////////////////////







/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////






int main (){
    int procedure;
    int aSize;
    int i;
    int number;
    int bSize;
    int nSize;

    cin >> procedure;

/////////////////////////////////////////////////////////////////

    if ( procedure == -1 ){ // Size
        cin >> aSize;
        int a [ aSize ];
        i = 0;
        while ( i < aSize ){
            cin >> a [ i ];
            i = i + 1;
            }
        a [ aSize ] = -1;

        cout << Size ( a );
        }

/////////////////////////////////////////////////////////////////

    else if ( procedure == 0 ){ // Sort
        cin >> aSize;
        int a [ aSize ];
        i = 0;
        while ( i < aSize ){
            cin >> a [ i ];
            i = i + 1;
            }
        a [ aSize ] = -1;

        Sort ( a );
        i = 0;
        while ( a [ i ] != -1  ){
            cout << a [ i ] << " ";
            i = i + 1;
            }

/////////////////////////////////////////////////////////////////

        }
    else if ( procedure == 1 ){ // Add
        cin >> aSize;
        int a [ aSize + 2 ];
        i = 0;
        while ( i < aSize ){
            cin >> a [ i ];
            i = i + 1;
            }
        a [ aSize ] = -1;
        cin >> number;

        Add ( number, a );
        i = 0;
        while ( a [ i ] != -1  ){
            cout << a [ i ] << " ";
            i = i + 1;
            }
        }

/////////////////////////////////////////////////////////////////

    else if ( procedure == 2 ){ // Create

        cin >> nSize;
        int n [ nSize ];
        int a [ nSize + 1 ];
        i = 0;
        while ( i < nSize ){
            cin >> n [ i ];
            i = i + 1;
            }
        Create ( nSize, n, a );
        i = 0;
        while ( a [ i ] != -1  ){
            cout << a [ i ] << " ";
            i = i + 1;
            }
        }

/////////////////////////////////////////////////////////////////

    else if ( procedure == 3 ){ // Complement
        cin >> aSize;
        int a [ aSize + 1];
        i = 0;
        while ( i < aSize ){
            cin >> a [ i ];
            i = i + 1;
            }
        a [ aSize ] = -1;

        int c [ 50 ];

        Complement ( a, c );

        i = 0;
        while ( c [ i ] != -1 ){
            cout << c [ i ] << " ";
            i = i + 1;
            }
        }

/////////////////////////////////////////////////////////////////

    else if ( procedure == 4 ){ // Union
        cin >> aSize;
        int a [ aSize + 1];
        i = 0;
        while ( i < aSize ){
            cin >> a [ i ];
            i = i + 1;
            }
        a [ aSize ] = -1;

        cin >> bSize;
        int b [ bSize + 1 ];
        i = 0;
        while ( i < bSize ){
            cin >> b [ i ];
            i = i + 1;
            }
        b [ bSize ] = -1;

        int u [ 10000 ];

        Union ( a, b, u );

        i = 0;
        while ( u [ i ] != -1 ){
            cout << u [ i ] << " ";
            i = i + 1;
            }
        }

/////////////////////////////////////////////////////////////////

    else if ( procedure == 5 ){ // Intersection
        cin >> aSize;
        int a [ aSize + 1];
        i = 0;
        while ( i < aSize ){
            cin >> a [ i ];
            i = i + 1;
            }
        a [ aSize ] = -1;

        cin >> bSize;
        int b [ bSize + 1 ];
        i = 0;
        while ( i < bSize ){
            cin >> b [ i ];
            i = i + 1;
            }
        b [ bSize ] = -1;

        int I [ 10000 ];

        Intersection ( a, b, I );

        i = 0;
        while ( I [ i ] != -1 ){
            cout << I [ i ] << " ";
            i = i + 1;
            }
        }


/////////////////////////////////////////////////////////////////

    else if ( procedure == 6 ){ // Difference
        cin >> aSize;
        int a [ aSize + 1];
        i = 0;
        while ( i < aSize ){
            cin >> a [ i ];
            i = i + 1;
            }
        a [ aSize ] = -1;

        cin >> bSize;
        int b [ bSize + 1 ];
        i = 0;
        while ( i < bSize ){
            cin >> b [ i ];
            i = i + 1;
            }
        b [ bSize ] = -1;

        int d [ 10000 ];

        Difference ( a, b, d );

        i = 0;
        while ( d [ i ] != -1 ){
            cout << d [ i ] << " ";
            i = i + 1;
            }
        }

/////////////////////////////////////////////////////////////////

    else if ( procedure == 7 ){ // Symmetric
        cin >> aSize;
        int a [ aSize + 1];
        i = 0;
        while ( i < aSize ){
            cin >> a [ i ];
            i = i + 1;
            }
        a [ aSize ] = -1;

        cin >> bSize;
        int b [ bSize + 1 ];
        i = 0;
        while ( i < bSize ){
            cin >> b [ i ];
            i = i + 1;
            }
        b [ bSize ] = -1;

        int s [ 10000 ];

        Symmetric ( a, b, s );

        i = 0;
        while ( s [ i ] != -1 ){
            cout << s [ i ] << " ";
            i = i + 1;
            }
        }

/////////////////////////////////////////////////////////////////

    else if ( procedure == 8 ){ // Subset
        cin >> aSize;
        int a [ aSize + 1];
        i = 0;
        while ( i < aSize ){
            cin >> a [ i ];
            i = i + 1;
            }
        a [ aSize ] = -1;

        cin >> bSize;
        int b [ bSize + 1 ];
        i = 0;
        while ( i < bSize ){
            cin >> b [ i ];
            i = i + 1;
            }
        b [ bSize ] = -1;



        cout << Subset ( a, b );

        }

/////////////////////////////////////////////////////////////////

    else if ( procedure == 9 ){ // Equal
        cin >> aSize;
        int a [ aSize + 1];
        i = 0;
        while ( i < aSize ){
            cin >> a [ i ];
            i = i + 1;
            }
        a [ aSize ] = -1;

        cin >> bSize;
        int b [ bSize + 1 ];
        i = 0;
        while ( i < bSize ){
            cin >> b [ i ];
            i = i + 1;
            }
        b [ bSize ] = -1;



        cout << Equal ( a, b );
        }

/////////////////////////////////////////////////////////////////

    else if ( procedure == 10 ){ // Empty
        cin >> aSize;
        int a [ aSize + 1 ];
        i = 0;
        while ( i < aSize ){
            cin >> a [ i ];
            i = i + 1;
            }
        a [ aSize ] = -1;

        cout << Empty ( a );
        }

/////////////////////////////////////////////////////////////////

    else if ( procedure == 11 ){ // Nonempty
        cin >> aSize;
        int a [ aSize + 1 ];
        i = 0;
        while ( i < aSize ){
            cin >> a [ i ];
            i = i + 1;
            }
        a [ aSize ] = -1;

        cout << Nonempty ( a );
        }

/////////////////////////////////////////////////////////////////

    else if ( procedure == 12 ){ // Element
        cin >> aSize;
        int a [ aSize + 1 ];
        i = 0;
        while ( i < aSize ){
            cin >> a [ i ];
            i = i + 1;
            }
        a [ aSize ] = -1;

        cin >> number;

        cout << Element ( number, a );

        }

/////////////////////////////////////////////////////////////////

    else if ( procedure == 13 ){ // Arithmetic
        cin >> aSize;
        int a [ aSize ];
        i = 0;
        while ( i < aSize ){
            cin >> a [ i ];
            i = i + 1;
            }
        a [ aSize ] = -1;

        cout << Arithmetic ( a );
        }

/////////////////////////////////////////////////////////////////

    else if ( procedure == 14 ){ // Harmonic
        cin >> aSize;
        int a [ aSize ];
        i = 0;
        while ( i < aSize ){
            cin >> a [ i ];
            i = i + 1;
            }
        a [ aSize ] = -1;

        cout << Harmonic ( a );
        }

/////////////////////////////////////////////////////////////////

    else if ( procedure == 15 ){ // MinMax
        cin >> aSize;
        int a [ aSize ];
        i = 0;
        while ( i < aSize ){
            cin >> a [ i ];
            i = i + 1;
            }
        a [ aSize ] = -1;

        int minimal = -9999;
        int maximal = 9999;

        MinMax ( a, &minimal, maximal );

        cout << minimal << " " << maximal;
        }

/////////////////////////////////////////////////////////////////

    else if ( procedure == 16 ){ // Cardinality
        cin >> aSize;
        int a [ aSize ];
        i = 0;
        while ( i < aSize ){
            cin >> a [ i ];
            i = i + 1;
            }
        a [ aSize ] = -1;
        int cardinality = -20;

        Cardinality ( a, &cardinality );

        cout << cardinality;
        }

/////////////////////////////////////////////////////////////////

    else if ( procedure == 17 ){ // Properties
        cin >> aSize;
        int a [ aSize ];
        i = 0;
        while ( i < aSize ){
            cin >> a [ i ];
            i = i + 1;
            }
        a [ aSize ] = -1;

        char text [ 1000 ];
        cin >> text;
        double arithmetic = -1;
        double harmonic = -1;
        int minimal = -1;
        int maximal = -1;
        int cardinality = -1;

        Properties ( a, text, arithmetic, &harmonic, minimal, &maximal, cardinality );

        cout << "arithmetic: " << arithmetic << endl;
        cout << "harmonic: " << harmonic << endl;
        cout << "minimal: " << minimal << endl;
        cout << "maximal: " << maximal << endl;
        cout << "cardinality: " << cardinality << endl;
        }

/////////////////////////////////////////////////////////////////

}
