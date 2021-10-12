class Cola:
    def __init__(self):
        self.items = []

    def estaVacia(self):
        return self.items == []

    def frente(self):
        if (self.estaVacia()):
            print("La cola esta vacia")
        else:
            return self.items[0]

    def last(self):
        return self.items[self.tamano()-1]

    def agregar(self, item):
        self.items.append(item)

    def avanzar(self):
        try:
            return self.items.pop(0)
        except:
            raise ValueError("La cola esta vacia")

    def tamano(self):
        return len(self.items)

if __name__ == '__main__':
    cola = Cola()
    cola.agregar(5)
    cola.agregar(10)
    cola.agregar(15)
    print(cola.frente())
    print(cola.last())
