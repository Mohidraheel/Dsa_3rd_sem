#include <iostream>
#include <string.h>

using namespace std;
void selectionsort(char fruit[][60], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(fruit[min], fruit[j]) > 0)
            {
                min = j;
            }
        }
        if (i != min)
        {
            swap(fruit[i], fruit[min]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << fruit[i] << "\t";
    }
}
int main()
{
    char fruit[][60] = {"papaya", "lime", "kiwi", "orange", "apple", "banana"};
    int n;
    n = sizeof(fruit) / sizeof(fruit[0]);
    
    selectionsort(fruit,n);
    return 0;
}
