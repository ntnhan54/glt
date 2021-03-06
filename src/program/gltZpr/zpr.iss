; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

[Setup]
AppName=GltZpr
AppVerName=GltZpr 0.4
AppPublisher=Nigel Stewart
AppPublisherURL=http://www.nigels.com/glt/gltzpr/
AppSupportURL=http://www.nigels.com/glt/gltzpr/
AppUpdatesURL=http://www.nigels.com/glt/gltzpr/
DefaultDirName={pf}\GltZpr
DefaultGroupName=GltZpr
AllowNoIcons=yes
Uninstallable=yes
; uncomment the following line if you want your installation to run on NT 3.51 too.
; MinVersion=4,3.51

[Tasks]

[Files]
Source: "..\..\..\msvc\Release\gltZpr.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "zpr.h"; DestDir: "{app}"; Flags: ignoreversion
Source: "zpr.c"; DestDir: "{app}"; Flags: ignoreversion
Source: "zprdemo.c"; DestDir: "{app}"; Flags: ignoreversion

[INI]
Filename: "{app}\gltZpr.url"; Section: "InternetShortcut"; Key: "URL"; String: "http://www.nigels.com/glt/gltzpr/"

[Icons]
Name: "{group}\GltZpr Demo"; Filename: "{app}\gltZpr.exe"
Name: "{group}\GltZpr on the Web"; Filename: "{app}\gltZpr.url"

[Run]
;Filename: "{app}\gltZpr.exe"; Description: "Launch GltZpr"; Flags: nowait postinstall skipifsilent

[UninstallDelete]
Type: files; Name: "{app}\gltZpr.url"

