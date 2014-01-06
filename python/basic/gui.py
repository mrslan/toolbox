from Tkinter import *
import Tkinter

class MousePointer():
    def __init__(self):
        self.x = 0
        self.y = 0
        self.width = 30
        self.height = 30
        
    def SetPos(self, x, y):
        self.x = x
        self.y = y
    
    def Paint(self, canvas):
        ':type canvas: Canvas'
        canvas.create_line(self.x, self.y - self.height/2,
                           self.x, self.y + self.width/2)
        canvas.create_line(self.x - self.width/2, self.y,
                           self.x + self.width/2, self.y)
        
class BasicFrame(Frame):
    
    def SetMousePointer(self, pointer):
        print "SetMousePointer"
        self.mousePointer = pointer
    
    def MouseClickCallback(self, event):
        print "Mouse click: ", event.x, "x", event.y

    def MouseMoveCallback(self, event):
        """Mouse motion tracking"""
        print "Mouse move: ", event.x, "x", event.y
        if self.mousePointer is not None:
            self.mousePointer.SetPos(event.x, event.y)
        
        self.Paint()
        
    def Paint(self):
        self.canvas.delete("all")
        self.mousePointer.Paint(self.canvas)
        
    def __init__(self):
        self.mousePointer = None
        self.frame = Frame(root, width = 500, height = 500)
        self.frame.pack()
        
        self.canvas = Canvas(self.frame)
        self.canvas.bind("<Button-1>", self.MouseClickCallback);
        self.canvas.bind("<Motion>", self.MouseMoveCallback)
        self.canvas.pack(fill = BOTH, expand = 1)

root = Tkinter.Tk()
root.attributes('-topmost', True)
basic_frame = BasicFrame()
pointer = MousePointer()
basic_frame.SetMousePointer(pointer)
root.mainloop()