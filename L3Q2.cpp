/*
Write a program to find the fast transpose of a sparse matrix represented using array of objects.
*/

#include<iostream>
using namespace std;
#define MAX 100

const int Max_Col=6;
class spm{
    public:
        int row, col, val;
        void read(spm a[], int m, int n){
            int i, j, k, item, p;
            a[0].row = m;
            a[0].col = n;
            k = 1;
            cout<<"\nEnter the elements:\n";
            for(i=0; i<m; i++){
                for(j=0; j<n; j++){
                    cin>>item;
                    if(item == 0)
                    continue;
                    a[k].row = i;
                    a[k].col = j;
                    a[k].val = item;
                    k++;
                    }
                    }
                    a[0].val = k-1;
                    cout<<"\nThe entered sparse matrix is:\n";
                    cout<<"\nRow\tColumn\tValue\n";
                    for(p=0;  p<=a[0].val;  p++){
                        cout<< a[p].row<<"\t";
                        cout<<a[p].col<<"\t";
                        cout<<a[p].val<<"\n";
                        }
                        }
        
        void fast_transpose(spm a[], spm b[]){
            int row_terms[Max_Col], starting_pos[Max_Col];
            int i,j,num_cols=a[0].col, num_terms=a[0].val;
            b[0].row=num_cols;
            b[0].col=a[0].row;
            b[0].val=num_terms;
            if(num_terms>0){
                for(i=0;i<num_cols;i++){
                    row_terms[i]=0;
                }
                for(i=1;i<num_terms;i++){
                    row_terms[a[i].col]++;
                }
                starting_pos[0]=1;
                for (i = 1; i < num_cols; i++){
                    starting_pos[i]=starting_pos[i-1]+row_terms[i-1];
                }
                for(i=1;i<num_terms;i++){
                    j=starting_pos[a[i].col]++;
                    b[j].row=a[i].col;
                    b[j].col=a[i].row;
                    b[j].val=a[i].val;
                }
                
            }
            cout<<"\nThe Fast Transpose sparse matrix is:\n";
            cout<<"\nRow\tColumn\tValue\n";
            for(int p=0; p<=a[0].val; p++){
                cout<< b[p].row<<"\t";
                cout<<b[p].col<<"\t";
                cout<<b[p].val<<"\n";
            }
        }
     };

int main(){
    int m, n;
    spm a[MAX], b[MAX],tr;
    cout<<"Enter  the no of rows and columns:";
    cin>>m>>n;
    tr.read(a, m, n);
    tr.fast_transpose(a, b);
    return 0;
}