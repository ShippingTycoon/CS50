https://cs50.harvard.edu/x/2020/psets/7/houses/


from cs50 import SQL
from sys import argv,exit
import csv

# sets up table to write to
db = SQL("sqlite:///students.db")

# check for correct number of command line arguments
if len(argv) != 2:
    print("Usage: python import.py filename.csv")
    exit(1)

#open file
file = open(argv[1], "r")

with file:
    # get dictreader function
    reader = csv.DictReader(file)

    # iterate over each row in csv file and write to table in students.db
    for row in reader:
        #split out the names into first, middle, last
        fullname = row["name"]
        names = fullname.split()
        first_name = names[0]
        if len(names) > 2:
            middle_name = names[1]
            last_name = names[2]
        elif len(names) == 2:
            middle_name = None
            last_name = names[1]
        # assign values to house and birth
        house = row["house"]
        birth = row["birth"]
        # write to table
        db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", first_name, middle_name, last_name, house, birth)
