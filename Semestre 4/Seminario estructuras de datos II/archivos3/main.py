archivo1 = open('archivo.txt','a')
texto = input("Dame el texto prro: ")

archivo1.write(texto +'\n')
archivo1.close()