CC = g++
TARGET = cluster.exe
OBJECTS = main.o

all: clean $(TARGET)

main.o:
	$(CC) -c -o main.o main.cpp

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)

clean:
	rm -rf *.o $(TARGET)