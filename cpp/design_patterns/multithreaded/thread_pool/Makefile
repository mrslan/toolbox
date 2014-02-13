CXXFLAGS =	-I $(INCLUDES) -O0 -g -Wall -fmessage-length=0

OBJS = main.o

LIBS =

TARGET = runThreadPool

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
