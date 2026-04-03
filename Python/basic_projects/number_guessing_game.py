from random import randint

random_num = randint(0, 100)
print("Secret number: " + str(random_num))

print()
print("Enter your guessing.")

while True:
    number = int(input("Enter your nummber: "))

    if number > random_num:
        print("Too large.")
    elif number < random_num:
        print("Too small.")
    else:
        print("You win")
        break