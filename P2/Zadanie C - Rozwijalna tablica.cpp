// Lukasz Rudnik

NODE_STRUCT* NewNode ( void ){
    NODE_STRUCT* nodePtr = new NODE_STRUCT;
    nodePtr -> object = new OBJECT_TYPE [ SIZE ];
    nodePtr -> use = 0;
    nodePtr -> next = NULL;
    return nodePtr;
    }

void DeleteNode ( NODE_STRUCT* nodePtr ){
    if ( nodePtr != NULL ){
        delete [] nodePtr -> object;
        delete nodePtr;
        }
    }

void Clear ( NODE_STRUCT** headPtr ){
    if ( *headPtr != NULL ){
        Clear ( &( (*headPtr)->next ) );
        DeleteNode ( *headPtr );
        *headPtr = NULL;
        }
    }

void AddFirst ( NODE_STRUCT** headPtr, OBJECT_TYPE* element ){
    if ( *headPtr != NULL ){
        if ( (*headPtr) -> use < SIZE ){
            for ( BYTE i = (*headPtr) -> use; i > 0; i-- )
                *( (*headPtr) -> object + i ) = *( (*headPtr) -> object + i - 1 );
            *( (*headPtr) -> object ) = *element;
            ( (*headPtr) -> use )++;
            }
        else{
            NODE_STRUCT* savePtr = *headPtr;
            *headPtr = NewNode ();
            (*headPtr) -> next = savePtr;
            *( (*headPtr) -> object ) = *element;
            (*headPtr) -> use = 1;
            }
        }
    else{
        *headPtr = NewNode ();
        *( (*headPtr) -> object ) = *element;
        (*headPtr) -> use = 1;
        }
    }

void AddLast ( NODE_STRUCT** headPtr, OBJECT_TYPE* element ){
    if ( *headPtr != NULL ){
        NODE_STRUCT** auxPtr = headPtr;
        while ( (*auxPtr) -> next != NULL ){
            auxPtr = &( (*auxPtr) -> next );
            }
        if ( (*auxPtr) -> use < SIZE ){
            *( ( (*auxPtr) -> object ) + ( (*auxPtr) -> use ) ) = *element;
            ( (*auxPtr) -> use )++;
            }
        else{
            (*auxPtr) -> next = NewNode ();
            *( ( (*auxPtr) -> next ) -> object ) = *element;
            ( (*auxPtr) -> next ) -> use = 1;
            }
        }
    else{
        *headPtr = NewNode ();
        *( (*headPtr) -> object ) = *element;
        (*headPtr) -> use = 1;
        }
    }

void GetFirst ( NODE_STRUCT* head, NODE_STRUCT** outPtr, BYTE* outIndex ){
    if ( head == NULL )
        *outPtr = NULL;
    else{
        *outPtr = head;
        *outIndex = 0;
        }
    }

void GetPrev ( NODE_STRUCT* head, NODE_STRUCT* targetNode, BYTE targetIndex, NODE_STRUCT** outPtr, BYTE* outIndex ){
    if ( targetIndex == 0 ){
        if ( targetNode == head )
            *outPtr = NULL;
        else{
            NODE_STRUCT* auxNode = head;
            while ( auxNode -> next != targetNode )
                auxNode = auxNode -> next;
            *outPtr = auxNode;
            *outIndex = ( auxNode -> use ) - 1;
            }
        }
    else{
        *outPtr = targetNode;
        *outIndex = targetIndex - 1;
        }
    }

void GetNext ( NODE_STRUCT* head, NODE_STRUCT* targetNode, BYTE targetIndex, NODE_STRUCT** outPtr, BYTE* outIndex ){
    if ( targetIndex == ( targetNode -> use ) - 1 ){
        if ( targetNode -> next == NULL )
            *outPtr = NULL;
        else{
            *outPtr = targetNode -> next;
            *outIndex = 0;
            }
        }
    else{
        *outPtr = targetNode;
        *outIndex = targetIndex + 1;
        }
    }

