#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


void primeFactor(long num)
{
    vector <long> simple;                           //prime numbers
    simple.reserve(num / 2);
    bool *isSimple = new bool[num];                //prime flag
    isSimple[1] = false;
    for(long i = 2; i <= num; i++)
        isSimple[i] = true;

    for(long i = 2; i * i <= num; i++)
        if(isSimple[i])
            for(long j = i * i; j <= num; j += i)
                isSimple[j] = false;

    for(long i = 2; i <= num; i++)
        if(isSimple[i])
            simple.push_back(i);                    //Add prime number to vector

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
    primeFactor(10000);
    return 0;
}
