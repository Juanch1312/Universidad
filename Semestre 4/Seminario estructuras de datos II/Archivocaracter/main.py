with open("archivo2.txt", 'r') as file:
    cont = 0
    char = file.read(1)
    message = ''
    while (char != ''):
        cont += 1
        message += char
        char = file.read(1)
    print(message)
    print("\nNumero total de caracteres:",cont)
