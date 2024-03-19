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