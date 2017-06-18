#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
using namespace std;
#pragma comment(lib, "crypt32.lib") 
 
WINCRYPT32API
        BOOL
        WINAPI
        CryptUnprotectData(
        __in            DATA_BLOB*      pDataIn,             // in encr blob
        __deref_opt_out_opt LPWSTR*     ppszDataDescr,       // out
        __in_opt        DATA_BLOB*      pOptionalEntropy,
        __reserved      PVOID           pvReserved,
        __in_opt        CRYPTPROTECT_PROMPTSTRUCT*  pPromptStruct,
        __in            DWORD           dwFlags,
        __out           DATA_BLOB*      pDataOut
        );
 

int getpop3_1()
{
        printf("\r\n");
        HKEY hKey;     
        LPCTSTR lpRun = L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Windows Messaging Subsystem\\Profiles\\Outlook\\9375CFF0413111d3B88A00104B2A6676\\00000001";
        //READ POP3 DATA define
        //----------------------------------------
        DWORD sizeBuff = 1000; //read length
        DWORD dwtype = REG_BINARY; // reg type
        BYTE reBuff[1000] = {0}; //save string length
        long lRet; //Reg return values
        BYTE SmtpServer[200] = {0}; //read reg String length
        DWORD SMtplen = 200; //DWORD reg read length
        BYTE SmtpUser[200] = {0};//read reg String length
        DWORD SMtpUserlen = 200; //DWORD reg read length
        //------------------------------------------
 
        lRet= RegOpenKeyEx(HKEY_CURRENT_USER, lpRun, 0, KEY_READ, &hKey); //open reg
        if (lRet != ERROR_SUCCESS)
        {
                printf("RegOpenKeyEx Failed\r\n");
                return 0;
        }else
        {
                printf("RegOpenKeyEx Ing.....\r\n");
        }
 
        if (RegQueryValueEx(hKey,L"POP3 User",0,&dwtype,SmtpUser,&SMtpUserlen) == ERROR_SUCCESS) //query Pop3 Server address
        {
                //cout << "Smtp User:" << SmtpServer << endl;
                printf("POP3 User:%S\r\n",SmtpUser);//print Pop3 user
        }
 
        if (RegQueryValueEx(hKey,L"POP3 Server",0,&dwtype,SmtpServer,&SMtplen) == ERROR_SUCCESS) //query Pop3 Server address
        {
                //cout << "Smtp User:" << SmtpServer << endl;
                printf("Smtp Server:%S\r\n",SmtpServer);//print server address
        }
 
        if(RegQueryValueEx(hKey,L"POP3 Password",0,&dwtype,reBuff,&sizeBuff) == ERROR_SUCCESS) //query POP3 password
        {
                DATA_BLOB DataPassword;
                DATA_BLOB DataOutput;
                DataPassword.cbData = sizeBuff -1;
                DataPassword.pbData = &reBuff[1];
                if(CryptUnprotectData(&DataPassword,0,0,0,0,CRYPTPROTECT_UI_FORBIDDEN,&DataOutput)) //Crypt pop3 password
                {
                        //cout << DataOutput.pbData << endl;
                        wcout << "POP3 Password: " << (wchar_t*)DataOutput.pbData;   //print password
                }else
                {
                        cout << "Read error\r\n" << endl; //error
                        return 0;
                }
                return 0;
		}
 
        RegCloseKey(hKey);
        return 0;

}

