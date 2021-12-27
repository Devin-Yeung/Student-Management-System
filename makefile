main: main.c Student.h Student.c UI.c File.c
	gcc -std=c99 main.c Student.c UI.c File.c -o main.out
	./main.out

debug: main.c Student.h Student.c UI.c File.c
	gcc -std=c99 -g main.c Student.c UI.c File.c -o main.out
	lldb main.out

clean: 
	if [ -e *.out ]; then \
		rm *.out; \
	fi
	if [ -e *.dSYM ]; then \
		rm -r *.dSYM; \
	fi