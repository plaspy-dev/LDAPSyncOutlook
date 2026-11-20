# LDAPSyncOutlook
[English](#english) · [Español](#español)

## English

Archived Windows utility and Outlook add-in to copy contacts from an LDAP directory

> [!WARNING]
> **Status:** Archived application. Check the requirements before opening Outlook.

### Overview

LDAP is a protocol for looking up entries in a shared directory. This project copies a directory’s contacts into Outlook so an operator can look them up from the address book.

### Features

- Choose an LDAP host, search base and time between synchronizations.
- Read contact names and email addresses and keep a mapping to the Outlook destination.
- Configure synchronization from the desktop window or the original Outlook add-in.
- Include groups and people in the LDAP search. Entries with email follow the same contact workflow.

### History

**2026-11-20.** The compatibility commit points the desktop and add-in imports to the installed Office and Outlook type libraries and assigns the generated symbol a distinct name.

The initial January 1, 2015 revision contains documentation. The source arrives on January 5. The revisions retain the dates recorded in the original archive. The 2026 reconstruction adds the v145 projects and the local trial.

- **2026-11-18** Add a screenshot from the isolated fictional LDAP lookup recorded on November 20, 2026.

### Requirements


Use a Developer PowerShell with the Desktop development with C++ workload, the x86/x64 C++ MFC and ATL components, MSVC v145 14.51.36231 and Windows SDK 10.0.26100.0. Provide the Windows Address Book (WAB) inputs of Windows SDK 7.1 and the type libraries `MSOUTL.OLB` 16.0.19929.20032, `MSO.DLL` from Office 16.0.20527.20196 and `MSADDNDR.DLL` 6.00.8100. The Outlook add-in must match the bitness of the installed Outlook. This solution builds Win32. Use the Office installation paths for your test machine. The build leaves COM registration to the operator. Obtain the WAB headers and x86 library from Microsoft’s Windows SDK 7.1. Use MSOUTL.OLB and MSO.DLL from a licensed installation of 32-bit desktop Outlook and Office. The exact Microsoft package that supplied the tested copy of MSADDNDR.DLL 6.00.8100 could not be identified. If the designer library is unavailable, use the standalone LDAP probe.

### Getting started

Build the solution from the repository root.

```powershell
$wab = 'C:\ruta\Windows-SDK-7.1\WAB'
$outlook = 'C:\ruta\Office16'
$office = 'C:\ruta\Microsoft Shared\Office16'
$designer = 'C:\ruta\Designer'
MSBuild .\src\LDAPSyncOutlook.sln /m:1 /t:Build /p:Configuration=Release /p:Platform=Win32 /p:PreferredToolArchitecture=x64 "/p:LegacyWabSdk=$wab" "/p:OutlookTypeDirectory=$outlook" "/p:OfficeTypeDirectory=$office" "/p:DesignerTypeDirectory=$designer"
```

### Usage

Use a separate Outlook profile and a fictional LDAP directory. In the desktop window set a label, the LDAP host and the search base and choose a test Outlook folder. Click **Agregar**, then right-click the saved configuration and choose **Actualizar**. Compare the one fictional entry with the folder after synchronization.

### Project structure

`docs/media/` contains the capture from the LDAP probe.

`demo/ldap/` contains the OpenLDAP fixture and the standalone `Probe.vcxproj`.

`src/LDAPSyncOutlook/` contains the desktop application, `src/LDAPSyncOutlookAddin/` contains the add-in and `src/comun/` implements LDAP retrieval and contact mapping. `src/mapi/` contains historical headers. `installer/` contains the NSIS script. The original projects and headers keep their notices.

### Verification

This compatibility commit uses the installed Office and Outlook type libraries from the paths supplied to MSBuild. Its two Outlook imports give the generated online meeting symbol a distinct alias to avoid a header collision. The loopback test checks the shared LDAP lookup with a fictional contact. The import and add-in require an isolated Outlook profile. No such profile was available for the trial.

The solution and LDAP query were repeated on 2026-11-23 on Windows 11 build 26300. The capture is from the November 20, 2026 run of the same probe and fictitious directory. The screenshot shows the command-line probe reading Alicia Ejemplo from a loopback directory. It shows the LDAP code that the desktop program and the add-in share.

![The local query returns the fictional contact Alicia Ejemplo](docs/media/ldap-query.png)

The [local LDAP instructions](demo/ldap/README.md) use the same fictional directory as the recorded probe. A separate isolated fixture supplied OpenLDAP for the recorded run.

MSBuild 18.11.1.51303 compiled the Win32 desktop client and add-in. A separate test executable invoked the original LDAP retrieval method against a disposable OpenLDAP 2.5.13+dfsg-5 server at 127.0.0.1. It returned one fictional contact. The trial covered directory retrieval. Writing to Outlook, registering the add-in and running the installer still need a separate Windows and Outlook test profile.

### Support

Use a synthetic entry to report the failing screen, commit and Outlook or LDAP version.

### Contributing

Include the MSBuild results for the client and add-in and a fictional directory test with the change.

### License

See [MIT](LICENSE) for the project code. The archived components keep their [third-party notices](THIRD-PARTY-NOTICES.md).

---

## Español

Archivado — utilidad de Windows y complemento de Outlook para copiar contactos desde LDAP

> [!WARNING]
> **Estado:** Aplicación archivada. Consulta los requisitos antes de usar Outlook.

### Descripción general

LDAP es un protocolo para consultar fichas en un directorio compartido. Este proyecto copia los contactos del directorio a Outlook para que el operador pueda consultarlos en su libreta.

### Funciones

- Elige un servidor LDAP, una base de búsqueda y el intervalo entre sincronizaciones.
- Lee nombres y correos y conserva la relación con la carpeta de Outlook.
- Configura la sincronización desde la ventana de escritorio o el complemento original de Outlook.
- Incluye grupos y personas en la búsqueda LDAP. Las entradas con correo siguen el mismo recorrido de contactos.

### Historial

**2026-11-20.** El commit de compatibilidad apunta a las bibliotecas de tipos instaladas de Office y Outlook y asigna un nombre distinto al símbolo generado.

La primera revisión del 1 de enero de 2015 contiene documentación. El código entra el 5 de enero. Las revisiones conservan las fechas que registra el respaldo original. La preparación de 2026 añade los proyectos v145 y la prueba local.

- **2026-11-18** Agrega una captura de la consulta LDAP ficticia y aislada que se registró el 20 de noviembre de 2026.

### Requisitos


Usa Developer PowerShell con la carga Desarrollo para el escritorio con C++, los componentes MFC y ATL de C++ para x86/x64, MSVC v145 14.51.36231 y Windows SDK 10.0.26100.0. Proporciona los archivos de la libreta de direcciones de Windows (WAB) de Windows SDK 7.1 y las bibliotecas de tipos `MSOUTL.OLB` 16.0.19929.20032, `MSO.DLL` de Office 16.0.20527.20196 y `MSADDNDR.DLL` 6.00.8100. El complemento tiene que coincidir con la arquitectura de Outlook. Esta solución compila para Win32. Usa las rutas de Office de tu equipo de prueba. La compilación deja el registro COM a cargo del operador. Obtén las cabeceras WAB y la biblioteca x86 de Windows SDK 7.1 de Microsoft. Usa MSOUTL.OLB y MSO.DLL de una instalación con licencia de Outlook de escritorio y Office de 32 bits. No se pudo identificar qué paquete de Microsoft aportó la copia probada de MSADDNDR.DLL 6.00.8100. Si falta esa biblioteca, usa el probador LDAP separado.

### Cómo empezar

Compila la solución desde la raíz del repositorio.

```powershell
$wab = 'C:\ruta\Windows-SDK-7.1\WAB'
$outlook = 'C:\ruta\Office16'
$office = 'C:\ruta\Microsoft Shared\Office16'
$designer = 'C:\ruta\Designer'
MSBuild .\src\LDAPSyncOutlook.sln /m:1 /t:Build /p:Configuration=Release /p:Platform=Win32 /p:PreferredToolArchitecture=x64 "/p:LegacyWabSdk=$wab" "/p:OutlookTypeDirectory=$outlook" "/p:OfficeTypeDirectory=$office" "/p:DesignerTypeDirectory=$designer"
```

### Uso

Usa un perfil separado de Outlook y un directorio LDAP ficticio. En la ventana de escritorio define un rótulo, el servidor LDAP y la base de búsqueda. Elige una carpeta de Outlook de prueba. Pulsa **Agregar**. Luego haz clic derecho en la configuración guardada y elige **Actualizar**. Coteja el contacto ficticio con la carpeta después de sincronizar.

### Estructura del proyecto

`docs/media/` contiene la captura del probador LDAP.

`demo/ldap/` contiene el directorio ficticio de OpenLDAP y el proyecto `Probe.vcxproj` del probador.

`src/LDAPSyncOutlook/` contiene la aplicación de escritorio, `src/LDAPSyncOutlookAddin/` el complemento y `src/comun/` la consulta LDAP y la relación de contactos. `src/mapi/` contiene cabeceras históricas. `installer/` contiene el script NSIS. Los proyectos y cabeceras originales conservan sus avisos.

### Verificación

Este commit de compatibilidad usa las bibliotecas de tipos de Office y Outlook instaladas en las rutas indicadas a MSBuild. Las dos importaciones de Outlook asignan un alias distinto al símbolo de reuniones en línea para evitar el choque en las cabeceras. La prueba local comprueba la consulta LDAP compartida con un contacto ficticio. La importación y el complemento requieren un perfil aislado de Outlook. Ese perfil no estaba disponible para el ensayo.

La captura muestra al probador de consola consultando a Alicia Ejemplo en un directorio local. La misma función de lectura la comparten el programa de escritorio y el complemento.

La solución y la consulta LDAP se repitieron el 2026-11-23 en Windows 11 compilación 26300. La captura corresponde al ensayo del 20 de noviembre de 2026 de la misma sonda y directorio ficticio.

![La consulta local devuelve a la usuaria ficticia Alicia Ejemplo](docs/media/ldap-query.png)

La [guía local de LDAP](demo/ldap/README.md) usa el mismo directorio ficticio de la sonda registrada. El ensayo usó una instancia local de OpenLDAP preparada por separado.

MSBuild 18.11.1.51303 compiló el cliente Win32 y el complemento. Un ejecutable de prueba llamó al método original de lectura contra OpenLDAP 2.5.13+dfsg-5 desechable en 127.0.0.1 y obtuvo un contacto ficticio. La prueba cubrió la consulta. Guardar en Outlook, registrar el complemento y ejecutar el instalador requieren un perfil de prueba separado de Windows y Outlook.

### Soporte

Usa una ficha ficticia para indicar la pantalla, el commit y la versión de Outlook o LDAP donde ocurre el problema.

### Contribuir

Incluye la compilación del cliente y el complemento, y una prueba con un directorio ficticio al proponer un cambio.

### Licencia

Consulta [MIT](LICENSE) para el código propio. Los componentes archivados conservan sus [avisos de terceros](THIRD-PARTY-NOTICES.md).
