"""
    Trenton D Scott
    LAB 12 | 11/25/2014
    TRACE: Scott031
"""
from node import TwoWayNode

class DoublyLinkedStructure():
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0

    def append(self, value):
        newNode = TwoWayNode(value)
        if self.size == 0:
            self.tail = newNode
            self.head = newNode
        else:
            self.tail.next = newNode
            newNode.previous = self.tail
            self.tail = self.tail.next
        self.size += 1

    def addFirst(self, value):
        if not self.size:
            self.head = TwoWayNode(value, self.head)
        else:
            self.head = TwoWayNode(value, None, self.head)
        self.size += 1

    def __len__(self):
        return self.size

    def __str__(self):
        nodeStr = ""
        probe = self.head
        while probe != None:
            nodeStr += (str(probe.data)+" ")
            probe = probe.next
        return nodeStr


def main():
    d = DoublyLinkedStructure()
    for value in range(1, 6):
        d.append(value)

    for value in ["a", "b", "c"]:
        d.addFirst(value)

    print(d)
    print("Length of d is", len(d))  

main()













