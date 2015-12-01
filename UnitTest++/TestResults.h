#ifndef UNITTEST_TESTRESULTS_H
#define UNITTEST_TESTRESULTS_H

#include "HelperMacros.h"

namespace UnitTest
{

class TestReporter;
class TestDetails;
class TestProperty;

class UNITTEST_LINKAGE TestResults
{
public:
    explicit TestResults(TestReporter* reporter = 0);

    void OnTestStart(TestDetails const& test);
    void OnTestFailure(TestDetails const& test, char const* failure);
    void OnTestFinish(TestDetails const& test, float secondsElapsed);
	void OnTestReportPropery(TestDetails const& test, const char* propName, const TestProperty& propValue);

    int GetTotalTestCount() const;
    int GetFailedTestCount() const;
    int GetFailureCount() const;

private:
    TestReporter* m_testReporter;
    int m_totalTestCount;
    int m_failedTestCount;
    int m_failureCount;

    bool m_currentTestFailed;

    TestResults(TestResults const&);
    TestResults& operator =(TestResults const&);
};

}

#endif
