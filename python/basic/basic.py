#Basic output
print "Hello World"

#Basic use of function
def HelloWorld():
    """Function that prints line of text"""
    print "Hello World 2"
    pass

HelloWorld()

#Basic class
class Printer(object):
    """Print line of text"""
    def __init__(self, text):
        print "Initializing " + self.__class__.__name__
        self.text = text

    #Class method
    def Print(self):
        """Printing stored string"""
        print self.text
    
    @staticmethod
    def PrintText(text):
        """Printing text"""
        print text
        
    def __del__(self):
        print "Deleting " + self.__class__.__name__

#Creating object
printer = Printer("Hello World 3")

#Use class method
printer.Print()

#Use static method
printer.PrintText("Hello World 4")

#Class inheritance
class BigPrinter(Printer):
    
    def PrintLine(self):
        """Print line of dashes"""
        print "----------"
    pass

bigPrinter = BigPrinter("Hello World 5")
bigPrinter.Print()
bigPrinter.PrintLine()