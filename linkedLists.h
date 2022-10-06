#ifndef LISTS_H
#define LISTS_H

#include <string>

using namespace std;


struct Node
{
  string word;
  int freq;
  Node* next;
};

class LinkedList
{
  public:
    LinkedList();    
    void insert(string w);
    Node* find(string w);
    void updateFrequency(string w);
    string printFrequency(Node* h);
    Node* getHead();
    void bubbleSort(int len);
    void updateHead(Node* newHead);
    int length();
    void lexicographical(int len);
    
    string finalCall(int rank, int listLength);
    
  private:
    Node* head;
};


#endif
