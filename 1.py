
from random import randint

pc_choice = randint(1,10)
play = True
while play:
    user_choice = int(input("Choose number (1-10): "))
    if user_choice == pc_choice :
        print("You win!")
        play = False
    elif user_choice > pc_choice:
        print("Too high!")
    elif user_choice < pc_choice:
        print("Too law!")