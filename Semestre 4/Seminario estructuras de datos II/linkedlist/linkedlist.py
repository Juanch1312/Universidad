class node:
    def __init__(self, data = None, next = None):
        self.data = data
        self.next = next

class linked_list:
    def __init__(self):
        self.head = None

    def add_at_front(self, data):
        self.head = node(data = data, next= self.head)

    def is_empty(self):
        return self.head == None

    def add_at_end(self,data):
        if not self.head:
            self.head = node(data = data)
            return
        curr = self.head
        while curr.next:
            curr = curr.next
        curr.next = node(data= data)

    def delete_node(self, key):
        curr = self.head
        prev = None

        while curr and curr.data != key:
            prev = curr
            curr = curr.next
        if prev == None:
            self.head = curr.next
        elif curr:
            prev.next = curr.next
            curr.next = None


    def get_last_node(self):
        temp = self.head
        while(temp.next is not None):
            temp = temp.next
        return  temp.data

    def print_list(self):
        node = self.head
        while node is not None:
            print(node.data, end = " => ")
            node = node.next

if __name__ == '__main__':
    linked = linked_list()
    linked.add_at_front(5)
    linked.add_at_end(10)
    linked.add_at_end(20)
    linked.print_list()
    linked.delete_node(5)
    print("\n")
    linked.print_list()
