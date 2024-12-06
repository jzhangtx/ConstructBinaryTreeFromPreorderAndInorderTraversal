ConstructFromPreAndInorder: ConstructFromPreAndInorder.o
	g++ -g -o ConstructFromPreAndInorder.exe ConstructFromPreAndInorder.o -pthread    

ConstructFromPreAndInorder.o: ConstructFromPreAndInorder/ConstructFromPreAndInorder.cpp
	g++ -g  -c -pthread ConstructFromPreAndInorder/ConstructFromPreAndInorder.cpp
