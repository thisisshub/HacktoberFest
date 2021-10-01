#!/bin/bash

echo "[+] Searching for SUID Binaries (https://gtfobins.github.io/)"
for binary in $(find / -type f -perm -04000 -ls 2>/dev/null | awk '{print $NF}')
do
    echo -e "\t[>] $binary"
done
