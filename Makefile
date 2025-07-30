CXX = g++
CXXFLAGS = -std=c++14 -Wall -g -MMD
EXEC = sorcery

# Find all .cc files in src and its subdirectories.
SRCS := $(wildcard src/*.cc) $(wildcard src/*/*.cc)
OBJS := $(SRCS:.cc=.o)
DEPS := $(SRCS:.cc=.d)

$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $(EXEC)

# Pattern rule to compile any .cc file found.
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(DEPS)

.PHONY: clean
clean:
	rm -f $(EXEC) $(OBJS) $(DEPS)