int getpop3_2()
{
        printf("\r\n");
        HKEY hKey;     
        LPCTSTR lpRun = L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Windows Messaging Subsystem\\Profiles\\Outlook\\9375CFF0413111d3B88A00104B2A6676\\00000002";
        //READ POP3 DATA define
        //----------------------------------------
        DWORD sizeBuff = 1000; //read length
        DWORD dwtype = REG_BINARY; // reg type
        BYTE reBuff[1000] = {0}; //save string length
        long lRet; //Reg return values
        BYTE SmtpServer[200] = {0}; //read reg String length
        DWORD SMtplen = 200; //DWORD reg read length
        BYTE SmtpUser[200] = {0};//read reg String length
        DWORD SMtpUserlen = 200; //DWORD reg read length
        //------------------------------------------
 
        lRet= RegOpenKeyEx(HKEY_CURRENT_USER, lpRun, 0, KEY_READ, &hKey); //open reg
        if (lRet != ERROR_SUCCESS)
        {
                printf("RegOpenKeyEx Failed\r\n");
                return 0;
        }else
        {
                printf("RegOpenKeyEx Ing.....\r\n");
        }
 
        if (RegQueryValueEx(hKey,L"POP3 User",0,&dwtype,SmtpUser,&SMtpUserlen) == ERROR_SUCCESS) //query Pop3 Server address
        {
                //cout << "Smtp User:" << SmtpServer << endl;
                printf("POP3 User:%S\r\n",SmtpUser);//print Pop3 user
        }
 
        if (RegQueryValueEx(hKey,L"POP3 Server",0,&dwtype,SmtpServer,&SMtplen) == ERROR_SUCCESS) //query Pop3 Server address
        {
                //cout << "Smtp User:" << SmtpServer << endl;
                printf("Smtp Server:%S\r\n",SmtpServer);//print server address
        }
 
        if(RegQueryValueEx(hKey,L"POP3 Password",0,&dwtype,reBuff,&sizeBuff) == ERROR_SUCCESS) //query POP3 password
        {
                DATA_BLOB DataPassword;
                DATA_BLOB DataOutput;
                DataPassword.cbData = sizeBuff -1;
                DataPassword.pbData = &reBuff[1];
                if(CryptUnprotectData(&DataPassword,0,0,0,0,CRYPTPROTECT_UI_FORBIDDEN,&DataOutput)) //Crypt pop3 password
                {
                        //cout << DataOutput.pbData << endl;
                        wcout << "POP3 Password: " << (wchar_t*)DataOutput.pbData;   //print password
                }else
                {
                        cout << "Read error\r\n" << endl; //error
                        return 0;
                }
                return 0;
		}
 
        RegCloseKey(hKey);
        return 0;

}

int getpop3_3()
{
        printf("\r\n");
        HKEY hKey;     
        LPCTSTR lpRun = L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Windows Messaging Subsystem\\Profiles\\Outlook\\9375CFF0413111d3B88A00104B2A6676\\00000003";
        //READ POP3 DATA define
        //----------------------------------------
        DWORD sizeBuff = 1000; //read length
        DWORD dwtype = REG_BINARY; // reg type
        BYTE reBuff[1000] = {0}; //save string length
        long lRet; //Reg return values
        BYTE SmtpServer[200] = {0}; //read reg String length
        DWORD SMtplen = 200; //DWORD reg read length
        BYTE SmtpUser[200] = {0};//read reg String length
        DWORD SMtpUserlen = 200; //DWORD reg read length
        //------------------------------------------
 
        lRet= RegOpenKeyEx(HKEY_CURRENT_USER, lpRun, 0, KEY_READ, &hKey); //open reg
        if (lRet != ERROR_SUCCESS)
        {
                printf("RegOpenKeyEx Failed\r\n");
                return 0;
        }else
        {
                printf("RegOpenKeyEx Ing.....\r\n");
        }
 
        if (RegQueryValueEx(hKey,L"POP3 User",0,&dwtype,SmtpUser,&SMtpUserlen) == ERROR_SUCCESS) //query Pop3 Server address
        {
                //cout << "Smtp User:" << SmtpServer << endl;
                printf("POP3 User:%S\r\n",SmtpUser);//print Pop3 user
        }
 
        if (RegQueryValueEx(hKey,L"POP3 Server",0,&dwtype,SmtpServer,&SMtplen) == ERROR_SUCCESS) //query Pop3 Server address
        {
                //cout << "Smtp User:" << SmtpServer << endl;
                printf("Smtp Server:%S\r\n",SmtpServer);//print server address
        }
 
        if(RegQueryValueEx(hKey,L"POP3 Password",0,&dwtype,reBuff,&sizeBuff) == ERROR_SUCCESS) //query POP3 password
        {
                DATA_BLOB DataPassword;
                DATA_BLOB DataOutput;
                DataPassword.cbData = sizeBuff -1;
                DataPassword.pbData = &reBuff[1];
                if(CryptUnprotectData(&DataPassword,0,0,0,0,CRYPTPROTECT_UI_FORBIDDEN,&DataOutput)) //Crypt pop3 password
                {
                        //cout << DataOutput.pbData << endl;
                        wcout << "POP3 Password: " << (wchar_t*)DataOutput.pbData;   //print password
                }else
                {
                        cout << "Read error\r\n" << endl; //error
                        return 0;
                }
                return 0;
		}
 
        RegCloseKey(hKey);
        return 0;

}

