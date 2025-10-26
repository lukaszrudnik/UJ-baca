// Lukasz Rudnik

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void AFR ( int w, int* insertedRow, int*** array2d, unsigned short** rowSizes, unsigned short* numOfRows ){
    *array2d = (int**) realloc ( *array2d, ( *numOfRows + 1 ) * sizeof(int*) );
    *rowSizes = (unsigned short*) realloc ( *rowSizes, ( *numOfRows + 1 ) * sizeof(unsigned short) );

    int i;
    for ( i = *numOfRows; i > 0; i-- ) {
        *(*array2d + i) = *(*array2d + i - 1);
        *(*rowSizes + i) = *(*rowSizes + i - 1);
        }

    *(*array2d + 0) = (int*) malloc ( w * sizeof(int) );
    for ( i = 0; i < w; i++ ){
        *(*(*array2d + 0) + i) = *(insertedRow + i);
        }

    *(*rowSizes + 0) = w;
    (*numOfRows)++;
    free ( insertedRow );
    }

void ALR ( int w, int* insertedRow, int*** array2d, unsigned short** rowSizes, unsigned short* numOfRows ){
    *array2d = (int**) realloc ( *array2d, ( *numOfRows + 1 ) * sizeof(int*) );
    *rowSizes = (unsigned short*) realloc ( *rowSizes, ( *numOfRows + 1 ) * sizeof(unsigned short) );

    *(*array2d + *numOfRows) = (int*) malloc ( w * sizeof(int) );
    int i;
    for ( i = 0; i < w; i++ ){
        *(*(*array2d + *numOfRows) + i) = *(insertedRow + i);
        }

    *(*rowSizes + *numOfRows) = w;
    (*numOfRows)++;
    free ( insertedRow );
    }

void AFC ( int h, int* insertedCol, int*** array2d, unsigned short** rowSizes, unsigned short* numOfRows ){
    if ( h > *numOfRows ){
        *array2d = (int**) realloc ( *array2d, h * sizeof(int*) );
        *rowSizes = (unsigned short*) realloc ( *rowSizes, h * sizeof(unsigned short) );
        }

    int i;
    for ( i = 0; i < h; i++ ){
        if ( i < *numOfRows ){
            *(*array2d + i) = (int*) realloc ( *(*array2d + i), (*(*rowSizes + i) + 1 ) * sizeof(int));
            int j;
            for ( j = *((*rowSizes + i)); j > 0; j-- ){
                *(*(*array2d + i) + j) = *(*(*array2d + i) + j - 1 );
                }
            *(*(*array2d + i) + 0) = *(insertedCol + i);

            (*(*rowSizes + i))++;
            }
        else{
            *(*array2d + i) = (int*) malloc ( 1 * sizeof(int));
            *(*(*array2d + i) + 0) = *(insertedCol + i);
            (*(*rowSizes + i)) = 1;
            }
        }

    if ( h > *numOfRows )
        (*numOfRows) = h;
    free ( insertedCol );
    }

void ALC ( int h, int* insertedCol, int*** array2d, unsigned short** rowSizes, unsigned short* numOfRows ){
    if ( h > *numOfRows ){
        *array2d = (int**) realloc ( *array2d, h * sizeof(int*) );
        *rowSizes = (unsigned short*) realloc ( *rowSizes, h * sizeof(unsigned short) );
        }

    int i;
    for ( i = 0; i < h; i++ ){
        if ( i < *numOfRows ){
            *(*array2d + i) = (int*) realloc ( *(*array2d + i), (*(*rowSizes + i) + 1 ) * sizeof(int));
            *(*(*array2d + i) + *(*rowSizes + i)) = *(insertedCol + i);
            (*(*rowSizes + i))++;
            }
        else{
            *(*array2d + i) = (int*) malloc ( 1 * sizeof(int));
            *(*(*array2d + i) + 0) = *(insertedCol + i);
            (*(*rowSizes + i)) = 1;
            }
        }

    if ( h > *numOfRows )
        (*numOfRows) = h;
    free ( insertedCol );
    }

