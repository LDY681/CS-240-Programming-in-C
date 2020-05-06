
all: toascii countlines towords test_stack rpncalc plot

countlines: countlines.c
	gcc  -std=c99 -g -o countlines countlines.c

towords: towords.c nextword.c
	gcc  -std=c99 -g -o towords towords.c nextword.c

test_stack: test_stack.c stack.c
	gcc  -std=c99 -g -o test_stack test_stack.c stack.c

rpncalc: rpncalc.c stack.c nextword.c rpn.c
	gcc  -std=c99 -g -o rpncalc rpncalc.c stack.c nextword.c rpn.c -lm

plot: plot.c stack.c nextword.c rpn.c
	gcc  -std=c99 -g -o plot plot.c stack.c nextword.c rpn.c -lm

toascii: toascii.c
	gcc  -std=c99 -g -o toascii toascii.c

org: countlines towords rpncalc 
	cp countlines countlines.org
	cp towords towords.org
	cp rpncalc rpncalc.org
	cp plot plot.org
	cp test_stack test_stack.org

clean:
	rm -f hello countlines towords test_stack rpncalc plot *out
