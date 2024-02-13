# open and read the file to a string
with open("input.in", "r") as file:
    lines = file.read()

class Node:
    def __init__(self, data, next=None):
        self.data = data
        self.next = next

def find_all_presents_elf(count):
    head = Node(1)
    current = head
    for i in range(2, count+1):
        current.next = Node(i)
        current = current.next
    current.next = head

    while head.next != head:
        head.next = head.next.next
        head = head.next

    return head.data

print(find_all_presents_elf(int(lines)))
