rwildcard=$(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2) $(filter $(subst *,%,$2),$d))
SCR=$(call rwildcard,,*.cpp)

all: make run

make:
	g++ $(SCR) -std=c++11 -w -o coeficiente

run:
	./coeficiente