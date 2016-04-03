all:
	bash ./derp.txt
	echo "read this for options:"
	cat Makefile
	

update:
	git add .
	git commit
	echo "These should all be green"
	git status
	git git push
	echo "Should be blank now"
	git status

bonus:
	gcc vanhouten_walker_bonus1.c -o bonus
	./bonus
	rm bonus


p2:
	c99 -Wall vanhouten_walker_bonus1.c -o program2 -lm
	./program2
	rm program2

l6:
	c99 -Wall vanhouten_walker_lab6.c -o lab6
	./lab6
	rm lab6
