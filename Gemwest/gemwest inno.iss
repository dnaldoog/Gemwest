; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

#define MyAppName "Gemwest"
#define MyAppVersion "v3.0.0"
#define MyAppPublisher "Zaniah"
#define MyAppURL "https://github.com/dnaldoog/Gemwest"
#define MyAppExeName "Gemwest.exe"
#define USER "zan64"
#define BuildPath "Desktop\build"


[Setup]
; NOTE: The value of AppId uniquely identifies this application. Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{BAB0378D-47D6-4627-BA0C-11D4E5A27347}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
;AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName={autopf}\{#MyAppName}
DisableProgramGroupPage=yes
LicenseFile=C:\Users\{#USER}\{#BuildPath}\COPYING.txt
; Uncomment the following line to run in non administrative install mode (install for current user only.)
;PrivilegesRequired=lowest
OutputBaseFilename=Gemwest setup
SetupIconFile=C:\Users\{#USER}\{#BuildPath}\app.ico
Compression=lzma
SolidCompression=yes
WizardStyle=modern

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
Source: "C:\Users\{#USER}\{#BuildPath}\CSconfig.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\{#USER}\{#BuildPath}\gemreference.json"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\{#USER}\{#BuildPath}\{#MyAppExeName}"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\{#USER}\{#BuildPath}\Newtonsoft.Json.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\{#USER}\{#BuildPath}\msvcp140.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\{#USER}\{#BuildPath}\vcruntime140.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\{#USER}\{#BuildPath}\vcruntime140_1.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\{#USER}\{#BuildPath}\app.ico"; DestDir: "{app}"; Flags: ignoreversion
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Icons]
Name: "{autoprograms}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{autodesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent

