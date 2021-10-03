# Let's install Microsoft Teams Module  
Install-Module MicrosoftTeams

# Let's add MicrosoftTeams Module to the current session
Import-Module MicrosoftTeams

# Let's get global admin credentials
$credentials=Get-Credential

# Let's connect to Microsoft Teams
Connect-MicrosoftTeams -Credential $credentials

# Let's get all the teams
Get-Team
