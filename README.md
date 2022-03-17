# TERMINAL FILE FINDER (TFF)
Terminal file finder application with CLI.

* [About The Project](#about-the-project)
* [Purpose Of The Project](#purpose-of-the-project)
* [Build And Run](#build-and-run)
* [Install And Uninstall](#install-and-uninstall)
* [User Guide](#user-guide)
* [Bugs](#bugs)

# About The Project
I was looking for a project to improve myself in c++,
then I noticed the filesystem library in c++ 2017 and while I was thinking about how I could do a project on it,
I started to make a file finder and listing program for the terminal and for the linux operating system.

## Images And Gifs Of The Program

### Install section

<img src="https://user-images.githubusercontent.com/77579421/158826408-0f0aba77-2040-4297-b1f1-0dcf3c2dd7e6.gif" width="480">

### List section

<img src="https://user-images.githubusercontent.com/77579421/158826873-16ab9b0f-caa6-49fd-aade-c5d82b9edb3b.gif" width="480">

### Main section

<img src="https://user-images.githubusercontent.com/77579421/158826995-091f8957-e0eb-4a94-b4c2-c34052a5d681.gif" width="480">

### Help section

<img src="https://user-images.githubusercontent.com/77579421/158827073-2e93fa94-8608-41d4-bc01-0a66495ffc57.png" width="480">

### Keymap guide

<img src="https://user-images.githubusercontent.com/77579421/158827187-83cb17d8-c313-451d-8531-f26bc696416e.png" width="480">

### User interface file content

<img src="https://user-images.githubusercontent.com/77579421/158827265-5e324ee3-0996-48c0-a2f6-8084a0f1340d.png" width="144">


# Purpose Of The Project
The purpose of this project is to navigate easily in file directories
in the terminal of the linux operating system and also to search for certain files in certain file directories.
The colors used in the program can be changed completely, of course, if the user has installed the program.

# Build And Run
## Required Tools
* make (Gnu Make)
* gcc (Gnu C Compiler)
* C++ 2017 (Doesn't work on windows for now.)

## Build

Building without installing: ` make `
Building with installing: ` make ` and then ` make install `

# Install And Uninstall

Installing:

* ` make ` and then ` make install `
* `./tff -install`

Uninstalling:

* ` make uninstall `
* ` ./tff -uninstall `

# User Guide

### Executing Types
* ` ./tff ` for executing program.
* ` ./tff -list ` only for listing and navigating.
* ` ./tff -install ` to install.
* ` ./tff -uninstall ` to uninstall.
* ` ./tff -help ` for help section.
* ` ./tff -keymap ` to see keymaps.

### Changing Color (Require to install)
Enter the .tff/ folder in home folder. Then open 'ui_color.txt' file in conf folder.
You can only change # included lines. If you change other things doesn't effect to program but
if you delete or add a line then program may not work.

# Bugs

* Sometimes search section doesn't work. I think its happening because of c++ 2017 but I'm not sure.

  > If you uninstall the project and then install again then problem solves.

* ' path_change() ' function used like ` for(int i = 0; 20 > i; i+=1) { path_change("../"); } ` and that was a bad solution.

  > If you get certain value of your directory count then you can solve this problem. (For developers)
