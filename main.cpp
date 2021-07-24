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

//stack
class STACK{
    int num[100];
    int top;
    public:
        STACK();
        int pushS(int);
        int popS();
        int isEmptyS();
        int isFullS();
        void displaySt();
};

struct stackLi{
    int data;
    stackLi *link;
};

stackLi *top = NULL;

bool isempty()
{
 if(top == NULL)
 return true; else
 return false;
}

void pushLSt(int val){
    stackLi *ptr = new stackLi();
    ptr->data = val;
    ptr->link = top;
    top = ptr;
}

void popLSt(){
    if(isempty())
        cout<<"Stack is Empty";
    else
        {
            stackLi *ptr = top;
            top = top->link;
            delete(ptr);
        }
}
void dispTop(){
    if(isempty())
        cout<<"Stack is Empty";
    else
        cout<<"The top element is "<<top->data;
}

void displayLSt(){
    if(isempty())
        cout<<"Stack is empty";
    else{
        stackLi *temp =top;
        while(temp!=NULL){
            cout<<"|"<<temp->data<<"|"<<endl;
            temp = temp->link;
        }
    }
}
STACK::STACK(){
    top=-1;
}
int STACK::isEmptyS(){
    if(top==-1)
        return 1;
    else    
        return 0;
}

int STACK::isFullS(){
    if(top==(100-1))
        return 1;
    else
        return 0;

}

int STACK::pushS(int n){
    if(isFullS())
        return 0;
    ++top;
    num[top]=n;
    return n;
}

int STACK::popS(){
    int temp;
    if(isEmptyS())
        return 0;
    temp=num[top];
    --top;
    return temp;
}

void STACK::displaySt(){
    for(int i=(top);i>=0;i--)
        cout<<"|"<<num[i]<<"|"<<endl;
}
void StackLinked(){
    int choice,flag=1,val;
    while(flag==1){
        cout<<"1.Push an item into the stack\n2.Pop an item from the stack\n3.Display the stack\n4.Display the top\n5.Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch (choice)                 
        {
        case 1:
            cout<<"\nEnter the value to be inserted: ";
            cin>>val;
            break;
        case 2:popLSt();
                break;
        case 3:displayLSt();
                break;
        case 4:dispTop();
                break;
        
        case 5: flag = 0;
                break;
        default:
            cout<<"Invalid";
            break;
        }
    }
}
void StackN(){
    int choice,n,temp,val;
    STACK stk;
    do{
        cout<<endl;
        cout<<"1.Push an item into the stack\n2.Pop an item from the stack\n3.Display the stack\n4.Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"\nEnter item to insert: ";
            cin>>n;
            temp=stk.pushS(n);
            if(temp==0)
                cout<<"Stack is Full"<<endl;
            else    
                cout<<"Item inserted";
            break;
        case 2:val=stk.popS();
               if(val!=-1)
                    cout<<"\nThe value removed from the stack is "<<val;
                break;
        case 3:stk.displaySt();
                break;
        default:
            cout<<"\nAn Invalid choice.";
            break;
        }
    }while(choice!=4);
}



//Fuction to return precedence of operators
int prec(char c){
    if(c=='^')
        return 3;
    else if(c=='/'|| c=='*')
        return 2;
    else if(c=='+'|| c=='-')
        return 1;
    else
        return -1;
}

void inToPo(string s){
    stack<char> st;
    string result;

    for(int i=0;i<s.length();i++){
        char c = s[i];

        if((c>='a'&& c<='z')|| (c>='A' && c<='Z') || (c>='0' && c<='9'))
            result +=c;
        else if(c=='(')
            st.push('(');
        else if(c==')'){
            while(st.top()!='('){
                result+= st.top();
                st.pop();
            }
            st.pop();
        }

        else{
            while(!st.empty() && prec(s[i]) <=prec(st.top())){
                result+=st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()){
        result += st.top();
        st.pop();
    }
    cout<<result<<endl;
}
void infixTopostfix(){
    string exp ;
    cout<<"Enter infix expression: ";
    cin>>exp;
    inToPo(exp);
}


//main stack


void stackMain(){
    int choice;
    do{
    cout<<"\nWhat type of Stack do you want to make?\n1.Normal stack\n2.Stack using Linked list\n3.Convert infix to postfix\n4.Exit";
    cout<<"\nEnter your option: ";
    cin>>choice;
    switch (choice)
    {
    case 1:
        StackN();
        break;
    case 2:StackLinked();
        break;
    case 3:infixTopostfix();
        break;
    default:
        cout<<"Invalid";
        break;
    }
    }while(choice!=4);
}
//Tree Part
struct Tr{
    int data;
    struct Tr *left, *right;
    Tr(int data){
        this->data = data;
        left = right = NULL;
    }
};
void printPostorder(struct Tr* node){
    if(node==NULL)
        return;
    
    //first recur on left subtree
    printPostorder(node->left);

    //then recur on right subtree
    printPostorder(node->right);

    //now deal with the node
    cout<<node->data<<"| ";
}

void printInorder(struct Tr* node){
    if(node==NULL)
        return;

    //first recur on left child
    printInorder(node->left);

    //Then print the data of node
    cout<<node->data<<"| ";

    //now recur on right child
    printInorder(node->right);

}

void printPreorder(struct Tr* node){
    if(node==NULL)
        return;

    //first print data of node
    cout<<node->data<<"| ";

    //then recur on left stree
    printPreorder(node->left);

    //now recur on right subtree
    printPreorder(node->right);
}
void inputTRele(struct Tr* root){
      int o;
      char op,y,n;
      cout<<"Enter which side you want to input data: ";
      cin>>op;
      if(op=='l'){
        cout<<"Enter the data: ";
        cin>>o;
        root->left=new Tr(o);
        cout<<"Do you want input more data(y/n): ";
        cin>>op;
        if(op=='y')
            inputTRele(root->left);
        else {
            return;
        }
    }
    else if(op=='r'){
        cout<<"Enter the data: ";
        cin>>o;
        root->right=new Tr(o);
        cout<<"Do you want input more data(y/n): ";
        cin>>op;
        if(op=='y')
            inputTRele(root->right);
        else {
            return;
        }
    }
        
}
//main tree
void Ttraversal(struct Tr* root){
    int n;
    char op;
    cout<<"Enter the root node: ";
    cin>>n;
    root=new Tr(n);
    cout<<"Do you want to enter anymore data(y/n): ";
    cin>>op;
    if(op=='y'){
      inputTRele(root);  
    }
    else if(op=='n')
        return;
}
void mTree(){
    struct Tr* root;
    char op;
    cout<<"Do you want to Traverse a array: ";
    cin>>op;
    if(op=='y')
        Ttraversal(root);
    else if(op=='n')
        return;
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
    case 4: stackMain();break;
    case 6: mTree(); break;
    }
    }while(option!=10);
    return 0;
}
