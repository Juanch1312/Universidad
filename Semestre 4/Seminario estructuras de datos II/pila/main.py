class Pila:
    def __init__(self):
        self.items = []

    def estaVacia(self):
        return self.items == []

    def incluir(self, item):
        self.items.append(item)

    def extraer(self):
        return self.items.pop()

    def inspeccionar(self):
        return self.items[len(self.items) - 1]

    def tamano(self):
        return len(self.items)

if __name__ == '__main__':
    pila = Pila()
    pila.incluir(5)
    pila.incluir(10)
    print(pila.inspeccionar())
    pila.extraer()
    print(pila.inspeccionar())
    pila.extraer()
    print(pila.estaVacia())
