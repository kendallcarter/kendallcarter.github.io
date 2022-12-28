#Kendall Carter IT 327 11AM section Program 1
import re
import sys
num2words = {'1': 'One', '2': 'Two', '3': 'Three', '4': 'Four', '5': 'Five', \
             '6': 'Six', '7': 'Seven', '8': 'Eight', '9': 'Nine', '10': 'Ten', \
             '0': 'Zero'}

word2nums = {'1st': 'first', '2nd': 'second', '3rd': 'Third', '4th': 'fourth', '5th': 'fifth', \
             '6th': 'sixth', '7th': 'seventh', '8th': 'eigth', '9th': 'ninth', '10th': 'tenth'}

def my_replace(m):
    a = m.group()
    return num2words[a]

subject = "here is a test with a mf number like "
print(subject)
#re.search(r'\d\d*/gm', subject)
list = re.findall('\d', subject)
print(re.sub('\d',my_replace, subject))

if 23 in num2words:
    print("you son of a bitch")
else:
    print("glorious bastard")


#print(num2words[re.findall('\d', subject)])

#print(word2nums[re.match(r'\d', subject)])