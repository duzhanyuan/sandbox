//
// MessageHeader.cpp
//
// $Id$
//
// Library: MongoDB
// Package: MongoDB
// Module:  MessageHeader
//
// Implementation of the MessageHeader class.
//
// Copyright (c) 2012, Applied Informatics Software Engineering GmbH.
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
#include "Poco/MongoDB/Message.h"

#include "Poco/Exception.h"
#include "Poco/Net/SocketStream.h"
#include "Poco/StreamCopier.h"

namespace Poco
{
namespace MongoDB
{

MessageHeader::MessageHeader(OpCode opCode) : _messageLength(0), _requestID(0), _responseTo(0), _opCode(opCode)
{
}

MessageHeader::~MessageHeader()
{
}

void MessageHeader::read(BinaryReader& reader)
{
	reader >> _messageLength;
	reader >> _requestID;
	reader >> _responseTo;

	Int32 opCode;
	reader >> opCode;
	_opCode = (OpCode) opCode;

	if (!reader.good())
	{
		throw IOException("Failed to read from socket");
	}
}

void MessageHeader::write(BinaryWriter& writer)
{
	writer << _messageLength;
	writer << _requestID;
	writer << _responseTo;
	writer << (Int32) _opCode;
}

}} // Namespace MongoDB
