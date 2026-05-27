#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool can(ll a,ll b,ll c,char start){
    ll blocks=c+1;
    ll lblock=0,qblock=0;


    if(start=='l'){
        lblock=(blocks+1)/2;
        qblock=blocks/2;
    }else{
        qblock =(blocks+1)/2;
        lblock=blocks/2;
    }

    return (a>=lblock && b>=qblock);
}

string build(ll a, ll b,ll c,char start){
    ll blocks=c+1;
    ll lblock=0,qblock=0;

    if(start=='l'){
        lblock=(blocks+1)/2;
        qblock=blocks/2;
    }else{
        qblock =(blocks+1)/2;
        lblock=blocks/2;
    }

 


    string ans;
    ans.reserve(a+b);

    char  cur=start;

    for(ll i=1;i<=blocks;i++){
        if(cur=='l'){
            ll len=a-(lblock-1);
            ans.append(len,'L');

            lblock--;
            a-=len;
            cur='q';
        }else{
            ll len;
            if(qblock==1){
                len=b;
            }else{
                len=1;
            }

            ans.append(len,'Q');

            qblock--;
            b-=len;
            cur='l';
        }
    }

    return ans;

}

int main(){
    ll a,b,c;

    cin >> a >> b>>c;

    if(a==0){
        if(c==0){
            cout << string(b,'Q')<< endl;

        }else{
            cout << -1 << endl;
        }
        return 0;
    }

    if(b==0){
        if(c==0){
            cout << string(a,'L')<< endl;

        }else{
            cout << -1 << endl;
        }
        return 0;
    }

    if(c==0){
        cout<< -1 << endl;
        return 0;
    }

    ll mx;
    if(a==b){
        mx=2*a-1;
    }else{
        mx=2*min(a,b);
    }

    if(c>mx){
        cout<<-1<< endl;
        return 0;
    }


    if(can(a,b,c,'l')){
        cout << build(a,b,c,'l');
    }else  if(can(a,b,c,'q')){
        cout << build(a,b,c,'q');
    }else{
        cout << -1 << endl;
    }


    return 0;
}