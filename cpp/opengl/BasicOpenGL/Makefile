INCLUDES = -I/opt/local/include


CXXFLAGS =	$(INCLUDES) -O2 -g -Wall -fmessage-length=0

OBJS = main.o jpeg.o

LIBPATH = -L"/System/Library/Frameworks/OpenGL.framework/Libraries" -L"/opt/local/lib/"

FRAMEWORK = -framework GLUT
FRAMEWORK += -framework OpenGL

TARGET = basicGL

LIB = -ljpeg

$(TARGET):	$(OBJS)
	$(CXX) $(FRAMEWORK) -o $(TARGET) $(OBJS) $(LIBPATH) $(LIB)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
