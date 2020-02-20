#include<bits/stdc++.h>
using namespace std;

struct library
{
    long int nob;
    long int sign;
    long int perd;
    queue<long int> books;
};

struct ans
{
    long int liv;
    long int nob;
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
    vector<long int> scrord;
    multimap<long int, long int, std::greater<int> > scr;
    multimap<long int, long int, std::greater<int> > :: iterator itr;
    for(i=0;i<bks;i++)
    {
        long int tp;
        cin>>tp;
        //scr.push_back(tp);
        scr.insert(make_pair(tp,i));
    }

    for (itr=scr.begin();itr!=scr.end();itr++)
    {
        //cout << itr->second << " " ;
        scrord.push_back(itr->second);
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
        set<long int> b;
        for(j=0;j<p1;j++)
        {
            long int tp;
            cin>>tp;
            //n1.books.push_back(tp);
            b.insert(tp);
        }
        for(j=0;j<scrord.size();j++){
            if(b.find(scrord[j])!=b.end())
                n1.books.push(scrord[j]);
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

    showq(order);

    //print
    
    cout<<endl;
    for(i=0;i<libs;i++)
    {
        cout<<li[i].nob<<" "<<li[i].sign<<" "<<li[i].perd<<endl;
        queue<long int> b=li[i].books;
        while(b.size()!=0)
        {
            cout<<b.front()<<" ";
            b.pop();
        }
        cout<<endl;
    }
    

    vector<long int> slib;
    //vector<long int> :: iterator it;
    long int signedlib=0;
    vector<ans> answer;

    while(days>0){
        days--;
        
        if(!order.empty()){
        if(li[order.front()].sign==0){
            signedlib++;
            ans tp;
            tp.liv=order.front();
            slib.push_back(order.front());
            order.pop();
            
            answer.push_back(tp);
            cout<<days<<" "<<answer.size()<<" "<<li[order.front()].sign<<" "<<signedlib<<endl;
            cout<<"`"<<order.empty()<<endl;
            
            if(order.empty()){
                //cout<<"true";
                days++;
                continue;
            }
            //cout<<"\norder\n";
            //showq(order);
            
            li[order.front()].sign--;
            
        }
        else{
            cout<<days<<" "<<answer.size()<<" "<<li[order.front()].sign<<" "<<signedlib<<endl;
            li[order.front()].sign--;
            
        }
        }
        
        for(long int indx=0;indx<slib.size();indx++){
            long int d=li[slib[indx]].perd;
            long int lii;
            for(i=0;i<answer.size();i++){
                if(answer[i].liv==indx)
                    lii=i;
            }
            while(d--){
                answer[i].nob++;
                answer[i].books.push_back(li[slib[indx]].books.front());
                li[slib[indx]].books.pop();
            }
        }
        
    }

    cout<<"\nAnswer\n";
    cout<<signedlib<<endl;
    for(i=0;i<answer.size();i++){
        cout<<answer[i].liv<<" "<<answer[i].nob<<endl;
        for(j=0;j<answer[i].books.size();j++){
            cout<<answer[i].books[j]<<" ";
        }
        cout<<endl;
    }
      
}