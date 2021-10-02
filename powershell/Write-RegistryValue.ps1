# This PowerShell script is used to add the Key Value to Registry in Windows Operating System
# Go through the script before execution & change the options accordingly


function Write-RegistryValue {
[CmdletBinding(SupportsShouldProcess=$True,
    ConfirmImpact='Medium',
    HelpURI='http://vcloud-lab.com',
    DefaultParameterSetName='NewValue')]
    Param ( 
        [parameter(ParameterSetName = 'NewValue', Position=0, ValueFromPipeline=$True, ValueFromPipelineByPropertyName=$True)]
        [parameter(ParameterSetName = 'NewKey', Position=0, ValueFromPipeline=$True, ValueFromPipelineByPropertyName=$True)]
        [alias('C')]
        [String[]]$ComputerName = '.',

        [Parameter(ParameterSetName = 'NewValue', Position=1, Mandatory=$True, ValueFromPipelineByPropertyName=$True)]
        [parameter(ParameterSetName = 'NewKey', Position=1, ValueFromPipelineByPropertyName=$True)]
        [alias('Hive')]
        [ValidateSet('ClassesRoot', 'CurrentUser', 'LocalMachine', 'Users', 'CurrentConfig')]
        [String]$RegistryHive = 'LocalMachine',

        [Parameter(ParameterSetName = 'NewValue', Position=2, Mandatory=$True, ValueFromPipelineByPropertyName=$True)]
        [parameter(ParameterSetName = 'NewKey', Position=2, ValueFromPipelineByPropertyName=$True)]
        [alias('ParentKeypath')]
        [String]$RegistryKeyPath = 'SYSTEM\CurrentControlSet\Software',

        [parameter(ParameterSetName = 'NewKey',Position=3, Mandatory=$True, ValueFromPipelineByPropertyName=$true)]
        [String]$ChildKey = 'TestKey',
    
        [parameter(ParameterSetName = 'NewValue',Position=4, Mandatory=$True, ValueFromPipelineByPropertyName=$true)]
        [alias('Type')]
        [ValidateSet('String', 'Binary', 'DWord', 'QWord', 'MultiString', 'ExpandString')]
        [String]$ValueType = 'DWORD',

        [parameter(ParameterSetName = 'NewValue',Position=5, Mandatory=$True, ValueFromPipelineByPropertyName=$true)]
        [String]$ValueName = 'ValueName',

        [parameter(ParameterSetName = 'NewValue',Position=6, Mandatory=$True, ValueFromPipelineByPropertyName=$true)]
        [String]$ValueData = 'ValueData'
    )
    Begin {
        $RegistryRoot= "[{0}]::{1}" -f 'Microsoft.Win32.RegistryHive', $RegistryHive
        try {
            $RegistryHive = Invoke-Expression $RegistryRoot -ErrorAction Stop
        }
        catch {
            Write-Host "Incorrect Registry Hive mentioned, $RegistryHive does not exist" 
        }
    }
    Process {
        Foreach ($Computer in $ComputerName) {
            if (Test-Connection $Computer -Count 2 -Quiet) {
                try {
                    $reg = [Microsoft.Win32.RegistryKey]::OpenRemoteBaseKey($RegistryHive, $Computer)
                    $key = $reg.OpenSubKey($RegistryKeyPath, $true)
                }
                catch {
                    Write-Host "Check access on computer name $Computer, cannot connect registry" -BackgroundColor DarkRed
                    Continue
                }
                switch ($PsCmdlet.ParameterSetName) {
                    'NewValue' {
                        $ValueType = [Microsoft.Win32.RegistryValueKind]::$ValueType
                        $key.SetValue($ValueName,$ValueData,$ValueType)
                        $Data = $key.GetValue($ValueName)
                        $Obj = New-Object psobject
                        $Obj | Add-Member -Name Computer -MemberType NoteProperty -Value $Computer
                        $Obj | Add-Member -Name RegistryPath -MemberType NoteProperty -Value "$RegistryKeyPath"
                        $Obj | Add-Member -Name RegistryValueName -MemberType NoteProperty -Value $ValueName
                        $Obj | Add-Member -Name RegistryValueData -MemberType NoteProperty -Value $ValueData
                        $Obj
                        break
                    }
                    'NewKey' {
                        try {
                            if ($key.GetSubKeyNames() -contains $ChildKey) {
                                $Obj = New-Object psobject
                                $Obj | Add-Member -Name Computer -MemberType NoteProperty -Value $Computer
                                $Obj | Add-Member -Name RegistryPath -MemberType NoteProperty -Value $RegistryKeyPath
                                $Obj | Add-Member -Name RegistryChildKey -MemberType NoteProperty -Value $Childkey
                                $Obj
                                Continue
                            }
                            [void]$Key.CreateSubKey("$ChildKey")
                        }
                        catch {
                            Write-Host "Not able to create $ChildKey on remote computer name $Computer" -BackgroundColor DarkRed
                            Continue
                        }
                        break
                    }
                }
            }
            else {
                Write-Host "Computer Name $Computer not reachable" -BackgroundColor DarkRed
            }
        }
    }
    End {
        #[Microsoft.Win32.RegistryHive]::ClassesRoot
        #[Microsoft.Win32.RegistryHive]::CurrentUser
        #[Microsoft.Win32.RegistryHive]::LocalMachine
        #[Microsoft.Win32.RegistryHive]::Users
        #[Microsoft.Win32.RegistryHive]::CurrentConfig
    }
}

#Write-RegistryValue -ComputerName server01, Member01, test, 192.168.33.11, 192.168.33.12, server01 -RegistryHive LocalMachine -RegistryKeyPath SYSTEM\DemoKey -ChildKey test
#Write-RegistryValue -ComputerName server01, Member01, test -RegistryHive LocalMachine -RegistryKeyPath SYSTEM\DemoKey -ValueName 'Start' -ValueData 10 -ValueType DWord
