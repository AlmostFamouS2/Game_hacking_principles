#include <windows.h>
#include <iostream>
#include <tlhelp32.h>

using namespace std;

//#pragma warning(disable:4996)

struct tINFO
{
       char * Process_Name;
       DWORD PID;
};


void FormatTxt(char Text[40], DWORD value)
{
       char * txt;
       txt = Text;
       for (int i = strlen(txt); i <= 30 ; i++)
       {
               strcat(txt, " ");
       }
       int c = value;
       char cvalue[10] = "";
       strcat(txt, "[ PID: ");
       itoa(c, cvalue, 10);
       for (int g = strlen(cvalue); g <= 4; g++)
       {
               strcat(cvalue, " ");
       }
       strcat(txt, cvalue);
       strcat(txt, " ]");
       cout << txt << endl;
}

int GetProcessID()
{
       HANDLE hAndle;
       PROCESSENTRY32 pEntry;
       hAndle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
       ZeroMemory(&pEntry, sizeof(pEntry));
       pEntry.dwSize = sizeof(PROCESSENTRY32);

       char PN[100] = "";
       if (Process32First(hAndle, &pEntry))
       {
               do
               {
                       memcpy(PN, pEntry.szExeFile, 30);
                       FormatTxt(PN, pEntry.th32ProcessID);
               } while (Process32Next(hAndle,&pEntry));

       }

               return 1;

}

int main()
{
       GetProcessID();
       getchar();
       return 0;
}
