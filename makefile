CXXFLAGS = -Wall
OBJS = List.o main.o
LIBS = 
TARGET = lab04
all: $(TARGET)	

$(TARGET): $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

List.o: List.h List.cpp	
	$(CXX) $(CXXFLAGS) -c List.cpp

main.o: main.cpp	
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm *.o lab04