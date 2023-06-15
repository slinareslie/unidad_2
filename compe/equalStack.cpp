#include <iostream>
#include <deque>

using namespace std;

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    long h1, h2, h3;
    cin >> h1 >> h2 >> h3;

    deque<int> n1, n2, n3;
    long t1 = 0, t2 = 0, t3 = 0;

    int aux;
    for (long i = 0; i < h1; i++)
    {
        cin >> aux;
        n1.push_back(aux);
        t1 += aux;
    }
    for (long i = 0; i < h2; i++)
    {
        cin >> aux;
        n2.push_back(aux);
        t2 += aux;
    }
    for (long i = 0; i < h3; i++)
    {
        cin >> aux;
        n2.push_back(aux);
        t3 += aux;
    }

    if (t1 != t2 || t2 != t3)
    {
        do
        {
            if ((t1 <= t2 && t2 < t3) || (t2 <= t1 && t2 < t3))
            {
                t3 -= n3.front();
                cout << "3:" << t3 << endl;
                n3.pop_front();
            }
            else if ((t1 <= t3 && t3 < t2) || (t3 <= t1 && t2 < t3))
            {
                t2 -= n2.front();
                cout << "2:" << t3 << endl;
                n2.pop_front();
            }
            else if ((t2 <= t3 && t3 < t1) || (t3 <= t2 && t2 < t1))
            {
                t1 -= n1.front();
                cout << "1:" << t3 << endl;
                n1.pop_front();
            }
        } while (t1 != t2 || t2 != t3);
    }
    if (t1 <= 0 || t2 <= 0 || t3 <= 0)
        cout << "0\n";
    cout << t1 << "\n";
    return 0;
}