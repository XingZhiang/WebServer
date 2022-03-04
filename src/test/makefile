cc=g++

server:server_test.o webserver.o
	$(cc) -o server server_test.o webserver.o

server_test.o:server_test.cpp
	$(cc) -c ./server_test.cpp

webserver.o : ../server/webserver.cpp ../server/webserver.h
	$(cc) -c ../server/webserver.cpp

clean:
	rm *.o
	rm server

