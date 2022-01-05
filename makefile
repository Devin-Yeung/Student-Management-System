main: main.c Student.h sha-256.h Student.c Filter.c UI.c File.c Stat.c sha-256.c login.c
	@gcc -std=c99 -Wall main.c Student.c Filter.c UI.c File.c Stat.c sha-256.c login.c -o main.out
	@./main.out

debug: main.c Student.h sha-256.h Student.c Filter.c UI.c File.c Stat.c sha-256.c login.c
	@gcc -std=c99 -Wall -g main.c Student.c Filter.c UI.c File.c Stat.c sha-256.c login.c -o main.out
	@lldb main.out

fake: FakeData.c
	@gcc -std=c99 -Wall FakeData.c -o fake.out
	@./fake.out

clean: 
	@if [ -e main.out ]; then \
		rm *.out; \
	fi
	@if [ -e main.out.dSYM ]; then \
		rm -r *.dSYM; \
	fi

zip :
	@zip release.zip Student.h sha-256.h main.c Student.c Filter.c UI.c File.c Stat.c sha-256.c login.c FakeData.c main.bat fake.bat