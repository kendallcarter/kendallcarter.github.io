#Kendall Carter IT 327 11AM section
def keep_multiples(myList, num):    
    """The function will return a list containing the items from the original list that are multiples of the second parameter"""
    
    return [i for i in myList if i% num ==0]
