main: 
	@g++ -o main *.cpp -std=c++11

run: main
	@echo "Running the program:"
	@./main

edit:
	@vim main.cpp

debug:
	@gdb ./main

clean :
	@rm main
