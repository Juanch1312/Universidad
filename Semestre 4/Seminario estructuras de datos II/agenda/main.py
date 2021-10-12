import os.path as path
#Class student
class student:
    def __init__(self):
        self.c = ''
        self.co = ''

    def setNombre(self, name):
        self.n = name

    def setCarrera(self,career):
        self.c = career

    def setCodigo(self,code):
        self.co = code

    def toFile(self): #Add the delimited attributes to the end of each
        archivo = open("agenda.txt",'a')
        archivo.write(self.n+'@' + self.c+'@' + self.co+'@'+'\n')
        archivo.close()

#Function read file
def readFile():
    if(path.exists('agenda.txt')):
        lectura = '\n'
        archivo = open("agenda.txt","r")
        caracter = archivo.read(1)
        while(caracter != ''):
            if(caracter == '@'):
                lectura += '\n' #Check the delimiter if it exists changes to line break
            else:
                lectura += caracter

            caracter = archivo.read(1) #File travel
        print(lectura)
        archivo.close()

    else:
        print("The file doesnt exist!!")

def search(id):
    if(path.exists('agenda.txt')):
        archivo = open('agenda.txt','r')
        band = False
        for line in archivo:
            code = ''
            count = 0
            rec = 0
            while count != 2:
                if(line[rec] == '@'):
                    count += 1
                rec += 1
            for i in range(0,9):
                code += line[rec + i]
            if(code == id):
                a = len(line)
                student = ''
                for b in range(0,a):
                    if(line[b] == '@'):
                        student += '\n'
                    else:
                        student += line[b]
                print('\nFound it: ')
                print(student)
                return 1
        if(band == False):
            print("\nNot found it\n")
        archivo.close()
    else:
        print('The file doesnt exist!!')

def option1(student):
    name = input("\nName of the student: ")
    career = input("Career of the student: ")
    code = input("Code of the student: ")

    student.setNombre(name)
    student.setCarrera(career)
    student.setCodigo(code)

    student.toFile()

    print("Registered!!")


if __name__ == '__main__': #Main
    student = student()
    while(True):
        opc = int(input("1) New student\n2) Listen schedule\n3) Search\n4) Exit\nPut option : "))
        if(opc == 1): #Add student

            option1(student)

        elif(opc == 2): #Read file (comprovation integrated)
            readFile()

        elif(opc == 3): #Search
            id = input("Put the id: ")

            retorno = search(id)
            if(retorno != 1):
                print("Do you want register a new student? If yes tab S or s. If not press another key")
                answ = input("")
                if(answ == 'S' or answ == 's'):
                    option1(student)

        elif(opc == 4): #Exit
            break

        else: #Other options
            print("That option doesnt exist")
