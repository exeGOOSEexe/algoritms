my_list = [1, 2, 3, 4, 5, {23}]
check = set()
for i in my_list:
    try:
        check.add(i)
    except TypeError:
        continue

def list_to_set(a):
    print(a)

list_to_set(check)


class SET:
    def __init__(self, check_list):
        self.check_list = check_list
        self.list_to_set = set()
    def add(self):
        for i in self.check_list:
            try:
                self.list_to_set.add(i)
            except TypeError:
                continue
def  print_set(a):
    print(a)
if __name__ == "__main__":
    check_list = [1, "testd", 4.42, [5, 5,343], {23 : "test"}]
    a = (SET(check_list))
    a.add()
    print_set(a.list_to_set)
// Неправильно