#/bin/bash

if [ $# -ne 2 ]
then
  echo "Usage: `basename $0` server-prog port"
  exit 1
fi

SERVER=$1
PORT=$2

echo "Start Test 7"

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

./TestIRCServer localhost $PORT "GET-ALL-USERS superman clarkkent"

echo Test password in GET_ALL_USERS
./TestIRCServer localhost $PORT "GET-ALL-USERS superman badpassword"
./TestIRCServer localhost $PORT "GET-ALL-USERS baduser badpassword"

echo Create Room
./TestIRCServer localhost $PORT "CREATE-ROOM superman clarkkent java-programming"

echo Test password in ENTER-ROOM
./TestIRCServer localhost $PORT "ENTER-ROOM superman badpassword java-programming"
./TestIRCServer localhost $PORT "ENTER-ROOM baduser badpassword java-programming"

echo Test password in GET-USERS-IN-ROOM
./TestIRCServer localhost $PORT "GET-USERS-IN-ROOM superman badpassword java-programming"
./TestIRCServer localhost $PORT "GET-USERS-IN-ROOM baduser badpassword java-programming"

echo Test password in LEAVE-ROOM
./TestIRCServer localhost $PORT "LEAVE-ROOM superman badpassword java-programming"
./TestIRCServer localhost $PORT "LEAVE-ROOM baduser badpassword java-programming"

echo Test password in SEND-MESSAGE
./TestIRCServer localhost $PORT "SEND-MESSAGE superman badpassword java-programming"
./TestIRCServer localhost $PORT "SEND-MESSAGE baduser badpassword java-programming"

echo Test password in GET-MESSAGES
./TestIRCServer localhost $PORT "GET-MESSAGES superman badpassword java-programming"
./TestIRCServer localhost $PORT "GET-MESSAGES baduser badpassword java-programming"

echo Test password OK
./TestIRCServer localhost $PORT "GET-ALL-USERS mary poppins"

# Kill server
echo Killing Server
PID=`ps | grep IRCServer | awk '{ print $1;}'`
kill -9 $PID
