#include<vector>
#include<iostream>
#include<stdlib.h>

using namespace std;

void print_matrix(vector< vector<int> > mat){
    cout<<"[";
    for (int i = 0; i < mat.size(); i++) {
		if (mat[i].size() > 0) {
			cout << " ( ";
			for (int j = 0; j < mat[i].size(); j++)
				cout << mat[i][j] << " ";
			cout << ")";
		}
	}
    cout<<"]"<<endl;
}

vector< vector<int> > transpose_matrix(vector<vector<int> > &b){
    if (b.size() == 0)
        cout<<"Empty";

    vector<vector<int> > trans_vec(b[0].size(), vector<int>());

    for (int i = 0; i < b.size(); i++)
    {
        for (int j = 0; j < b[i].size(); j++)
        {
            trans_vec[j].push_back(b[i][j]);
        }
    }

    return trans_vec;    // <--- reassign here
}



int main(){

    vector< vector<int> > relation;
    vector< vector<int> > transpose;

    int m, n;
    cout<<"Enter number of elements in first set: "; cin>>m;
    cout<<"Enter number of elements in second set: "; cin>>n;


    cout<<"Enter Relation matrix"<<endl;

    vector<int> temp;
    int in;
    for (int i = 0; i < m; i++){
        cout<<"Enter row "<<i<<endl;
        
        for (int j = 0; j < n; j++){
            cout<<"Enter col "<<j<<" - ";
            cin>>in;
            temp.push_back(in);
        }

        relation.push_back(temp);
        temp.clear();

    }

    system("cls");

    print_matrix(relation);

    transpose = transpose_matrix(relation);

    print_matrix(transpose);

    return 0;
}