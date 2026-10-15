#include<iostream>
using namespace std;
int ReadSeconds(){
    int seconds;
    cout << "Enter the number of seconds: ";
    cin >> seconds;
    return seconds;
}
int SecondsToDays(int seconds){
    return seconds / 86400;
}
int SecondsToHours(int seconds){
    return (seconds % 86400) / 3600;
}
int SecondsToMinutes(int seconds){
    return ((seconds % 86400) % 3600) / 60;
}
int SecondsToSeconds(int seconds){
    return ((seconds % 86400) % 3600) % 60;
}
int main(){
    int seconds = ReadSeconds();
    cout << SecondsToDays(seconds) << " : " << SecondsToHours(seconds) << " : " << SecondsToMinutes(seconds) << " : " << SecondsToSeconds(seconds);
}