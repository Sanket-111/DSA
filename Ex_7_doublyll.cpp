# include <bits/stdc++.h>
using namespace std;
// initiating the circular linked list 
class ll{
public:
    ll *next;
    ll *prev;
    int data;
};
// To display the circular linked list 
void display(ll *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<"\n";
}
// inserting in a linked list 
ll* insert (ll * head,int d,int pos){
    int i=1;
    ll *in=new ll;
    ll *at=new ll;
    at=head;
    in->data=d;
    while(head!=NULL){
        //  to insert at first position 
        if(pos==1){
            in->next=head;
            in->prev=NULL;
            head->prev=in;
            at=in;
            break;
        }
        // to insert at position from second to end of ll
        else if(i==(pos-1)){
            in->next=head->next;
            in->prev=head;
            head->next=in;
            break;
        }
        head=head->next;
        i++;
    }
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
            head->prev=NULL;
            in=head;
        }
    // deleting at any other position than first position 
    else{
    while(at!=NULL){
    
         if(i==pos){
            (at->next)->prev=head;
            head->next=at->next;
        }
        head=head->next;
        at=at->next;
        i++;
    }}
    return in;
}
// main function 
int main(){
    ll* first=new ll;
    ll* second=new ll;
    ll* third=new ll;

    first->data=34;
    first->prev=NULL;
    first->next=second;

    second->data=56;
    second->prev=first;
    second->next=third;

    third->data=4;
    third->next=NULL;
    third->prev=second;

    display(first);
    // to insert the data in a circular ll
    first=insert(first,55,4);
    first=insert(first,89,4);
    first=del(first,1);
    display(first);
    return 0 ;
}