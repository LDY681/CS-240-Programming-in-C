#/bin/bash

if [ $# -ne 2 ]
then
  echo "Usage: `basename $0` server-prog port"
  exit 1
fi

SERVER=$1
PORT=$2

echo "Start Test 1"

#echo Killing Server if any
PID=`ps | grep IRCServer | awk '{ print $1;}'`
kill -9 $PID 2> /dev/null
sleep 2

#Start server in the background
rm -f password.txt
$SERVER $PORT > talk-server.out &
sleep 1

echo Add Users
./TestIRCServer localhost $PORT "ADD-USER superman clarkkent"
./TestIRCServer localhost $PORT "ADD-USER spiderman peterpark"
./TestIRCServer localhost $PORT "ADD-USER aquaman xyz"
./TestIRCServer localhost $PORT "ADD-USER mary poppins"


echo Print Users
./TestIRCServer localhost $PORT "GET-ALL-USERS superman clarkkent"
# Kill server
echo Killing Server
PID=`ps | grep IRCServer | awk '{ print $1;}'`
kill -9 $PID

