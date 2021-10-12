import os
opc = 0
while(opc != 3):
    opc = int(input("1)Endode \n2)Decode \n3)Close \nChoose an option : "))
    if(opc == 1):
        if os.path.exists("archivo2.txt"):
            archivo = open("archivo2.txt",'r')
            archivo2 = open('cifrado.txt','w')
            character = archivo.read(1)
            while(character != ''):

                if(character >= 'a' and character <='y' or character >= 'A' and character <='Y'):
                    code = chr(ord(character)+1)
                elif(character == 'z'):
                    code = 'a'
                elif(character == 'Z'):
                    code = 'A'
                else:
                    code = character

                archivo2.write(code)
                character = archivo.read(1)

            archivo.close()
            archivo2.close()
        else:
            print("File not found")
    elif(opc == 2):
        if os.path.exists("cifrado.txt"):
            archivo = open('cifrado.txt', 'r')
            archivo2 = open("desifrado.txt",'w')
            character = archivo.read(1)
            while(character != ''):

                if(character >= 'b' and character <='y' or character >= 'B' and character <='Y'):
                    code = chr(ord(character)-1)
                elif(character == 'a'):
                    code = 'z'
                elif(character == 'A'):
                    code = 'Z'
                else:
                    code = character

                archivo2.write(code)
                character = archivo.read(1)

            archivo.close()
            archivo2.close()
        else:
            print("File not found")
    elif(opc == 3):
        break

    elif(opc < 0 or opc > 3):
        print("Invalid option")