int getpop3_4()
{
        printf("\r\n");
        HKEY hKey;     
        LPCTSTR lpRun = L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Windows Messaging Subsystem\\Profiles\\Outlook\\9375CFF0413111d3B88A00104B2A6676\\00000004";
        //READ POP3 DATA define
        //----------------------------------------
        DWORD sizeBuff = 1000; //read length
        DWORD dwtype = REG_BINARY; // reg type
        BYTE reBuff[1000] = {0}; //save string length
        long lRet; //Reg return values
        BYTE SmtpServer[200] = {0}; //read reg String length
        DWORD SMtplen = 200; //DWORD reg read length
        BYTE SmtpUser[200] = {0};//read reg String length
        DWORD SMtpUserlen = 200; //DWORD reg read length
        //------------------------------------------
 
        lRet= RegOpenKeyEx(HKEY_CURRENT_USER, lpRun, 0, KEY_READ, &hKey); //open reg
        if (lRet != ERROR_SUCCESS)
        {
                printf("RegOpenKeyEx Failed\r\n");
                return 0;
        }else
        {
                printf("RegOpenKeyEx Ing.....\r\n");
        }
 
        if (RegQueryValueEx(hKey,L"POP3 User",0,&dwtype,SmtpUser,&SMtpUserlen) == ERROR_SUCCESS) //query Pop3 Server address
        {
                //cout << "Smtp User:" << SmtpServer << endl;
                printf("POP3 User:%S\r\n",SmtpUser);//print Pop3 user
        }
 
        if (RegQueryValueEx(hKey,L"POP3 Server",0,&dwtype,SmtpServer,&SMtplen) == ERROR_SUCCESS) //query Pop3 Server address
        {
                //cout << "Smtp User:" << SmtpServer << endl;
                printf("Smtp Server:%S\r\n",SmtpServer);//print server address
        }
 
        if(RegQueryValueEx(hKey,L"POP3 Password",0,&dwtype,reBuff,&sizeBuff) == ERROR_SUCCESS) //query POP3 password
        {
                DATA_BLOB DataPassword;
                DATA_BLOB DataOutput;
                DataPassword.cbData = sizeBuff -1;
                DataPassword.pbData = &reBuff[1];
                if(CryptUnprotectData(&DataPassword,0,0,0,0,CRYPTPROTECT_UI_FORBIDDEN,&DataOutput)) //Crypt pop3 password
                {
                        //cout << DataOutput.pbData << endl;
                        wcout << "POP3 Password: " << (wchar_t*)DataOutput.pbData;   //print password
                }else
                {
                        cout << "Read error\r\n" << endl; //error
                        return 0;
                }
                return 0;
		}
 
        RegCloseKey(hKey);
        return 0;

}

