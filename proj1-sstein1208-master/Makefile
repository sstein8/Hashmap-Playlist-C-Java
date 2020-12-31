# Linked List Makefile

CFLAGS=-g -Werror -Wextra -Wall -pedantic -std=c99 -O0
DEPS=hashmap.h

all: c java

%.o: %.c $(DEPS)
	gcc -c -o $@ $< $(CFLAGS)

%.class: %.java 
	javac -cp . $< 

hashmap: tests.o hashmap.o
	gcc tests.o hashmap.o -o hashmap $(CFLAGS)

c: hashmap

java: HashMap.class LList.class LNode.class Tests.class

runc: c
	./hashmap

runjava: java
	java -cp . Tests
	
clean:
	rm -f *.class *.o hashmap
