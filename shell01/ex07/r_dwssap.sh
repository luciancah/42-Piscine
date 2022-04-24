cat /etc/passwd | grep -v "#" | awk "NR % 2 == 0" | cut -f 1 -d ":" | rev | sort -r | awk "NR >= $FT_LINE1 && NR <= $FT_LINE2" | xargs | sed -e "s/ /, /g" | xargs | sed "s/$/./g" | tr -d "\n"
