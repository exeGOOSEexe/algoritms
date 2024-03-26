from collections import deque
def func(element1, element2, length):
    for i in range(length):
        element2.append(element1[i])
    total = (sum(element2) / length)
    print(total)
    element1.clear()
    for i in range(length):
        if element2[i] % 2 == 0:
                element2[i] = total
    for i in range(length):
         element1.append(element2[i])
    print(element1)
if __name__ == '__main__':
    base = deque([0.3, 55.3, 23.67, 94.1, 32.0, 12.3, 45.6, 78.9, 23.4, 56.7])
    sets = []
    length = len(base)
    func(base, sets, length)
