from cs50 import get_int

# TODO
if __name__ == "__main__":
    height = 0

    while True:
        height = get_int("Enter the height: ")

        for i in range(height):
            print(" " * (height - 1 - i), end="")

            print("#" * (1 + i), end="")

            print("  ", end="")

            print("#" * (1 + i), end="")

            print()

        if height >= 1 and height <= 8:
            break
