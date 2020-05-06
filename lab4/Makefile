
goal: convert test_bits 

convert: convert.c
	gcc -g -o convert convert.c

test_bits: test_bits.c
	gcc -g -o test_bits test_bits.c bits.c

clean:
	rm -f convert test_bits