int getpop3_5()
{
        printf("\r\n");
        HKEY hKey;     
        LPCTSTR lpRun = L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Windows Messaging Subsystem\\Profiles\\Outlook\\9375CFF0413111d3B88A00104B2A6676\\00000005";
        //READ POP3 DATA define
        //----------------------------------------
        DWORD sizeBuff = 1000; //read length
        DWORD dwtype = REG_BINARY; // reg type
        BYTE reBuff[1000] = {0}; //save string length
        long lRet; //Reg return values
        BYTE SmtpServer[200] = {0}; //read reg String length
        DWORD SMtplen = 200; //DWORD reg read length
        BYTE SmtpUser[200] = {0};//read reg String length
        DWORD SMtpUserlen = 200; //DWORD reg read length
        //------------------------------------------
 
        lRet= RegOpenKeyEx(HKEY_CURRENT_USER, lpRun, 0, KEY_READ, &hKey); //open reg
        if (lRet != ERROR_SUCCESS)
        {
                printf("RegOpenKeyEx Failed\r\n");
                return 0;
        }else
        {
                printf("RegOpenKeyEx Ing.....\r\n");
        }
 
        if (RegQueryValueEx(hKey,L"POP3 User",0,&dwtype,SmtpUser,&SMtpUserlen) == ERROR_SUCCESS) //query Pop3 Server address
        {
                //cout << "Smtp User:" << SmtpServer << endl;
                printf("POP3 User:%S\r\n",SmtpUser);//print Pop3 user
        }
 
        if (RegQueryValueEx(hKey,L"POP3 Server",0,&dwtype,SmtpServer,&SMtplen) == ERROR_SUCCESS) //query Pop3 Server address
        {
                //cout << "Smtp User:" << SmtpServer << endl;
                printf("Smtp Server:%S\r\n",SmtpServer);//print server address
        }
 
        if(RegQueryValueEx(hKey,L"POP3 Password",0,&dwtype,reBuff,&sizeBuff) == ERROR_SUCCESS) //query POP3 password
        {
                DATA_BLOB DataPassword;
                DATA_BLOB DataOutput;
                DataPassword.cbData = sizeBuff -1;
                DataPassword.pbData = &reBuff[1];
                if(CryptUnprotectData(&DataPassword,0,0,0,0,CRYPTPROTECT_UI_FORBIDDEN,&DataOutput)) //Crypt pop3 password
                {
                        //cout << DataOutput.pbData << endl;
                        wcout << "POP3 Password: " << (wchar_t*)DataOutput.pbData;   //print password
                }else
                {
                        cout << "Read error\r\n" << endl; //error
                        return 0;
                }
                return 0;
		}
 
        RegCloseKey(hKey);
        return 0;

}




int getimap3_1()
{
        printf("\r\n");
        HKEY hKey;     
        LPCTSTR lpRun = L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Windows Messaging Subsystem\\Profiles\\Outlook\\9375CFF0413111d3B88A00104B2A6676\\00000001";
        //READ POP3 DATA define
        //----------------------------------------
        DWORD sizeBuff = 1000; //read length
        DWORD dwtype = REG_BINARY; // reg type
        BYTE reBuff[1000] = {0}; //save string length
        long lRet; //Reg return values
        BYTE SmtpServer[200] = {0}; //read reg String length
        DWORD SMtplen = 200; //DWORD reg read length
        BYTE SmtpUser[200] = {0};//read reg String length
        DWORD SMtpUserlen = 200; //DWORD reg read length
        //------------------------------------------
 
        lRet= RegOpenKeyEx(HKEY_CURRENT_USER, lpRun, 0, KEY_READ, &hKey); //open reg
        if (lRet != ERROR_SUCCESS)
        {
                printf("RegOpenKeyEx Failed\r\n");
                return 0;
        }else
        {
                printf("RegOpenKeyEx Ing.....\r\n");
        }
 
        if (RegQueryValueEx(hKey,L"IMAP User",0,&dwtype,SmtpUser,&SMtpUserlen) == ERROR_SUCCESS) //query Pop3 Server address
        {
                //cout << "Smtp User:" << SmtpServer << endl;
                printf("IMAP User:%S\r\n",SmtpUser);//print Pop3 user
        }
 
        if (RegQueryValueEx(hKey,L"IMAP Server",0,&dwtype,SmtpServer,&SMtplen) == ERROR_SUCCESS) //query Pop3 Server address
        {
                //cout << "Smtp User:" << SmtpServer << endl;
                printf("Smtp Server:%S\r\n",SmtpServer);//print server address
        }
 
        if(RegQueryValueEx(hKey,L"IMAP Password",0,&dwtype,reBuff,&sizeBuff) == ERROR_SUCCESS) //query POP3 password
        {
                DATA_BLOB DataPassword;
                DATA_BLOB DataOutput;
                DataPassword.cbData = sizeBuff -1;
                DataPassword.pbData = &reBuff[1];
                if(CryptUnprotectData(&DataPassword,0,0,0,0,CRYPTPROTECT_UI_FORBIDDEN,&DataOutput)) //Crypt pop3 password
                {
                        //cout << DataOutput.pbData << endl;
                        wcout << "IMAP Password: " << (wchar_t*)DataOutput.pbData;   //print password
                }else
                {
                        cout << "Read error\r\n" << endl; //error
                        return 0;
                }
                return 0;
		}
 
        RegCloseKey(hKey);
        return 0;

}

