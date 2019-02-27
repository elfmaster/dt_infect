all:
	gcc -no-pie test2.c -o test2
	gcc -g inject.c /opt/elfmaster/lib/libelfmaster.a -o inject 
	gcc -no-pie test.c -o test
	gcc -c -fpic evil.c
	gcc -shared -o libevil.so evil.o -ldl
	gcc -c -fpic keylogger.c
	gcc -shared -o keylogger.so keylogger.o -ldl
clean:
	rm -f inject test
