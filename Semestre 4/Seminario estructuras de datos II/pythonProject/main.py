from os import system, name
import time

# define our clear function
def clear():
    # for windows
    if name == 'nt':
        _ = system('cls')

        # for mac and linux(here, os.name is 'posix')
    else:
        _ = system('clear')


class imaginary():
    def __init__(self,nreal,nimag):
        self.numreal = nreal
        self.numimag = nimag

    def add(self,nreal,nimag):
        self.numreal += nreal
        self.numimag += nimag

    def sustract(self,nreal,nimag):
        self.numreal -= nreal
        self.numimag -= nimag

    def Print(self):
        if(self.numimag > 0 and self.numreal > 0):
            print(self.numreal , "+", self.numimag, "i")

        elif self.numreal == 0 and self.numimag != 0:
            print(self.numimag, 'i')

        elif self.numimag == 0 and self.numreal != 0:
            print(self.numreal)
        else:
            print(self.numreal, self.numimag, "i")


while(True):
    clear()
    print("Input the ecuation\n")

    nreal = int(input("Input the real number: "))
    nimag = int(input("Input de imaginary number: "))
    operators = imaginary(nreal,nimag)

    print("Select an option \n")
    print("1)Add \n2)Sustract \n3)Exit")
    option = int(input(""))

    if(option == 1):
        addreal = int(input("Input the real number for the add: "))
        addimag = int(input("Input de imaginary number for the add: "))

        operators.add(addreal,addimag)
        operators.Print()
        time.sleep(5)

    elif(option == 2):
        susreal = int(input("Input the real number for the sustraction: "))
        susimag = int(input("Input de imaginary number for the sustraction: "))

        operators.sustract(susreal, susimag)
        operators.Print()
        time.sleep(5)

    elif(option == 3):
        print("Thanks...")
        break

    else:
        print("Invalid option")
        time.sleep(5)
        continue
