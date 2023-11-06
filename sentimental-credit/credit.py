from cs50 import get_int

if __name__ == "__main__":
    firstDigit = 0
    secondDigit = 0
    digits = 0

    doubleOdds = 0
    evens = 0

    valid = False

    cardNo = get_int("Enter the card number: ")

    while cardNo > 0:
        secondDigit = firstDigit
        firstDigit = cardNo % 10

        if digits % 2 == 0:
            evens += firstDigit
        else:
            multiple = 2 * firstDigit
            doubleOdds += (multiple // 10) + (multiple % 10)

        cardNo = cardNo // 10
        digits += 1

    if (evens + doubleOdds) % 10 == 0:
        valid = True

    firstTwo = (firstDigit * 10) + secondDigit

    if valid:
        if firstDigit == 4 and digits >= 13 and digits <= 16:
            print("VISA\n")
        elif firstTwo >= 51 and firstTwo <= 55 and digits == 16:
            print("MASTERCARD\n")
        elif firstTwo == 34 or firstTwo == 37 and digits == 15:
            print("AMEX\n")
        else:
            print("INVALID\n")
    else:
        print("INVALID\n")
