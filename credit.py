from cs50 import get_int
from sys import exit
#get input from user
number = get_int("Number: ")

#calculate number of digits
nd = len(str(number))

#initialise number array
num_array = []

iscard = 1

#populate number array
for i in range(1, nd):
    num_array.append(number %(10 ** (nd + 1 - i)))

def luhn(array):
    step1 = []
    for i in range(len(array)):
        tmp = array[i]*2
        nd2 = len(str(tmp))
        for i in range(1, nd2):
            step1.append(tmp %(10 ** (nd2 + 1 - i)))
        i += 1
    step2 = 0
    for i in range(len(step1)):
        step2 += step1[i]
    step3 = 0
    for i in range(1, len(array)):
        step3 += array[i]
        i += 1
    step4 = step2 + step3
    step5 = step4 % 10
    if step5 % 10 == 0:
        iscard = 0

if (nd == 13 or nd > 14 and nd < 17):
    luhn(num_array)
if iscard == 0:
    if num_array[0] == 3 and num_array[1] == (4, 7) and nd == 15:
        print("AMEX")
    if num_array[0] == 5 and num_array[1] == (1, 2, 3, 4, 5) and nd == 16:
        print("MASTERCARD")
    if num_array[0] == 4 and nd == (13, 16):
        print("VISA")

if (nd < 13) or (nd > 13 and nd < 15) or (nd > 16):
    exit



