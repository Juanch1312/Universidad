import os

class node:
    def __init__(self, data):
        self.left = None
        self.right = None
        self.data = data


class tree:

    def __init__(self):
        self.root = None

    def altura(self):
        return self.tamano

    def insert(self, n, data):
        if n == None:
            n = node(data)
        else:
            d = n.data
            if data < d:
                n.left = self.insert(n.left, data)
            else:
                n.right = self.insert(n.right, data)
        return n

    def inorder(self, d):
        if d == None:
            return None
        else:
            self.inorder(d.left)
            print(d.data)
            self.inorder(d.right)

    def preorder(self, d):
        if d == None:
            return None
        else:
            print(d.data)
            self.preorder(d.left)
            self.preorder(d.right)

    def posorder(self, d):
        if d == None:
            return None
        else:
            self.posorder(d.left)
            self.posorder(d.right)
            print(d.data)

    def search(self, d, data):
        if d == None: return d
        elif (data == d.data): return d
        else:
            if(data < d.data):
                return self.search(d.left, data)
            else:
                return self.search(d.right, data)

    def breadthfirsttraversal(self, root, data):
        queue = []
        self.enqueue(queue, root)
        while self.empty(queue) is not True:
            t = queue.pop(0)
            if t == data:
                return True
            self.enqueue(queue, self.left(t))
            self.enqueue(queue, self.right(t))
        return False

    def enqueue(self, queue, n):
        if n is not None:
            queue.append(n.data)

    def empty(self, q):
        return q == []

    def left(self, data):
        n = self.search(self.root,data)
        return n.left

    def right(self, data):
        n = self.search(self.root , data)
        return n.right

trees = tree()
trees.root = trees.insert(trees.root, 20)
trees.root = trees.insert(trees.root, 30)
trees.root = trees.insert(trees.root, 5)
trees.root = trees.insert(trees.root, 25)
trees.root = trees.insert(trees.root, 4)

n = trees.search(trees.root ,30)
if n == None:
    print("No encontrado")
else:
    print("Encontrado")

print('\n')
print("Inorder")
trees.inorder(trees.root)
print('\n')
print("Posorder")
trees.posorder(trees.root)
print('\n')
print("Preorder")
trees.preorder(trees.root)
print('\n')

if trees.breadthfirsttraversal(trees.root, 30):
    print("Encontrado")
else:
    print("No encontrado")
