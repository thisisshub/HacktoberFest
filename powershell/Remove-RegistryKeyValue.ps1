# This PowerShell script can be used to delete the Key Values at Registry in Windows Operating System
# Go through the code before execution & change the options accordingly


function Remove-RegistryKeyValue {
[CmdletBinding(SupportsShouldProcess=$True,
    ConfirmImpact='Medium',
    HelpURI='http://vcloud-lab.com',
    DefaultParameterSetName='DelValue')]
    Param ( 
        [parameter(ParameterSetName = 'DelValue', Position=0, ValueFromPipeline=$True, ValueFromPipelineByPropertyName=$True)]
        [parameter(ParameterSetName = 'DelKey', Position=0, ValueFromPipeline=$True, ValueFromPipelineByPropertyName=$True)]
        [alias('C')]
        [String[]]$ComputerName = '.',

        [Parameter(ParameterSetName = 'DelValue', Position=1, Mandatory=$True, ValueFromPipelineByPropertyName=$True)]
        [parameter(ParameterSetName = 'DelKey', Position=1, ValueFromPipelineByPropertyName=$True)]
        [alias('Hive')]
        [ValidateSet('ClassesRoot', 'CurrentUser', 'LocalMachine', 'Users', 'CurrentConfig')]
        [String]$RegistryHive = 'LocalMachine',

        [Parameter(ParameterSetName = 'DelValue', Position=2, Mandatory=$True, ValueFromPipelineByPropertyName=$True)]
        [parameter(ParameterSetName = 'DelKey', Position=2, ValueFromPipelineByPropertyName=$True)]
        [alias('ParentKeypath')]
        [String]$RegistryKeyPath,

        [parameter(ParameterSetName = 'DelKey',Position=3, Mandatory=$True, ValueFromPipelineByPropertyName=$true)]
        [String[]]$ChildKey,
    
        [parameter(ParameterSetName = 'DelValue',Position=5, Mandatory=$True, ValueFromPipelineByPropertyName=$true)]
        [String[]]$ValueName
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
                    Write-Host "Check permissions on computer name $Computer, cannot connect registry" -BackgroundColor DarkRed
                    Continue
                }
                switch ($PsCmdlet.ParameterSetName) {
                    'DelValue' {
                        foreach ($regvalue in $ValueName) {
                            if ($key.GetValueNames() -contains $regvalue) {
                                [void]$key.DeleteValue($regvalue)
                            }
                            else {
                                Write-Host "Registry value name $regvalue doesn't exist on Computer $Computer under path $RegistryKeyPath" -BackgroundColor DarkRed
                            }
                        }
                        break
                    }
                    'DelKey' {
                        foreach ($regkey in $ChildKey) {
                            if ($key.GetSubKeyNames() -contains $regkey) {
                                [void]$Key.DeleteSubKey("$regkey")
                            }
                            else {
                                Write-Host "Registry key $regKey doesn't exist on Computer $Computer under path $RegistryKeyPath" -BackgroundColor DarkRed
                            }
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

#Remove-RegistryKeyValue -ComputerName server01, member01 -RegistryHive LocalMachine -RegistryKeyPath SYSTEM\DemoKey -ChildKey test1, test2
#Remove-RegistryKeyValue -ComputerName server01, member01 -RegistryHive LocalMachine -RegistryKeyPath SYSTEM\DemoKey -ValueName start, exp
