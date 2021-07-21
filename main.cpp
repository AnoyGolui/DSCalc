#include<bits/stdc++.h>
using namespace std;




//quicksort
void quickSort(int number[25],int first,int last)
{int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
            i++;    
         while(number[j]>number[pivot])
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quickSort(number,first,j-1);
      quickSort(number,j+1,last);

   }

}



//insert element in an array
void arIn(int arr[],int n,int option){
    int i,num,pos;
    if(option==1){
        cout<<"Enter the number to be inserted: ";
        cin>>num;
        cout<<"Enter the position at which the has to be inserted: ";
        cin>>pos;
        for(i=n-1;i>=pos;i--)
            arr[i+1]=arr[i];
        arr[pos]=num;
        n=n+1;
        for(i=0;i<n;i++)
            cout<<"|"<<arr[i]<<"| ";
    }
    else if(option==2){

    }
    

}



void arinsert(int arr[],int n){
    int option;
    do{
        cout<<"\n======================================\n 1.Insert elements into given location\n 2.Insert element in an already sorted array\n 3.Go back";
        cout<<"\nEnter your option: ";
        cin>>option;
        switch (option)
        {
        case 1:arIn(arr,n,option);
            
            break;
        case 2:arIn(arr,n,option);
            
            break;
        }
    }while(option!=3);
        
}


//delete element from array
void ardelete(int arr[],int n){
};



void checkPos(int arr[],int n){
    
    int elem;

    cout<<"Enter the element to be search: ";
    cin>>elem;
    
    int i = 0;
    while (i < n)
    {
        if (arr[i] == elem) {
            break;
        }
        i++;
    }
 
    if (i < n)
    {
        cout << "\nElement " << elem << " is present at position " << i
             << " in the given array";
    }
    else {
        cout << "\nElement is not present in the given array";
    }
 
}




//operation in array
void arcon(int arr[],int n){
    int option;
    do{
        cout<<"\n======================================\n 1.Insertion\n 2.Deletion\n 3.Check position\n 4.Go Back\n======================================\n";
        cout<<"Enter your option: ";
        cin>>option;
        switch(option){
        case 1: arinsert(arr,n);
                break;
        case 2: ardelete(arr,n);
                break;
        case 3:checkPos(arr,n);
        }
    }while(option!=4);
}



//making a array
void arr(){
    int ar[100],n,i;
    cout<<"Enter the size of the array: ";
    cin>>n;
    cout<<"Enter the elements: \n";
    for(i=0;i<n;i++){
        cout<<"arr["<<i<<"] = ";
        cin>>ar[i];
    }
    char op;
    cout<<"\nDo you want sort the array?(y/n) ";
    cin>>op;
    if(op=='y'){
        quickSort(ar,0,n-1);
        for(i=0;i<n;i++)
            cout<<" "<<ar[i];
    }
    else if(op=='n')
        cout<<"never mind";
    arcon(ar,n);

}





//make a singly linked List
class NodeL{ 
    public:
    int data;
    NodeL *next;
};
void pushL(NodeL** headL ,int new_data){
    NodeL* new_node = new NodeL();
    new_node->data = new_data;
    new_node->next = (*headL);
    (*headL) = new_node;
}


void insertAfterL(NodeL* prev, int new_data){
    if(prev == NULL){
        cout<<"The previous number cannot be NULL";
        return;
    }
    NodeL* new_node = new NodeL();
    new_node->data = new_data;
    new_node->next = prev->next;
    prev->next = new_node;
}



void appendL(NodeL** headL,int new_data){
    NodeL* new_node = new NodeL();
    NodeL* last = *headL;

    new_node->data = new_data;
    new_node->next = NULL;

    if(*headL ==NULL){
        *headL = new_node;
        return;
    }

    while(last->next!=NULL)
        last = last->next;

    last->next = new_node;
    return;
}


void deleteNodeL(NodeL** head,int ele){
    NodeL* temp = *head;
    NodeL* prev = NULL;

    if(temp!= NULL && temp->data == ele){
        *head = temp->next;
        delete temp;
        return;
    }
    else{
        while(temp!=NULL && temp->data!=ele){
            prev =temp;
            temp = temp->next;
        }
        if(temp==NULL)
            return;
        prev->next = temp->next;
        delete temp;
    }
}


void printList1(NodeL* node){
    while(node!=NULL){
        cout<<" "<<node->data;
        node = node->next;
    }
}



