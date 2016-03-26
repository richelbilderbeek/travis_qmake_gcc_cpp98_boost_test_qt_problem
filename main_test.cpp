#include <QApplication>

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#define BOOST_TEST_MODULE my_test_module

bool initialise() { return true; }

int main(int argc, char* argv[])
{
  QApplication a(argc, argv);
  ::boost::unit_test::unit_test_main(&initialise, argc, argv);
  //Don't call this:
  //return a.exec();
}

/*

I enjoy using Boost.Test its automatic test suite generation.
In many of my projects, my main.cpp file looks like this:

    #define BOOST_TEST_DYN_LINK
    #define BOOST_TEST_MODULE my_test_module
    #include <boost/test/unit_test.hpp>

My test cases are automatically added using BOOST_AUTO_TEST_CASE, like, for example:

    #include <boost/test/unit_test.hpp>
    BOOST_AUTO_TEST_CASE(my_test)
    {
      BOOST_CHECK(1 + 1 == 2); //Trivial test here
    }

Also in serious projects, my many test cases are generated and run smoothly.

However, when using Qt (4 and 5) its GUI functions, a main function should look like this:

    #include <QApplication>

    int main(int argc, char *argv[])
    {
      QApplication a(argc, argv);
      return a.exec();
    }

To get both Boost.Test and Qt to work, I will need to merge these two forms of main,
that uses both QApplication and calls the Boost.Test test cases. This is something that
works closest to what I'd like:

    #include <QApplication>

    #define BOOST_TEST_DYN_LINK
    #include <boost/test/unit_test.hpp>

    #define BOOST_TEST_MODULE my_test_module

    bool initialise() { return true; }

    int main(int argc, char* argv[])
    {
      QApplication a(argc, argv);
      ::boost::unit_test::unit_test_main(&initialise, argc, argv);
      return a.exec();
    }

The problem is that with this approach the application does not terminate anymore. It calls the unit tests, shows
non fails, then waits forever.

All my unit test does, is show a QDialog for some milliseconds:

    #include <boost/test/unit_test.hpp>
    #include <QApplication>
    #include <QDialog>

    BOOST_AUTO_TEST_CASE(qdialog_can_be_shown_and_closed)
    {
      QDialog d;
      d.show();
      //Without 'qApp->processEvents()' the dialog is not drawn well
      for (int i=0; i!=1000000; ++i) { qApp->processEvents(); }
      d.close();
    }

How can I get my application to close?


I have found some hints to

 * Do or do not #define BOOST_TEST_NO_MAIN
 * Do or do not #define BOOST_TEST_ALTERNATIVE_INIT_API




*/
