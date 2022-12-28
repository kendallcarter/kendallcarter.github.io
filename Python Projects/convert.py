#Kendall Carter IT 327 11AM section Program 1 Convert Program 

#This program converts all numbers and ordinals into words and writes the converted text file to a file

import re
import sys

#Used for converting numbers to words and ordinals to words
num2words = {'1': 'one', '2': 'two', '3': 'three', '4': 'four', '5': 'five', \
             '6': 'six', '7': 'seven', '8': 'eight', '9': 'nine', '10': 'ten', \
             '0': 'zero'}

ordinal2words = {'1st': 'first', '2nd': 'second', '3rd': 'Third', '4th': 'fourth', '5th': 'fifth', \
             '6th': 'sixth', '7th': 'seventh', '8th': 'eigth', '9th': 'ninth', '10th': 'tenth'}

def num_replace(m):
    """This function replaces the given number or ordinal with the word conversion"""
    val = m.group()
    word = ''
    if val in num2words:
        word = num2words[val]
    if val in ordinal2words:
        word = ordinal2words[val]
    
    return word
    
#Opens files    
file = open(sys.argv[1],'r')
file2 = open(sys.argv[2],"w")

with open(sys.argv[1]) as data:
    for line in data:
        file2.writelines(re.sub('(?:((?:\dst|\drd|\dnd|\dth)))|(?<!\S)\d(?=\D)',num_replace, line))

#Closes files
file2.close()    
file.close()