Problem set https://cs50.harvard.edu/x/2020/psets/6/credit/


from cs50 import get_int
from sys import exit
import sys
#get input from user
number = get_int("Number: ")

#calculate number of digits
nd = len(str(number))
#nd is correct

#initialise number array
num_array = []

iscard = 1

#populate number array
for i in range(1, nd + 1):
    nn = int(number /(10 ** (nd - i)))
    num_array.append(nn)
    number -= (nn * (10 ** (nd - i)))
#num array successfully populated

#luhn algorithm function
def luhn(array):
    #populate array with every other number multiplied by 2, separated out into individual digits
    step1 = []
    j = len(array) - 2 #j = 13
    while True:
        tmp = array[j]*2
        nd2 = len(str(tmp))
        for i in range(1, nd2 + 1):
            new = int(tmp /(10 ** (nd2 - i)))
            step1.append(new)
            tmp -= (new * (10 ** (nd2 - i)))
        j = j - 2
        if j < 0:
            break

    #add numbers in step 1 array together
    step2 = 0
    for i in range(len(step1)):
        step2 += step1[i]

    #add the digits from the input number that werent multiplied by two
    step3 = 0
    k = len(array) - 1
    while True:
        step3 += array[k]
        k = k - 2
        if k < 0:
            break

    #add step 2 to step 3
    step4 = step2 + step3

    #check if number ends in 0
    step5 = step4 % 10
    if int(step5) == 0:
        return True
    else:
        sys.exit("INVALID")

if (nd == 13 or nd > 14 and nd < 17):

    if luhn(num_array) == True:
        if num_array[0] == 3 and (num_array[1] == 4 or num_array[1] == 7) and nd == 15:
            print("AMEX")
        if num_array[0] == 5 and (num_array[1] == 1 or num_array[1] == 2 or num_array[1] == 3 or num_array[1] == 4 or num_array[1] == 5) and nd == 16:
            print("MASTERCARD")
        if num_array[0] == 4 and (nd == 13 or nd == 16):
            print("VISA")
elif (nd < 13) or (nd > 13 and nd < 15) or (nd > 16):
    sys.exit("INVALID")


