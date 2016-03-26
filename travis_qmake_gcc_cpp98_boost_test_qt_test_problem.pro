CONFIG += console debug_and_release
CONFIG -= app_bundle
QT += core gui widgets
TEMPLATE = app

# Unique files
SOURCES += main_test.cpp my_dialog_test.cpp

# Debug and release build
CONFIG(release, debug|release) {
  DEFINES += NDEBUG
}

# Boost.Test
LIBS += -lboost_unit_test_framework


