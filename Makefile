main.o: main.cpp analyzer.h analyzer.cpp
	@g++ analyzer.cpp main.cpp -o main.o 

clean:
	@rm main.o
