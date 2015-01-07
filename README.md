# LDAPSyncOutlook

[Español](#español) · [English](#english)

## Español

Herramienta para llevar a Outlook los contactos guardados en un directorio compartido. Su objetivo es que las fichas de contactos se puedan consultar en Outlook cuando el directorio es la fuente de los datos.

### Esta revisión

**2015-01-07 · Sincronizar contactos organizados por grupo.** Actualiza el lector LDAP, el modelo de contactos y la integración con Outlook para procesar grupos del directorio. De esta forma, el flujo de sincronización puede usar los contactos agrupados de la fuente.

### Cómo explorar el código

El código se creó para Windows y Visual C++. Usa las versiones de MFC o de los SDK que indiquen la solución y sus referencias. Los recursos y componentes externos de la época pueden requerir una copia autorizada. La compilación completa depende de ese entorno original.

- [src/LDAPSyncOutlook.sln](src/LDAPSyncOutlook.sln)
- [src/LDAPSyncOutlook/LDAPSyncOutlook.sln](src/LDAPSyncOutlook/LDAPSyncOutlook.sln)
- [src/LDAPSyncOutlookAddin/OutlookAddin.sln](src/LDAPSyncOutlookAddin/OutlookAddin.sln)
- [src/LDAPSyncOutlookAddin/OutlookAddin.vcproj](src/LDAPSyncOutlookAddin/OutlookAddin.vcproj)

## English

A tool for bringing contacts from a shared directory into Outlook. It makes directory-managed contact records available for lookup in Outlook.

### This revision

**2015-01-07 · Synchronize contacts organized by directory group.** Update the LDAP reader, contact model, and Outlook integration to handle directory groups. The synchronization workflow can then use the contacts grouped in the source.

### How to explore the source

The code was written for Windows and Visual C++. Use the MFC and SDK versions indicated by the solution and its references. Historical resources and external components may require an authorized copy. A full build depends on that original environment.

- [src/LDAPSyncOutlook.sln](src/LDAPSyncOutlook.sln)
- [src/LDAPSyncOutlook/LDAPSyncOutlook.sln](src/LDAPSyncOutlook/LDAPSyncOutlook.sln)
- [src/LDAPSyncOutlookAddin/OutlookAddin.sln](src/LDAPSyncOutlookAddin/OutlookAddin.sln)
- [src/LDAPSyncOutlookAddin/OutlookAddin.vcproj](src/LDAPSyncOutlookAddin/OutlookAddin.vcproj)
