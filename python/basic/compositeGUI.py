from Tkinter import *
import Tkinter
import Image
import ImageTk
import threading

class GUIObject():
    def __init__(self, x, y, width, height):
        self.x = x
        self.y = y
        self.width = width
        self.height = height
        
    def SetPos(self, x, y):
        self.x = x
        self.y = y
    
    def Paint(self, canvas):
        ':type canvas: Canvas'
        pass

    def OnClickAction(self, event):
        pass
    
    
    def OnClick(self, event):
        x = event.x
        y = event.y
        if x > self.x and x < self.x + self.width and \
          y > self.y and y < self.y + self.height:
            self.OnClickAction(event)
    
class MousePointer(GUIObject):
    '''Mouse pointer class'''
    def __init__(self):
        GUIObject.__init__(self, 0, 0, 30, 30)

    def Paint(self, canvas):
        ':type canvas: Canvas'
        canvas.create_line(self.x, self.y - self.height/2,
                           self.x, self.y + self.width/2)
        canvas.create_line(self.x - self.width/2, self.y,
                           self.x + self.width/2, self.y)
        GUIObject.Paint(self, canvas)
        
    def OnClick(self, event):
        print "MousePointer:", event.x, "x", event.y
        GUIObject.OnClick(self, event)
        
class GraphicsButton(GUIObject):
    def __init__(self, x, y, name):
        GUIObject.__init__(self, x, y, 100, 20)
        self.name = name
        
    def Paint(self, canvas):
        ':type canvas: Canvas'
        canvas.create_rectangle(self.x, self.y,
                                 self.x + self.width, self.y + self.height)
        text_cfg = canvas.create_text(self.x, self.y, anchor="nw")
        canvas.insert(text_cfg, 12, self.name)
        GUIObject.Paint(self, canvas)
    
    def OnClickAction(self, event):
        print self.name, ":OnClick"

class Picture(GUIObject):
    '''Display jpg image'''
    def __init__(self, x, y, path):
        self.jpg = Image.open(path)
        width = 400
        height = 300
        compSize = width, height
        self.jpg.thumbnail(compSize, Image.ANTIALIAS)
        self.image = ImageTk.PhotoImage(self.jpg)

        print "jpg:", width, "x", height
        GUIObject.__init__(self, x, y, width, height)
        
    def Paint(self, canvas):
        ':type canvas: Canvas'
        canvas.create_rectangle(self.x, self.y,
                                self.x + self.width, self.y + self.height)
        canvas.create_image(self.x + self.width/2,
                            self.y + self.height/2,
                            image = self.image)

class Graph(GUIObject):
    '''Graph'''
    def __init__(self, x, y, width, height):
        self.values = [0] * width
        GUIObject.__init__(self, x, y, width, height)

    def Add(self, value):
        '''Add new point'''
        self.values.append(value)
    
    def Paint(self, canvas):
        ':type canvas: Canvas'
        canvas.create_rectangle(self.x, self.y,
                                self.x + self.width, self.y + self.height)
        last_index = len(self.values) - 1
        for offset in range(0, self.width):
            prvValue = self.values[last_index - offset - 1]
            curValue = self.values[last_index - offset]
            canvas.create_line(self.x + offset, self.y + self.height - prvValue,
                               self.x + offset + 1, self.y + self.height - curValue)
            
    def OnClick(self, event):
        self.values.append(event.y)
        GUIObject.OnClick(self, event)

class XLSReader():
    '''Reads content of a file'''
    def __init__(self, file_name):
        self.file = open(file_name, 'r')
        self.data = self.file.read().split('\n')

    def Read(self, line):
        return self.data[line]

class CheckBox(GUIObject):
    """CheckBox"""
    def __init__(self, x, y, name):
        self.name = name
        self.selected = FALSE
        GUIObject.__init__(self, x, y, 10, 10)

    def Paint(self, canvas):
        ':type canvas: Canvas'
        canvas.create_rectangle(self.x, self.y,
                self.x + self.width, self.y + self.height)
        
        if self.selected:
            canvas.create_rectangle(self.x + 2, self.y + 2,
                                    self.x + self.width - 2, self.y + self.height - 2)

        text_cfg = canvas.create_text(self.x + self.width, self.y - 2, anchor="nw")
        canvas.insert(text_cfg, 12, self.name)
        GUIObject.Paint(self, canvas)

    def OnClickAction(self, event):
        self.selected = not self.selected
        GUIObject.OnClickAction(self, event)

class CheckBoxList(GUIObject):
    """List of check boxes"""
    def __init__(self, x, y, width, height):
        self.checkboxes = []
        GUIObject.__init__(self, x, y, width, height)

    def AddCheckBox(self, checkbox):
        ':type checkbox: CheckBox'
        checkbox.x = self.x + checkbox.x
        checkbox.y = self.y + checkbox.y
        self.checkboxes.append(checkbox)

    def Paint(self, canvas):
        canvas.create_rectangle(self.x, self.y,
                        self.x + self.width, self.y + self.height)

        for checkbox in self.checkboxes:
            checkbox.Paint(canvas)

        GUIObject.Paint(self, canvas)

    def OnClickAction(self, event):
        for checkbox in self.checkboxes:
            checkbox.OnClick(event)
        GUIObject.OnClickAction(self, event)

class BasicFrame(Frame):
    '''
    Composite frame to render multi-component GUI
    '''
    
    def SetMousePointer(self, pointer):
        print "SetMousePointer"
        self.mousePointer = pointer
        self.gfxObjects.append(self.mousePointer)
    
    def MouseClickCallback(self, event):
        for obj in self.gfxObjects:
            obj.OnClick(event)
        self.Paint()

    def MouseMoveCallback(self, event):
        """Mouse motion tracking"""
        #TODO fix excessive update issue
#         if self.mousePointer is not None:
#             self.mousePointer.SetPos(event.x, event.y)
#         self.Paint()
        
    def Paint(self):
        self.canvas.delete("all")
    
        for obj in self.gfxObjects:
            obj.Paint(self.canvas)
        
    def __init__(self):
        self.mousePointer = None
        self.frame = Frame(root)
        self.frame.pack()
        
        self.canvas = Canvas(self.frame, width = 800, height = 600)
        self.canvas.bind("<Button-1>", self.MouseClickCallback);
        self.canvas.bind("<Motion>", self.MouseMoveCallback)
        self.canvas.pack(fill = BOTH, expand = 1)
        
        self.gfxObjects = []
        
        self.gfxObjects.append(GraphicsButton(10, 10, "Button1"))
        self.gfxObjects.append(GraphicsButton(10, 40, "Button2"))
        self.gfxObjects.append(GraphicsButton(10, 70, "Button3"))
        self.gfxObjects.append(Picture(400, 10, "image.jpg"))
        self.gfxObjects.append(Graph(150, 350, 650, 250))
        check_box_list = CheckBoxList(10, 350, 130, 250)
        self.gfxObjects.append(check_box_list)
        
        #Initialize logs
        xlsreader = XLSReader("text.xls")
        
        tags = xlsreader.Read(94).split('\t')
        for logName in tags:
            check_box_list.AddCheckBox(CheckBox(10, 10, logName))
        self.Paint()

root = Tkinter.Tk()
root.attributes('-topmost', True)
basic_frame = BasicFrame()
pointer = MousePointer()
basic_frame.SetMousePointer(pointer)
root.mainloop()