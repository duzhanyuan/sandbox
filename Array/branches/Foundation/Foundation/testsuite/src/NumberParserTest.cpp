//
// NumberParserTest.cpp
//
// $Id: //poco/svn/Foundation/testsuite/src/NumberParserTest.cpp#2 $
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#include "NumberParserTest.h"
#include "CppUnit/TestCaller.h"
#include "CppUnit/TestSuite.h"
#include "Poco/NumberParser.h"
#include "Poco/Exception.h"


using Poco::NumberParser;
using Poco::SyntaxException;


NumberParserTest::NumberParserTest(const std::string& name): CppUnit::TestCase(name)
{
}


NumberParserTest::~NumberParserTest()
{
}


void NumberParserTest::testParse()
{
	assert (NumberParser::parse("123") == 123);
	assert (NumberParser::parse("-123") == -123);
	assert (NumberParser::parseUnsigned("123") == 123);
	assert (NumberParser::parseHex("12AB") == 0x12ab);

#if defined(POCO_HAVE_INT64)
	assert (NumberParser::parse64("123") == 123);
	assert (NumberParser::parse64("-123") == -123);
	assert (NumberParser::parseUnsigned64("123") == 123);
	assert (NumberParser::parseHex64("12AB") == 0x12ab);
#endif

	assertEqualDelta (12.34, NumberParser::parseFloat("12.34"), 0.01);
}

void NumberParserTest::testParseError()
{
	try
	{
		NumberParser::parse("");
		failmsg("must throw SyntaxException");
	}
	catch (SyntaxException&)
	{
	}

	try
	{
		NumberParser::parse("asd");
		failmsg("must throw SyntaxException");
	}
	catch (SyntaxException&)
	{
	}

	try
	{
		NumberParser::parseUnsigned("a123");
		failmsg("must throw SyntaxException");
	}
	catch (SyntaxException&)
	{
	}

	try
	{
		NumberParser::parseHex("z23");
		failmsg("must throw SyntaxException");
	}
	catch (SyntaxException&)
	{
	}

	try
	{
		NumberParser::parseHex("23z");
		failmsg("must throw SyntaxException");
	}
	catch (SyntaxException&)
	{
	}
	
#if defined(POCO_HAVE_INT64)

	try
	{
		NumberParser::parse64("asd");
		failmsg("must throw SyntaxException");
	}
	catch (SyntaxException&)
	{
	}

	try
	{
		NumberParser::parseUnsigned64("");
		failmsg("must throw SyntaxException");
	}
	catch (SyntaxException&)
	{
	}

	try
	{
		NumberParser::parseHex64("zaz");
		failmsg("must throw SyntaxException");
	}
	catch (SyntaxException&)
	{
	}

	try
	{
		NumberParser::parseHex64("12345z");
		failmsg("must throw SyntaxException");
	}
	catch (SyntaxException&)
	{
	}
	
#endif

	try
	{
		NumberParser::parseFloat("a12.3");
		failmsg("must throw SyntaxException");
	}
	catch (SyntaxException&)
	{
	}

	try
	{
		NumberParser::parseFloat("12.3aa");
		failmsg("must throw SyntaxException");
	}
	catch (SyntaxException&)
	{
	}
}


void NumberParserTest::setUp()
{
}


void NumberParserTest::tearDown()
{
}


CppUnit::Test* NumberParserTest::suite()
{
	CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("NumberParserTest");

	CppUnit_addTest(pSuite, NumberParserTest, testParse);
	CppUnit_addTest(pSuite, NumberParserTest, testParseError);

	return pSuite;
}
