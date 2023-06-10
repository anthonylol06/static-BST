CC = g++
CFLAG = -Wall -g
TARGET = proj

all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAG) -o $(TARGET) $(TARGET).cpp
	
clean:
	$(RM) $(TARGET)