int getimap3_2()
{
        printf("\r\n");
        HKEY hKey;     
        LPCTSTR lpRun = L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Windows Messaging Subsystem\\Profiles\\Outlook\\9375CFF0413111d3B88A00104B2A6676\\00000002";
        //READ POP3 DATA define
        //----------------------------------------
        DWORD sizeBuff = 1000; //read length
        DWORD dwtype = REG_BINARY; // reg type
        BYTE reBuff[1000] = {0}; //save string length
        long lRet; //Reg return values
        BYTE SmtpServer[200] = {0}; //read reg String length
        DWORD SMtplen = 200; //DWORD reg read length
        BYTE SmtpUser[200] = {0};//read reg String length
        DWORD SMtpUserlen = 200; //DWORD reg read length
        //------------------------------------------
 
        lRet= RegOpenKeyEx(HKEY_CURRENT_USER, lpRun, 0, KEY_READ, &hKey); //open reg
        if (lRet != ERROR_SUCCESS)
        {
                printf("RegOpenKeyEx Failed\r\n");
                return 0;
        }else
        {
                printf("RegOpenKeyEx Ing.....\r\n");
        }
 
        if (RegQueryValueEx(hKey,L"IMAP User",0,&dwtype,SmtpUser,&SMtpUserlen) == ERROR_SUCCESS) //query Pop3 Server address
        {
                //cout << "Smtp User:" << SmtpServer << endl;
                printf("IMAP User:%S\r\n",SmtpUser);//print Pop3 user
        }
 
        if (RegQueryValueEx(hKey,L"IMAP Server",0,&dwtype,SmtpServer,&SMtplen) == ERROR_SUCCESS) //query Pop3 Server address
        {
                //cout << "Smtp User:" << SmtpServer << endl;
                printf("Smtp Server:%S\r\n",SmtpServer);//print server address
        }
 
        if(RegQueryValueEx(hKey,L"IMAP Password",0,&dwtype,reBuff,&sizeBuff) == ERROR_SUCCESS) //query POP3 password
        {
                DATA_BLOB DataPassword;
                DATA_BLOB DataOutput;
                DataPassword.cbData = sizeBuff -1;
                DataPassword.pbData = &reBuff[1];
                if(CryptUnprotectData(&DataPassword,0,0,0,0,CRYPTPROTECT_UI_FORBIDDEN,&DataOutput)) //Crypt pop3 password
                {
                        //cout << DataOutput.pbData << endl;
                        wcout << "IMAP Password: " << (wchar_t*)DataOutput.pbData;   //print password
                }else
                {
                        cout << "Read error\r\n" << endl; //error
                        return 0;
                }
                return 0;
		}
 
        RegCloseKey(hKey);
        return 0;

}

