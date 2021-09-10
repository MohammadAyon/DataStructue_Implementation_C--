#include <iostream>
#include "linkList.cpp"
using namespace std;

int main()
{  
    linked_list ll;

    int n,inFrst,inLst;
    cout<<"Enter the number elements that to add at first :";
    cin>>inFrst;
    while (inFrst)
    {
        cin >> n;
        if (n != 0)
        {
            ll.insertAtFirst(n);
        }
        else
        {
            break;
        }
        inFrst--;
    }
    cout << "\nPrinted the list : " << endl;
    ll.print();
    cout << "\nEnter the number elements that to add at lasy :";
    cin >> inLst;
    while (inLst)
    {
        cin >> n;
        if (n != 0)
        {
            ll.insertAtLast(n);
        }
        else
        {
            break;
        }
        inLst--;
    }
    cout << "\nPrinted the list : " << endl;
    ll.print();
    cout << "\nInsert 46 at position 3" << endl;
    ll.insertAtPosition(3, 25);
    ll.print();
    cout << "\nFirst node is deleted" << endl;
    ll.deleteAtStart();
    ll.print();
    cout << "\nLast node is deleted" << endl;
    ll.DeleteAtLast();
    ll.print();
    cout << "\nNode of position 2 is deleted" << endl;
    ll.deleteAtPosition(2);
    ll.DeleteValue(2);
    ll.print();
    ll.reverse();
    ll.print();
   
    
   
    return 0;
}
