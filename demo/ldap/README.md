# Local LDAP trial · Prueba LDAP local

## English

Build the probe from Developer PowerShell with MSVC v145, the Win32 MFC workload and Windows SDK 10.0.26100.0. Build the local image before the trial so Docker can cache Debian and its packages. Then run the probe against the directory on loopback.

```powershell
MSBuild demo\ldap\Probe.vcxproj /t:Build /p:Configuration=Release /p:Platform=Win32
docker build -t ldapsyncoutlook-test:local demo/ldap
docker run --rm --detach --name prueba-ldapsyncoutlook-ldap --publish 127.0.0.1:1389:389 ldapsyncoutlook-test:local
.\demo\ldap\bin\Probe.exe 1389
docker logs prueba-ldapsyncoutlook-ldap
docker stop prueba-ldapsyncoutlook-ldap
```

Wait for `slapd starting` in the log before running the probe. Success prints `1 fictional contact read`. The probe reads Alicia Ejemplo using the original LDAP code and stores any registry writes in a temporary process-local mapping. It never opens Outlook.

## Español

Compila el probador desde Developer PowerShell con MSVC v145, el módulo MFC Win32 y Windows SDK 10.0.26100.0. Construye la imagen antes de la prueba para que Docker guarde Debian y sus paquetes. Ejecuta el probador contra el directorio en loopback.

```powershell
MSBuild demo\ldap\Probe.vcxproj /t:Build /p:Configuration=Release /p:Platform=Win32
docker build -t ldapsyncoutlook-test:local demo/ldap
docker run --rm --detach --name prueba-ldapsyncoutlook-ldap --publish 127.0.0.1:1389:389 ldapsyncoutlook-test:local
.\demo\ldap\bin\Probe.exe 1389
docker logs prueba-ldapsyncoutlook-ldap
docker stop prueba-ldapsyncoutlook-ldap
```

Espera a que el registro indique `slapd starting`. La prueba correcta imprime `1 fictional contact read`. El probador recupera a Alicia Ejemplo con el código original de LDAP. Las escrituras del Registro quedan en una asignación temporal del proceso. El programa de prueba no abre Outlook.
