
#include <iostream>
#include<vector>
#include <bits/stdc++.h>

using namespace std;

void combinations(vector<int>  &ar, int sum, vector< vector<int> > &ans, vector<int> &temp, int i)
{
	if (sum == 0) {
		ans.push_back(temp);
		return;
	}

	while (i < ar.size() && sum - ar[i] >= 0) {

		temp.push_back(ar[i]);

		combinations(ar, sum - ar[i], ans, temp, i);
		i++;

		temp.pop_back(); 
	}
}

vector< vector<int> > combinationSum(vector<int> &ar, int sum)
{
	sort(ar.begin(), ar.end());

	ar.erase(unique(ar.begin(), ar.end()), ar.end());

	vector<int> r;
	vector<vector<int> > ans;
	combinations(ar, sum, ans, r, 0);

	return ans;
}

// Driver code
int main()
{

    int len;

    cout<<"Enter array size: "; 
    cin>>len;

    cout<<"Enter array elements: "<<endl;
    int t;
	
    vector<int> ar;

    for (int i=0; i<len; i++){
        cin>>t;
        ar.push_back(t);
    }


	int n = ar.size();

	int sum;// set value of sum
    cout<<"Enter Sum Value: ";
    cin>>sum;

	vector<vector<int> > ans = combinationSum(ar, sum);

	if (ans.size() == 0) {
		cout << "Empty";
		return 0;
	}

	// Print all combinations stored in ans.
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i].size() > 0) {
			cout << " ( ";
			for (int j = 0; j < ans[i].size(); j++)
				cout << ans[i][j] << " ";
			cout << ")"<<endl;
		}
	}
return 0;
}
