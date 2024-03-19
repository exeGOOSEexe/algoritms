my_list = (5.5, 6.5, 7.5, 8.1, 9.3, 10.33)

def lab(my_lists):
    check = float(0)
    for i in my_lists:
        check += i
        return check
def lab2(check):
    check = lab(my_list)
    a = len(my_list)
    b = check / a
    print("{:.2f}".format(b))

if __name__ == "__main__":
    lab2(my_list)
    lab(my_list)
# 2 задание 3 лабы