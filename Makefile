# TERMINAL FILE FINDER (MAKEFILE) #

CC = g++
c17 = -std=c++17

main = src/main.cpp
file = src/file.cpp
util = src/util.cpp
conf = src/conf.cpp
ui = src/ui.cpp
lib = $(file) $(util) $(conf) $(ui)

ifeq ($(OS),Windows_NT)
	output = tff.exe
	exe = tff.exe
	delete = del
else
	output = tff
	exe = ./tff
	delete = rm
endif

.PHONY: run clean install uninstall

run: $(main) $(lib)
	$(CC) $(c17) $(main) $(lib) -o $(output)

clean: $(output)
	$(delete) $(output)

install: $(output)
	$(exe) -install

uninstall: $(output)
	$(exe) -uninstall

# MADE BY @hanilr #