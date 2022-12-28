#Kendall Carter IT 327 11AM section Program 1

#This program opens a database table file and validates the entires
#It then returns all the problematic entries into another file

import re
import sys
import csv

#Opens Files
file = open(sys.argv[1],'r')
file2 = open(sys.argv[2],"w")
counter = 1

out= ''
out2= ': '

#Opens the file and checks each value seperated by tabs
with open(sys.argv[1]) as data:
    for line in csv.reader(data, delimiter="\t"):

        if (re.search('\d{3}\w{3}',line[0])== None):
           out = 'Error in ID field of record '
           file2.writelines(out + str(counter) + ': ' +str(line[0])+ "\n")

        if (re.search(r'(\w+ )(\w+( )?)+(,?( )(I|V|Jr\Q.\E)+)?',line[1])== None):
            out = 'Error in Name field of record '
            file2.writelines(out + str(counter) + ': ' +str(line[1])+ "\n")


        if (re.search(r'^(?:\d{5}\Z|(?:\d{5}(-\d{4})?)$)',line[2])== None):
            out = 'Error in Zip code field of record '
            file2.writelines(out + str(counter) + ': ' +str(line[2])+ "\n")


        if (re.search(r'(?:\d+)$',line[3])== None):
            out = 'Error in Number purchased field of record '
            file2.writelines(out + str(counter) + ': ' +str(line[3])+ "\n")

        if (re.search(r'/\Q$\E\d+\Q.\E\d{2}/gm',line[4])== None):
            out = 'Error in Purchase amount field of record '
            file2.writelines(out + str(counter) + ': ' +str(line[4])+ "\n")  

        counter += 1