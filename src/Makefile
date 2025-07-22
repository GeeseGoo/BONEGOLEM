CXX = g++
CXXFLAGS = -std=c++14 -Wall -g -MMD  # MMD auto generates dependencies
EXEC = sorcery
CCFILES = $(wildcard *.cc)
OBJECTS = $(CCFILES:.cc=.o)
DEPENDS = $(CCFILES:.cc=.d)

$(EXEC): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXEC) -lX11

-include $(DEPENDS)

.PHONY: clean
clean:
	rm $(EXEC) $(OBJECTS) $(DEPENDS)
