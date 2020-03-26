from cs50 import get_int
from sys import exit

while True:
    height = get_int("Height: ")

    if height > 0 and height < 9:
        break

def main():

    def space(n):
        for i in range(n):
            print(" ", end="")

    def block(n):
        for i in range(n):
            print("#", end="")

    for i in range(height):
        space(height - i - 1)
        block(i + 1)
        print("  ", end="")
        block(i + 1)
        print("")

main()
