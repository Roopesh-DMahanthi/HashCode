#include<bits/stdc++.h>
using namespace std;

struct library
{
    long int nob;
    long int sign;
    long int perd;
    vector<long int> books;
};

void showq(queue <long int> gq) 
{ 
    queue <long int> g = gq; 
    while (!g.empty()) 
    { 
        cout << '\t' << g.front(); 
        g.pop(); 
    } 
    cout << '\n'; 
} 

int main()
{
    long int bks,libs,days,i=0,j;
    cin>>bks>>libs>>days;
    vector<long int> scr;

    for(i=0;i<bks;i++)
    {
        long int tp;
        cin>>tp;
        scr.push_back(tp);
    }

    

    vector<library> li;
    vector<long int> signupset;
    queue<long int> order;
    for(i=0;i<libs;i++)
    {
        long int p1,p2,p3;
        cin>>p1>>p2>>p3;
        library n1;
        n1.nob=p1;
        n1.sign=p2;
        n1.perd=p3;
        signupset.push_back(p2);
        for(j=0;j<p1;j++)
        {
            long int tp;
            cin>>tp;
            n1.books.push_back(tp);
        }
        li.push_back(n1);
    }

    for(i=0;i<libs;i++)
    {
        long int indi=min_element(signupset.begin(),signupset.end())-signupset.begin();
        signupset[indi]=INT_MAX;
        //cout<<indi<<endl;
        order.push(indi);
    }

    //showq(order);

    //print
    /*
    for(i=0;i<libs;i++)
    {
        cout<<li[i].nob<<" "<<li[i].sign<<" "<<li[i].perd<<endl;
        for(j=0;j<li[i].nob;j++)
        {
            cout<<li[i].books[j]<<" ";
        }
        cout<<endl;
    }
    */    

    vector<long int> slib;

    while(days--){
        
    }
    
}