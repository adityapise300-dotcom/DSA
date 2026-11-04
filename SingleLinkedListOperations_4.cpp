#include<iostream>
#include<string>
using namespace std;

struct node{
    int data;
    node*next;
};

class SingleLinkedList{
    node*head = NULL;
    node*tail = NULL;

    public:
        void createList(int d);
        void displayList();
        void insertFirst();
        void insertLast();
        void insertByPos();
        void insertByVal();
        void deleteFirst();
        void deleteLast();
        void deleteByPos();
        void deleteByVal();
        void search();
        void reverseList();
        void findMiddle();
        ~SingleLinkedList();
};

void SingleLinkedList::createList(int d){
    node* temp = new node;
    temp->data = d;
    temp->next = NULL;

    if(head==NULL){
        head = tail = temp;
    }else{
        tail->next = temp;
        tail = temp;
    }
}

void SingleLinkedList::displayList(){
    if(head==NULL){
        cout<<"List is Empty"<<endl;
        return;
    }
    node* temp1 = head;
    while(temp1==NULL){
        cout<<temp1->data<<" ";
        temp1 = temp1->next;
    }
    cout<<endl;
}

void SingleLinkedList::insertFirst(){
    node*temp = new node;
    int d;
    cout<<"Value for new node: ";
    cin>>d;
    temp->data = d;
    temp->next = head;
    head = temp;
}

void SingleLinkedList::insertLast(){
    node*temp = new node;
    int d;
    cout<<"Value of new node: ";
    cin>>d;
    temp->data = d;
    if(head == NULL){
        head = tail = temp;
    }else{
        tail->next = temp;
        tail = temp;
    }
}

void SingleLinkedList::insertByPos(){
    int pos,d;
    cout << "Enter the data for the new node : ";
    cin >> d;
    cout << "Enter the position for the new node : ";
    cin >> pos;
    node*temp = new node;
    temp->data = d;
    node*temp1 = head;
    int count = 1;
    while(count == pos-1){
        temp1 = temp->next;
        count++;
    }
    temp->next = temp1->next;
    temp1->next = temp;
}

void SingleLinkedList::insertByVal(){
    int d,val;
    cout << "Enter the data for the new node : ";
    cin >> d;
    cout << "Enter the value of the node after which you want to inseert the new one : ";
    cin >> val;
    node*temp = new node;
    temp->data = d;
    node*temp1 = head;
    while(temp1->data != val){
        temp1 = temp1->next;
    }
    temp->next = temp1->next;
    temp1->next = temp;
}

void SingleLinkedList::deleteFirst(){
    node*temp = head;
    node*temp1 = temp;
    temp = temp->next;
    head = temp;
    temp1->next = NULL;
    delete temp1;
}

void SingleLinkedList::deleteLast(){
    node*temp = head;
    node*temp1;
    while(temp->next != NULL){
        temp1 = temp;
        temp = temp->next;
    }
    temp1->next = NULL;
    temp->next = NULL;
    delete temp;
}

void SingleLinkedList::deleteByPos(){
    node*temp = head;
    node*temp1 = head;
    int count = 1;
    int pos;
    cout<<"Node at what position do you want to delete : "; 
    cin>>pos;
    while(temp->next != NULL){
        if(count == pos){
            temp1->next = temp->next;
            temp->next = NULL;
            delete temp;
            return;
        }else{
            temp1=temp;
            temp = temp->next;
            count++;
        }
    }
}

void SingleLinkedList::deleteByVal(){
    node*temp = head;
    node*temp1 = head;
    int val;
    cout<<"Enter the value you want to delete: ";
    cin>>val;
    while(temp->next != NULL){
        if(temp->data == val){
            temp1->next = temp->next;
            temp->next = NULL;
            delete temp;
            return;
        }else{
            temp1 = temp;
            temp = temp->next;
        }
    }
}

void SingleLinkedList:: search(){
    node*temp1 = head;
    int val;
    cout<<"Enter the value you want to search: ";
    cin>>val;
    int count = 1;
    while(temp1->data != val){
        temp1 = temp1->next;
        count++;
    }
    cout<<"This node was found at position:"<<count<<endl;
}

void SingleLinkedList :: reverseList(){
    node *prev, *curr, *nxt;
    prev = NULL;
    curr = head;
    while(curr!=NULL){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }

    head = prev;
}

void SingleLinkedList :: findMiddle(){
    if(head == NULL) {
        cout << "List is empty";
        return;
    }
    node*temp1 = head;
    node*temp = head;
    int count = 0;

    while(temp1!=NULL){
        temp1=temp1->next;
        count++;
    }
    int search = 1;
    while(search!=count/2){
        temp=temp->next;
        search++;
    }
    cout<<"Value of middle node is: "<<temp->data<<endl;
}

int main(){
    int n, choice, subchoice, temp;
    SingleLinkedList L;
    char cont;

    cout<<"How many elements do you want in the list ? : "; 
    cin>>n;
    
    for(int i=0; i<n; i++){
        cin>>temp;
        L.createList(temp);
    }

    cout<<"Current Linked List: ";
    L.displayList();

   do{  
        cout<<"1. Insertion\n2. Deletion\n3. Search\n4. Reverse\n5. Display "<<endl; 
        cout<<"Which opertion do you want to perform : "; 
        cin>>choice; 

        switch(choice){ 
        case 1: 
        cout<<"1 Insert at first position\n2 Insert at last position\n3 Insert at any position\n4 Insert after any value"<<endl; 
        cout<<"Choose the operation : "; 
        cin>>subchoice; 
        switch(subchoice){ 
            case 1: 
            L.insertFirst(); 
            L.displayList(); 
            break; 
            case 2: 
            L.insertLast(); 
            L.displayList(); 
            break; 
            case 3: 
            L.insertByPos(); 
            L.displayList(); 
            break; 
            case 4: 
            L.insertByVal(); 
            L.displayList(); 
            break; 
            default: 
            cout<<"Invalid Choice!"<<endl; 
            break; 
        } 
        break; 
        case 2: 
        cout<<"1 Delete the head\n2 Delete the tail\n3 Delete by position\n4 Delete by value"<<endl; 
        cout<<"Choose the operation : "; 
        cin>>subchoice; 
        switch(subchoice){ 
            case 1: 
            L.deleteFirst(); 
            L.displayList(); 
            break; 
            case 2: 
            L.deleteLast(); 
            L.displayList(); 
            break; 
            case 3: 
            L.deleteByPos(); 
            L.displayList(); 
            break; 
            case 4: 
            L.deleteByVal(); 
            L.displayList(); 
            break; 
            default: 
            cout<<"Invalid Choice!"<<endl; 
            break; 
        } 
        break; 
        case 3: 
        L.search(); 
        break; 
        case 4: 
        L.reverseList(); 
        L.displayList(); 
        break; 
        case 5: 
        L.displayList(); 
        break; 
        default: 
        cout<<"Invalid Choice!"; 
        break; 
       }

      cout<<"Do you want to continue>(y/n): ";
      cin>>cont;
    }while(cont=='Y'||cont=='y');

    return 0;
}