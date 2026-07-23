# all:
# # 	g++ -o a.exe main.cpp classes.cpp print.cpp parser.cpp helper.cpp && ./a.exe
# # 	g++ -o src/a.exe src/main.cpp src/classes.cpp src/print.cpp src/parser.cpp src/helper.cpp && ./a.exe
# 	g++ -Iinclude src/*.cpp -o a.exe && ./a.exe

# clean:
# 	rm -f a.exe && clear

CXX = g++
CXXFLAGS = -Iinclude -Wall -Wextra -std=c++17

all:
	$(CXX) $(CXXFLAGS) src/*.cpp -o a.exe
	./a.exe

clean:
	rm -f a.exe
	clear