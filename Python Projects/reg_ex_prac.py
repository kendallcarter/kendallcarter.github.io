#Kendall Carter IT 327 11AM section
import re
def check_phone_number(num):    
    """The function will check if the line is a phone number"""
    
    return re.match(r'^((?:(\(?\d{3}\))\s)?)(\d{3}-\d{4})$', num)
    
    
file = open('data.txt', "r")
file2 = open('phones.txt',"w")

with open('data.txt') as data:
    for line in data:
        if check_phone_number(line):
            file2.write(line)

file2.close()    
file.close()