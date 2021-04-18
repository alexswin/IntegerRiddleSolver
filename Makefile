all:
	g++ -std=c++11 -o solver *.cpp

clean:
	rm -f solver
