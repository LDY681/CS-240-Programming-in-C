#/bin/bash

if [ $# -ne 2 ]
then
  echo "Usage: `basename $0` server-prog port"
  exit 1
fi

SERVER=$1
PORT=$2

echo "Start Test 6"

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

echo Create Room
./TestIRCServer localhost $PORT "CREATE-ROOM superman clarkkent java-programming"

echo Enter room
./TestIRCServer localhost $PORT "ENTER-ROOM superman clarkkent java-programming"
./TestIRCServer localhost $PORT "ENTER-ROOM aquaman xyz java-programming"

echo Print users in room
./TestIRCServer localhost $PORT "GET-USERS-IN-ROOM superman clarkkent java-programming"

echo Enter another user
./TestIRCServer localhost $PORT "ENTER-ROOM mary poppins java-programming"

echo Print users in room
./TestIRCServer localhost $PORT "GET-USERS-IN-ROOM mary poppins java-programming"

echo Send message
./TestIRCServer localhost $PORT "SEND-MESSAGE mary poppins java-programming Hi everybody!"
./TestIRCServer localhost $PORT "SEND-MESSAGE mary poppins java-programming Welcome to the talk program!"

echo Get messages
./TestIRCServer localhost $PORT "GET-MESSAGES superman clarkkent 0 java-programming"

echo Send message
./TestIRCServer localhost $PORT "SEND-MESSAGE superman clarkkent java-programming Hi Mary!"
./TestIRCServer localhost $PORT "SEND-MESSAGE superman clarkkent java-programming Here I am working on cs240"
./TestIRCServer localhost $PORT "SEND-MESSAGE superman clarkkent java-programming I am testing the project"
./TestIRCServer localhost $PORT "SEND-MESSAGE superman clarkkent java-programming message 1"
./TestIRCServer localhost $PORT "SEND-MESSAGE superman clarkkent java-programming message 2"
./TestIRCServer localhost $PORT "SEND-MESSAGE superman clarkkent java-programming message 3"
./TestIRCServer localhost $PORT "SEND-MESSAGE superman clarkkent java-programming message 4"
./TestIRCServer localhost $PORT "SEND-MESSAGE superman clarkkent java-programming message 5"
./TestIRCServer localhost $PORT "SEND-MESSAGE superman clarkkent java-programming message 6"
./TestIRCServer localhost $PORT "SEND-MESSAGE superman clarkkent java-programming message 7"
./TestIRCServer localhost $PORT "SEND-MESSAGE superman clarkkent java-programming message 8"

echo Get messages from 0
./TestIRCServer localhost $PORT "GET-MESSAGES mary poppins 0 java-programming"

echo Enter another user
./TestIRCServer localhost $PORT "LEAVE-ROOM mary poppins java-programming"

echo Get messages from 2
./TestIRCServer localhost $PORT "GET-MESSAGES superman clarkkent 2 java-programming"

# Kill server
echo Killing Server
PID=`ps | grep IRCServer | awk '{ print $1;}'`
kill -9 $PID

