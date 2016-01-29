
all: exec

exec: Person.o Employee.o main.c
	gcc -g $^ -o $@

Person.o: Person.c Person.h
	gcc -g $< -c -o $@
Employee.o: Employee.c Employee.h
	gcc -g $< -c -o $@

clean:
	rm -rf *.o ./exec
		         

