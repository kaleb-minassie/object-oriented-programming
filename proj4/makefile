FILE = testing

all: compile

compile: $(FILE)

$(FILE): $(FILE).cpp Fraction.cpp
	g++ -Wall $(FILE).cpp Fraction.cpp -o $(FILE)

run: $(FILE)
	./$(FILE)
