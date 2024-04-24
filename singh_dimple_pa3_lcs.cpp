// The longest common subsequence in C++

#include <iostream>
#include <cstring>
#include<string.h>
using namespace std;

void lcs(char *S1, char *S2, int m, int n) {
  int LCS_table[m + 1][n + 1];


  // Building the mtrix in bottom-up way
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == 0 || j == 0)
        LCS_table[i][j] = 0;
      else if (S1[i - 1] == S2[j - 1])
        LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
      else
        LCS_table[i][j] = max(LCS_table[i - 1][j], LCS_table[i][j - 1]);
    }
  }

  int index = LCS_table[m][n];
  char lcsAlgo[index + 1];
  lcsAlgo[index] = '\0';

  int i = m, j = n;
  while (i > 0 && j > 0) {
    if (S1[i - 1] == S2[j - 1]) {
      lcsAlgo[index - 1] = S1[i - 1];
      i--;
      j--;
      index--;
    }

    else if (LCS_table[i - 1][j] > LCS_table[i][j - 1])
      i--;
    else
      j--;
  }
  
  // Printing the sub sequences
  cout << "S1 : " << S1 << "\nS2 : " << S2 << "\nLCS: "<<lcsAlgo << "\n";
  cout << "Length of LCS: "<<strlen(lcsAlgo) <<endl;
}

int main(int argc, char* argv[]) {

  if(argc <3 || argc>3){
        cout << "error in input!!!" <<endl;
	return -1;
  }
  char S1[10000];
  char S2[10000];
  strcpy(S1,argv[1]);
  strcpy(S2,argv[2]);
  
  int m = strlen(S1);
  int n = strlen(S2);
  
  if(m>100 || n>100){
  cout<<"String too long!!!"<<endl;
  return -2;
  }
  
  else{
  lcs(S1, S2, m, n);
  }
}

