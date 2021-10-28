main: main.cpp crossoverCX.o crossoverOB.o getDistance.o intensify.o print.o utils.o evaluate.o initialize_heuristic.o MA.o Problem.o Individual.o
	g++ -O2 -o $@ $^

Individual.o: Individual.h Individual.cpp
	g++ -O2 -c -o $@ Individual.cpp 

crossoverCX.o: crossoverCX.cpp Individual.h 
	g++ -O2 -c -o $@ crossoverCX.cpp

crossoverOB.o: crossoverOB.cpp Individual.h 
	g++ -O2 -c -o $@ crossoverOB.cpp

getDistance.o: getDistance.cpp Individual.h 
	g++ -O2 -c -o $@ getDistance.cpp

intensify.o: intensify.cpp Individual.h 
	g++ -O2 -c -o $@ intensify.cpp

print.o: print.cpp Individual.h 
	g++ -O2 -c -o $@ print.cpp

evaluate.o: evaluate.cpp Individual.h 
	g++ -O2 -c -o $@ evaluate.cpp

initialize_heuristic.o: initialize_heuristic.cpp Individual.h 
	g++ -O2 -c -o $@ initialize_heuristic.cpp

Problem.o: Problem.h
	g++ -O2 -c -o $@ Problem.cpp

MA.o: MA.h Individual.h Problem.h MA.cpp
	g++ -O2 -c -o $@ MA.cpp

utils.o: utils.cpp utils.h
	g++ -O2 -c -o $@ utils.cpp

clean:
	rm -f main *.o
