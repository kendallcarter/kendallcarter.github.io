#Kendall Carter IT 327


class Person:
    def __init__(self, name, email):
        self.name = name
        self.email = email
    def print_directory(self):
        print(self.name + "\n" + self.email)

class Student(Person):
    def __init__(self, name, email, major, classLevel):
        Person.__init__(self, name, email)
        self.major = major
        self.classLevel = classLevel
    def print_directory(self):
        print(self.name + "\n" + self.email + "\n" + self.major + "\n" + self.classLevel)

class Employee(Person):
    def __init__(self, name, email, dept, office):
        Person.__init__(self, name, email)
        self.dept = dept
        self.office = office
    def print_directory(self):
        print(self.name + "\n" + self.email + "\n" + self.dept + "\n" + self.office)

class Faculty(Employee):
    def __init__(self, name, email, dept, office, research):
        Employee.__init__(self, name, email, dept, office)
        self.research = research
    def print_directory(self):
        print(self.name + "\n" + self.email + "\n" + self.dept + "\n" + self.office + "\n" + self.research)


bob = Person("Bob", "bob@yahoo.com")
bobette = Person("Bobette", "bobette@yahoo.com")

lisa = Student("Lisa","Lisa@yahoo.com", "Information Technology", "Sophomore")
liso = Student("Liso","Liso@yahoo.com", "Jazz Studies", "Junior")

dan = Employee("Dan", "Dan@yahoo.com", "Music", "CE 221")
danielle = Employee("Danielle", "Danielle@yahoo.com", "Music", "CE 126")

jim = Faculty("Jim", "Jim@yahoo.com", "Information Technology", "JH 205", "Machine Learning, Graphics")
jimette = Faculty("Jimette", "Jimette@yahoo.com", "Music", "CE 102", "Cello, Double Bass")

theDirectory = [bob,bobette,lisa,liso,dan,danielle,jim,jimette]

for obj in theDirectory:
    obj.print_directory()
    print("\n")
