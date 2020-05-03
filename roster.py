https://cs50.harvard.edu/x/2020/psets/7/houses/


from cs50 import SQL
from sys import argv, exit

# check correct number of args
if len(argv)!= 2:
    print("Usage: python roster.py house_name")
    exit(1)

# accessing table
db = SQL("sqlite:///students.db")
house = argv[1]

# selecting information from table in correct order into list of dicts
people = db.execute("SELECT first, middle, last, birth FROM students WHERE house = ? ORDER BY last, first;", house)

# print out names and birth years of ppl in specified house
for i in range(len(people)):
    if people[i]['middle'] != None:
        print(f"{people[i]['first']} {people[i]['middle']} {people[i]['last']}, born {people[i]['birth']}")
    else:
        print(f"{people[i]['first']} {people[i]['last']}, born {people[i]['birth']}")
