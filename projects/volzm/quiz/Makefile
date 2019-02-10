CC=gcc
DEPS = testme.c

testme: $(DEPS)
	$(CC) -o $@ $^ -coverage -fpic -lm -std=c99
	./$@

.PHONY: clean

clean:
	rm -rf testme.c.gcov testme.gcda testme testme.gcno

