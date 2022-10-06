# Much-Ado-about-Linking
Program that takes in a file (file contains all words used in Shakespeare's writings) and returns the frequency of words by rank. These ranks are categorized by the amount of letters in each word.

README for test HW 1: A Dramatic Analysis assignment, CSE101

A. Yamasaki, October 2021
-----------------------------------------------------

Code files: Makefile, bard.cpp, linkeLists.cpp, linkedLists.h
Test files: simple-input.txt, test-output.txt, simple-output.txt, more-input.txt, more-output.txt
Extra files: README, hw_shakespeare.pdf, shakespear-cleaned5.txt

----------------------------------------------------

This is an assignment that reads in a text file of Shakespeare's used words along with a text file of given word lengths and 
frequency rankings to then output in another text file.

----------------------------------------------------

USAGE: 
1) Run "make", to get executable "bard".
2) Run "./bard <INPUT FILE> <OUTPUT FILE>"

Each line of INPUT FILE should have two integers separated by a space. (The first integer is greater than 4 while the second is any value.)
Each corresponding line of OUTPUT FILE displays a word that matches its length with the first input integer and frequency rank (for words with that length) with the second integer.
