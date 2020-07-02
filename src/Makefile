CFLAGS = -g

tokenize: main.o
	cc -o $@ $^ $(CFLAGS)

tokenizer.o: tokenizer.h tokenizer.c
history.o: history.h history.c
main.o: main.c history.o tokenizer.o

clean:
	rm -f *.o *# *~ lab1
