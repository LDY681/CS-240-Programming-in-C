#!/bin/bash

if [ ! -d "debugging_log" ]; then mkdir "debugging_log"; fi

LOGNUM=0

while true; do
        if [ -e "debugging_log/log$LOGNUM" ]
        then
                LOGNUM=$((LOGNUM+1))
        else
                touch "debugging_log/log$LOGNUM";
                break
        fi
done

echo `date` > "debugging_log/log$LOGNUM"

/usr/bin/gdb --eval-command="set logging file debugging_log/log$LOGNUM" \
        --eval-command="set trace-commands on" \
        --eval-command="set logging on" \
        "$@"

