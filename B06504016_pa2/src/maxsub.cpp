#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
using namespace std;
int counting=0;    
void recursive(int n, int i,int** M,int *chord,int *record){
    if(n<=i){
       return; 
    }//stop
    else if(chord[n]==i){
        record[counting]=i;
        counting=counting+1;
        recursive(n-1,i+1,M,chord,record);
    }//case 3
    else if(chord[n]>i&&chord[n]<n){
        if(M[i][chord[n]-1]+M[(chord[n]+1)][n-1]+1>M[i][n-1]){ 
            record[counting]=chord[n]; 
            counting=counting+1;          
            recursive(chord[n]-1,i,M,chord,record);
            recursive(n-1,chord[n]+1,M,chord,record);
        }//case 2
        else{
            recursive(n-1,i,M,chord,record);
}//case 2
    }
    else{
        recursive(n-1,i,M,chord,record);
    }//case 1
}

int main(int argc,char* argv[]){
	fstream fin(argv[1]);
	fstream fout;
    fout.open(argv[2],ios::out);
	int n;
	fin >> n;
  int chord[n]; // if chord(i,j) exists, then chord[i] = j & chord[j] = i // array for final answer
	for(int i = 0; i < n / 2; i++){
		int a, b;
		
    fin >> a >> b;
		chord[a] = b;
		chord[b] = a;
	}
    int **M=NULL;	//used to store the optimal number of chords in region(i,j) j>=i
    M=new int*[n];    
  for(int i=0;i<n;i++){
    M[i]=new int[n];
    M[i][i]=0;
    }
	for(int j=1;j<n;j++){
        for(int i=0;i<n-j;i++){
            if(chord[j+i]>i&&chord[j+i]<j+i&&M[i][chord[i+j]-1]+M[chord[i+j]+1][i+j-1]+1>M[i][i+j-1]){
                M[i][j+i]=M[i][chord[i+j]-1]+M[chord[i+j]+1][i+j]+1;
                                
            }//case 2
            else if(chord[j+i]==i){
                M[i][j+i]=M[i+1][i+j-1]+1;
            }//case 3
            else{
                M[i][j+i]=M[i][j+i-1];
            }//case 1
    }
    }
	  fout<<M[0][n-1]<<endl;
    int record[M[0][n-1]]={0};
    recursive(n-1,0,M,chord,record);
    sort(record,record+M[0][n-1]);
    for(int i=0;i<M[0][n-1];i++){
    fout<<record[i]<<' '<<chord[record[i]]<<endl;
  }
    fin.close();
    fout.close();
    for(int i=0;i<n;i++){
    delete M[i];
  }
    delete M;
	return 0;
 }
