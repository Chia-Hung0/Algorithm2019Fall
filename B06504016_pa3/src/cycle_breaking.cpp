#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
using namespace std;
int V,E;
int FindMaxIndex(int *d,bool *visited){
    int j=0,k=d[0];
    for(int i=1;i<V;i++){
        if(k<d[i]&&visited[i]==0){
            k=d[i];
            j=i;
            
        }
    }
    return j;
}
bool cycledetecting(char gtype,int root,int **W){
    int d[V],G[V],vp[V] ;
    bool visited[V];
    for(int k=0;k<V;k++){
      d[k]=-101;
      G[k]=0;
      vp[k]=0;
      visited[k]=0;
      }
    visited[root]=1;
    vp[root]=-1;
    G[0]=root;
    int i=0,g=0,s=0,m=0;
    while(g<V-1){
            m=0;
            i=G[g];
            for(int j=0;j<V;j++){
                if(W[i][j]>d[j]&&visited[j]==0){
                    d[j]=W[i][j];
                    vp[j]=i;
                    
                }
            }
            for(int k=0;k<V;k++){
                if(d[k]==-101){
                   m++; 
                }
              }                      
            s=FindMaxIndex(d,visited);
            W[vp[s]][s]=-1000;
            if(gtype=='u'){
              W[s][vp[s]]=-1000;
            }
            d[s]=-101;
            visited[s]=1;
            g++;
            G[g]=s;            
}           
            if(m==V){
              return 0;
            }
            else{
              return 1;
            }
}
int weight_compute(int **W,char gtype){
  int weight_sum=0;
        if(gtype=='u'){
        for(int i=0;i<V;i++){
            for(int j=i;j<V;j++){
                if(W[i][j]!=-1000){
                    weight_sum=weight_sum+W[i][j];
                }
            }
            }
            }
        else{
            for(int i=0;i<V;i++){
                for(int j=0;j<V;j++){
                    if(W[i][j]!=-1000){
                      weight_sum=weight_sum+W[i][j];
        
        }            
     
}
}
}
   return weight_sum;
}
void manytime_cycledetecting(int **W){
        int **W_copy=NULL;
        W_copy=new int*[V];
        for(int i=0;i<V;i++){
            W_copy[i]=new int[V];
            }
        int l=99999999,n=0;    
            
        for(int k=0;k<V;k++){
            for(int i=0;i<V;i++){
                for(int j=0;j<V;j++){
                W_copy[i][j]=W[i][j];
                }                 
        }
        cycledetecting('d',k,W_copy);
        if(weight_compute(W_copy,'d')<l&&cycledetecting('d',k,W_copy)){
            l=weight_compute(W_copy,'d');
            n++;
        }
         
        }
        for(int i=0;i<V;i++){
            delete W_copy[i];
        }
        delete W_copy;
        cycledetecting('d',n,W);
 }          
int main(int argc,char* argv[]){
	fstream fin(argv[1]);
	fstream fout;
    fout.open(argv[2],ios::out);
	char gtype;
	fin>>gtype;
  fin>>V>>E;
  int u,v,w;
  int **Weight=NULL;
        Weight=new int*[V];
        for(int i=0;i<V;i++){
            Weight[i]=new int[V];
            }
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                Weight[i][j]=-1000;

            }
        }
	if(gtype=='u'){        
        for(int i=0;i<E;i++){
            fin>>u>>v>>w;
            Weight[u][v]=w;
            Weight[v][u]=w;

            }           
        
        cycledetecting('u',0,Weight);
        fout<<weight_compute(Weight,'u')<<endl;
        for(int i=0;i<V;i++){
            for(int j=i;j<V;j++){
                if(Weight[i][j]!=-1000){
                    fout<<i<<" "<<j<<" "<<Weight[i][j]<<endl;
                    Weight[i][j]=-1000;
                    Weight[j][i]=-1000;
                }
            }
        }
        }
  else if(gtype=='d'){
        for(int i=0;i<E;i++){
            fin>>u>>v>>w;
            Weight[u][v]=w;
        }       
        cycledetecting('d',0,Weight);
        fout<<weight_compute(Weight,'d')<<endl;
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(Weight[i][j]!=-1000){
                    fout<<i<<" "<<j<<" "<<Weight[i][j]<<endl;
                    Weight[i][j]=-1000;
                }
            }  
        } 
            
        for(int i=0;i<V;i++){
            delete Weight[i];
        }
        delete Weight;

        

        fin.close();
        fout.close();

        return 0;
}
}
