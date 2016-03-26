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
