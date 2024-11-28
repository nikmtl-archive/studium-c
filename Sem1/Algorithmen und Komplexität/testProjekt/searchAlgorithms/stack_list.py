class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Stack:
    def __init__(self):
        self.top = None

    def push(self, data):
        new_node = Node(data)
        new_node.next = self.top
        self.top = new_node

    def pop(self):
        if self.top is None:
            return None
        popped = self.top
        self.top = self.top.next
        return popped.data

    def peek(self):
        if self.top is None:
            return None
        return self.top.data

    def is_empty(self):
        return self.top is None

# Test
stack = Stack()
stack.push(1)
stack.push(2)
stack.push(3)
print(stack.pop()) # 3
print(stack.peek()) # 2
print(stack.is_empty()) # False
print(stack.pop()) # 2
print(stack.pop()) # 1
print(stack.is_empty()) # True
print(stack.pop()) # None
