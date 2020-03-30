from dataclasses import dataclass
import sys
from sys import argv, exit
import os
import csv


def main():

    if len(argv) != 3:
        print("Usage: python dna.py filename.csv filename.txt")
        exit(1)

    #define structure used to store csv database
    #class person():
        #def __init__(self):
           # self.name: str
            #self.AGATC: int
            #self.TTTTTTCT: int
            #self.AATG: int
            #self.TCTAG: int
            #self.GATA: int
            #self.TATC: int
            #self.GAAA: int
            #self.TCTG: int

    #define array to staor individual people's info from database
    people = []

    #open files
    table = open(argv[1], 'r')

    txt = open(argv[2], 'r')

    #read from csv file into memory, populating an array of persons
    with table:

        reader = csv.DictReader(table)
        people = (reader.fieldnames)

    ppl_quantity = len(people)
    matches = []

#            tmp = person()
 #           tmp.name = row['name']
  #          tmp.AGATC = int(row['AGATC'])
   #         tmp.TTTTTTCT = int(row['TTTTTTCT'])
    #        tmp.AATG = int(row['AATG'])
     #       tmp.TCTAG = int(row['TCTAG'])
      #      tmp.GATA = int(row['GATA'])
       #     tmp.TATC = int(row['TATC'])
        #    tmp.GAAA = int(row['GAAA'])
         #   tmp.TCTG = int(row['TCTG'])
          #  people.append(tmp)

    #read dna file into vaiable
    text = txt.read()
    #make function to search for how many repeating occurances of that string there are in the text (works now!)
    def max_consecutive(string):
        maximum = 0
        length = len(string)
        for j in range(len(text)):
            counter = 0
            while text[j:(j + length)] == string:
                counter+=1
                j = j + length
                if maximum < counter:
                    maximum = counter
        return maximum

    for i in range(1, ppl_quantity):
        matches[people[i]] = max_consecutive(people[i])



    #create person structure by placing the names of str strings into max_consecutive function
#    sample = person
 #   sample.name = "?"
  #  sample.AGATC = max_consecutive("AGATC")
   # sample.TTTTTTCT = max_consecutive("TTTTTTCT")
    #sample.AATG = max_consecutive("AATG")
    #sample.TCTAG = max_consecutive("TCTAG")
    #sample.GATA = max_consecutive("GATA")
    #sample.TATC = max_consecutive("TATC")
    #sample.GAAA = max_consecutive("GAAA")
    #sample.TCTG = max_consecutive("TCTG")

    #compare sample person information to the information taken from CSV file to determine whether the DNA matches anyone
#    for i in range(len(people)):
 #       if sample.AGATC == people[i].AGATC and sample.TTTTTTCT == people[i].TTTTTTCT and sample.AATG == people[i].AATG and sample.TCTAG == people[i].TCTAG and sample.GATA == people[i].GATA and sample.TATC == people[i].TATC and sample.GAAA == people[i].GAAA and sample.TCTG == people[i].TCTG:
  #          print(people[i].name)
   #         exit(0)
    #print("No match")

main()