int getimap3_3()
{
        printf("\r\n");
        HKEY hKey;     
        LPCTSTR lpRun = L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Windows Messaging Subsystem\\Profiles\\Outlook\\9375CFF0413111d3B88A00104B2A6676\\00000003";
        //READ POP3 DATA define
        //----------------------------------------
        DWORD sizeBuff = 1000; //read length
        DWORD dwtype = REG_BINARY; // reg type
        BYTE reBuff[1000] = {0}; //save string length
        long lRet; //Reg return values
        BYTE SmtpServer[200] = {0}; //read reg String length
        DWORD SMtplen = 200; //DWORD reg read length
        BYTE SmtpUser[200] = {0};//read reg String length
        DWORD SMtpUserlen = 200; //DWORD reg read length
        //------------------------------------------
 
        lRet= RegOpenKeyEx(HKEY_CURRENT_USER, lpRun, 0, KEY_READ, &hKey); //open reg
        if (lRet != ERROR_SUCCESS)
        {
                printf("RegOpenKeyEx Failed\r\n");
                return 0;
        }else
        {
                printf("RegOpenKeyEx Ing.....\r\n");
        }
 
        if (RegQueryValueEx(hKey,L"IMAP User",0,&dwtype,SmtpUser,&SMtpUserlen) == ERROR_SUCCESS) //query Pop3 Server address
        {
                //cout << "Smtp User:" << SmtpServer << endl;
                printf("IMAP User:%S\r\n",SmtpUser);//print Pop3 user
        }
 
        if (RegQueryValueEx(hKey,L"IMAP Server",0,&dwtype,SmtpServer,&SMtplen) == ERROR_SUCCESS) //query Pop3 Server address
        {
                //cout << "Smtp User:" << SmtpServer << endl;
                printf("Smtp Server:%S\r\n",SmtpServer);//print server address
        }
 
        if(RegQueryValueEx(hKey,L"IMAP Password",0,&dwtype,reBuff,&sizeBuff) == ERROR_SUCCESS) //query POP3 password
        {
                DATA_BLOB DataPassword;
                DATA_BLOB DataOutput;
                DataPassword.cbData = sizeBuff -1;
                DataPassword.pbData = &reBuff[1];
                if(CryptUnprotectData(&DataPassword,0,0,0,0,CRYPTPROTECT_UI_FORBIDDEN,&DataOutput)) //Crypt pop3 password
                {
                        //cout << DataOutput.pbData << endl;
                        wcout << "IMAP Password: " << (wchar_t*)DataOutput.pbData;   //print password
                }else
                {
                        cout << "Read error\r\n" << endl; //error
                        return 0;
                }
                return 0;
		}
 
        RegCloseKey(hKey);
        return 0;

}

int getimap3_4()
{
        printf("\r\n");
        HKEY hKey;     
        LPCTSTR lpRun = L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Windows Messaging Subsystem\\Profiles\\Outlook\\9375CFF0413111d3B88A00104B2A6676\\00000004";
        //READ POP3 DATA define
        //----------------------------------------
        DWORD sizeBuff = 1000; //read length
        DWORD dwtype = REG_BINARY; // reg type
        BYTE reBuff[1000] = {0}; //save string length
        long lRet; //Reg return values
        BYTE SmtpServer[200] = {0}; //read reg String length
        DWORD SMtplen = 200; //DWORD reg read length
        BYTE SmtpUser[200] = {0};//read reg String length
        DWORD SMtpUserlen = 200; //DWORD reg read length
        //------------------------------------------
 
        lRet= RegOpenKeyEx(HKEY_CURRENT_USER, lpRun, 0, KEY_READ, &hKey); //open reg
        if (lRet != ERROR_SUCCESS)
        {
                printf("RegOpenKeyEx Failed\r\n");
                return 0;
        }else
        {
                printf("RegOpenKeyEx Ing.....\r\n");
        }
 
        if (RegQueryValueEx(hKey,L"IMAP User",0,&dwtype,SmtpUser,&SMtpUserlen) == ERROR_SUCCESS) //query Pop3 Server address
        {
                //cout << "Smtp User:" << SmtpServer << endl;
                printf("IMAP User:%S\r\n",SmtpUser);//print Pop3 user
        }
 
        if (RegQueryValueEx(hKey,L"IMAP Server",0,&dwtype,SmtpServer,&SMtplen) == ERROR_SUCCESS) //query Pop3 Server address
        {
                //cout << "Smtp User:" << SmtpServer << endl;
                printf("Smtp Server:%S\r\n",SmtpServer);//print server address
        }
 
        if(RegQueryValueEx(hKey,L"IMAP Password",0,&dwtype,reBuff,&sizeBuff) == ERROR_SUCCESS) //query POP3 password
        {
                DATA_BLOB DataPassword;
                DATA_BLOB DataOutput;
                DataPassword.cbData = sizeBuff -1;
                DataPassword.pbData = &reBuff[1];
                if(CryptUnprotectData(&DataPassword,0,0,0,0,CRYPTPROTECT_UI_FORBIDDEN,&DataOutput)) //Crypt pop3 password
                {
                        //cout << DataOutput.pbData << endl;
                        wcout << "IMAP Password: " << (wchar_t*)DataOutput.pbData;   //print password
                }else
                {
                        cout << "Read error\r\n" << endl; //error
                        return 0;
                }
                return 0;
		}
 
        RegCloseKey(hKey);
        return 0;

}

