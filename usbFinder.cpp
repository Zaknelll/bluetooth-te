//
// Created by Alexey on 21.03.2021.
//

#include <stdio.h>
#include <windows.h>
#include <Setupapi.h>
#include <devguid.h>
#include "conio.h"
#include "tchar.h"

int main(int argc, char ** argv)
{
    HDEVINFO deviceInfoSet;
    GUID *guidDev = (GUID*) &GUID_DEVCLASS_USB;
    deviceInfoSet = SetupDiGetClassDevs(guidDev, NULL, NULL, DIGCF_PRESENT | DIGCF_PROFILE);
    TCHAR buffer [4000];
    DWORD buffersize =4000;
    int memberIndex = 0;
    while (true) {
        SP_DEVINFO_DATA deviceInfoData;
        ZeroMemory(&deviceInfoData, sizeof(SP_DEVINFO_DATA));
        deviceInfoData.cbSize = sizeof(SP_DEVINFO_DATA);
        if (SetupDiEnumDeviceInfo(deviceInfoSet, memberIndex, &deviceInfoData) == FALSE) {
            if (GetLastError() == ERROR_NO_MORE_ITEMS) {
                break;
            }
        }
        DWORD nSize=0 ;
        SetupDiGetDeviceInstanceId (deviceInfoSet, &deviceInfoData, buffer, sizeof(buffer), &nSize);
        buffer [nSize] ='\0';
        _tprintf (_T("%s\n"), buffer);
        memberIndex++;
    }
    if (deviceInfoSet) {
        SetupDiDestroyDeviceInfoList(deviceInfoSet);
    }
    getch();
    return 0;
}
