#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define profit first
#define weight second
using namespace std;
void inputKnapsack(vector<pair<ll,ll>>&a,ll items){
	for(ll i=0;i<items;i++){
		ll p,w;
		cout<<"Enter profit of "<<i+1<<" item\n";
		cin>>p;
		cout<<"Enter weight of "<<i+1<<" item\n";
		cin>>w;
		a.push_back({p,w});
	}	
}
ld knapsackLogic(vector<pair<ll,ll>>a,ll items,ll maxCapacity){
	ld maxProfit=0.0;
	for(ll i=0;i<items;i++){
		if(a[i].weight<=maxCapacity){
			maxProfit+=a[i].profit;
			maxCapacity-=a[i].weight;
		}else{
			maxProfit+=(a[i].profit/a[i].weight)*maxCapacity;
			break;
		}	
	}
	return maxProfit;
}
int main(){
	ll items;
	cout<<"Enter total no. of items\n";
	cin>>items;
	vector<pair<ll,ll>>a;
	inputKnapsack(a,items);
	ll maxCapacity;
	cout<<"Enter Maximum capacity of knapsack\n";
	cin>>maxCapacity;
	sort(a.begin(),a.end(),[](pair<ll,ll>&one,pair<ll,ll>&two){
		return ((ld)one.profit/(ld)one.weight)>((ld)two.profit/(ld)two.weight);	
	});
	for(auto i:a){
		cout<<i.first<<" "<<i.second<<"\n";
	}
	ld maxProfit=knapsackLogic(a,items,maxCapacity);
	cout<<"Maximum profit is "<<maxProfit;
  return 0;
}
