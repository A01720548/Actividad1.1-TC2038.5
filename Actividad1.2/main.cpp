#include <iostream>
using namespace std;

int main(){
  int coins, value, change, productPrice, money;

  cout << "Total de monedas distintas: " << endl;
  cin >> coins;

  int changeOpt[coins];

  cout << "Valores de las monedas: " << endl;
  for (int i = 0; i < coins; i++){
    cin >> value;
    changeOpt[i] = value;
  }

  cout << "Precio del producto: " << endl;
  cin >> productPrice;

  cout << "Cantidad de dinero: " << endl;
  cin >> money;

  change = money - productPrice;

  int dynamic[change+1][change+1];

  for (int i = 0; i<= change; i++){
    for (int j = 0; j<= change; j++){
      dynamic[i][j] = 0;
    }
  }

  for (int i = 1; i <= change; i++){
    dynamic[i][0] = change+1;
  }


  for (int i = 1; i <= change; i++){
    for (int j = 0; j < coins; j++){
      int temporaryCoins = 0;
      if ((i - changeOpt[j]) >= 0){
        temporaryCoins = 1 + dynamic[i - changeOpt[j]][0];
        if (temporaryCoins < dynamic[i][0]){
          dynamic[i][0] = temporaryCoins;
          dynamic[i][1] = changeOpt[j];
          for (int k = 2; k <= change; k++){
            dynamic[i][k] = dynamic[i - changeOpt[j]][k-1];
          }
        } 
      }
    }
  }

  cout << "Cambio = " << change << endl;
  cout << endl;
  cout << "Resultado DP" << endl;
  cout << endl;

  for(int i = 0; i < coins; i++){
    int counter = 0;
    for(int j = 1; j <= change; j++){
      if(dynamic[change][j] == changeOpt[i]){
        counter++;
      }
  }
    cout << changeOpt[i] << " " << counter << endl;
    cout << endl;
    counter = 0;
  }


  return 0;
}
