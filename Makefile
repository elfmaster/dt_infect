all:
	gcc -g inject.c /opt/elfmaster/lib/libelfmaster.a -o inject 
	gcc -no-pie test.c -o test
	gcc -c -fpic evil.c
	gcc -c -fpic logger.c
	gcc -shared -o libevil.so evil.o -ldl
	gcc -shared -o liblogger.so logger.o -ldl
clean:
	rm -f inject test
