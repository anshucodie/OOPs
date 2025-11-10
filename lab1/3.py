class Student:
    def __init__(self, marks1, marks2, marks3):
        self.marks1 = marks1
        self.marks2 = marks2
        self.marks3 = marks3

    def avgmarks(self):
        return ((self.marks1 + self.marks2 + self.marks3)/3)


def main():
    for i in range(2):
        marks1 = int(input("Input marks 1 : "))
        marks2 = int(input("Input marks 2 : "))
        marks3 = int(input("Input 2marks 3 : "))

        a = Student(marks1, marks2, marks3)
        print("Average marks of student ", i+1, " is ", a.avgmarks())

if __name__ == "__main__":
    main()