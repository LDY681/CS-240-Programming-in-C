/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:

**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtWidgets>
#include "dialog.h"
#include <string>
#include <string.h>
#include <stdio.h>
#include <iostream>
//
#include <talk_client.h>
//


using namespace std;


talk_client* client;
int port = 19672;
int currnum = -1;
int totalnum = -1;

void Dialog::sendAction()
{
    QString text1 = inputUser->text();
    string s1 = text1.toUtf8().constData();
    QString text2 = inputPassword->text();
    string s2 = text2.toUtf8().constData();

    QString text4 = inputERoom->text();
    string s4 = text4.toUtf8().constData();

    QString text = inputMessage->toPlainText();
    string s3 = text.toUtf8().constData();
    
    string space(" ");
    string s5 = s4 + space + s3;

   //TODO:
    char response[100];
    response[0] = '\0';
    client->sendCommand("localhost", port, "SEND-MESSAGE", strdup(s1.c_str()), strdup(s2.c_str()), strdup(s5.c_str()), response);
    cout << "the msg sent is" << response << endl;
    totalnum = totalnum + 1;

    printf("Send Button\n");
    //FIXME
}

void Dialog::newUserAction()
{
    QString text1 = inputUser->text();
    string s1 = text1.toUtf8().constData();
    QString text2 = inputPassword->text();
    string s2 = text2.toUtf8().constData();
    
    cout <<s1<< endl;
    cout <<s2<< endl;
    printf("New User Button\n");

    char response[100];
    response[0] = '\0';
    client->sendCommand("localhost", port, "ADD-USER", strdup(s1.c_str()), strdup(s2.c_str()), "", response);
}

void Dialog::loginAction()
{
    QString text1 = inputUser->text();
    string s1 = text1.toUtf8().constData();
    QString text2 = inputPassword->text();
    string s2 = text2.toUtf8().constData();
    cout <<s1<< endl;
    cout <<s2<< endl;
    printf("Login Buttom\n");

    char response[100];
    response[0] = '\0';

    client->sendCommand("localhost", port, "ADD-USER", strdup(s1.c_str()), strdup(s2.c_str()), "", response);
    timer->start(5000);
}

void Dialog::CroomAction()
{
    QString text1 = inputUser->text();
    string user = text1.toUtf8().constData();
    QString text2 = inputPassword->text();
    string pass = text2.toUtf8().constData();
    QString CRoom = inputCRoom->text();
    string Croom = CRoom.toUtf8().constData();
    cout <<Croom<< endl;
    printf("Create Room Buttom\n");

    char response[100];
    response[0] = '\0';
    client->sendCommand("localhost", port, "CREATE-ROOM", strdup(user.c_str()), strdup(pass.c_str()),strdup(Croom.c_str()), response);
    cout << " the response from create room is " << response << endl;
}

//TODO:
void Dialog::EroomAction()
{
    QString text1 = inputUser->text();
    string user = text1.toUtf8().constData();
    QString text2 = inputPassword->text();
    string pass = text2.toUtf8().constData();
    QString ERoom = inputERoom->text();
    string Eroom = ERoom.toUtf8().constData();
    cout <<Eroom<< endl;
    printf("Enter Room Buttom\n");

    char response[100];
    response[0] = '\0';
    client->sendCommand("localhost", port, "ENTER-ROOM", strdup(user.c_str()), strdup(pass.c_str()),strdup(Eroom.c_str()), response);
    cout << "the enter room is " << response << endl;




    //show messages of enter room
    string enter1 = Eroom+ " " + user + " entered room";
    client->sendCommand("localhost", port, "SEND-MESSAGE", strdup(user.c_str()), strdup(pass.c_str()), strdup(enter1.c_str()), response);
    cout << " does the entered room reponse send?" << response << endl;


    timer2->start(5000);
    timer3->start(5000);
}

//FIXME
void Dialog::LroomAction()
{
    QString text1 = inputUser->text();
    string user = text1.toUtf8().constData();
    QString text2 = inputPassword->text();
    string pass = text2.toUtf8().constData();
    QString LRoom = inputERoom->text();
    string Lroom = LRoom.toUtf8().constData();
    cout <<Lroom<< endl;
    printf("Leave Room Buttom\n");

    char response[100];
    response[0] = '\0';

    //show messages of enter room
    string enter1 = Lroom + " " + user + " left room";
    client->sendCommand("localhost", port, "SEND-MESSAGE", strdup(user.c_str()), strdup(pass.c_str()), strdup(enter1.c_str()), response);
    cout << " does the entered room reponse send?" << response << endl;



    client->sendCommand("localhost", port, "LEAVE-ROOM", strdup(user.c_str()), strdup(pass.c_str()),strdup(Lroom.c_str()), response);


}