int getimap3_5()
{
        printf("\r\n");
        HKEY hKey;     
        LPCTSTR lpRun = L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Windows Messaging Subsystem\\Profiles\\Outlook\\9375CFF0413111d3B88A00104B2A6676\\00000005";
        //READ POP3 DATA define
        //----------------------------------------
        DWORD sizeBuff = 1000; //read length
        DWORD dwtype = REG_BINARY; // reg type
        BYTE reBuff[1000] = {0}; //save string length
        long lRet; //Reg return values
        BYTE SmtpServer[200] = {0}; //read reg String length
        DWORD SMtplen = 200; //DWORD reg read length
        BYTE SmtpUser[200] = {0};//read reg String length
        DWORD SMtpUserlen = 200; //DWORD reg read length
        //------------------------------------------
 
        lRet= RegOpenKeyEx(HKEY_CURRENT_USER, lpRun, 0, KEY_READ, &hKey); //open reg
        if (lRet != ERROR_SUCCESS)
        {
                printf("RegOpenKeyEx Failed\r\n");
                return 0;
        }else
        {
                printf("RegOpenKeyEx Ing.....\r\n");
        }
 
        if (RegQueryValueEx(hKey,L"IMAP User",0,&dwtype,SmtpUser,&SMtpUserlen) == ERROR_SUCCESS) //query Pop3 Server address
        {
                //cout << "Smtp User:" << SmtpServer << endl;
                printf("IMAP User:%S\r\n",SmtpUser);//print Pop3 user
        }
 
        if (RegQueryValueEx(hKey,L"IMAP Server",0,&dwtype,SmtpServer,&SMtplen) == ERROR_SUCCESS) //query Pop3 Server address
        {
                //cout << "Smtp User:" << SmtpServer << endl;
                printf("Smtp Server:%S\r\n",SmtpServer);//print server address
        }
 
        if(RegQueryValueEx(hKey,L"IMAP Password",0,&dwtype,reBuff,&sizeBuff) == ERROR_SUCCESS) //query POP3 password
        {
                DATA_BLOB DataPassword;
                DATA_BLOB DataOutput;
                DataPassword.cbData = sizeBuff -1;
                DataPassword.pbData = &reBuff[1];
                if(CryptUnprotectData(&DataPassword,0,0,0,0,CRYPTPROTECT_UI_FORBIDDEN,&DataOutput)) //Crypt pop3 password
                {
                        //cout << DataOutput.pbData << endl;
                        wcout << "IMAP Password: " << (wchar_t*)DataOutput.pbData;   //print password
                }else
                {
                        cout << "Read error\r\n" << endl; //error
                        return 0;
                }
                return 0;
		}
 
        RegCloseKey(hKey);
        return 0;

}







int main(int argc,char* argv[])
{
	getpop3_1();
	getpop3_2();
	getpop3_3();
	getpop3_4();
	getpop3_5();


	getimap3_1();
	getimap3_2();
	getimap3_3();
	getimap3_4();
	getimap3_5();

}