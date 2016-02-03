#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
/*
void Ferma(long N)
{
    int x = (int) sqrt(N) + 1;
    int square = x * x - N;
    while (pow((int)sqrt(square), 2) != square)
    {
        x++;
        square = x * x - N;
    }
    int y = sqrt(square);
    int a = x - y;
    int b = x + y;
    cout << a << " " << b;
}*/

/*void primeFactor(long N)
{
    long x = sqrt(N);
    long y = 0;
    long r = x * x - y * y - N;
    while(r != 1)
        if(r == 0)
        {
            int a;
            x != y? a = x - y : a = x + y;
            cout << a << " ";
            r /= a;
            //return;
        }
        else
            if(r > 0)
            {
                r -= 2 * y + 1;
                y++;
            }
            else
            {
                r += 2 * x + 1;
                x++;
            }
}*/

void primeFactor(long num)
{
    vector <long> simple;
    simple.reserve(num / 2);
    bool *isSimple = new bool[num];
    isSimple[1] = false;
    for(long i = 2; i <= num; i++)
        isSimple[i] = true;

    for(long i = 2; i * i <= num; i++)
        if(isSimple[i])
            for(long j = i * i; j <= num; j += i)
                isSimple[j] = false;

    for(long i = 2; i <= num; i++)
        if(isSimple[i])
            simple.push_back(i);

    long sqrtNum = sqrt(num);
    for(long i = 2; i <= num; i++)
    {
        cout << i << "'s simple factors: " << endl;
        long number = i;
        for(vector <long>::iterator it = simple.begin(); *it <= sqrtNum; )
        {
            if(number == 1) break;
            if(number % (*it) == 0)
            {
                cout << (*it) << " ";
                number /= (*it);
            }
            else
                it++;
            if(isSimple[number])
            {
                cout << number << " ";
                cout << endl;
                cout << endl;
                break;
            }
        }
        cout << endl;
        cout << endl;
    }


    //delete isSimple;
}

int main(int argc, char *argv[])
{
    primeFactor(10000000);
    return 0;
}