void Dialog::timerAction()
{
//    printf("Timer wakeup\n");
//    messageCount++;

//    char message[50];
//    //sprintf(message,"Timer Refresh New message %d",messageCount);
//    //allMessages->append(message);
//    allMessages->clear();

    QString text1 = inputUser->text();
    string user = text1.toUtf8().constData();
    QString text2 = inputPassword->text();
    string pass = text2.toUtf8().constData();

    roomsList->clear();
    char response[100];
    response[0] = '\0';

    cout << "the4 user name is "  << user << endl;
    cout << " the password is "<< pass << endl;

    client->sendCommand("localhost", port, "LIST-ROOMS", strdup(user.c_str()), strdup(pass.c_str())," ", response);
    cout<< " ther esponse is " << response << endl;

    char *pch = strtok(response, "\r\n");
    while (pch != NULL){
        roomsList->addItem(pch);
        pch = strtok(NULL, "\r\n");
    }

}

void Dialog::timer2Action()
{
//    printf("Timer wakeup\n");
//    messageCount++;

//    char message[50];
//    //sprintf(message,"Timer Refresh New message %d",messageCount);
//    //allMessages->append(message);
//    allMessages->clear();

    QString text1 = inputUser->text();
    string user = text1.toUtf8().constData();
    QString text2 = inputPassword->text();
    string pass = text2.toUtf8().constData();
    QString text3 = inputERoom->text();
    string eroom = text3.toUtf8().constData();

    //Users
    usersList->clear();
    char response[100];
    response[0] = '\0';

    client->sendCommand("localhost", port, "GET-USERS-IN-ROOM", strdup(user.c_str()), strdup(pass.c_str()),strdup(eroom.c_str()), response);
    cout<< " ther users is " << response << endl;

    char *pch = strtok(response, "\r\n");
    while (pch != NULL){
        usersList->addItem(pch);
        pch = strtok(NULL, "\r\n");
    }

}

void Dialog::timer3Action()
{


    QString text1 = inputUser->text();
    string user = text1.toUtf8().constData();
    QString text2 = inputPassword->text();
    string pass = text2.toUtf8().constData();
    QString text3 = inputERoom->text();
    string eroom = text3.toUtf8().constData();


    allMessages->clear();
    char response2[1000];
    response2[0] = '\0';

    cout << "curr" << currnum << endl;
    cout << "total" << totalnum << endl;

    char *str1 = new char[20];
    sprintf(str1, "%d ", currnum);
    string str11(str1);

    string s3 = str11 + eroom;

    client->sendCommand("localhost", port, "GET-MESSAGES", strdup(user.c_str()), strdup(pass.c_str()), strdup(s3.c_str()), response2);
    cout << "args is" << user.c_str() <<pass.c_str() <<s3.c_str() << endl;
    cout<< " ther messages is " << response2 << endl;

    char *pch1 = strtok(response2, "\r\n");
    while (pch1 != NULL){
        allMessages->append(pch1);
        pch1 = strtok(NULL, "\r\n");
    }

}

