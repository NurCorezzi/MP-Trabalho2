CXX = g++

INC_DIR=../include
LIB_DIR=../lib
GTEST_DIR = $(LIB_DIR)/gtest
O_DIR=obj

GCOV_FLAGS = -ftest-coverage -fprofile-arcs
CXX_FLAGS = -I $(INC_DIR) -std=c++11
CXX_GTEST_LIB = -I $(GTEST_DIR)/include -L $(GTEST_DIR)/lib\
				-lgtest -lgtest_main -lpthread

_DEPS = ConversorRomanos.h
DEPS = $(patsubst %,$(INC_DIR)/%,$(_DEPS))

_OBJ = ConversorRomanos.o ModuloTestes.o 
OBJ = $(patsubst %,$(O_DIR)/%,$(_OBJ))

$(O_DIR)/%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXX_FLAGS) $(CXX_GTEST_LIB) $(GCOV_FLAGS)

a: $(OBJ)
	$(CXX) -o $@ $^ $(CXX_FLAGS) $(CXX_GTEST_LIB) $(GCOV_FLAGS)

.PHONY: clean

clean:
	rm -f $(O_DIR)/*.o *~ core $(INCDIR)/*~ 
	
#romanos: ModuloTestes.cpp ConversorRomanos.cpp ConversorRomanos.h
#	$(CXX) -o romanos ModuloTestes.cpp ConversorRomanos.cpp ConversorRomanos.h -std=c++11 -I GTEST_HOME/include -L GTEST_HOME/lib -lgtest -lgtest_main -lpthread 
