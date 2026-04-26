CXX = g++
TARGET = $(notdir $(CURDIR))

CXXFLAGS = -std=c++17 -Wall $(shell pkg-config --cflags opencv4)
LDFLAGS = $(shell pkg-config --libs opencv4)

SRC = main.cpp

link = src/morphology.cpp	

all:
	$(CXX) $(SRC) $(link) -o $(TARGET) $(CXXFLAGS) $(LDFLAGS)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: build
build:
ifndef SRC
	$(error "SRC is not set")
endif
ifndef link
	$(error "link is not set")
endif
	@echo "Building..."
	@$(CC) $(SRC) $(link) -o $(PROJECT) $(CFLAGS) $(LIBS)

.PHONY: clean
clean:
	@echo "Cleaning"
	@rm -rf $(PROJECT)