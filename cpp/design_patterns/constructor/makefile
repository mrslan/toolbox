TARGET_NAME = createCar

INCLUDES = inc

SOURCES = src/main.cpp \
					src/Car.cpp \
					src/CarBasic.cpp \
					src/Breaks.cpp \
					src/Engine.cpp \
					src/EngineDummy.cpp \
					src/BreaksDummy.cpp \
					sample/CarSample.cpp \
					sample/EngineSample.cpp \
					sample/BreaksSample.cpp

$(TARGET_NAME): $(SOURCES)
	g++ -I $(INCLUDES) -o $(TARGET_NAME) $(SOURCES)
