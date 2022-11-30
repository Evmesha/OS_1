#include <iostream>
#include <windows.h>
using namespace std;

DWORD Worker(short _n, short* _a)
{
    short size = _n;
    short* arr = _a;
    int sec;
    cout << "miliseconds " << endl;
    cin >> sec;
    Sleep(sec);
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0 && arr[i] % 9 == 0)
        {
            cout << arr[i] << ' ';
        }

        Sleep(30);
    }
    cout << endl;

    return 0;
}

int main()
{
    short n;
    volatile DWORD dwCount;
    cout << "Enter the size of the massive " << endl;
    cin >> n;
    short* a = new short[n];
    cout << "Enter the elements of the massive " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << endl;
    HANDLE hThread;
    DWORD IDThread;
    hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Worker, NULL, 0, &IDThread);
    if (hThread == NULL)
        return GetLastError();
    dwCount = SuspendThread(hThread); 
    cout << "Thread suspend count = " << dwCount << endl;
    dwCount = ResumeThread(hThread);
    cout << "Thread suspend count = " << dwCount << endl; 
    WaitForSingleObject(hThread, INFINITE);
    CloseHandle(hThread);
}