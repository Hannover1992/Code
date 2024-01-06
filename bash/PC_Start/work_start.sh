#!/bin/bash

# Funktion zum Öffnen einer URL in einem neuen Fenster
open_url() {
  if [[ "$1" == *"teams.microsoft.com"* ]]; then
    teams_command="-chrome --app=$1"  # Anpassen Sie den Befehl für Ihren Chrome-Browser
    $teams_command &
  else
    chrome_command="google-chrome"  # Anpassen Sie den Befehl für Ihren Chrome-Browser
    $chrome_command "$1" &
  fi
}

# URLs zum Öffnen
urls=(
  "https://outlook.office365.com/mail/inbox/id/AAQkADdhNzEwZjM2LTcyOGItNGViMC04NDQwLWVlZTgwYTI5ZmI4NAAQAErfn%2BQXhsNGgCgd816DGDE%3D"
  "https://outlook.office365.com/mail/support@cpc-baulogistik.de/inbox/id/AAQkAGRhM2JjYTg1LWJhOWQtNDc2Ny1hYmEwLTYxNmFmZTdlZmFkNgAQAOKq%2BFf4hBtFkLvBor7vNYc%3D"
  "https://outlook.office365.com/mail/sysint@cpc-baulogistik.de/inbox/id/AAQkADkxYjQ0YWFkLTU4NDEtNGU5Yi04ZTQxLTYxNmVhMjY4ZjE1MQAQAPLGUxQje5lJjU7qZyAhA9I%3D"
  "https://teams.microsoft.com/_?culture=de-de&country=de#/conversations/19:add4072ec217469a9fa39952e120c71a@thread.v2?ctx=chat",
"https://teams.microsoft.com/_?culture=de-de&country=de#/conversations/19:275b649d-169c-43f0-866f-9b433d294018_bbfdd9e1-bbf0-48ac-a403-7710760315df@unq.gbl.spaces?ctx=chat"
)

# URLs in neuen Fenstern öffnen
for url in "${urls[@]}"; do
  open_url "$url"
done
