all:
	g++ -o a.exe scheduler.cpp && ./a.exe

clean:
	rm -f a.exe