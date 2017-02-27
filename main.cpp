//compile with 	"g++ -g -o a LCS_Jiang_Wu_jiangwu.cpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string a, b, subL;
int totalL = 0;

int max(int a, int b){
    if(a >= b) return a;
    return b;
}

//LCS Alg
void lcs(string  a, string b){
    int m, n;
    m = a.length();
    n = b.length();
    int length[m+1][n+1];
    for(int i = m; i >= 0; i--){
        for(int j = n; j >= 0; j--){
            if(i == m || j == n) length[i][j] = 0;
            else if(a[i] == b[j]) length[i][j] = length[i+1][j+1] + 1;
            else length[i][j] = max(length[i+1][j], length[i][j+1]);
        }
    }
    totalL = length[0][0];
   
    int i = 0, j = 0;
    while(i < m && j < n){
        if(a[i] == b[j]){
            subL.push_back(a[i]);
            i++;
            j++;
        }
        else if(length[i+1][j] >= length[i][j+1]) i++;
	    else j++;
    }
}

int main(){
//read file
    ifstream myfile("input.txt");
    myfile >> a;
    myfile.ignore(1000, '\n');
    myfile >> b;
    myfile.close();
    
    lcs(a, b);

//write to file    
    ofstream myfile1("output.txt");
    myfile1 << totalL << endl;
    myfile1 << subL << endl;
    myfile1.close();
    return 0;
}