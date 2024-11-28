class ArrayStack:
    def __init__(self, size):
        self.stack = [None] * size
        self.top = -1

    def push(self, data):
        self.top += 1
        self.stack[self.top]= data

    def pop(self):
        if len(self.stack) == 0:
            return None
        data = self.stack[self.top]
        self.stack[self.top] = None
        self.top -= 1
        return data

    def peek(self):
        if len(self.stack) == 0:
            return None
        return self.stack[self.top]

    def is_empty(self):
        return self.top == -1

# Test
stack = ArrayStack(3)
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