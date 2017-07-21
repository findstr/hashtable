.PHONY:all

all:testhash

testhash:hashtable.c testhash.c
	gcc -Wall -g -o $@ $^

clean:
	rm testhash
