struct node
{
    global int data;
    global node* link;
};
node* A ;
A = NULL;
node* t = A;
A





node* createNode(int data, node* link)
{
 
  node* temp = new node();
  temp->link = NULL;
  temp->data = data;
  return temp;
  
}

node* traverseNode(node* add)
{
  node* temp = add;
  cout<<"traversing node:<<endl;
  while(temp->link!=NULL)
  {
      temp = temp->link;
      cout<<"data: "<< temp->data<<endl;
  }
  temp -> link = temp;
}



