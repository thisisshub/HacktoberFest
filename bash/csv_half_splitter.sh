#!/bin/bash
# Pass a file in as the first argument on the command line (note, not secure)
file=$1

# Get the header file out
header=$(head -1 "$file")

# Separate the data from the header
tail -n +2 "$file" > output.data

ln=$(cat "$file" | wc -l)

z=$((ln / 2))
echo "$z"

fname="${file%%.*}"

split -l "$z" output.data "$fname"

# Append the header back into each file from split
for part in $(ls -1 "$fname"*)
do
  if [[ "$part" != *".csv" ]];
  then
    echo "$part"
    printf "%s\n%s" "$header" "$(cat "$part")" > "$part.csv"
    rm "$part"
  fi
done

rm "output.data"