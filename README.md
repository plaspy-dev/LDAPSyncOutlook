# LDAPSyncOutlook

[Español](#español) · [English](#english)

## Español

Herramienta para llevar a Outlook los contactos guardados en un directorio compartido. Su objetivo es que las fichas de contactos se puedan consultar en Outlook cuando el directorio es la fuente de los datos.

### Qué puedes hacer

- Incluye el módulo de sincronización y el proyecto del complemento de Outlook.
- Reúne la consulta LDAP y la integración con contactos de Outlook.
- Conserva el historial recuperado de las dos piezas de Windows.

### Ejemplo

Usa un directorio y un perfil de Outlook de laboratorio con un contacto ficticio. Sigue el recorrido desde el directorio hasta la libreta de prueba.

### Cómo empezar

El código se creó para Windows y Visual C++. Usa las versiones de MFC o de los SDK que indiquen la solución y sus referencias. Los recursos y componentes externos de la época pueden requerir una copia autorizada. La compilación completa depende de ese entorno original.

Puntos de entrada en el código. [`src/LDAPSyncOutlook.sln`](src/LDAPSyncOutlook.sln), [`src/LDAPSyncOutlook/LDAPSyncOutlook.sln`](src/LDAPSyncOutlook/LDAPSyncOutlook.sln), [`src/LDAPSyncOutlookAddin/OutlookAddin.sln`](src/LDAPSyncOutlookAddin/OutlookAddin.sln), [`src/LDAPSyncOutlookAddin/OutlookAddin.vcproj`](src/LDAPSyncOutlookAddin/OutlookAddin.vcproj).

Las fechas del historial se apoyan en Git o en la evidencia disponible de los respaldos. Las fechas reconstruidas a partir de archivos sin zona horaria usan las 12:00 UTC como referencia.

## English

A tool for bringing contacts from a shared directory into Outlook. It makes directory-managed contact records available for lookup in Outlook.

### What you can do

- Includes the synchronization module and the Outlook add-in project.
- Brings together LDAP lookup and Outlook contact integration.
- Preserves the recovered history of both Windows components.

### Example

Use a test directory and Outlook profile with one fictional contact. Trace it from the directory into the test address book.

### Getting started

The code was written for Windows and Visual C++. Use the MFC and SDK versions indicated by the solution and its references. Historical resources and external components may require an authorized copy. A full build depends on that original environment.

Entry points in the source. [`src/LDAPSyncOutlook.sln`](src/LDAPSyncOutlook.sln), [`src/LDAPSyncOutlook/LDAPSyncOutlook.sln`](src/LDAPSyncOutlook/LDAPSyncOutlook.sln), [`src/LDAPSyncOutlookAddin/OutlookAddin.sln`](src/LDAPSyncOutlookAddin/OutlookAddin.sln), [`src/LDAPSyncOutlookAddin/OutlookAddin.vcproj`](src/LDAPSyncOutlookAddin/OutlookAddin.vcproj).

History dates come from Git or available backup evidence. Reconstructed dates from files with no time zone use 12:00 UTC as a reference.
