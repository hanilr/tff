# TERMINAL FILE FINDER (MAKEFILE) #

CC = g++
c17 = -std=c++17

main = src/main.cpp
file = src/file.cpp
util = src/util.cpp
ui = src/ui.cpp
lib = $(file) $(util) $(ui)

ifeq ($(OS),Windows_NT)
	output = tff.exe
	delete = del
else
	output = tff
	delete = rm
endif

.PHONY: run clean

run: $(main) $(lib)
	$(CC) $(c17) $(main) $(lib) -o $(output)

clean: $(output)
	$(delete) $(output)

# MADE BY @hanilr #