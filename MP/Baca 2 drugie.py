# Lukasz Rudnik

class HistogramNode:
    def __init__(self, key):
        self.key = key
        self.count = 1 # liczba wezlow w poddrzewie (na poczatku tylko ten wezel)
        self.left = None
        self.right = None

class HistogramTree:
    def __init__(self):
        self.root = None


    def insert(self, key):
        """Wstawia element do drzewa. Zlozonosc: O(h)"""
        if self.search ( key ):
            return False
        else:
            node = self.root
            while node:
                node.count += 1
                if node.key > key: # idziemy w lewo jak mozemy, jak juz nie to znaczy ze musimy wstawic
                    if node.left:
                        node = node.left
                    else:
                        node.left = HistogramNode ( key )
                        return True
                else:
                    if node.right:
                        node = node.right
                    else:
                        node.right = HistogramNode ( key )
                        return True
            # wyjdziemy z petli tylko jak nie ma self.root
            self.root = HistogramNode ( key )
            return True
        

    def delete(self, key):
        """Usuwa element z drzewa. Zlozonosc: O(h)""" 
        if not self.search ( key ):
            return False
        else:
            node = self.root
            father = None
            isLeftSon = None
            while node:
                node.count -= 1
                if node.key > key:
                    father = node
                    isLeftSon = True
                    node = node.left
                elif node.key < key:
                    father = node
                    isLeftSon = False
                    node = node.right
                else:
                    # znalezlismy szukana, pamietamy ojca. # moze nie byc ojca wtedy korzen
                    # ma ojca, czyli nie korzen
                    if father:
                        if not node.left and not node.right: # lisc
                            if isLeftSon:
                                father.left = None
                                return True
                            else:
                                father.right = None
                                return True
                        elif not ( node.left and node.right ): # jedno poddrzewo
                            if isLeftSon:
                                father.left = node.left if node.left else node.right
                                return True
                            else:
                                father.right = node.left if node.left else node.right
                                return True
                        else: # dwa poddrzewa
                            replacement = node.left
                            replacementFather = node
                            while replacement.right:
                                replacement.count -= 1
                                replacementFather = replacement
                                replacement = replacement.right
                            if replacementFather is node:
                                replacementFather.left = replacement.left
                            else:
                                replacementFather.right = replacement.left
                            node.key = replacement.key
                            return True
                        
                    # nie ma ojca, czyli usuwamy korzen        
                    else:
                        if not node.left and not node.right: # lisc
                            self.root = None
                            return True
                        elif not ( node.left and node.right ): # jedno poddrzewo
                            if node.left:
                                self.root = node.left
                                return True
                            else:
                                self.root = node.right
                                return True
                        else: # dwa poddrzewa
                            replacement = node.left
                            replacementFather = node
                            while replacement.right:
                                replacement.count -= 1
                                replacementFather = replacement
                                replacement = replacement.right
                            if replacementFather is node:
                                replacementFather.left = replacement.left
                            else:
                                replacementFather.right = replacement.left
                            node.key = replacement.key
                            return True


    def search(self, key):
        """Sprawdza czy element jest w drzewie. Zlozonosc: O(h)"""
        node = self.root
        while node:
            if node.key == key:
                return True
            elif node.key > key:
                node = node.left
            else:
                node = node.right
        return False


    def count_in_range(self, start, end): # [<= end] - [<start]
        """Liczy elementy w zakresie [start, end]. Zlozonosc: O(h)"""
        if not self.root or start > end:
            return 0
        result = 0
        node = self.root
        while node:
            if node.key <= end:
                result += node.left.count + 1 if node.left else 1
                node = node.right
            else:
                node = node.left
        return result - self.count_less_than ( start )


    def count_less_than(self, key):
        """Liczy elementy mniejsze od klucza. Zlozonosc: O(h)"""
        result = 0
        node = self.root
        while node:
            if node.key < key:
                result += node.left.count + 1 if node.left else 1
                node = node.right
            else:
                node = node.left
        return result

    def count_greater_than(self, key):
        """Liczy elementy wieksze od klucza. Zlozonosc: O(h)"""
        if not self.root:
            return 0
        else:
            result = self.root.count - self.count_less_than ( key )
            if self.search ( key ):
                result -= 1
            return result


    def find_kth_smallest(self, k):
        """Znajduje k-ty najmniejszy element w drzewie. Zlozonosc: O(h)"""
        if not self.root or k > self.root.count or k < 1:
            return None
        else:
            node = self.root
            leftSide = node.left.count if node.left else 0
            while node:
                if leftSide == k - 1:
                    return node.key
                elif leftSide < k - 1:
                    node = node.right
                    k = k - leftSide - 1
                    leftSide = node.left.count if node.left else 0
                else:
                    node = node.left
                    leftSide = node.left.count if node.left else 0             


    def inorder_traversal(self): # z chata
        """Zwraca liste elementow w porzadku in-order. Zlozonosc: O(n)"""
        result = []
        def traverse(node):
            if node is None:
                return
            traverse(node.left)
            result.append(node.key)
            traverse(node.right)

        traverse(self.root)
        return result
    

    # pomocnicze do debugowania
    def print_inorder(self):
        def inorder(node):
            if node is None:
                return
            inorder(node.left)
            print(f"Key: {node.key}, Count: {node.count}")
            inorder(node.right)
        
        inorder(self.root)
    # -------------------------


# main
tree = HistogramTree ()
command = ""
while command != "EXIT":
    prompt = input().split()
    command = prompt [ 0 ]

    if command == "INSERT": # ok
        x = int ( prompt [ 1 ] )
        if tree.insert ( x ):
            print ( f"Added: {x}" )
        else:
            print ( "Element already exists" )
        
    elif command == "DELETE": # ok
        x = int ( prompt [ 1 ] )
        if tree.delete ( x ):
            print ( f"Deleted: {x}")
        else:
            print ( "Element does not exist" )

    elif command == "SEARCH": # ok
        x = int ( prompt [ 1 ] )
        if tree.search ( x ):
            print ( "YES" )
        else:
            print ( "NO" )

    elif command == "COUNT_RANGE": # ok
        x, y = int ( prompt [ 1 ] ), int ( prompt [ 2 ] )
        aux = tree.count_in_range ( x, y )
        print ( f"Elements in range [{x}, {y}]: {aux}" )

    elif command == "COUNT_LESS": # ok
        x = int ( prompt [ 1 ] )
        aux = tree.count_less_than ( x )
        print ( f"Elements less than {x}: {aux}" )

    elif command == "COUNT_GREATER": # ok
        x = int ( prompt [ 1 ] )
        aux = tree.count_greater_than ( x )
        print ( f"Elements greater than {x}: {aux}" )
    
    elif command == "FIND_KTH":
        k = int ( prompt [ 1 ] )
        aux = tree.find_kth_smallest ( k )
        if aux == None:
            print ( "Invalid index" )
        else:
            print ( aux )

    elif command == "INORDER": # ok
        aux =  tree.inorder_traversal ()
        print ( "[ ", end='' )
        for a in aux:
            print ( f"{a}", end='')
            if a is not aux [ len ( aux ) - 1 ]:
                print ( ",", end='')
            print ( " ", end='')
        print ( "]" )
    
    elif command == "PRINT": # pomocnicze do debugowania
        tree.print_inorder()

