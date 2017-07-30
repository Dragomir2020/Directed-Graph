/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_DirectedGraphInsertSizeCap_init = false;
#include "DirectedGraph_test.h"

static DirectedGraphInsertSizeCap suite_DirectedGraphInsertSizeCap;

static CxxTest::List Tests_DirectedGraphInsertSizeCap = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_DirectedGraphInsertSizeCap( "DirectedGraph_test.h", 22, "DirectedGraphInsertSizeCap", suite_DirectedGraphInsertSizeCap, Tests_DirectedGraphInsertSizeCap );

static class TestDescription_suite_DirectedGraphInsertSizeCap_testEmpty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_DirectedGraphInsertSizeCap_testEmpty() : CxxTest::RealTestDescription( Tests_DirectedGraphInsertSizeCap, suiteDescription_DirectedGraphInsertSizeCap, 25, "testEmpty" ) {}
 void runTest() { suite_DirectedGraphInsertSizeCap.testEmpty(); }
} testDescription_suite_DirectedGraphInsertSizeCap_testEmpty;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
