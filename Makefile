CC = g++
CFLAGS = -g -c
STANDARD = -std=c++11


all: fileDownloading mOffloading new_offloading 

fileDownloading: fileDownloading.o 
	$(CC) -o $@ $? 

fileDownloading.o: fileDownloading.cpp
	$(CC) $(STANDARD) $(CFLAGS) -o $@ fileDownloading.cpp 

mOffloading: mOffloading.o 
	$(CC) -o $@ $? 

mOffloading.o: mOffloading.cpp
	$(CC) $(STANDARD) $(CFLAGS) -o $@ mOffloading.cpp 

new_offloading: new_offloading.o 
	$(CC) -o $@ $? 

new_offloading.o: new_offloading.cpp
	$(CC) $(STANDARD) $(CFLAGS) -o $@ new_offloading.cpp 

#main:  main.o
#	$(CC) -o $@ $? 

#deadlineratio: deadlineratio.o random.o
#	$(CC) -o $@ $? 

#deadlineratio: deadlineratio.o
#	$(CC) -o $@ $? 

#deadlineratio.o: deadlineratio.cpp
#	$(CC) $(STANDARD) $(CFLAGS) -o $@ deadlineratio.cpp 

#stationary: stationary.o
#	$(CC) -o $@ $? 	

#stationary.o: stationary.cpp
#	$(CC) $(STANDARD) $(CFLAGS) -o $@ stationary.cpp 

#download: download.o
#	$(CC) -o $@ $? 	

#download.o: download.cpp
#	$(CC) $(STANDARD) $(CFLAGS) -o $@ download.cpp 		

#main.o:	main.cpp
#	$(CC) $(STANDARD) $(CFLAGS) -o $@ main.cpp 


		
#deadlineratio.o: deadlineratio.cpp
#	$(CC) $(STANDARD) $(CFLAGS) -o $@ deadlineratio.cpp 
	
#random.o: random.cc 
#	$(CC) $(CFLAGS) -o $@ random.cc 
	
clean:
	rm *.o *.txt *.exe filedownloading mOffloading new_offloading

