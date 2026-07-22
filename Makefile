all:
# 	g++ -o a.exe main.cpp classes.cpp print.cpp parser.cpp helper.cpp && ./a.exe
	g++ -o src/a.exe src/main.cpp src/classes.cpp src/print.cpp src/parser.cpp src/helper.cpp && ./a.exe

clean:
	rm -f a.exe && clear