# TERMINAL FILE FINDER (MAKEFILE) #
# ONLY WORK ON LINUX #

CC = g++
c17 = -std=c++17

main = src/main.cpp
file = src/file.cpp
util = src/util.cpp
conf = src/conf.cpp
ui = src/ui.cpp
lib = $(file) $(util) $(conf) $(ui)

output = tff
exe = ./tff
delete = rm

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