void IBR ( int r, int w, int* insertedRow, int*** array2d, unsigned short** rowSizes, unsigned short* numOfRows ){
    *array2d = (int**) realloc ( *array2d, ( *numOfRows + 1 ) * sizeof(int*) );
    *rowSizes = (unsigned short*) realloc ( *rowSizes, ( *numOfRows + 1 ) * sizeof(unsigned short) );

    int i;
    for ( i = *numOfRows; i > r; i-- ) {
        *(*array2d + i) = *(*array2d + i - 1);
        *(*rowSizes + i) = *(*rowSizes + i - 1);
        }

    *(*array2d + r) = (int*) malloc ( w * sizeof(int) );
    for ( i = 0; i < w; i++ ){
        *(*(*array2d + r) + i) = *(insertedRow + i);
        }

    *(*rowSizes + r) = w;
    (*numOfRows)++;
    free ( insertedRow );
    }

void IAR ( int r, int w, int* insertedRow, int*** array2d, unsigned short** rowSizes, unsigned short* numOfRows ){
    if ( r < *numOfRows - 1 )
        IBR ( r + 1, w, insertedRow, array2d, rowSizes, numOfRows );
    else
        ALR ( w, insertedRow, array2d, rowSizes, numOfRows );
    }

void IBC ( int c, int h, int* insertedCol, int*** array2d, unsigned short** rowSizes, unsigned short* numOfRows ){
    if ( h > *numOfRows ){
        *array2d = (int**) realloc ( *array2d, h * sizeof(int*) );
        *rowSizes = (unsigned short*) realloc ( *rowSizes, h * sizeof(unsigned short) );
        }

    int i;
    for ( i = 0; i < h; i++ ){
        if ( i < *numOfRows ){
            *(*array2d + i) = (int*) realloc ( *(*array2d + i), (*(*rowSizes + i) + 1 ) * sizeof(int));
            if ( c < (*(*rowSizes + i)) ){
                int j;
                for ( j = *((*rowSizes + i)); j > c; j-- ){
                    *(*(*array2d + i) + j) = *(*(*array2d + i) + j - 1 );
                    }
                *(*(*array2d + i) + c) = *(insertedCol + i);
                (*(*rowSizes + i))++;
                }
            else{
                *(*(*array2d + i) + *(*rowSizes + i) ) = *(insertedCol + i);
                (*(*rowSizes + i))++;
                }
            }
        else{
            *(*array2d + i) = (int*) malloc ( 1 * sizeof(int));
            *(*(*array2d + i) + 0) = *(insertedCol + i);
            (*(*rowSizes + i)) = 1;
            }
        }

    if ( h > *numOfRows )
        (*numOfRows) = h;
    free ( insertedCol );
    }

void IAC ( int c, int h, int* insertedCol, int*** array2d, unsigned short** rowSizes, unsigned short* numOfRows ){
    IBC ( c + 1, h, insertedCol, array2d, rowSizes, numOfRows );
    }

void SWR ( int r, int s, int*** array2d, unsigned short** rowSizes, unsigned short* numOfRows ){
    int* tempRow = *(*array2d + r);
    *(*array2d + r) = *(*array2d + s);
    *(*array2d + s) = tempRow;

    unsigned short tempSize = *(*rowSizes + r);
    *(*rowSizes + r) = *(*rowSizes + s);
    *(*rowSizes + s) = tempSize;
    }

void SWC ( int c, int d, int*** array2d, unsigned short** rowSizes, unsigned short* numOfRows ){
    int i;
    for ( i = 0; i < *numOfRows; i++ ){
        if ( c < *(*rowSizes + i) && d < *(*rowSizes + i) ){
            int temp = *(*(*array2d + i) + c);
            *(*(*array2d + i) + c) = *(*(*array2d + i) + d);
            *(*(*array2d + i) + d) = temp;
            }
        }
    }

