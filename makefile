CXXFLAGS=	-I "./include"

basla: program1
	./bin/program1.exe
program1: calisanDugum.o elemanlar.o AvlDugum.o avlAgaci.o main.o
	g++ ./lib/calisanDugum.o ./lib/elemanlar.o ./lib/AvlDugum.o ./lib/avlAgaci.o ./lib/main.o -o ./bin/program1
	
calisanDugum.o:
	g++ $(CXXFLAGS) -c ./src/calisanDugum.cpp -o ./lib/calisanDugum.o 
elemanlar.o:
	g++ $(CXXFLAGS) -c ./src/elemanlar.cpp -o ./lib/elemanlar.o 
AvlDugum.o:
	g++ $(CXXFLAGS) -c ./src/AvlDugum.cpp -o ./lib/AvlDugum.o 
avlAgaci.o:
	g++ $(CXXFLAGS) -c ./src/avlAgaci.cpp -o ./lib/avlAgaci.o 
main.o:
	g++ $(CXXFLAGS) -c ./src/main.cpp -o ./lib/main.o 
