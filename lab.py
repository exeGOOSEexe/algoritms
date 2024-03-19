user_input1 = str(input("Enter a firth string: "))
user_input2 = str(input("Enter a second string: "))
def lab(user_input1, user_input2):
    user_list = [i for i in user_input1]
    user_list.sort()
    user_list2 = [j for j in user_input2]
    user_list2.sort()
    for i in user_list:
        if i not in user_list2:
            return print(i)
    for j in user_list2:
        if j not in user_list:
            return print(j)
    return print("No missing letter")
lab(user_input1, user_input2)