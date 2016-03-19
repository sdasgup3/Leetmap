CFLAGS= -std=c++11
CC=g++ 
SRC=$(wildcard *.cpp)
OBJ=$(patsubst %.cpp, %.o, $(SRC))
TARGET=$(patsubst %.o,%,$(OBJ))  
ARGS=


$(TARGET): $(SRC)	
	for prog in $(TARGET); do $(CC) $(CFLAGS)  $$prog.cpp -o $$prog ; done
		     
%-test: %.cpp	
	$(CC) $(CFLAGS)  $^  -o $@
	./$@ $(ARGS)

%.o: %.cpp
	$(CC) $(CFLAGS)  $^ -c -o $@

%:%.o  
	$(CC) $(CFLAGS)  $^ -o $@

clean:
	rm -rf *.o $(TARGET) *-test

printvar:
	@echo "CC    : " '$(CC)'
	@echo "SRC    : " '$(SRC)'
	@echo "OBJ    : " '$(OBJ)'
	@echo "TARGET    : " '$(TARGET)'
