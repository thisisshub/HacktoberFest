### Clears all users proxy settings ###
# searches for all system users via registry ID, and clears each user identified on the system.

$stuff = $(Get-ChildItem "HKLM:\Software\Microsoft\Windows NT\CurrentVersion\ProfileList").name
$new = $(foreach ($thing in $stuff) { Get-ItemProperty registry::"$thing" | select ProfileImagePath, PSChildName })

foreach ($newer in $new) {
    $name = $newer.PSChildName
    #$name
    $newer.ProfileImagePath
    $(Get-ItemPropertyValue  registry::"HKU\"$name"\Software\Microsoft\Windows\CurrentVersion\Internet Settings" -Name ProxyEnable) 2> $null
    Remove-ItemProperty registry::"HKU\"$name"\Software\Microsoft\Windows\CurrentVersion\Internet Settings" -Name AutoDetect 2> $null
    Remove-ItemProperty registry::"HKU\"$name"\Software\Microsoft\Windows\CurrentVersion\Internet Settings" -Name ProxyEnable 2> $null
    Remove-ItemProperty registry::"HKU\"$name"\Software\Microsoft\Windows\CurrentVersion\Internet Settings" -Name ProxyServer 2> $null
    Remove-ItemProperty registry::"HKU\"$name"\Software\Microsoft\Windows\CurrentVersion\Internet Settings" -Name ProxyOverride 2> $null
    Remove-ItemProperty registry::"HKU\"$name"\Software\Microsoft\Windows\CurrentVersion\Internet Settings" -Name EnableNegotiate 2> $null
    Remove-ItemProperty registry::"HKU\"$name"\Software\Microsoft\Windows\CurrentVersion\Internet Settings\Connections" -Name SavedLegacySettings 2> $null
    #Remove-ItemProperty registry::"HKU\"$name"\Software\Microsoft\Windows\CurrentVersion\Internet Settings\Connections" -Name DefaultConnectionSettings 2> $null

    #Test-Path registry::"HKU\"$name"\Software\Microsoft\Windows\CurrentVersion\Internet Settings" -Name ProxyEnable
}

### Created by Rob Fitz
