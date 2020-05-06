QT += widgets

HEADERS     = dialog.h \
    talk_client.h

SOURCES     = dialog.cpp \
              main.cpp \
    talk_client.cpp



# install

target.path = $$[QT_INSTALL_EXAMPLES]/widgets/layouts/basiclayouts

INSTALLS += target

