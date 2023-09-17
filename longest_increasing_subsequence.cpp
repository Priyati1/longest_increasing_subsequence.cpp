#include<iostream>
#include<vector>
using namespace std;
int lis(int *arr,int n){
	int dp[100000];
	for(int i=0;i<100000;i++){
		dp[i]=1;
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(arr[i]>arr[j]){
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
	}
	int ans=1;
	int i=0;
	for(int j=0;j<n;j++){
		if(ans<dp[j]){
			ans=dp[j];
			i=j;

		}
	}
	vector<int>v;
	int len=ans;
	v.push_back(arr[i]);
	len--;
	for(int j=i-1;j>=0;j--){
		if(dp[j]==len&&v[v.size()-1] >arr[j]){
			v.push_back(arr[j]);
			len--;
			if(len==0){
				break;
			}
		}
	}
	for(int i=v.size()-1;i>=0;i--){
		cout<<v[i]<<" ";
	}
	cout<<endl;
	return ans;
}
int main(){
	int arr[]={1,3,4,6,4,7,3,8};
	int n=sizeof(arr)/sizeof(int);
	cout<<"lis : "<<lis(arr,n)<<endl;
	return 0;
}