void DFR ( int*** array2d, unsigned short** rowSizes, unsigned short* numOfRows ){
    free(*(*array2d + 0));
    int i;
    for ( i = 0; i < *numOfRows - 1; i++ ) {
        *(*array2d + i) = *(*array2d + i + 1);
        *(*rowSizes + i) = *(*rowSizes + i + 1);
        }

    (*numOfRows)--;
    if ( *numOfRows > 0 ){
        *array2d = (int**) realloc ( *array2d, ( *numOfRows ) * sizeof(int*) );
        *rowSizes = (unsigned short*) realloc ( *rowSizes, ( *numOfRows ) * sizeof(unsigned short) );
        }
    else{
        free(*array2d);
        free(*rowSizes);
        *array2d = NULL;
        *rowSizes = NULL;
        }
    }

void DLR ( int*** array2d, unsigned short** rowSizes, unsigned short* numOfRows ){
    free(*(*array2d + *numOfRows - 1));

    (*numOfRows)--;
    if ( *numOfRows > 0 ){
        *array2d = (int**) realloc ( *array2d, ( *numOfRows ) * sizeof(int*) );
        *rowSizes = (unsigned short*) realloc ( *rowSizes, ( *numOfRows ) * sizeof(unsigned short) );
        }
    else{
        free(*array2d);
        free(*rowSizes);
        *array2d = NULL;
        *rowSizes = NULL;
        }
    }

void DFC ( int*** array2d, unsigned short** rowSizes, unsigned short* numOfRows ){
    int i;
    for ( i = 0; i < *numOfRows; i++ ){
        if ( *(*rowSizes + i) > 1 ){
            int j;
            for ( j = 0; j < *(*rowSizes + i) - 1; j++){
                *(*(*array2d + i) + j ) = *(*(*array2d + i) + j + 1);
                }
            *(*array2d + i) = (int*) realloc ( *(*array2d + i), (*(*rowSizes + i) - 1 ) * sizeof(int));
            (*(*rowSizes + i))--;
            }
        else{
            free (*(*array2d + i));
            int j;
            for ( j = i; j < *numOfRows - 1; j++ ){
                *(*array2d + j) = *(*array2d + j + 1);
                *(*rowSizes + j) = *(*rowSizes + j + 1);
                }
            (*numOfRows)--;
            if ( *numOfRows > 0 ){
                *array2d = (int**) realloc ( *array2d, ( *numOfRows ) * sizeof(int*) );
                *rowSizes = (unsigned short*) realloc ( *rowSizes, ( *numOfRows ) * sizeof(unsigned short) );
                }
            else{
                free(*array2d);
                free(*rowSizes);
                *array2d = NULL;
                *rowSizes = NULL;
                }
            // i--, bo jakby usunelismy juz ten wiersz i wszystko zaktualizowalismy
            // wiec kolejny wiersz wskakuje na ten indeks i chcemy ponownie rozwazyc
            i--;
            }
        }
    }

void DLC ( int*** array2d, unsigned short** rowSizes, unsigned short* numOfRows ){
    int i;
    for ( i = 0; i < *numOfRows; i++ ){
        if ( *(*rowSizes + i) > 1 ){
            *(*array2d + i) = (int*) realloc ( *(*array2d + i), (*(*rowSizes + i) - 1 ) * sizeof(int));
            (*(*rowSizes + i))--;
            }
        else{
            // tak samo jak dla DFC, bo na jedno wychodzi
            free (*(*array2d + i));
            int j;
            for ( j = i; j < *numOfRows - 1; j++ ){
                *(*array2d + j) = *(*array2d + j + 1);
                *(*rowSizes + j) = *(*rowSizes + j + 1);
                }
            (*numOfRows)--;
            if ( *numOfRows > 0 ){
                *array2d = (int**) realloc ( *array2d, ( *numOfRows ) * sizeof(int*) );
                *rowSizes = (unsigned short*) realloc ( *rowSizes, ( *numOfRows ) * sizeof(unsigned short) );
                }
            else{
                free(*array2d);
                free(*rowSizes);
                *array2d = NULL;
                *rowSizes = NULL;
                }
            // i--, bo jakby usunelismy juz ten wiersz i wszystko zaktualizowalismy
            // wiec kolejny wiersz wskakuje na ten indeks i chcemy ponownie rozwazyc
            i--;
            }
        }
    }

