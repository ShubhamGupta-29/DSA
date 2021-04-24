#include<bits/stdc++.h>
using namespace std;

class Node{
public:
int key;
int data;
Node* next;

Node(){
    key=0;
    data=0;
    next=NULL;
    }

    Node(int k,int d){
        key=k;
        data=d;
    }
};

class SinglyLinkedList{
    public:
    Node* head;
    
    SinglyLinkedList(){
        head=NULL;
    }
    SinglyLinkedList(Node* n){
        head=n;
    }


    // Check if a node exists using a key value
    Node* nodeExists(int k){
         Node* temp = NULL;
         Node* ptr= head;

         while(ptr!=NULL){
             if(ptr->key==k){
                 temp=ptr;
             }
             ptr=ptr->next;
         }
         return temp;
    }

    //Appending a node at end
    void appendnode(Node* n){
         if(nodeExists(n->key)!=NULL){
             cout<<"Node already exist with kay value : "<<n->key<<"Append another node"<<endl;
         }
         else{
             if(head==NULL){
                 head = n;
                 cout<<"Node appended"<<endl;
             }
             else{
                 Node* ptr=head;
                 while(ptr->next!=NULL){
                     ptr=ptr->next;
                 }
                 ptr->next=n;
                 cout<<"Node appended"<<endl;  
             }
         }

    }


    //Prepend Node- Attach the node at the last
    void prependnode(Node* n){
        if(nodeExists(n->key)!=NULL){
             cout<<"Node already exist with kay value : "<<n->key<<"Append another node"<<endl;
        }
        else{
            n->next=head;
            head=n;
            cout<<"Node prepended"<<endl;
        }
    }

    //Insert Node after a particular node in the list
    void insertnodeafter(int k,Node* n){
        Node* ptr= nodeExists(k);
        if(ptr==NULL){
            cout<<"No Node exists with key value:  "<<k<<endl;
        }

    else{
         if(nodeExists(n->key)!=NULL){
             cout<<"Node already exist with kay value : "<<n->key<<"Append another node"<<endl;
        }
        else{
            n->next=ptr->next;
            ptr->next=n;
            cout<<"Node Inserted"<<endl;
        }
      }    
    }
    

    //Delete node by unique key
    void deleteNodeByKey(int k){
        if(head==NULL){
            cout<<"Singly Linkedlist Already empty. Cant't Delete\n";
        }
        else if(head!=NULL){
            if(head->key==k){
                head = head->next;
                cout<<"Node Unlinked with key value: "<<k<<endl;
            }else{

                Node* temp=NULL;
                Node* prevptr=head;
                Node* currptr=head->next;
                while(currptr!=NULL){
                    if(currptr->key==k){
                        temp=currptr;
                        currptr=NULL;
                    }else{
                        prevptr=prevptr->next;
                        currptr=currptr->next;
                    }
                }
                if(temp!=NULL){
                    prevptr->next=temp->next;
                    cout<<"Node Unlinked with key value : "<<k<<endl;
                }else{
                    cout<<"Node does not exists with key value: "<<k<<endl;
                }
            }
        }       
    }


    //Update Node 
    void updateNodeByKey(int k, int d){
        Node*ptr = nodeExists(k);
        if(ptr!=NULL){
            ptr->data=d;
            cout<<"Node Data Updated Succesfully"<<endl;
        }
        else{
            cout<<"Node Doesn't with key value: "<<k<<endl;
        }
    }



    //Printing
    void printList(){
        if(head==NULL){
            cout<<"No Nodes in Singly Linked List\n";
        }
        else{
            cout<<endl<<"Singly Linked list Values: ";
            Node*temp =head;
            while (temp!=NULL)
            {
                cout<<"("<<temp->key<<","<<temp->data<<")-->";
                temp=temp->next;
            }   
        }
    }

};


int main(){

SinglyLinkedList s;
int option;
int key1,k1,data1;
do{
    cout<<"\nSelect an Operator.Enter 0 to exit."<<endl;
    cout<<"1.appendNode()"<<endl;
    cout<<"2.prependNode()"<<endl;
    cout<<"3.insertNodeAfter()"<<endl;
    cout<<"4.deleteNodeByKey()"<<endl;
    cout<<"5.updateNodeByKey()"<<endl;
    cout<<"6.print()"<<endl;
    cout<<"7.Clear Screen()"<<endl;


    cin>>option;
    Node* n1 =  new Node();

    switch(option){
        case 0:
          break;
        case 1:
        cout<<"Enter key & data of the Node to be Appended\n";
        cin>>key1;
        cin>>data1;
        n1->key=key1;
        n1->data=data1;
        s.appendnode(n1);
        break;

        case 2:
        cout<<"Enter key & data of the Node to be Prepended\n";
        cin>>key1;
        cin>>data1;
        n1->key=key1;
        n1->data=data1;
        s.prependnode(n1);
        break;

        case 3:
        cout<<"Enter key after which you want to insert node\n";
        cin>>k1;
        cout<<"Enter key and data\n";
        cin>>key1;
        cin>>data1;
        n1->key=key1;
        n1->data=data1;
        s.insertnodeafter(k1,n1);
        break;

        case 4:
        cout<<"Enter key to delete value\n";
        cin>>k1;
        s.deleteNodeByKey(k1);
        break;

        case 5:
        cout<<"Enter key and data to Update node\n";
        cin>>key1;
        cin>>data1;
        s.updateNodeByKey(key1,data1);
        break;

        case 6:
        s.printList();
        break;

        case 7:
        system("cls");
        break;

        default:
        cout<<"Enter proper number\n";
    }

}while(option!=0);

    return 0;
}

 