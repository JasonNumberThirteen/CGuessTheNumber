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
- Adjustable range of integers
- Validation of numbers range (minimum greater than maximum and minimum equal to maximum)
- Validation of typed number (used technique from [this link](https://stackoverflow.com/a/14099507 "How to scanf only integer and repeat reading if the user enters non-numeric characters?"))

## Usage
- Type a whole number when prompted

## Compilation
- Just type ```gcc -o main main.c``` command from command line to compile code and launch the application typing ```main```.

## Credits
- This project was made by [Jason](https://jasonxiii.pl "Jason. Gry, muzyka, kursy, artykuły, programy i filmy!")