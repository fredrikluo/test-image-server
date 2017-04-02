CXX = clang++
CXXFLAGS = -I /usr/local/include/ -std=c++11
LDFLAGS = -L /usr/local/lib/
LIBS = -lboost_system -lstdc++
LD = clang++
BIN = appserver
SRC = $(shell find . -name *.cpp)
OBJ = $(SRC:%.cpp=%.o)

debug: CXXFLAG += -O0 -g -Wall -DDEBUG
debug: $(BIN)

release: CXXFLAG += -O2
release: $(BIN)

$(BIN): $(OBJ)
	$(LD) $(LDFLAGS)  -o $@ $^ $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCPATH) -MMD -MT -MF -c $< -o $@

clean:
	rm -rf src/*.o  src/*.d $(BIN)


