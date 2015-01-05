
#include "stdafx.h"
#include "ThreadLDAP.h"
#include <cstdio>
#include <cwchar>
#include <ole2.h>

CWinApp application;

class IsolatedProbe : public CThreadLDAP
{
public:
    bool Fetch(int port)
    {
        CSitio fixture;
        fixture.m_szNombre = L"Directorio ficticio";
        fixture.m_szServidor = L"127.0.0.1";
        fixture.m_szBase = L"ou=People,dc=example,dc=test";
        fixture.m_nPuerto = port;
        fixture.m_bAuth = false;
        m_bRunning = true;
        const bool passed = GetLDAP(&fixture);
        m_bRunning = false;
        return passed && m_pContactos.GetCount() == 1;
    }
protected:
    bool Init() override { return false; }
    void SetMensaje(const CString message, CSitio*) override
    {
        std::wprintf(L"%ls\n", message.GetString());
    }
};

int wmain(int argc, wchar_t** argv)
{
    if (argc != 2) return 2;
    const int port = _wtoi(argv[1]);
    if (port < 1024 || port > 65535) return 3;
    GUID id{};
    if (FAILED(CoCreateGuid(&id))) return 4;
    wchar_t suffix[50]{};
    if (StringFromGUID2(id, suffix, 50) < 1) return 4;
    const CString key = CString(L"Software\\PruebaLDAPSyncOutlook-") + suffix;
    HKEY temporary{};
    DWORD action{};
    if (RegCreateKeyExW(HKEY_CURRENT_USER, key, 0, nullptr, REG_OPTION_VOLATILE,
        KEY_ALL_ACCESS, nullptr, &temporary, &action) != ERROR_SUCCESS) return 5;
    if (action != REG_CREATED_NEW_KEY) { RegCloseKey(temporary); return 6; }

    bool passed = false;
    const auto user = RegOverridePredefKey(HKEY_CURRENT_USER, temporary);
    if (user == ERROR_SUCCESS &&
        AfxWinInit(GetModuleHandleW(nullptr), nullptr, GetCommandLineW(), 0))
    {
        IsolatedProbe demo;
        passed = demo.Fetch(port);
    }
    RegOverridePredefKey(HKEY_CURRENT_USER, nullptr);
    RegCloseKey(temporary);
    const auto cleaned = RegDeleteTreeW(HKEY_CURRENT_USER, key);
    if (cleaned != ERROR_SUCCESS) return 7;
    if (passed) std::puts("1 fictional contact read");
    return passed ? 0 : 8;
}
