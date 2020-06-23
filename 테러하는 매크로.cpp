#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

#define TYPING_DELAY 1000
// 230

int main()
{
    char my_typing[100] = "";
    cout << "매크로 내용 : ";
    cin.getline(my_typing, 100);

    while(1)
    {
        if(kbhit())
        {
            while(kbhit())
                getch();

            system("cls");
            cout << "매크로 내용 : ";
            cin.getline(my_typing, 100);
        }
        AttachThreadInput(GetCurrentThreadId(), GetWindowThreadProcessId(GetForegroundWindow(), NULL), TRUE);
        HWND hWnd = GetFocus();
        cout << "Current Window: " << hWnd << endl;
        int length = strlen(my_typing);
        for(int i = 0;i < length;i++)
        {
            PostMessage(hWnd, WM_CHAR, my_typing[i], NULL);
            Sleep(TYPING_DELAY / length - length * length / 4 / TYPING_DELAY);
        }
        PostMessage(hWnd, WM_KEYDOWN, VK_RETURN, NULL);
    }
}
