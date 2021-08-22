#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> coinsVector;
int coins, value, change, productPrice, money;

void greed(int product, int paid)
{
    sort(coinsVector.begin(), coinsVector.end(), greater<int>());

    int change = paid - product;
    // cout << change << endl;
    int i = 0;
    vector<int> coinsUsed;
    int counter = 0;
    // cout << coins[i] << endl;

    while (change > 0)
    {

        if (change >= coinsVector[i])
        {
            change -= coinsVector[i];
            coinsUsed.push_back(coinsVector[i]);
        }
        else
            i++;
    }

    cout << "Resultado Greedy" << endl
         << endl;
    for (int i = 0; i < coinsVector.size(); i++)
    {
        int counter = count(coinsUsed.begin(), coinsUsed.end(), coinsVector[i]);
        cout << coinsVector[i] << " " << counter << endl;
        cout << endl;
    }
}

void dynamicProgramming(int changeOpt[])
{
    int dynamic[change + 1][change + 1];

    for (int i = 0; i <= change; i++)
    {
        for (int j = 0; j <= change; j++)
        {
            dynamic[i][j] = 0;
        }
    }

    for (int i = 1; i <= change; i++)
    {
        dynamic[i][0] = change + 1;
    }

    for (int i = 1; i <= change; i++)
    {
        for (int j = 0; j < coins; j++)
        {
            int temporaryCoins = 0;
            if ((i - changeOpt[j]) >= 0)
            {
                temporaryCoins = 1 + dynamic[i - changeOpt[j]][0];
                if (temporaryCoins < dynamic[i][0])
                {
                    dynamic[i][0] = temporaryCoins;
                    dynamic[i][1] = changeOpt[j];
                    for (int k = 2; k <= change; k++)
                    {
                        dynamic[i][k] = dynamic[i - changeOpt[j]][k - 1];
                    }
                }
            }
        }
    }

    cout << "Cambio = " << change << endl;
    cout << endl;
    cout << "Resultado DP" << endl;
    cout << endl;

    for (int i = 0; i < coins; i++)
    {
        int counter = 0;
        for (int j = 1; j <= change; j++)
        {
            if (dynamic[change][j] == changeOpt[i])
            {
                counter++;
            }
        }
        cout << changeOpt[i] << " " << counter << endl;
        cout << endl;
        counter = 0;
    }
}

int main()
{
    cin >> coins;
    cout << "Total de monedas distintas: " << coins << endl;

    int changeOpt[coins];

    for (int i = 0; i < coins; i++)
    {
        cin >> value;
        changeOpt[i] = value;
        coinsVector.push_back(value);
    }

    cin >> productPrice;
    cout << "Precio del producto: " << productPrice << endl;

    cin >> money;
    cout << "Cantidad de dinero: " << money << endl;

    change = money - productPrice;

    dynamicProgramming(changeOpt);

    greed(productPrice, money);

    return 0;
}
