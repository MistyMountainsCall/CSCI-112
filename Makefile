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

l6:
	c99 -Wall vanhouten_walker_lab6.c -o lab6
	./lab6 2
	rm lab6
	

testing:
	gcc test.c -o test
	./test

clean:
	rm test
