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
bool suite_DirectedGraphtest_init = false;
#include "DirectedGraph_test.h"

static DirectedGraphtest suite_DirectedGraphtest;

static CxxTest::List Tests_DirectedGraphtest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_DirectedGraphtest( "DirectedGraph_test.h", 22, "DirectedGraphtest", suite_DirectedGraphtest, Tests_DirectedGraphtest );

static class TestDescription_suite_DirectedGraphtest_test0 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_DirectedGraphtest_test0() : CxxTest::RealTestDescription( Tests_DirectedGraphtest, suiteDescription_DirectedGraphtest, 25, "test0" ) {}
 void runTest() { suite_DirectedGraphtest.test0(); }
} testDescription_suite_DirectedGraphtest_test0;

static class TestDescription_suite_DirectedGraphtest_test1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_DirectedGraphtest_test1() : CxxTest::RealTestDescription( Tests_DirectedGraphtest, suiteDescription_DirectedGraphtest, 30, "test1" ) {}
 void runTest() { suite_DirectedGraphtest.test1(); }
} testDescription_suite_DirectedGraphtest_test1;

static class TestDescription_suite_DirectedGraphtest_test2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_DirectedGraphtest_test2() : CxxTest::RealTestDescription( Tests_DirectedGraphtest, suiteDescription_DirectedGraphtest, 36, "test2" ) {}
 void runTest() { suite_DirectedGraphtest.test2(); }
} testDescription_suite_DirectedGraphtest_test2;

static class TestDescription_suite_DirectedGraphtest_test3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_DirectedGraphtest_test3() : CxxTest::RealTestDescription( Tests_DirectedGraphtest, suiteDescription_DirectedGraphtest, 43, "test3" ) {}
 void runTest() { suite_DirectedGraphtest.test3(); }
} testDescription_suite_DirectedGraphtest_test3;

static class TestDescription_suite_DirectedGraphtest_test4 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_DirectedGraphtest_test4() : CxxTest::RealTestDescription( Tests_DirectedGraphtest, suiteDescription_DirectedGraphtest, 51, "test4" ) {}
 void runTest() { suite_DirectedGraphtest.test4(); }
} testDescription_suite_DirectedGraphtest_test4;

static class TestDescription_suite_DirectedGraphtest_test5 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_DirectedGraphtest_test5() : CxxTest::RealTestDescription( Tests_DirectedGraphtest, suiteDescription_DirectedGraphtest, 57, "test5" ) {}
 void runTest() { suite_DirectedGraphtest.test5(); }
} testDescription_suite_DirectedGraphtest_test5;

static class TestDescription_suite_DirectedGraphtest_test6 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_DirectedGraphtest_test6() : CxxTest::RealTestDescription( Tests_DirectedGraphtest, suiteDescription_DirectedGraphtest, 64, "test6" ) {}
 void runTest() { suite_DirectedGraphtest.test6(); }
} testDescription_suite_DirectedGraphtest_test6;

static class TestDescription_suite_DirectedGraphtest_test7 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_DirectedGraphtest_test7() : CxxTest::RealTestDescription( Tests_DirectedGraphtest, suiteDescription_DirectedGraphtest, 72, "test7" ) {}
 void runTest() { suite_DirectedGraphtest.test7(); }
} testDescription_suite_DirectedGraphtest_test7;

static class TestDescription_suite_DirectedGraphtest_test8 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_DirectedGraphtest_test8() : CxxTest::RealTestDescription( Tests_DirectedGraphtest, suiteDescription_DirectedGraphtest, 80, "test8" ) {}
 void runTest() { suite_DirectedGraphtest.test8(); }
} testDescription_suite_DirectedGraphtest_test8;

static class TestDescription_suite_DirectedGraphtest_test9 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_DirectedGraphtest_test9() : CxxTest::RealTestDescription( Tests_DirectedGraphtest, suiteDescription_DirectedGraphtest, 85, "test9" ) {}
 void runTest() { suite_DirectedGraphtest.test9(); }
} testDescription_suite_DirectedGraphtest_test9;

static class TestDescription_suite_DirectedGraphtest_test10 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_DirectedGraphtest_test10() : CxxTest::RealTestDescription( Tests_DirectedGraphtest, suiteDescription_DirectedGraphtest, 91, "test10" ) {}
 void runTest() { suite_DirectedGraphtest.test10(); }
} testDescription_suite_DirectedGraphtest_test10;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
