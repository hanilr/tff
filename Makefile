# TERMINAL FILE FINDER (MAKEFILE) #
# ONLY WORK ON LINUX #

CC = g++ # C++ COMPILER
c17 = -std=c++17 # COMPILE STANDARD

main = src/main.cpp # MAIN FILE
file = src/file.cpp
util = src/util.cpp
conf = src/conf.cpp
ui = src/ui.cpp
lib = $(file) $(util) $(conf) $(ui) # UTILITY FILES BUFFER

output = tff # COMPLIED FILE
exe = ./tff # EXECUTE COMMAND
delete = rm # DELETE COMMAND FOR LINUX

.PHONY: run clean install uninstall

run: $(main) $(lib) # COMPILE IF 'main' AND 'lib' BUFFERS EXIST
	$(CC) $(c17) $(main) $(lib) -o $(output)

clean: $(output) # DELETE COMPILED FILE IF COMPILED
	$(delete) $(output)

install: $(output) # INSTALL THE APPLICATION IF COMPILED FILE EXIST
	$(exe) -install

uninstall: $(output) # UNINSTALL THE APPLICATION IF COMPILED FILE EXIST
	$(exe) -uninstall

# MADE BY @hanilr #