#include <bits/stdc++.h>
using namespace std;

class Node
{
  public:
    int tInputs;
    Node *startLeft;
    Node *startRight;
  public:
    Node(int a)
    {
      tInputs = a;
      startLeft = NULL;
      startRight = NULL;
    }
};

Node *insert_BST(Node *theStructure, int use)
{
  if(theStructure == NULL)
  {
    cout <<"node inserted successfully"<<endl;
    return (new Node(use));
  }
  if(theStructure->tInputs >= use)
    theStructure->startLeft = insert_BST(theStructure->startLeft, use);
  else
    theStructure->startRight = insert_BST(theStructure->startRight, use);
  return theStructure;
}

int search_BST(Node *theStructure, int use)
{
  if(theStructure == NULL)
  {
    cout<<"node is not present.\n";
    return 0;
  }
  string ret_use;
  if(theStructure->tInputs == use)
    cout<< "node is present.\n";
  else if(theStructure->tInputs > use)
    search_BST(theStructure->startLeft, use);
  else
     search_BST(theStructure->startRight, use);
  return 0;
}

Node* delete_BST(Node *theStructure, int use)
{
  if(theStructure == NULL)
  {
    cout<<"not present"<<endl;
    return theStructure;
  }
  if(theStructure->tInputs > use)
    theStructure->startLeft = delete_BST(theStructure->startLeft, use);
  else if(theStructure->tInputs < use)
    theStructure->startRight = delete_BST(theStructure->startRight, use);
  else
  {
    if(theStructure->startLeft == NULL)
    {
      Node *bb = theStructure->startRight;
      free(theStructure);
      theStructure= bb;
    }
    else if(theStructure->startRight == NULL)
    {
      Node *bb = theStructure->startLeft;
      theStructure = bb;
      free(bb);
    }
    else
    {
      Node *bb = theStructure->startLeft;
      while(bb->startRight->startRight!=NULL)
      {
        bb = bb->startRight;
      }
      theStructure->tInputs = bb->startRight->tInputs;
      Node *bb2 = bb->startRight->startLeft;
      free(bb->startRight);
      bb->startRight = bb2;
    }
  }
  return theStructure;
}

void inorder(Node *theStructure)
{
    if (theStructure != NULL)
    {
        inorder(theStructure->startLeft);
        cout<<theStructure->tInputs<<" ";
        inorder(theStructure->startRight);
    }
}

int main()
{
  Node *theStructure;
  theStructure = new Node(10);
  theStructure->startLeft = new Node(5);
  theStructure->startLeft->startLeft = new Node(2);
  theStructure->startLeft->startRight = new Node(8);
  theStructure->startLeft->startLeft->startLeft = new Node(1);
  theStructure->startLeft->startLeft->startRight = new Node(4);
  theStructure->startLeft->startRight->startLeft = new Node(7);
  theStructure->startRight = new Node(17);
  theStructure->startRight->startLeft = new Node(16);
  theStructure->startRight->startRight = new Node(18);

  insert_BST(theStructure, 9);
  cout<<"the inorder traversal is: ";
  inorder(theStructure);
  cout<<endl;

  search_BST(theStructure,9);
  theStructure = delete_BST(theStructure,5);
  cout<<"node 5 is deleted \n";
  search_BST(theStructure,5);
  cout<<"the inorder traversal is: ";
  inorder(theStructure);
  cout<<endl;
  return 0;
}
