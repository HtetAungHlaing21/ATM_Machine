#ATM

import random
balance=random.randint(100,100000)
initialBalance=balance
pin=101010
history=[]

# User Defined Functions

def checkPin():
    chance=3
    check=False
    while (chance>0):
        typePin=int(input("Enter the pin number: "))
        if typePin==pin:
            check=True
            break
        else:
            chance-=1
            print("Wrong Pin! Try agiain, You have", chance, "chances left.")
        if chance==0:
            print("Your card has been temporarily blocked! Please visit the nearest branch!")
    return check

def showMenu():
    action=int(input("Type '1' to show your balance. Type '2' to withdraw money. Type '3' to deposit money. Type '4' to show recent transcations. Type '5' to change your pin. Type '6' to quit. Your action: "))
    return action

def showBalance(balance):
    print("Your balance is", balance, ".")

def greet():
    print("Thank you for using ATM machine. Have a nice day!")

# Main Function

print("Welcome to the Bank. How can I help you?")
check=checkPin()
if check==True:
    while True:
        action=showMenu()
        if action==1:
            showBalance(balance)
        elif action==2:
            showBalance(balance)
            while True:
                withdraw=int(input("Enter the amount of money to withdraw: "))
                if withdraw>balance:
                    print("Sorry! Not enough money! Please type again.")
                else:
                    break
            balance-=withdraw
            print("Cash successfully withdrawn! You have", balance, "left in your account.")
            transcation="Withdrawn "+str(withdraw)
            history.append(transcation)
        elif action==3:
            showBalance(balance)
            deposit=int(input("Enter the amount of money to deposit: "))
            balance+=deposit
            print("Cash successfully deposited! You have", balance, "left in your account.")
            transcation="Deposited "+str(deposit)
            history.append(transcation)
        elif action==4:
            update="Your current balance = "+str(balance)
            history.append(update)
            initial="Your initial balance = "+str(initialBalance)
            history.insert(0, initial)
            print("Your transaction history:")
            print(history)
        elif action==5:
            pin=int(input("Enter a new pin number: "))
            while True:
                pin2=int(input("Enter a new pin number again: "))
                if pin==pin2:
                    print("Pin changed successfully!")
                    break
                else:
                    print("Please type exactly the same password.")
        elif action==6:
            greet()
            break
        else:
            print("Invalid Syntax! Please try again!")
else:
    greet()
