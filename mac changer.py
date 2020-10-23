import subprocess
 
subprocess.call(["sudo","ifconfig","ens33","down"])
subprocess.call(["sudo","ifconfig","ens33","hw","ether","00:11:22:33:44:55"])
subprocess.call(["sudo","ifconfig","ens33","up"])