void RMR ( int r, int*** array2d, unsigned short** rowSizes, unsigned short* numOfRows ){
    free(*(*array2d + r));
    int i;
    for ( i = r; i < *numOfRows - 1; i++ ) {
        *(*array2d + i) = *(*array2d + i + 1);
        *(*rowSizes + i) = *(*rowSizes + i + 1);
        }

    (*numOfRows)--;
    if ( *numOfRows > 0 ){
        *array2d = (int**) realloc ( *array2d, ( *numOfRows ) * sizeof(int*) );
        *rowSizes = (unsigned short*) realloc ( *rowSizes, ( *numOfRows ) * sizeof(unsigned short) );
        }
    else{
        free(*array2d);
        free(*rowSizes);
        *array2d = NULL;
        *rowSizes = NULL;
        }
    }

void RMC ( int c, int*** array2d, unsigned short** rowSizes, unsigned short* numOfRows ){
    if ( c == 0 )
        DFC ( array2d, rowSizes, numOfRows );
    else{
        int i;
        for ( i = 0; i < *numOfRows; i++ ){
            if ( *(*rowSizes + i) > c ){
                int j;
                for ( j = c; j < *(*rowSizes + i) - 1; j++){
                    *(*(*array2d + i) + j ) = *(*(*array2d + i) + j + 1);
                    }
                *(*array2d + i) = (int*) realloc ( *(*array2d + i), (*(*rowSizes + i) - 1 ) * sizeof(int));
                (*(*rowSizes + i))--;
                }
            }
        }
    }

void RMB ( int r, int h, int c, int w, int*** array2d, unsigned short** rowSizes, unsigned short* numOfRows ){
    if ( r + h > *numOfRows ){
        h = *numOfRows - r;
        }

    int i;
    for ( i = r; i < r + h; i++ ){
        if ( *(*rowSizes + i) > c ){
            int auxW = w;
            if ( c + w > *(*rowSizes + i) ){
                auxW = *(*rowSizes + i) - c;
                }
            if ( c == 0 && auxW == *(*rowSizes + i) ){
                RMR ( i, array2d, rowSizes, numOfRows );
                i--;
                h--;
                }
            else{
                int j;
                for ( j = c; j < *(*rowSizes + i) - auxW; j++){
                    *(*(*array2d + i) + j ) = *(*(*array2d + i) + j + auxW);
                    }
                *(*array2d + i) = (int*) realloc ( *(*array2d + i), (*(*rowSizes + i) - auxW ) * sizeof(int));
                (*(*rowSizes + i))-=auxW;
                }
            }
        }
    }

void ISB ( int r, int c, int h, int w, int*** array2d, unsigned short** rowSizes, unsigned short* numOfRows ){
    int i;
    unsigned short auxNumOfRows = *numOfRows;
    for ( i = r; i < r + h; i++ ){
        int* insertedRow = (int*) malloc ( w * sizeof (int) );
        int j;
        for ( j = 0; j < w; j++ )
            scanf ( "%d", ( insertedRow + j ) );
        if ( i < auxNumOfRows ){
            *(*array2d + i) = (int*) realloc ( *(*array2d + i), (*(*rowSizes + i) + w ) * sizeof(int));
            if ( *(*rowSizes + i) > c ){
                (*(*rowSizes + i))+=w;
                for ( j = *(*rowSizes + i) - 1; j >= c + w; j-- ){
                    *(*(*array2d + i) + j) = *(*(*array2d + i) + j - w );
                    }
                int aux = 0;
                for ( j = c + w - 1; j >= c; j-- ){
                    *(*(*array2d + i) + j) = *(insertedRow + w - 1 - aux);
                    aux++;
                    }
                }
            else{
                (*(*rowSizes + i))+=w;
                int aux = 0;
                for ( j = *(*rowSizes + i) - 1; j > *(*rowSizes + i) - 1 - w; j-- ){
                    *(*(*array2d + i) + j) = *(insertedRow + w - 1 - aux);
                    aux++;
                    }
                }
            free(insertedRow);
            }
        else{
            ALR ( w, insertedRow, array2d, rowSizes, numOfRows );
            }
        }
    }

