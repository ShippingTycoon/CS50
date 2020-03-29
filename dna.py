from dataclasses import dataclass
import sys
from sys import argv, exit
import os
import csv

if len(argv) != 3:
    print("Missing command-line argument")
    exit(1)

#define structure used to store csv database
class person():
    def __init__(self):
        self.name: str
        self.AGATC: int
        self.TTTTTTCT: int
        self.AATG: int
        self.TCTAG: int
        self.GATA: int
        self.TATC: int
        self.GAAA: int
        self.TCTG: int

#define array to staor individual people's info from database
people = []

#open files
table = open(argv[1], 'r')

txt = open(argv[2], 'r')

#read from csv file into memory
with table:

    reader = csv.DictReader(table)

    for row in reader:
        tmp = person()
        tmp.name = row['name']
        tmp.AGATC = int(row['AGATC'])
        tmp.TTTTTTCT = int(row['TTTTTTCT'])
        tmp.AATG = int(row['AATG'])
        tmp.TCTAG = int(row['TCTAG'])
        tmp.GATA = int(row['GATA'])
        tmp.TATC = int(row['TATC'])
        tmp.GAAA = int(row['GAAA'])
        tmp.TCTG = int(row['TCTG'])
        people.append(tmp)

#read dna file into vaiable
text = txt.read()

#make function to search for how many repeating occurances of that string there are in the text
def max_consecutive(string):
    counter = 0
    maximum = 0
    length = len(string)
    for i in range(len(text)):
        if text[i:(i + length)] == string:
            j = i
            while True:
                j += length
                counter += 1
                hi = text[j:(j + length)]
                if hi != string:
                    maximum = counter
                    counter = 0
                    break
    return maximum

sample = person
sample.name = "?"
sample.AGATC = max_consecutive("AGATC")
sample.TTTTTTCT = max_consecutive("TTTTTTCT")
sample.AATG = max_consecutive("AATG")
sample.TCTAG = max_consecutive("TCTAG")
sample.GATA = max_consecutive("GATA")
sample.TATC = max_consecutive("TATC")
sample.GAAA = max_consecutive("GAAA")
sample.TCTG = max_consecutive("TCTG")
print(sample.AGATC)
print(sample.TTTTTTCT)
print(sample.AATG)
print(sample.TCTAG)
print(sample.GATA)
print(sample.TATC)
print(sample.GAAA)
print(sample.TCTG)
