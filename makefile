OPT = -Wall -g
game: main.o Escape.o Participant.o Ninja.o random.o Hero.o Snorc.o EscapeeBehaviour.o RescuerBehaviour.o RescuedBehaviour.o VillainBehaviour.o
	g++ $(OPT) -o game main.o Escape.o Participant.o Ninja.o random.o Hero.o Snorc.o EscapeeBehaviour.o RescuerBehaviour.o RescuedBehaviour.o VillainBehaviour.o

main.o: main.cc
	g++ $(OPT) -c main.cc

Snorc.o: Snorc.cc Snorc.h
		g++ $(OPT) -c Snorc.cc

Escape.o: Escape.cc Escape.h
	g++ $(OPT) -c Escape.cc

Hero.o: Hero.cc Hero.h
	g++ $(OPT) -c Hero.cc
	
Participant.o: Participant.cc Participant.h
	g++ $(OPT) -c Participant.cc

Ninja.o: Ninja.cc Ninja.h
	g++ $(OPT) -c Ninja.cc

random.o: random.cc 
	g++ $(OPT) -c random.cc

EscapeeBehaviour.o: EscapeeBehaviour.cc MoveBehaviour.h 
	g++ $(OPT) -c EscapeeBehaviour.cc MoveBehaviour.h 
	
RescuerBehaviour.o: RescuerBehaviour.cc MoveBehaviour.h 
	g++ $(OPT) -c RescuerBehaviour.cc MoveBehaviour.h 

RescuedBehaviour.o: RescuedBehaviour.cc MoveBehaviour.h 
	g++ $(OPT) -c RescuedBehaviour.cc MoveBehaviour.h 

VillainBehaviour.o: VillainBehaviour.cc MoveBehaviour.h 
	g++ $(OPT) -c VillainBehaviour.cc MoveBehaviour.h 
	
clean:
	rm -f *.o game
