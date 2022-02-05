# include <bits/stdc++.h>
using namespace std;
// initiating the circular linked list 
class ll{
public:
    ll *next;
    int data;
};

// display ll
void display(ll * head){
    ll* at=head;
    do{
        cout<<head->data<<" ";
        head=head->next;
    }while(head!=at);
    cout<<"\n";
}

// inserting in a linked list 
ll* insert (ll * head,int d,int pos){
    int i=1;
    ll *in=new ll;
    ll *at=new ll;
    at=head;
    in->data=d;
        //  to insert at first position
        if(pos==1){
            in->next=head->next;
            head->next=in;
            return in;
        } 
    else{
        do{

        // to insert at position from second to end of ll
      if(i==(pos-1)){
            in->next=head->next;
            head->next=in;
            break;
        }
        head=head->next;
        i++;
    }while(head!=at);}
    return at;
}
// deleting in a doubly ll
ll* del(ll* head ,int pos){
    ll *at=new ll;
    ll *in=new ll;
    in=head;
    at=head->next;
    int i=2;
    // deleting at the top of ll
    if(pos==1){
            head=head->next;
            in=head;
        }
    // deleting at any other position than first position 
    else{
    do {
    
         if(i==pos){
            head->next=at->next;
        }
        head=head->next;
        at=at->next;
        i++;
    }while(at!=NULL);
    }
    return in;
}

// main function
int main(){
    ll* first=new ll;
    ll* second=new ll;
    ll* third=new ll;

    first->data=34;
    first->next=second;

    second->data=56;
    second->next=third;

    third->data=4;
    third->next=first;
   
    display(first);
    first=insert(first,25,1);
    display(first);
    first=del(first,2);
    display(first);
    return 0;
}