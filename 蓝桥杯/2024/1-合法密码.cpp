#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main()
{
    string s="kfdhtshmrw4nxg#f44ehlbn33ccto#mwfn2waebry#3qd1ubwyhcyuavuajb#vyecsycuzsmwp31ipzah#catatja3kaqbcss2th";

    ll res=0;
    ll len=s.size();

    for(ll i=0;i<len;i++){
        for(ll j=8;j<=16;j++){
            if(i+j>len) continue;

            bool hasdight=false;
            bool hassymbol=false;


            for(ll k=i;k<i+j;k++){
                if(isdigit(s[k]))  hasdight=true;
                else if(!isalpha(s[k]))  hassymbol=true;
            }

            if(hasdight&& hassymbol) res++;
        }
    }


    cout<< res;



    return 0;
}