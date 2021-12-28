main: main.c Student.h Student.c Filter.c UI.c File.c
	@gcc -std=c99 -Wall main.c Student.c Filter.c UI.c File.c -o main.out
	@./main.out

debug: main.c Student.h Student.c Filter.c UI.c File.c
	@gcc -std=c99 -Wall -g main.c Student.c Filter.c UI.c File.c -o main.out
	@lldb main.out

fake: FakeData.c Student.h Student.c Filter.c UI.c File.c
	@gcc -std=c99 -Wall FakeData.c Student.c Filter.c UI.c File.c -o fake.out
	@./fake.out

clean: 
	@if [ -e *.out ]; then \
		rm *.out; \
	fi
	@if [ -e *.dSYM ]; then \
		rm -r *.dSYM; \
	fi