void GetLast ( NODE_STRUCT* head, NODE_STRUCT** outPtr, BYTE* outIndex ){
    if ( head == NULL )
        *outPtr = NULL;
    else{
        NODE_STRUCT* auxNode = head;
        while ( auxNode -> next != NULL )
            auxNode = auxNode -> next;
        *outPtr = auxNode;
        *outIndex = ( auxNode -> use ) - 1;
        }
    }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void InsertPrev ( NODE_STRUCT** headPtr, NODE_STRUCT* targetNode, BYTE targetIndex, OBJECT_TYPE* targetObject ){
    if ( targetIndex != 0 ){
        if ( targetNode -> use < SIZE ){
            for ( BYTE i = targetNode -> use; i > targetIndex; i-- )
                *( targetNode -> object + i ) = *( targetNode -> object + i - 1 );
            *( targetNode -> object + targetIndex ) = *targetObject;
            ( targetNode -> use )++;
            }
        else{
            if ( targetNode == *headPtr ){
                AddFirst ( headPtr, targetNode -> object );
                for ( BYTE i = 0; i < targetNode -> use - 1; i++ )
                    *( targetNode -> object + i ) = *( targetNode -> object + i + 1 );
                ( targetNode -> use )--;
                InsertPrev ( headPtr, targetNode, targetIndex - 1, targetObject );
                }
            else{
                NODE_STRUCT* prevNode = *headPtr;
                while ( prevNode -> next != targetNode )
                    prevNode = prevNode -> next;
                if ( prevNode -> use < SIZE ){
                    *( prevNode -> object + prevNode -> use ) = *( targetNode -> object );
                    ( prevNode -> use )++;
                    for ( BYTE i = 0; i < targetNode -> use - 1; i++ )
                        *( targetNode -> object + i ) = *( targetNode -> object + i + 1 );
                    ( targetNode -> use )--;
                    InsertPrev ( headPtr, targetNode, targetIndex - 1, targetObject );
                    }
                else{
                    prevNode -> next = NewNode ();
                    ( prevNode -> next ) -> next = targetNode;
                    InsertPrev ( headPtr, targetNode, targetIndex, targetObject );
                    }
                }
            }
        }
    else{
        if ( targetNode == *headPtr )
            AddFirst ( headPtr, targetObject );
        else{
            if ( targetNode -> use < SIZE ){
                for ( BYTE i = targetNode -> use; i > 0; i-- )
                    *( targetNode -> object + i ) = *( targetNode -> object + i - 1 );
                *( targetNode -> object ) = *targetObject;
                ( targetNode -> use )++;
                }
            else{
                NODE_STRUCT* prevNode = *headPtr;
                while ( prevNode -> next != targetNode )
                    prevNode = prevNode -> next;
                if ( prevNode -> use < SIZE ){
                    *( prevNode -> object + prevNode -> use ) = *targetObject;
                    ( prevNode -> use )++;
                    }
                else{
                    prevNode -> next = NewNode ();
                    ( prevNode -> next ) -> next = targetNode;
                    *( prevNode -> next -> object ) = *targetObject;
                    prevNode -> next -> use = 1;
                    }
                }
            }
        }
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void InsertNext ( NODE_STRUCT* headPtr, NODE_STRUCT* targetNode, BYTE targetIndex, OBJECT_TYPE* targetObject ){
    if ( targetIndex != targetNode -> use - 1 ){
        if ( targetNode -> use < SIZE ){
            for ( BYTE i = targetNode -> use; i > targetIndex + 1; i-- )
                *( targetNode -> object + i ) = *( targetNode -> object + i - 1 );
            *( targetNode -> object + targetIndex + 1 ) = *targetObject;
            ( targetNode -> use )++;
            }
        else{
            if ( targetNode -> next == NULL ){
                AddLast ( &headPtr, targetNode -> object + targetNode -> use - 1 );
                ( targetNode -> use )--;
                InsertNext ( headPtr, targetNode, targetIndex, targetObject );
                }
            else{
                NODE_STRUCT* nextNode = targetNode -> next;
                if ( nextNode -> use < SIZE ){
                    for ( BYTE i = nextNode -> use; i > 0; i-- )
                        *( nextNode -> object + i ) = *( nextNode -> object + i - 1 );
                    *( nextNode -> object ) = *( targetNode -> object + targetNode -> use - 1 );
                    ( nextNode -> use )++;
                    ( targetNode -> use )--;
                    InsertNext ( headPtr, targetNode, targetIndex, targetObject );
                    }
                else{
                    targetNode -> next = NewNode ();
                    ( targetNode-> next ) -> next = nextNode;
                    InsertNext ( headPtr, targetNode, targetIndex, targetObject );
                    }
                }
            }
        }
    else{
        if ( targetNode -> next == NULL )
            AddLast ( &headPtr, targetObject );
        else{
            if ( targetNode -> use < SIZE ){
                *( targetNode -> object + targetNode -> use ) = *targetObject;
                ( targetNode -> use )++;
                }
            else{
                NODE_STRUCT* nextNode = targetNode -> next;
                if ( nextNode -> use < SIZE ){
                    for ( BYTE i = nextNode -> use; i > 0; i-- )
                        *( nextNode -> object + i ) = *( nextNode -> object + i - 1 );
                    *( nextNode -> object ) = *targetObject;
                    ( nextNode -> use )++;
                    }
                else{
                    targetNode -> next = NewNode ();
                    ( targetNode -> next ) -> next = nextNode;
                    *( ( targetNode -> next ) -> object ) = *targetObject;
                    ( targetNode -> next ) -> use = 1;
                    }
                }
            }
        }
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void RemoveFirst ( NODE_STRUCT** headPtr ){
        if ( *headPtr != NULL ){
            if ( (*headPtr) -> use == 1 ){
                NODE_STRUCT* savePtr = (*headPtr) -> next;
                DeleteNode ( *headPtr );
                *headPtr = savePtr;
                }
            else{
               for ( BYTE i = 0; i < (*headPtr) -> use - 1; i++ )
                    *( (*headPtr) -> object + i ) = *( (*headPtr) -> object + i + 1 );
                ( (*headPtr) -> use )--;
                }
            }
    }

void RemoveCurrent ( NODE_STRUCT** headPtr, NODE_STRUCT* targetNode, BYTE targetIndex ){
    if ( *headPtr != NULL ){
        NODE_STRUCT* prevNode = *headPtr;
        if ( targetNode != *headPtr ){
            while ( prevNode -> next != targetNode )
                prevNode = prevNode -> next;
            if ( targetNode -> use == 1 ){
                        NODE_STRUCT* savePtr = targetNode -> next;
                        DeleteNode ( targetNode );
                        prevNode -> next = savePtr;
                    }
                else{
                   for ( BYTE i = targetIndex; i < targetNode -> use - 1; i++ )
                        *( targetNode -> object + i ) = *( targetNode -> object + i + 1 );
                    ( targetNode -> use )--;
                    }
            }
        else{
            if ( targetNode -> use == 1 ){
                NODE_STRUCT* savePtr = targetNode -> next;
                DeleteNode ( targetNode );
                *headPtr = savePtr;
                }
            else{
                for ( BYTE i = targetIndex; i < targetNode -> use - 1; i++ )
                    *( targetNode -> object + i ) = *( targetNode -> object + i + 1 );
                ( targetNode -> use )--;
                }
            }
        }
    }

void RemovePrev ( NODE_STRUCT** headPtr, NODE_STRUCT* targetNode, BYTE targetIndex ){
    if ( targetIndex == 0 ){
        if ( targetNode == *headPtr && targetIndex == 0 )
            return;
        else{
            NODE_STRUCT* auxNode = *headPtr;
            while ( auxNode -> next != targetNode )
                auxNode = auxNode -> next;
            targetNode = auxNode;
            targetIndex = ( auxNode -> use ) - 1;
            }
        }
    else
        targetIndex = targetIndex - 1;

    RemoveCurrent ( headPtr, targetNode, targetIndex );
    }

void RemoveNext( NODE_STRUCT* headPtr, NODE_STRUCT* targetNode, BYTE targetIndex ){
    if ( targetIndex == ( targetNode -> use ) - 1 ){
        if ( targetNode -> next == NULL )
            return;
        else{
            targetNode = targetNode -> next;
            targetIndex = 0;
            }
        }
    else{
        targetIndex = targetIndex + 1;
        }
    RemoveCurrent ( &headPtr, targetNode, targetIndex );
    }

void RemoveLast( NODE_STRUCT** headPtr ){
    if ( *headPtr != NULL ){
            if ( (*headPtr) -> next == NULL ){
                if ( (*headPtr) -> use == 1 )
                    Clear ( headPtr);
                else{
                    ( (*headPtr) -> use )--;
                    }
                }
            else{
                NODE_STRUCT* secondLast = *headPtr;
                while ( ( secondLast -> next ) -> next != NULL )
                    secondLast = secondLast -> next;
                NODE_STRUCT* lastNode = secondLast -> next;
                if ( lastNode -> use == 1 ){
                    DeleteNode ( lastNode );
                    secondLast -> next = NULL;
                    }

                else{
                    ( lastNode -> use )--;
                    }
                }
            }
    }


void Find ( NODE_STRUCT* head, OBJECT_TYPE* targetObject, NODE_STRUCT** outPtr, BYTE* outIndex ){
    for ( int i = 0; i < head -> use; i++ ){
        if ( *( head -> object + i ) == *targetObject ){
            *outPtr = head;
            *outIndex = i;
            return;
            }
        }
    if ( head -> next != NULL )
        Find ( head -> next, targetObject, outPtr, outIndex );
    else{
        *outPtr = NULL;
        return;
        }
    }

void Compress ( NODE_STRUCT* head ){
    if ( head != NULL ){
        while ( head -> use < SIZE ){
            if ( head -> next == NULL )
                break;
            else{
                while ( ( head -> next ) -> use > 0 ){
                    *( head -> object + head -> use ) = *( ( head -> next ) -> object );
                    ( head -> use )++;
                    for ( BYTE i = 0; i < ( head -> next ) -> use - 1; i++ )
                        *( ( head -> next ) -> object + i ) = *( ( head -> next ) -> object + i + 1 );
                    ( ( head -> next ) -> use )--;
                    if ( head -> use >= SIZE )
                        break;
                    }
                if ( ( head -> next ) -> use == 0 ){
                    NODE_STRUCT* savePtr = head -> next;
                    head -> next = ( head -> next ) -> next;
                    DeleteNode ( savePtr );
                    }
                }
            }
        if ( head -> next != NULL )
            Compress ( head -> next );
        }
    }

void Reverse ( NODE_STRUCT* head ){
    Compress ( head );
    NODE_STRUCT* newHead = NewNode ();
    NODE_STRUCT* auxNode = head;
    while ( auxNode != NULL ){
        for ( BYTE i = 0; i < auxNode -> use; i++ ){
            AddFirst ( &newHead, auxNode -> object + i );
            }
        auxNode = auxNode -> next;
        }
    auxNode = newHead;
    while ( auxNode != NULL && head != NULL ){
        for ( BYTE i = 0; i < auxNode -> use; i++ ){
            *( head -> object + i ) = *( auxNode -> object + i );
            }
        auxNode = auxNode -> next;
        head = head -> next;
        }
    Clear ( &newHead );
    }
