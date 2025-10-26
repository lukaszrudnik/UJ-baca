// Lukasz Rudnik
#include <iostream>
using namespace std;
int main(){
    int sessions;
    int arraySize;
    int i;
    char operationType;

    int startIndex;
    int fragmentLength;
    int left;
    int right;
    int temp;
    int operationStage;
    int moveValue;
    int indexOne;
    int indexTwo;
    int tempOne;
    int tempTwo;
    int leftOne;
    int leftTwo;
    bool sortSwap;
    int j;
    int frOne;
    int frTwo;
    int rightOne;
    int rightTwo;
    int rememberMoveVal;


    cin >> sessions;
    while ( sessions > 0 ){
        sessions = sessions - 1;

        cin >> arraySize;
        int arrayOne [ arraySize ];

        i = 0;
        while ( i < arraySize ){
            cin >> arrayOne [ i ];
            i = i + 1;
            }

        i = 0;
        while ( i < arraySize ){
            cout << arrayOne [ i ];
            if ( i < arraySize - 1 )
                 cout  << " ";
            i = i + 1;
            }
        cout << endl;

        operationType = 'a';
        while ( operationType != 'F' ){
            cin >> operationType;

            if ( operationType == 'R' ){
                cin >> startIndex >> fragmentLength;
                if ( fragmentLength > 1 ){
                    if ( startIndex >= 0 )
                        startIndex = startIndex % arraySize;
                    else
                        startIndex = arraySize + ( startIndex % arraySize );

                    operationStage = 0;
                    while ( operationStage < ( arraySize / fragmentLength ) ){

                        left = ( startIndex + ( operationStage * fragmentLength ) ) % arraySize;
                        right = ( left + fragmentLength - 1 ) % arraySize;
                        i = fragmentLength / 2;
                        while ( i > 0 ){
                            temp = arrayOne [ left ];
                            arrayOne [ left ] = arrayOne [ right ];
                            arrayOne [ right ] = temp;
                            left = ( left + 1 ) % arraySize;
                            right = right - 1;
                            if ( right < 0 )
                                right = arraySize + ( right % arraySize );
                            i = i - 1;
                            }
                        operationStage = operationStage + 1;
                        }
                    }
/*
                    i = 0;
                    while ( i < arraySize ){
                        cout << arrayOne [ i ] << " ";
                        i = i + 1;
                        }
                    cout << endl;
*/
                }

/////////////////////////////////////////////////////////// \/\/\/\/\/\/\/\/\/\/
                else if ( operationType == 'M' ){
                    cin >> startIndex >> fragmentLength >> moveValue;
                    rememberMoveVal = moveValue;
                    if ( fragmentLength > 1 && moveValue != 0 ){
                        if ( moveValue > 0 )
                            moveValue = moveValue % fragmentLength;
                        else
                            moveValue = fragmentLength + ( moveValue % fragmentLength );
                        if ( startIndex >= 0 )
                            startIndex = startIndex % arraySize;
                        else
                            startIndex = arraySize + ( startIndex % arraySize );
                            //cout << endl << moveValue << endl << fragmentLength <<endl;

                        frOne = fragmentLength - moveValue;
                        frTwo = moveValue;

                        operationStage = 0;
                        while ( operationStage < arraySize / fragmentLength ){
                            left = ( startIndex + ( operationStage * fragmentLength ) ) % arraySize;
                            right = ( left + fragmentLength - 1 ) % arraySize;
                            leftOne = left;
                            rightOne = ( leftOne + frOne - 1 ) % arraySize;
                            leftTwo = ( rightOne + 1 ) % arraySize;
                            rightTwo = right;

                            i = frOne / 2;
                            while ( i > 0 ){
                                temp = arrayOne [ leftOne ];
                                arrayOne [ leftOne ] = arrayOne [ rightOne ];
                                arrayOne [ rightOne ] = temp;
                                leftOne = ( leftOne  + 1 ) % arraySize;
                                rightOne = rightOne - 1;
                                if ( rightOne < 0 )
                                    rightOne = arraySize + ( rightOne % arraySize );
                                i = i - 1;
                                }
                            i = frTwo / 2;
                            while ( i > 0 ){
                                temp = arrayOne [ leftTwo ];
                                arrayOne [ leftTwo ] = arrayOne [ rightTwo ];
                                arrayOne [ rightTwo ] = temp;
                                leftTwo = ( leftTwo  + 1 ) % arraySize;
                                rightTwo = rightTwo - 1;
                                if ( rightTwo < 0 )
                                    rightTwo = arraySize + ( rightTwo % arraySize );
                                i = i - 1;
                                }
                            i = fragmentLength / 2;
                            while ( i > 0 ){
                                temp = arrayOne [ left ];
                                arrayOne [ left ] = arrayOne [ right ];
                                arrayOne [ right ] = temp;
                                left = ( left + 1 ) % arraySize;
                                right = right - 1;
                                if ( right < 0 )
                                    right = arraySize + ( right % arraySize );
                                i = i - 1;
                                }

                            operationStage = operationStage + 1;
                            }
//cout << "\nprzeszlo\n";
                        left = ( startIndex + ( operationStage * fragmentLength ) ) % arraySize;
                        fragmentLength = arraySize % fragmentLength;
                        right = ( left + fragmentLength - 1 ) % arraySize;
                        moveValue = rememberMoveVal;

                        if ( fragmentLength > 0 ){
                            if ( moveValue > 0 )
                                moveValue = moveValue % fragmentLength;
                            else
                                moveValue = fragmentLength + ( moveValue % fragmentLength );
                        }
                        frOne = fragmentLength - moveValue;
                        frTwo = moveValue;
                        if ( fragmentLength > 1 && moveValue != 0 ){
                              // cout << "\nprzeszlo\n";
                            leftOne = left;
                            rightOne = ( leftOne + frOne - 1 ) % arraySize;
                            leftTwo = ( rightOne + 1 ) % arraySize;
                            rightTwo = right;

                            i = frOne / 2;
                            while ( i > 0 ){
                                temp = arrayOne [ leftOne ];
                                arrayOne [ leftOne ] = arrayOne [ rightOne ];
                                arrayOne [ rightOne ] = temp;
                                leftOne = ( leftOne  + 1 ) % arraySize;
                                rightOne = rightOne - 1;
                                if ( rightOne < 0 )
                                    rightOne = arraySize + ( rightOne % arraySize );
                                i = i - 1;
                                }
                            i = frTwo / 2;
                            while ( i > 0 ){
                                temp = arrayOne [ leftTwo ];
                                arrayOne [ leftTwo ] = arrayOne [ rightTwo ];
                                arrayOne [ rightTwo ] = temp;
                                leftTwo = ( leftTwo  + 1 ) % arraySize;
                                rightTwo = rightTwo - 1;
                                if ( rightTwo < 0 )
                                    rightTwo = arraySize + ( rightTwo % arraySize );
                                i = i - 1;
                                }
                            i = fragmentLength / 2;
                            while ( i > 0 ){
                                temp = arrayOne [ left ];
                                arrayOne [ left ] = arrayOne [ right ];
                                arrayOne [ right ] = temp;
                                left = ( left + 1 ) % arraySize;
                                right = right - 1;
                                if ( right < 0 )
                                    right = arraySize + ( right % arraySize );
                                i = i - 1;
                                }


                            }
                        }
/*
                    i = 0;
                    while ( i < arraySize ){
                        cout << arrayOne [ i ] << " ";
                        i = i + 1;
                        }
                    cout << endl;
*/
                    }
/////////////////////////////////////////////////////////////// /\/\/\/\/\/\/\/
                else if ( operationType == 'C' ){
                    cin >> startIndex >> fragmentLength;
                    if ( fragmentLength > 0 ){
                        if ( startIndex >= 0 )
                            startIndex = startIndex % arraySize;
                        else
                            startIndex = arraySize + ( startIndex % arraySize );

                        operationStage = 0;
                        while ( operationStage < ( arraySize / ( fragmentLength * 2 ) ) ){
                                leftOne = ( startIndex + operationStage * fragmentLength * 2 ) % arraySize;
                                leftTwo = ( leftOne + fragmentLength ) % arraySize;

                                i = fragmentLength;
                                while ( i > 0 ){
                                    i = i - 1;
                                    temp = arrayOne [ leftTwo ];
                                    arrayOne [ leftTwo ] = arrayOne [ leftOne ];
                                    arrayOne [ leftOne ] = temp;

                                    leftOne = ( leftOne + 1 ) % arraySize;
                                    leftTwo = ( leftTwo + 1 ) % arraySize;
                                    }
                                operationStage = operationStage + 1;
                                }
                    }

/*
                    i = 0;
                    while ( i < arraySize ){
                        cout << arrayOne [ i ] << " ";
                        i = i + 1;
                        }
                    cout << endl;
*/
                    }


                else if ( operationType == 'S' ){
                    cin >> startIndex >> fragmentLength;
                    if ( fragmentLength != 0 && fragmentLength != 1 && fragmentLength != -1 ){
                        if ( fragmentLength > 0 )
                            sortSwap = false;
                        else{
                            sortSwap = true;
                            fragmentLength = -fragmentLength;
                            }
                        if ( fragmentLength > arraySize )
                                fragmentLength = arraySize;

                        if ( startIndex >= 0 )
                            startIndex = startIndex % arraySize;
                        else
                            startIndex = arraySize + ( startIndex % arraySize );

                        operationStage = 0;
                        while ( operationStage < ( arraySize / fragmentLength ) ){
                                left = ( startIndex + operationStage * fragmentLength ) % arraySize;
                                right = ( left + fragmentLength - 1 ) % arraySize;

                                i = fragmentLength;
                                while ( i > 0 ){
                                    i = i - 1;
                                    j = left;
                                    while ( j != ( right ) ){
                                        if ( arrayOne [ j ] > arrayOne [ ( j + 1 ) % arraySize ] ){
                                            temp = arrayOne [ ( j + 1 ) % arraySize ];
                                            arrayOne [ ( j + 1 ) % arraySize ] = arrayOne [ j ];
                                            arrayOne [ j ] = temp;
                                            }
                                        j = ( j + 1 ) % arraySize;
                                        }
                                    }
                                if ( sortSwap == true ){
                                    i = fragmentLength / 2;
                                    while ( i > 0 ){
                                        temp = arrayOne [ left ];
                                        arrayOne [ left ] = arrayOne [ right ];
                                        arrayOne [ right ] = temp;
                                        left = ( left + 1 ) % arraySize;
                                        right = right - 1;
                                        if ( right < 0 )
                                            right = arraySize + ( right % arraySize );
                                        i = i - 1;
                                        }
                                    }
                                operationStage = operationStage + 1;
                                }
                            left = ( startIndex + operationStage * fragmentLength ) % arraySize;
                            fragmentLength = arraySize % fragmentLength;
                            right = ( left + fragmentLength - 1 ) % arraySize;

                            if ( fragmentLength > 1 ){

                                i = fragmentLength;
                                while ( i > 0 ){
                                    i = i - 1;
                                    j = left;
                                    while ( j < ( right ) ){
                                        if ( arrayOne [ j ] > arrayOne [ ( j + 1 ) % arraySize ] ){
                                            temp = arrayOne [ ( j + 1 ) % arraySize ];
                                            arrayOne [ ( j + 1 ) % arraySize ] = arrayOne [ j ];
                                            arrayOne [ j ] = temp;
                                            }
                                        j = ( j + 1 ) % arraySize;
                                        }
                                    }
                                if ( sortSwap == true ){
                                    i = fragmentLength / 2;
                                    while ( i > 0 ){
                                        temp = arrayOne [ left ];
                                        arrayOne [ left ] = arrayOne [ right ];
                                        arrayOne [ right ] = temp;
                                        left = ( left + 1 ) % arraySize;
                                        right = right - 1;
                                        if ( right < 0 )
                                            right = arraySize + ( right % arraySize );
                                        i = i - 1;
                                        }
                                    }
                                }
                        }
/*
                    i = 0;
                    while ( i < arraySize ){
                        cout << arrayOne [ i ] << " ";
                        i = i + 1;
                        }
                    cout << endl;
*/
                    }
            }
        i = 0;
        while ( i < arraySize ){
            cout << arrayOne [ i ];
            if ( i < arraySize - 1 )
                 cout  << " ";
            i = i + 1;
            }
        cout << endl;

        }

    }



