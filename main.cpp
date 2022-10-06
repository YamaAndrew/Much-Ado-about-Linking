#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
#include "linkedLists.h"

using namespace std;

int main(int argc, char** argv)
{
  ifstream file("shakespeare-cleaned5.txt"); //open file with shakespeare's wprds
  LinkedList** arrayOfPointers = new LinkedList*[35]; //create poiner for pointers
  string line; //create string to later hold shakespeare's words
  
  //create array to hold words based off character length
  for(int i = 0; i < 35; i++)
  {
    arrayOfPointers[i] = new LinkedList;
  }
  
  //loop while reading each line from shakespeare's words file
  while(getline(file, line))
  {   
    if(arrayOfPointers[line.length()-5]->find(line) != NULL) //if word already exists in linked list
    {
      arrayOfPointers[line.length()-5]->updateFrequency(line); //update frequency 
    }
    else //if word does not exist in array yet
    {
      arrayOfPointers[line.length()-5]->insert(line); //insert word into linked list
      arrayOfPointers[line.length()-5]->updateFrequency(line); //update frequency
    }
  }
  
  //sort each linked list by frequency
  for(int i = 0; i < 32; i++)
  {
    arrayOfPointers[i]->bubbleSort(arrayOfPointers[i]->length());
  }
  //sort each linked list by lexicographical order
  for(int i = 0; i < 32; i++)
  {
    arrayOfPointers[i]->lexicographical(arrayOfPointers[i]->length());
  }
  
  //open input and output files
  ifstream input;
  ofstream output;
  
  input.open(argv[1]); //first file in terminal is input
  output.open(argv[2]); //second file in terminal is output
    
  string repeat; //string to hold input integers
  
  //loop while reading each line from input file
  while(getline(input, repeat))
  {
    int num1, num2; //create variables for each input given in each line of input file
    stringstream ss; //hold strings from input file
    ss << repeat; //hold both integers from input file
    ss >> num1 >> num2; //store first integer in num1 and second in num2
    output << arrayOfPointers[num1-5]->finalCall(num2, arrayOfPointers[num1-5]->length()) << endl; //output desired final output in output file
  }    
  //close all files
  input.close();
  output.close();
  file.close();

   return 0;
}
