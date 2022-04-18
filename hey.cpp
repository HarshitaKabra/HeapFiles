#include <bits/stdc++.h>
#include <string>
#define ll  long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define base 1000000007
#define rep(i,a,n)    for(ll  i=a;i<n;i++)
#define inf LLONG_MAX
 
using namespace std;
 
void fast()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int N;

struct page{
    public:
    struct page* previous=nullptr;
    struct page* next=nullptr;
    int count=0;
    int left=0;
    int* point=new int[N/4+1];
};

class lists{
   public:
     struct page* root=nullptr;
     
     void insert(ll a,ll b){
         struct page* current=root;
         while(1){
             if(current==nullptr){
                 struct page* brand_new=new page;
                 brand_new->previous=current;
                 current=brand_new;
                 root=current;
                 break;
             }
             if(N-current->left>=a+4){
                break;
             }
             else{
                 if(current->next==nullptr){
                    struct page* brand_new=new page;
                    current->next=brand_new;
                    brand_new->previous=current;
                    current=brand_new;
                 }
                 else{
                     current=current->next;
                 }
             }
         }

         current->point[current->count]=b;
         current->left+=(a+4);
         current->count++;

     }

     void search(ll a){
        struct page* current=root;
        ll page_no=0;

        while(1){
           if(current==nullptr){
               cout<<"-1 -1"<<endl;
               break;
           }
           else{
              bool t=0;
              for(int x=0;x<current->count;x++){
                  if(current->point[x]==a){
                      t=1;
                      cout<<page_no<<" "<<x<<endl;
                      break;
                  }
              }
              if(t==0){
              current=current->next;
              page_no++;
              }
              else
              break;


           }
        }


     }

     void status(){
        vector<ll>v;
        struct page* current=root;
        while(current!=nullptr){
            v.pb(current->count);
            current=current->next;
        }

        cout<<v.size()<<" ";
        for(auto it:v){
            cout<<it<<" ";
        }
        cout<<endl;


     }

     


};





int main(){
     fast();
     cin>>N;
     N-=16;
     lists obj;
     while(1){
         ll a;
         cin>>a;
         if(a==2){
             obj.status();
         }
         else if(a==1){
             ll a1,a2;
             cin>>a1>>a2;
             obj.insert(a1,a2);
         }
         else if(a==3){
             ll a1;
             cin>>a1;
             obj.search(a1);
         }
         else{
             break;
         }

     }










}