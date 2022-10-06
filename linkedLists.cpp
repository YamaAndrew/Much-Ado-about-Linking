#include <iostream>
#include <string>
#include "linkedLists.h"

using namespace std;

//linked list constructor (always set head to NULL)
LinkedList::LinkedList()
{
  head = NULL;
}

//linked list insert function (inserts newest node to the head)
void LinkedList::insert(string w)
{
  
  Node* latest = new Node; //create new node
  latest->next = head; //point new node to the lists current head node
  latest->word = w; //set new node's word to given word
  head = latest; //update head to newest node
  return;
}

//linked list find function (returns node with desired word or NULL)
Node* LinkedList::find(string w)
{
  Node* temp = head; //set pointer to head node
  
  //loop while pointer doesnt point to NULL
  while(temp != NULL)
  {
    if(temp->word == w) //if current node's word matches desired word
    {
      return temp; //return current node
    }
    temp = temp->next; //point to next node in list
  }
  return NULL;
}


void LinkedList::updateFrequency(string w)
{
  Node* temp = find(w);
  temp->freq += 1;
}

string LinkedList::printFrequency(Node* h)
{
  return to_string(h->freq);
}

Node* LinkedList::getHead()
{
  return head;
}

void LinkedList::bubbleSort(int len)
{
  Node* temp1;
  Node* temp2;
  Node* prev;
  
  if(head == NULL)
  {
    return;
  }
  for(int i = 0; i < len-1; i++)
  {
    temp1 = head;
    temp2 = head->next;
    prev = NULL;
    
    for(int j = 0; j < len-i-1; j++)
    {
      if(temp2->freq > temp1->freq && j == 0)
      {
        updateHead(temp2);
        prev = temp2;
        temp1->next = temp2->next;
        temp2->next = temp1;
        temp2 = temp1->next;
      }
      
      else if(temp2->freq > temp1->freq)
      {
        prev->next = temp2;
        prev = temp2;
        temp1->next = temp2->next;
        temp2->next = temp1;
        temp2 = temp1->next;
      }
      else
      {
        prev = temp1;
        temp1 = temp2;
        temp2 = temp2->next;
      }
    }
  }
  return;
}

void LinkedList::updateHead(Node* newHead)
{
  head = newHead;
}

int LinkedList::length()
{
  int length = 0;
  Node* curr = head;
  
  while(curr != NULL)
  {
    length++;
    curr = curr->next;
  }
  return length;
}

void LinkedList::lexicographical(int len)
{ 
  Node* temp1;
  Node* temp2;
  Node* prev;
  
  for(int i = 0; i < len-1; i++)
  {
    temp1 = head;
    temp2 = head->next;
    prev = NULL;
    
    for(int j = 0; j < len-i-1; j++)
    {
      if(temp1->freq == temp2->freq)
      {
        if(temp1->word > temp2->word && j == 0)
        {
          updateHead(temp2);
          prev = temp2;
          temp1->next = temp2->next;
          temp2->next = temp1;
          temp2 = temp1->next;
        }
        else if(temp1->word > temp2->word)
        {
          prev->next = temp2;
          prev = temp2;
          temp1->next = temp2->next;
          temp2->next = temp1;
          temp2 = temp1->next;
        }
        else 
        {
          prev = temp1;
          temp1 = temp2;
          temp2 = temp2->next;
        }
      }
      else
      {
        prev = temp1;
        temp1 = temp2;
        temp2 = temp2->next;
      }
    }
  }
  return;
}
string LinkedList::finalCall(int rank, int listLength)
{
  Node* temp = head;

  if(rank >= listLength)
  {
    return "-";
  }
  if(rank == 0)
  {
    return temp->word;
  }
  else
  {
    for(int i = 0; i < rank; i++)
    {
      temp = temp->next;
    }
    return temp->word;
  }
} 