void list1(){
    NodeL* head = NULL;
    int n,a;
    
    do
    {
        cout<<"\n1. Push element\n2. Append element\n3. Insert after element\n4. Delete an element\n5. Print the LinkedList\n6. Exit\n";
        cout<<"Enter your opration: ";
        cin>>n;
        switch (n)
        {
            case 1:cout<<"\nEnter the element to be pushed: ";
                cin>>a;
                pushL(&head,a); break;
            case 2:cout<<"\nEnter the element to be append: ";
                cin>>a;
                appendL(&head,a); break;
            case 3:cout<<"\nEnter the element to be insert after: ";
                cin>>a;
                insertAfterL(head->next,a); break;
            case 4:cout<<"\nEnter the element to be deleted: ";
            cin>>a;
                deleteNodeL(&head,a); break;
            case 5:printList1(head); break;
        }  
    } while(n!=6);
    
    
}



//make a circular linkedList
struct NodeC{
    int data;
    struct NodeC* next;
};

struct NodeC *addToEmpty(struct NodeC* last,int data){
    if(last!= NULL)
        return last;
    struct NodeC* temp = (struct NodeC*)malloc(sizeof(struct NodeC));

    temp->data = data;
    last = temp;

    last->next = last;

    return last;
}



struct NodeC *addBegin(struct NodeC *last,int data){
    if(last == NULL)
        return addToEmpty(last,data);
    struct NodeC *temp = (struct NodeC*)malloc(sizeof(struct NodeC));

    temp->data = data;
    temp->next = last->next;
    last->next = temp;

    return last;
}



struct NodeC *addEnd(struct NodeC *last,int data){
    if(last==NULL)
        return addToEmpty(last,data);
    
    struct NodeC* temp = (struct NodeC *)malloc(sizeof(struct NodeC));
    temp->data = data;
    temp->next = last->next;
    last->next = temp;
    last = temp;

    return last;
}



struct NodeC *addAfter(struct NodeC *last,int data,int item){
    if(last==NULL)
        return NULL;
    
    struct NodeC *temp, *p;
    p = last->next;
    do{
        if(p->data == item){
            temp = (struct NodeC *)malloc(sizeof(struct NodeC));
            temp->data = data;
            temp->next = p->next;
            p->next = temp;

            if(p=last)
                last = temp;
            return last;
        }
        p=p->next;
    }while(p!= last->next);

    cout<<item<<" not present in the List."<<endl;
}


void printList2(struct NodeC *last){
    struct NodeC *p;
    if(last==NULL){
        cout<<"List is empty."<<endl;
        return;
    }
    p = last->next;
    do{
        cout<<p->data<<" ";
        p = p ->next;
    }while(p!=last->next);
}



void list2(){
    NodeC * last = NULL;
    int n,a,b;
    
    do
    {
        cout<<"\n1. Add element at Front\n2. Add element to the end\n3. Add element after a element\n4. Print the Circular LinkedList\n";
        cout<<"Enter your opration: ";
        cin>>n;
        switch (n)
        {
            case 1:cout<<"\nEnter the element to be added front: ";
                cin>>a;
                last=addBegin(last,a); break;
            case 2:cout<<"\nEnter the element to be added rear: ";
                cin>>a;
                last=addEnd(last,a); break;
            case 3:cout<<"\nEnter the before element: ";
            cin>>b;
            cout<<"\nEnter the element to be add after "<<b<<" element: ";
                cin>>a;
                last=addAfter(last,a,b); break;
            case 4:printList2(last); break;
        }  
    } while(n!=5);
    
}



//main list
void list0(){
    int option;
    do{
        cout<<"\n 1.Make a Singly linked list\n 2.Make a Circular linked list\n 3.Exit\n";
        cout<<"Enter your option: ";
        cin>>option;
        switch(option){
            case 1: list1(); break;
            case 2: list2(); break;
        }
    }while(option!=3);
}



//main function
int main()
{
    int option;
    do{
    
    cout<<"================WELCOME TO THE CALQ================\n1.Array\n2.String\n3.Linked list\n4.Stack\n5.Queue\n6.Tree\n7.Graph\n8.Calculator\n9.Number Conversion\n===================================================\nEnter your option: ";
    cin>>option;
    switch (option)
    {
    case 1: arr(); break;
    case 3: list0(); break;
    }
    }while(option!=10);
    return 0;
}
