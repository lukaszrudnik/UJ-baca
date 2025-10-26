# Lukasz Rudnik

class Person:
    def __init__(self, name, surname):
        self.name = name
        self.surname = surname
    def __str__(self):
        return 'name: {:10} surname: {:15}'.format(self.name, self.surname)
class Employee:
    def __init__(self, person, experience, salary):
        self.person = person
        self.experience = experience
        self.salary = salary

    def __str__(self):
        return '{} experience: {:2} salary: {:5}'.format(self.person, self.experience, self.salary)
    
def CocktailSortPerson ( arr ):
    start = 0
    end = len ( arr ) - 1
    swapped = True
    while ( swapped == True ):
        swapped = False
        for i in range ( start, end ):
            if ( arr [ i ].person.surname > arr [ i + 1 ].person.surname ):
                arr [ i ], arr [ i + 1 ] = arr [ i + 1 ], arr [ i ]
                swapped = True
            elif ( arr [ i ].person.surname == arr [ i + 1 ].person.surname ):
                if ( arr [ i ].person.name > arr [ i + 1 ].person.name ):
                    arr [ i ], arr [ i + 1 ] = arr [ i + 1 ], arr [ i ]
                    swapped = True
        end = end - 1

        if ( swapped == False ):
            break
        swapped = False

        # start - 1, bo mamy wtedy przedzial [start, end - 1]
        for i in range ( end - 1, start - 1, -1 ):
            if ( arr [ i ].person.surname > arr [ i + 1 ].person.surname ):
                arr [ i ], arr [ i + 1 ] = arr [ i + 1 ], arr [ i ]
                swapped = True
            elif ( arr [ i ].person.surname == arr [ i + 1 ].person.surname ):
                if ( arr [ i ].person.name > arr [ i + 1 ].person.name ):
                    arr [ i ], arr [ i + 1 ] = arr [ i + 1 ], arr [ i ]
                    swapped = True
        start = start + 1

def SelectionSortSalary ( arr ):
    n = len ( arr )
    for i in range ( n - 1 ): # -1 bo jak zrobimy dla n-1 elementu to element n bedzie juz na dobrym miejscu
        minIndex = i
        for j in range ( i + 1, n ):
            if ( arr [ j ].salary < arr [ minIndex ].salary ):
                minIndex = j
        arr [ i ], arr [ minIndex ] = arr [ minIndex ], arr [ i ]

def CountSortExperience ( arr ):
    maxVal = 0
    for i in range ( len ( arr ) ):
        if arr [ i ].experience > maxVal:
            maxVal = arr [ i ].experience
    count = [ 0 ] * ( maxVal + 1 )
    for i in range ( len ( arr ) ):
        count [ arr [ i ].experience ] += 1
    for i in range ( 1, maxVal + 1 ):
        count [ i ] += count [ i - 1 ]

    out = [ 0 ] * len ( arr )
    for i in range ( len ( out ) - 1, -1, -1 ):
        out [ count [ arr [ i ].experience ] - 1 ] = arr [ i ]
        count [ arr [ i ].experience ] -= 1

    for i in range ( len ( arr ) ):
        arr [ i ] = out [ i ]

# wczytywanie danych
# .split() tworzy liste ze slow oddzielonych spacjami z inputu
# map ( int, ... ) zamienia liste stringow na liste intow
nameList = input().split()
surnameList = input().split()
experienceList = list ( map ( int, input().split() ) )
salaryList = list ( map ( int, input().split() ) )

employeeList = []
for i in range ( len ( nameList ) ):
    person = Person ( nameList [ i ], surnameList [ i ] )
    employee = Employee ( person, experienceList [ i ], salaryList [ i ] )
    employeeList.append ( employee )

# sortowanie: person ( name -> surname ) -> experience -> salary
#             cocktail sort                 selection     count

# czyli bedziemy sortowac w oddzielnej kolejnosci:
#             salary -> experience -> person

# poniewaz wszystkie z uzywanych sortowan sa stabilne
# wiec przy sortowaniu elementy o rownych wartosciach decydujacych o kolejnosci
# nie beda ze soba zamieniane.

SelectionSortSalary ( employeeList )
CountSortExperience ( employeeList )
CocktailSortPerson ( employeeList )

for employee in employeeList:
    print ( employee )