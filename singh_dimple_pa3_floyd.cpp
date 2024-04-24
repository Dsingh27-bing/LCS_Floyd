#include <cstdlib>
#include <iostream>
using namespace std;

int a[100][100];
int p[100][100] = {0};    //initializing P matrix to 0 

void shortest_path(int q, int r){
  if(p[q][r]!=0){
    shortest_path(q, p[q][r]-1);      //finding shortest path
    cout << "->" <<p[q][r];
    shortest_path(p[q][r]-1, r); 
  }
  return;
}

void floyd_path(int n) {
  int d[100][100];      // declaring d matrix
  for(int i=0; i<n; i++){
    for(int j=0; j<n;j++){  // coping a to d matrix
      d[i][j]=a[i][j];
    }
  }

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {       //following slide algo
        if (d[i][j] > (d[i][k] + d[k][j])) {
          d[i][j] = (d[i][k] + d[k][j]);
          p[i][j] = k+1;
        }
      }
    }
  }

  cout<<"P Matrix :"<<endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {     //printing p matrix
      cout << p[i][j] << " ";
    }
    cout << endl;
  }
  cout<<endl;         // to find shortest path and printing it
  for (int i=0;i<n; ++i){
    for (int j=0;j<n;++j){
      if (i!=j){
        cout << "shortest path from v" << i+1 << " to" << " v"<<j+1 << ": ";
      cout << i+1;
      shortest_path(i,j);    //calling shortest path recursively
      cout<< "->"<< j+1;
      cout << " = " << d[i][j];
      cout <<endl;
      }
      
    }
    cout<<"\n";
  }
}

void adjacency_mat(int n) {             //random A matrix
  cout << "\nAdjacency matrix A : \n\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        a[i][j] = 0;
      } else {
        a[i][j] = a[j][i] = 1 + (rand() % 9);
      }
    }
  }
  for (int i = 0; i < n; i++) {     // printing A matrix
    for (int j = 0; j < n; j++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
  cout<<endl;
  floyd_path(n);        //calling floyd_path with n value
}

int main() {
  srand((unsigned)time(NULL));
  int n = 5 + (rand() % 5);      //getting n value randomly generated
  cout << "\nvalue of n= " << n << "\n";
  adjacency_mat(n);
  return 0;
}