Dialog::Dialog()
{
    createMenu();

    QVBoxLayout *mainLayout = new QVBoxLayout;

    ////////////////////////////////////////////////////////
    // Rooms List
    QVBoxLayout * roomsLayout = new QVBoxLayout();
    QLabel * roomsLabel = new QLabel("Rooms");
    roomsList = new QListWidget();
    roomsLayout->addWidget(roomsLabel);
    roomsLayout->addWidget(roomsList);

    // Users List
    QVBoxLayout * usersLayout = new QVBoxLayout();
    QLabel * usersLabel = new QLabel("Users");
    usersList = new QListWidget();
    usersLayout->addWidget(usersLabel);
    usersLayout->addWidget(usersList);

    // Layout for rooms and users
    QHBoxLayout *layoutRoomsUsers = new QHBoxLayout;
    layoutRoomsUsers->addLayout(roomsLayout);
    layoutRoomsUsers->addLayout(usersLayout);

    ///////////////////////////////////////////////////////////
    // Textbox for create room and create room button
    QVBoxLayout * inputCroomLayout = new QVBoxLayout();
    QLabel * inputCroomLabel = new QLabel("Create Room:");
    inputCRoom = new QLineEdit;
    inputCroomLayout->addWidget(inputCroomLabel);
    inputCroomLayout->addWidget(inputCRoom);

    QVBoxLayout * CroomLayout = new QVBoxLayout();
    QPushButton * CroomButton = new QPushButton("Create Room");
    CroomLayout->addWidget(CroomButton);

    // Layout for create room
    QHBoxLayout *layoutCrooms = new QHBoxLayout;
    layoutCrooms->addLayout(inputCroomLayout);
    layoutCrooms->addLayout(CroomLayout);

    connect(CroomButton, SIGNAL (released()), this, SLOT (CroomAction()));

    ///////////////////////////////////////////////////////////
    // Textbox for enter room textbox and enter room button and leave room buttom
    QVBoxLayout * inputEroomLayout = new QVBoxLayout();
    QLabel * inputEroomLabel = new QLabel("Enter Room:");
    inputERoom = new QLineEdit;
    inputEroomLayout->addWidget(inputEroomLabel);
    inputEroomLayout->addWidget(inputERoom);

    QVBoxLayout * EroomLayout = new QVBoxLayout();
    QPushButton * EroomButton = new QPushButton("Enter");
    EroomLayout->addWidget(EroomButton);

    QVBoxLayout * LroomLayout = new QVBoxLayout();
    QPushButton * LroomButton = new QPushButton("Leave");
    LroomLayout->addWidget(LroomButton);

    // Layout for enter room textbox and enter room button and leave room buttom
    QHBoxLayout *layoutErooms = new QHBoxLayout;
    layoutErooms->addLayout(inputEroomLayout);
    layoutErooms->addLayout(EroomLayout);
    layoutErooms->addLayout(LroomLayout);

    connect(EroomButton, SIGNAL (released()), this, SLOT (EroomAction()));
    connect(LroomButton, SIGNAL (released()), this, SLOT (LroomAction()));
    ////////////////////////////////////////////////////////////

    // Textbox for all messages
    QVBoxLayout * allMessagesLayout = new QVBoxLayout();
    QLabel * allMessagesLabel = new QLabel("Messages");
    allMessages = new QTextEdit;
    allMessagesLayout->addWidget(allMessagesLabel);
    allMessagesLayout->addWidget(allMessages);

    //////////////////////////////////////////////////////////
    // Textbox for input message
    QVBoxLayout * inputMessagesLayout = new QVBoxLayout();
    QLabel * inputMessagesLabel = new QLabel("Type your message:");
    inputMessage = new QTextEdit;
    inputMessagesLayout->addWidget(inputMessagesLabel);
    inputMessagesLayout->addWidget(inputMessage);

    // Textbox for user
    QVBoxLayout * inputUserLayout = new QVBoxLayout();
    QLabel * inputUserLabel = new QLabel("UserName:");
    inputUser = new QLineEdit;
    inputUserLayout->addWidget(inputUserLabel);
    inputUserLayout->addWidget(inputUser);

    // Textbox for password
    QVBoxLayout * inputPasswordLayout = new QVBoxLayout();
    QLabel * inputPasswordLabel = new QLabel("Password:");
    inputPassword = new QLineEdit;
    inputPasswordLayout->addWidget(inputPasswordLabel);
    inputPasswordLayout->addWidget(inputPassword);

    // Layout for room msg/create user pass/ create room
    QHBoxLayout *layoutUserPass = new QHBoxLayout;
    layoutUserPass->addLayout(inputMessagesLayout);
    layoutUserPass->addLayout(inputUserLayout);
    layoutUserPass->addLayout(inputPasswordLayout);
    layoutUserPass->addLayout(inputCroomLayout);

    /////////////////////////////////////////////////////////////
    // Send and new account buttons
    QHBoxLayout *layoutButtons = new QHBoxLayout;
    QPushButton * sendButton = new QPushButton("Send");
    layoutButtons->addWidget(sendButton);

    QPushButton * newUserButton = new QPushButton("Create User");
    layoutButtons->addWidget(newUserButton);

    QPushButton * loginButton = new QPushButton("Login");
    layoutButtons->addWidget(loginButton);

    // Setup actions for buttons
    connect(sendButton, SIGNAL (released()), this, SLOT (sendAction()));
    //connect(newUserButton, SIGNAL (released()), this, SLOT (newUserAction()));
    connect(newUserButton, SIGNAL (released()), this, SLOT (newUserAction()));
    //connect(loginButton, SIGNAL (released()), this, SLOT (loginAction()));
    connect(loginButton, SIGNAL (released()), this, SLOT (loginAction()));


    // Add all widgets to window
    mainLayout->addLayout(layoutRoomsUsers);
    mainLayout->addLayout(layoutCrooms);
    mainLayout->addLayout(layoutErooms);
    mainLayout->addLayout(allMessagesLayout);
    mainLayout->addLayout(layoutUserPass);
    mainLayout->addLayout(layoutButtons);

//    // Populate rooms
//    for (int i = 0; i < 20; i++) {
//        char s[50];
//        sprintf(s,"Room %d", i);
//        roomsList->addItem(s);
//    }

//    // Populate users
//    for (int i = 0; i < 20; i++) {
//        char s[50];
//        sprintf(s,"User %d", i);
//        usersList->addItem(s);
//    }

//    for (int i = 0; i < 20; i++) {
//        char s[50];
//        sprintf(s,"Message %d", i);
//        allMessages->append(s);
//    }

    // Add layout to main window
    setLayout(mainLayout);

    setWindowTitle(tr("CS240 IRC Client"));
    //timer->setInterval(5000);

    messageCount = 0;

    timer = new QTimer(this);
    connect(timer, SIGNAL (timeout()), this, SLOT (timerAction()));

    timer2= new QTimer(this);
    connect(timer2, SIGNAL (timeout()), this, SLOT (timer2Action()));

    timer3 = new QTimer(this);
    connect(timer3, SIGNAL (timeout()), this, SLOT (timer3Action()));

}


void Dialog::createMenu()

{
    menuBar = new QMenuBar;
    fileMenu = new QMenu(tr("&File"), this);
    exitAction = fileMenu->addAction(tr("E&xit"));
    menuBar->addMenu(fileMenu);

    connect(exitAction, SIGNAL(triggered()), this, SLOT(accept()));
}


