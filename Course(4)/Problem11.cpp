#include <iostream>
using namespace std;
enum enPassFail {pass = 1 , Fail = 2};
void ReadNumbers(int Mark[3])
{
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter Number " << i + 1 << ": ";
        cin >> Mark[i];
    }
}

int SumOf3Numbers(int Mark[3])
{
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum += Mark[i];
    }
    return sum;
}

float AvgOf3Marks(int Mark[3])
{
    return (float)SumOf3Numbers(Mark) / 3.0;
}
enPassFail CheckAvg(float avg){
    if (avg >= 50)
        return enPassFail::pass;
    else
        return enPassFail::Fail;
}
void PrintAvg(float avg)
{
    cout << "The Avg of the three numbers is: " << avg << endl;
    if (enPassFail::pass == CheckAvg(avg))
        cout << "Pass";
    else
        cout << "Fail";
}
int main()
{
    int Mark[3];
    ReadNumbers(Mark);
    PrintAvg(AvgOf3Marks(Mark));
    return 0;
}