void WRF ( char* name, int*** array2d, unsigned short** rowSizes, unsigned short* numOfRows ){
    FILE* file;
    file = fopen ( name, "wb" );

    fprintf ( file, "%d\n", *numOfRows );
    int i;
    for ( i = 0; i < *numOfRows; i++ ){
        unsigned short auxSize = *(*rowSizes + i);
        unsigned char byteOne = auxSize & 0xFF;
        unsigned char byteTwo = ( auxSize >> 8 ) & 0xFF;
        fprintf ( file, "%c%c", byteTwo, byteOne );

        int j;
        for ( j = 0; j < auxSize; j++ ){
            int auxInt = *(*(*array2d + i) + j);
            unsigned char byteOne = auxInt & 0xFF;
            unsigned char byteTwo = ( auxInt >> 8 ) & 0xFF;
            unsigned char byteThree = ( auxInt >> 16 ) & 0xFF;
            unsigned char byteFour = ( auxInt >> 24 ) & 0xFF;
            fprintf ( file, "%c%c%c%c", byteFour, byteThree, byteTwo, byteOne );
            }
        fprintf ( file, "\n" );
        }

    fclose ( file );
    free(name);
    }

void RDF ( char* name, int*** array2d, unsigned short** rowSizes, unsigned short* numOfRows ){
    FILE* file;
    file = fopen ( name, "rb" );

    unsigned short auxRows;
    fscanf ( file, "%d\n", &auxRows );
    int i;
    for ( i = 0; i < auxRows; i++ ){
        unsigned char byteOne;
        unsigned char byteTwo;
        fscanf ( file, "%c%c", &byteOne, &byteTwo );
        int auxSize = (byteOne << 8) | (byteTwo);

        int* insertedRow = (int*) malloc ( auxSize * sizeof (int) );

        int j;
        for ( j = 0; j < auxSize; j++ ){
            unsigned char byteOne;
            unsigned char byteTwo;
            unsigned char byteThree;
            unsigned char byteFour;
            fscanf ( file, "%c%c%c%c", &byteOne, &byteTwo, &byteThree, &byteFour );
            unsigned short auxInt = (byteOne << 24) | (byteTwo<<16) | (byteThree << 8) | (byteFour);
            *( insertedRow + j ) = auxInt;
            }
        ALR (auxSize, insertedRow, array2d, rowSizes, numOfRows);
        fscanf ( file, "\n" );
        }

    fclose ( file );
    free(name);
    }

void PRT ( int*** array2d, unsigned short** rowSizes, unsigned short* numOfRows ){
    int i = 0;
    int j = 0;
    printf ( "%d\n", *numOfRows );
    for ( i = 0; i < *numOfRows; i++ ) {
        printf("%d", *(*rowSizes + i));
        for (j = 0; j < *(*rowSizes + i); j++) {
            printf(" %d", *(*(*array2d + i) + j));
            }
        printf("\n");
        }
    }


