from cs50 import get_string
import string

if __name__ == "__main__":
    input = get_string("Enter the string: ")

    letters = 0
    words = 0
    sentences = 0

    for i in range(len(input)):
        if input[i].isalpha():
            letters += 1
        elif input[i].isspace():
            words += 1
        elif input[i] == "." or input[i] == "?" or input[i] == "!":
            sentences += 1

    L = (letters / (words + 1)) * 100
    S = (sentences / (words + 1)) * 100

    grade = 0.0588 * L - 0.296 * S - 15.8
    grade = round(grade)

    if grade > 16:
        print("Grade 16+")
    elif grade < 1:
        print("Before Grade 1")
    else:
        print("Grade", grade)
