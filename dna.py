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

text = txt.read()

print(text)
