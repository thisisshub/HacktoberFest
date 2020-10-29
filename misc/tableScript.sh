#!/bin/bash

#TODO improve directory input
function initialize() {
    
    inpath=$(readlink -f $1)
    outpath=$(readlink -f $2)
    
    files=()
    
    # TODO change for photorec
    if [[ "${inpath##*/}" = 'recup_dir.1' ]]
    then
        files+=("$outpath.photorec")
        mv $inpath/report.xml $HOME
        compute $inpath "photorec"
        mv $HOME/report.xml $inpath
    else
        
        # take all directories from input directory
        for dir in $inpath/*/
        do
            dir=${dir%*/}
            extension=${dir##/*/}
            
            files+=("$outpath.$extension")
            
            compute $dir $extension &
            
        done
        wait
    fi
    
    # merge all files
    for file in "${files[@]}"
    do
        cat $file >> $outpath
        rm $file
    done
    
    # clear duplicate single file
    sort -u -k 1,1 $outpath -o $outpath
    #sort records by type single file
    sort -k 2 $outpath -o $outpath
    
    #Full merge of files
    
    #result=$(dirname "$outpath")
    #result=$result"/result.txt"
    cat $outpath >> result.txt
    
    # clear in duplicate file
    sort -u -k 1,1 result.txt -o result.txt
    sort -k 2 result.txt -o result.txt
    
    
    
    echo "Start new directory?(y\n)"
    read decision
    
    if [[ "$decision" = 'y' ]]
    then
        echo "Insert directory"
        read directory
        echo "Insert output file"
        read file
        
        initialize $directory $file
    else
        echo "closed"
        return 1
    fi
}


# compute md5 for all files in a directory
function compute() {
    
    for x in $1/*
    do
        echo "$(md5sum $x) ${x##/*.} $(du -h $x)" | gawk '{print $1 "\t" $3 "\t" $4 }' >> $outpath"."$2
    done
}


if (( $# != 2 ))
then
    echo "No arguments supplied"
    echo "Usage: start inputdirectory outputfile"
    return 1
else
    initialize $1 $2
    
    echo -e 'MD5\tFOREMOST\tSCALPEL\tPHOTOREC\tTYPE\tDIMENSION' >> table.csv
    
    gawk 'FNR==NR{a[$1]="YES";next}{print $1, a[$1]?a[$1]:"NO", "\t" $2 "\t" $3}' foremost.txt result.txt >> tmp.txt
    gawk 'FNR==NR{a[$1]="YES";next}{print $1 "\t" $2 "\t" ,a[$1]?a[$1]:"NO", "\t"  $3 "\t"  $4}' scalpel.txt tmp.txt >> tmp2.txt
    gawk 'FNR==NR{a[$1]="YES";next}{print $1 "\t" $2 "\t" $3 "\t" ,a[$1]?a[$1]:"NO", "\t"  $4 "\t"  $5}' photorec.txt tmp2.txt >> table.csv
    
    rm tmp.txt tmp2.txt
fi
