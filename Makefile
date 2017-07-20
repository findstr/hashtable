.PHONY:all

all:testhash

testhash:hashtable.c testhash.c
	gcc -g -o $@ $^

clean:
	rm testhash
