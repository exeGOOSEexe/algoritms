user= ["user1", 15, ["user3"], 30, {"user5"}, ("user6"), {"user7": 1}, "user8", "user9", "user10"]

def check(lst):
    info = set()
    for item in lst:
        try:
            info.add(item)
        except TypeError:
            continue
        list_to_set(info)

def list_to_set(lst):
    print(lst)

if __name__ == '__main__':
    check(user)