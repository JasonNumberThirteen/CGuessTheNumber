# Guess the Number
> A simple console clone of "Guess the Number" game written in pure C.

## Table of Contents
* [General information](#general-information)
* [Used technologies](#used-technologies)
* [Features](#features)
* [Usage](#usage)
* [Compilation](#compilation)
* [Credits](#credits)

## General information
- This is a simple console application of "Guess the Number" game. It was written in pure C.
- The project presents my programming skills how I do write code taking care of several optimisations.
- The game selects random integer from specific range and player must guess what this number is. If he will choose lower number, then he receives a tip that this number is higher.
- When the game is over, it shows how many tries player needed to guess the right number.
- Win condition: player has selected correct number
- Lose condition: none

## Used technologies
- "Visual Studio Code" IDE for writing code
- GCC compiler (Rev2, Built by MSYS2 project) 12.1.0

## Features
- Adjustable range of integers (the game works only with POSITIVE values!)
- Validation of numbers range (minimum greater than maximum and minimum equal to maximum)
- Validation of typed number (used technique from [this link](https://stackoverflow.com/a/14099507 "How to scanf only integer and repeat reading if the user enters non-numeric characters?"))

## Usage
- Type a whole number when prompted

## Compilation
### Visual Studio Code
- If you are using "Visual Studio Code":
	1. Install a plugin for C/C++ compilation from [this link](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools "C/C++ - Visual Studio Marketplace")
	2. Select ```Terminal```, ```Configure default compilation tasks``` and choose your desired compiler
	3. Go to ```tasks.json``` file existing in ```.vscode``` directory, find created task, find the ```args``` keyword and replace default entries with these ones (after the ```-g``` entry):
		- ```"${fileDirname}\\*.c",```
		- ```"${fileDirname}\\*.h",```
	4. Select ```main.c``` file
	5. Press Ctrl+Shift+B to compile
	6. Select ```Terminal```, ```New terminal```
	7. Launch the game typing ```./main```
### GCC
- You can also compile the game using GCC compiler:
	1. Launch command prompt with administrator privileges
	2. Go to directory where this ```README``` file is using ```cd``` command
	3. Enter this command: ```gcc -o main main.c communicator.c game.c input.c typedNumbers.c```
	4. Launch the game typing ```main```

## Credits
- This project was made by [Jason](https://jasonxiii.pl "Jason. Gry, muzyka, kursy, artykuły, programy i filmy!")