#!/bin/bash
qmake travis_qmake_gcc_cpp98_boost_test_qt_test_problem.pro
make debug
./travis_qmake_gcc_cpp98_boost_test_qt_test_problem

qmake travis_qmake_gcc_cpp98_boost_test_qt_test_problem.pro
make release
./travis_qmake_gcc_cpp98_boost_test_qt_test_problem