int main() {
    char* operation = (char*) malloc (  4 * sizeof (char) );

    int** array2d = NULL;
    unsigned short* rowSizes = NULL;
    unsigned short numOfRows = 0;


    do{
        scanf ( "%s", operation );

        if ( strcmp ( operation, "AFR" ) == 0 ){ // add first row
            int w;
            scanf ( "%d", &w );
            if ( w > 0 ){
                int* insertedRow = (int*) malloc ( w * sizeof (int) );
                int i;
                for ( i = 0; i < w; i++ )
                    scanf ( "%d", ( insertedRow + i ) );
                AFR ( w, insertedRow, &array2d, &rowSizes, &numOfRows );
                }
            }

        else if ( strcmp ( operation, "ALR" ) == 0 ){ // add last row
            int w;
            scanf ( "%d", &w );
            if ( w > 0 ){
                int* insertedRow = (int*) malloc ( w * sizeof (int) );
                int i;
                for ( i = 0; i < w; i++ )
                    scanf ( "%d", ( insertedRow + i ) );
                ALR ( w, insertedRow, &array2d, &rowSizes, &numOfRows );
                }
            }

        else if ( strcmp ( operation, "AFC" ) == 0 ){ // add first column
            int h;
            scanf ( "%d", &h );
            if ( h > 0 ){
                int* insertedCol = (int*) malloc ( h * sizeof (int) );
                int i;
                for ( i = 0; i < h; i++ )
                    scanf ( "%d", ( insertedCol + i ) );
                AFC ( h, insertedCol, &array2d, &rowSizes, &numOfRows );
                }
            }

        else if ( strcmp ( operation, "ALC" ) == 0 ){ // add last column
            int h;
            scanf ( "%d", &h );
            if ( h > 0 ){
                int* insertedCol = (int*) malloc ( h * sizeof (int) );
                int i;
                for ( i = 0; i < h; i++ )
                    scanf ( "%d", ( insertedCol + i ) );
                ALC ( h, insertedCol, &array2d, &rowSizes, &numOfRows );
                }
            }

        else if ( strcmp ( operation, "IBR" ) == 0 ){ // insert before row
            int r;
            int w;
            scanf ( "%d", &r );
            scanf ( "%d", &w );
            if ( r >= 0 && r < numOfRows && w > 0 ){
                int* insertedRow = (int*) malloc ( w * sizeof (int) );
                int i;
                for ( i = 0; i < w; i++ )
                    scanf ( "%d", ( insertedRow + i ) );
                IBR ( r, w, insertedRow, &array2d, &rowSizes, &numOfRows );
                }
            }

        else if ( strcmp ( operation, "IAR" ) == 0 ){ // insert after row
            int r;
            int w;
            scanf ( "%d", &r );
            scanf ( "%d", &w );
            if ( r >= 0 && r < numOfRows && w > 0 ){
                int* insertedRow = (int*) malloc ( w * sizeof (int) );
                int i;
                for ( i = 0; i < w; i++ )
                    scanf ( "%d", ( insertedRow + i ) );
                IAR ( r, w, insertedRow, &array2d, &rowSizes, &numOfRows );
                }
            }

        else if ( strcmp ( operation, "IBC" ) == 0 ){ // insert before column
            int c;
            int h;
            scanf ( "%d", &c );
            scanf ( "%d", &h );
            if ( c >= 0 && h > 0 ){
                int* insertedCol = (int*) malloc ( h * sizeof (int) );
                int i;
                for ( i = 0; i < h; i++ )
                    scanf ( "%d", ( insertedCol + i ) );
                IBC ( c, h, insertedCol, &array2d, &rowSizes, &numOfRows );
                }
            }

        else if ( strcmp ( operation, "IAC" ) == 0 ){ // insert after column
            int c;
            int h;
            scanf ( "%d", &c );
            scanf ( "%d", &h );
            if ( c >= 0 && h > 0 ){
                int* insertedCol = (int*) malloc ( h * sizeof (int) );
                int i;
                for ( i = 0; i < h; i++ )
                    scanf ( "%d", ( insertedCol + i ) );
                IAC ( c, h, insertedCol, &array2d, &rowSizes, &numOfRows );
                }
            }

        else if ( strcmp ( operation, "SWR" ) == 0 ){ // swap rows
            int r;
            int s;
            scanf ( "%d", &r );
            scanf ( "%d", &s );
            if ( r >= 0 && s >= 0 && r < numOfRows && s < numOfRows ){
                SWR ( r, s, &array2d, &rowSizes, &numOfRows );
                }
            }

        else if ( strcmp ( operation, "SWC" ) == 0 ){ // swap columns
            int c;
            int d;
            scanf ( "%d", &c );
            scanf ( "%d", &d );
            if ( c >= 0 && d >= 0 )
                SWC ( c, d, &array2d, &rowSizes, &numOfRows );
            }

        else if ( strcmp ( operation, "DFR" ) == 0 ){ // delete first row
            if ( numOfRows > 0 )
                DFR ( &array2d, &rowSizes, &numOfRows );
            }

        else if ( strcmp ( operation, "DLR" ) == 0 ){ // delete last row
            if ( numOfRows > 0 )
                DLR ( &array2d, &rowSizes, &numOfRows );
            }

        else if ( strcmp ( operation, "DFC" ) == 0 ){ // delete first column
            if ( numOfRows > 0 )
                DFC ( &array2d, &rowSizes, &numOfRows );
            }

        else if ( strcmp ( operation, "DLC" ) == 0 ){ // delete last column
            if ( numOfRows > 0 )
                DLC ( &array2d, &rowSizes, &numOfRows );
            }

        else if ( strcmp ( operation, "RMR" ) == 0 ){ // remove row
            int r;
            scanf ( "%d", &r );
            if ( numOfRows > 0 && r >= 0 && r < numOfRows )
                RMR ( r, &array2d, &rowSizes, &numOfRows );
            }

        else if ( strcmp ( operation, "RMC" ) == 0 ){ // remove column
            int c;
            scanf ( "%d", &c );
            if ( numOfRows > 0 && c >=0 )
                RMC ( c, &array2d, &rowSizes, &numOfRows );
            }

        else if ( strcmp ( operation, "RMB" ) == 0 ){ // remove block
            int r;
            int h;
            int c;
            int w;
            scanf ( "%d", &r );
            scanf ( "%d", &h );
            scanf ( "%d", &c );
            scanf ( "%d", &w );
            if ( numOfRows > 0 && r >= 0 && r < numOfRows && c >= 0 && h > 0 && w > 0 )
                RMB ( r, h, c, w, &array2d, &rowSizes, &numOfRows );
            }

        else if ( strcmp ( operation, "ISB" ) == 0 ){ // insert block
            int r;
            int c;
            int h;
            int w;
            scanf ( "%d", &r );
            scanf ( "%d", &c );
            scanf ( "%d", &h );
            scanf ( "%d", &w );
            // wczytywanie wartosci obsluze w podprogramie
            if ( r >= 0 && c >= 0 && h > 0 && w > 0 )
                ISB ( r, c, h, w, &array2d, &rowSizes, &numOfRows );
            }

        else if ( strcmp ( operation, "WRF" ) == 0 ){ // write file
            char *name = (char*) malloc( 17 * sizeof (char));
            scanf ( "%s", name );
            WRF ( name, &array2d, &rowSizes, &numOfRows );
            }

        else if ( strcmp ( operation, "RDF" ) == 0 ){ // read file
            //zwalnianie tablicy
            int i;
            for (i = 0; i < numOfRows; i++) {
                if (*(array2d + i) != NULL)
                    free(*(array2d + i));
                }
            if (array2d != NULL) {
                free(array2d);
                array2d = NULL;
                }
            if (rowSizes != NULL) {
                free(rowSizes);
                rowSizes = NULL;
                }
            numOfRows = 0;
            //
            char *name = (char*) malloc( 17 * sizeof (char));
            scanf ( "%s", name );
            RDF ( name, &array2d, &rowSizes, &numOfRows );
            }

        else if ( strcmp ( operation, "PRT" ) == 0 ){ // print
            PRT ( &array2d, &rowSizes, &numOfRows );
            }

        }
    while ( strcmp ( operation, "END" ) ); // bo zwraca 0, jesli sa rowne

    // zwalnianie
    if (operation != NULL) {
        free(operation);
        operation = NULL;
        }

    int i;
    for (i = 0; i < numOfRows; i++) {
        if (*(array2d + i) != NULL)
            free(*(array2d + i));
        }
    if (array2d != NULL) {
        free(array2d);
        array2d = NULL;
        }
    if (rowSizes != NULL) {
        free(rowSizes);
        rowSizes = NULL;
        }
    numOfRows = 0;
    return 0;
    }
