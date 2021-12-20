/*
Write a program to implement queue concept.
Completed!
*/

#include<iostream>
using namespace std;

class queue{
    int f,r,size;
    int q[20];
    public:
    queue(int n){
        f=-1; r=-1; size=n;
    }
    void insert(int e){
        if(r==size-1)
        cout<<"Queue is full"<<endl;
        else
        q[++r]=e;
    }
    int remove(){
        if(r==f){
        cout<<"Queue is empty"<<endl;
        return 0;
        }
        else
        return(q[++f]);
    }
    void disp(){
        if(r==f)
        cout<<"Queue is empty"<<endl;
        else{
        for(int i=r;i>f;i--)
        cout<<q[i]<<" ";
        cout<<endl;
        }
    }
};

int main(){
    int n,input,ele;
    cout<<"Enter the size of the queue:";
    cin>>n;
    queue q(n);
    while(1){
        cout<<"1-Insert 2-Remove 3-Disp 4-Exit: ";
        cin>>input;
        if(input==4)
        break;
        switch(input){
            case 1: cin>>ele; q.insert(ele); break;
            case 2: cout<<q.remove()<<" is removed."<<endl; break;
            case 3: q.disp(); break;
            default: break;
        }
    }
    return 0;
}