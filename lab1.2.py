def lab(user_input1, user_input2):
    user_list = [i for i in user_input1]
    user_list2 = [j for j in user_input2]
    for i in user_list:
        counter = 0
        for j in user_list2:
            if i == j:
                counter += 1
        if counter == 0:
            return i
    return " "

if __name__ == "__main__":
    user_input1 = input("Enter a firth string: ")
    user_input2 = input("Enter a second string: ")

    c = lab(user_input1, user_input2)
    print(c)
