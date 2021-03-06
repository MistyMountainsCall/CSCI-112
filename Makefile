all:
	bash ./derp.txt
	echo "read this for options:"
	cat Makefile
	

upload:
	git add .
	git commit -S;git push

bonus:
	gcc vanhouten_walker_bonus1.c -o bonus
	./bonus thingy
	rm bonus


p2:
	gcc -o program2 vanhouten_walker_program2.c
	./program2 cat cat cat cat berry circus boss cherry church brush
	rm program2

p3:
	c99 -Wall -o program3 vanhouten_walker_program3.c -lm

l6:
	c99 -Wall vanhouten_walker_lab6.c -o lab6
	./lab6 2
	rm lab6

l7:
	c99 -Wall vanhouten_walker_lab7.c -o lab7

testing:
	gcc test.c -o test
	./test

