import random
class Stack:
    def __init__(self):
        self.stack = []
        self.min = None

    def push(self, item):
        self.stack.append(item)
        if len(self.stack) == 1 or item < self.min:
            self.min = item

    def pop(self):
        if len(self.stack) == 0:
            return None
        removed = self.stack.pop()
        if len(self.stack) == 0:
            self.min = None
        elif removed == self.min:
            self.min = self.stack[0]
            for value in self.stack:
                if value < self.min:
                    self.min =value
        return removed

        
if __name__ == "__main__":
    st = Stack()
    print("Enter the number of elements to be pushed into the stack:")
    user_input = int(input())
    for i in range(user_input):
        st.push(random.randint(10, 50))
    print(st.stack)
    print(st.min)
