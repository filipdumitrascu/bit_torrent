build:
	mpic++ bittorent.cpp lib/* -o tema2 -pthread -Wall

clean:
	rm -rf tema2
