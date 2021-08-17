// g++ main.cpp -o main.exe
// main.exe < in.txt
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> coins;
int product;
int paid;

vector<int> greed(int product, int paid)
{
    int change = paid - product;
    // cout << change << endl;
    int i = 0;
    vector<int> coinsUsed;
    // cout << coins[i] << endl;

    while (change > 0)
    {
        if (change >= coins[i])
        {
            change -= coins[i];
            coinsUsed.push_back(coins[i]);
        }
        else
            i++;
    }

    return coinsUsed;
}

int main()
{
    int n;
    cin >> n;
    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        coins.push_back(num);
    }

    sort(coins.begin(), coins.end(), greater<int>());
    cin >> product;
    cin >> paid;

    cout << "Product Cost: " << product << endl;
    cout << "Amount Paid: " << paid << endl;

    vector<int> result = greed(product, paid);
    cout << "Coins Used: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
}

// Se necesitan 1 moneda para alcanzar el valor de 3.
// Resultado = Valor en indice - ValorMonedaUtilizar = 3 - 3 = 0
// Cantidad de monedas a utilizar = CantidadMonedasParaResultado + 1 = 0+1 = 1
