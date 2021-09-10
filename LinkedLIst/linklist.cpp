#include <iostream>

using namespace std;

struct node
{
  int data;
  node *next;
};

class linked_list
{
private:
  node *head, *tail;

public:
  linked_list()
  {
    head = NULL;
    tail = NULL;
  }
  void insertAtFirst(int item)
  {
    node *tmp = new node;
    tmp->data = item;
    tmp->next = NULL;

    if (head == NULL)
    {
      head = tmp;
      tail = tmp;
    }
    else
    {
      tmp->next = head;
      head = tmp;
    }
  }
  void insertAtLast(int item)
  {
    node *tmp = new node;
    tmp->data = item;
    tmp->next = NULL;

    if (head == NULL)
    {
      head = tmp;
      tail = tmp;
    }
    else
    {
      tail->next = tmp;
      tail = tail->next;
    }
  }
  
  void insertAtPosition(int pos, int item)
  {
    node *tmp = new node;
    tmp->data = item;
    tmp->next = NULL;
    if (head == NULL)
    {
      if (pos != 0)
        return;
      else
        head = tmp;
    }
    if (head != NULL && pos == 0)
    {
      tmp->next = head;
      head = tmp;
      return;
    }
    node *curr = head;
    node *prev = NULL;

    int i = 0;
    while (i < pos)
    {
      prev = curr;
      curr = curr->next;
      if (curr == NULL)
        break;
      i++;
    }
    tmp->next = curr;
    prev->next = tmp;
  }
  void deleteAtStart()
  {
    if (head == NULL)
      return;
    if (head->next == NULL)
    {
      delete head;
      head = NULL;
      return;
    }
    node *tmp = head;
    head = head->next;
    delete tmp;
  }
  void DeleteAtLast()
  {
    if (head == NULL)
      return;
    if (head->next == NULL)
    {
      delete head;
      head = NULL;
      return;
    }

    node *tmp = head;
    while (tmp->next && tmp->next->next != NULL)
    {
      tmp = tmp->next;
    }
    delete tmp->next;
    tmp->next = NULL;
  }

  void DeleteValue(int item)
  {
    int pos = 0;
    if (head == NULL)
      return;
    if (head->data == item)
    {
      if (head->next != NULL)
      {
        head = head->next;
        return;
      }
      else
      {
        head = NULL;
        return;
      }
    }
    node *tmp = head;
    node *prev = head;

    while (tmp->next != NULL && tmp->data != item)
    {
      prev = tmp;
      tmp = tmp->next;
    }

    if (tmp->data == item)
    {
      prev->next = prev->next->next;
      delete tmp;
    }
    else
      cout << endl
           << item << " not found in the list";
  }
  void deleteAtPosition(int pos)
  {
    if (head == NULL)
      return;

    int i = 0;
    node *tmp = head;
    node *prev = head;

    if (pos == 0)
    {
      head = head->next;
      delete tmp;
      return;
    }

    while (tmp->next != NULL && i < pos)
    {
      prev = tmp;
      tmp = tmp->next;
      i++;
    }
    if (i == pos)
    {
      prev->next = prev->next->next;
      delete tmp;
    }
    else
    {
      cout << endl
            << pos << " doesn't exit in  the list";
    }
  }
  void reverse()
  {
    
    node *current = head;
    node *prev = NULL, *next = NULL;

    while (current != NULL)
    {
      
      next = current->next;

      
      current->next = prev;

     
      prev = current;
      current = next;
    }
    head = prev;
  }
  void print()
  {
    cout << endl;
    node *tmp = head;
    while (tmp != NULL)
    {
      cout << " "<<tmp->data;
      tmp = tmp->next;
    }
  }
};