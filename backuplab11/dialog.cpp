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
#include <iostream>
//
#include <talk-client.h>
//


using namespace std;


talk_client* talk = new talk_client();


void Dialog::sendAction()
{
    QString text = inputMessage->toPlainText();
    string s = text.toUtf8().constData();
    
    //TODO:
    talk->sendCommand("localhost", 19761, "ADD-USER", "localuser", "localpassword", "", "response");

    cout << s<< endl;
    printf("Send Button\n");
}

void Dialog::newUserAction()
{
    QString text1 = inputUser->text();
    string s1 = text1.toUtf8().constData();
    QString text2 = inputPassword->text();
    string s2 = text2.toUtf8().constData();
    
    //TODO:
    //sendCommand(host, port, "ADD-USER", s1.c_str(), s2.c_str(), "", response);

    cout <<s1<< endl;
    cout <<s2<< endl;
    printf("New User Button\n");
}

void Dialog::CroomAction()
{
    QString text1 = inputCRoom->text();
    string s1 = text1.toUtf8().constData();
    cout <<s1<< endl;
    printf("Room Buttom\n");
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
}

void Dialog::timerAction()
{
    printf("Timer wakeup\n");
    messageCount++;

    char message[50];
    sprintf(message,"Timer Refresh New message %d",messageCount);
    allMessages->append(message);
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
    mainLayout->addLayout(allMessagesLayout);
    mainLayout->addLayout(layoutUserPass);
    mainLayout->addLayout(layoutButtons);

    // Populate rooms
    for (int i = 0; i < 20; i++) {
        char s[50];
        sprintf(s,"Room %d", i);
        roomsList->addItem(s);
    }

    // Populate users
    for (int i = 0; i < 20; i++) {
        char s[50];
        sprintf(s,"User %d", i);
        usersList->addItem(s);
    }

    for (int i = 0; i < 20; i++) {
        char s[50];
        sprintf(s,"Message %d", i);
        allMessages->append(s);
    }

    // Add layout to main window
    setLayout(mainLayout);

    setWindowTitle(tr("CS240 IRC Client"));
    //timer->setInterval(5000);

    messageCount = 0;

    timer = new QTimer(this);
    connect(timer, SIGNAL (timeout()), this, SLOT (timerAction()));
    timer->start(5000);
}


void Dialog::createMenu()

{
    menuBar = new QMenuBar;
    fileMenu = new QMenu(tr("&File"), this);
    exitAction = fileMenu->addAction(tr("E&xit"));
    menuBar->addMenu(fileMenu);

    connect(exitAction, SIGNAL(triggered()), this, SLOT(accept()));
}



