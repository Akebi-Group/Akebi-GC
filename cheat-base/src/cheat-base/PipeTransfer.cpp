#include <pch.h>
#include "PipeTransfer.h"

#include <iostream>
#include <sstream>

#include <cheat-base/util.h>

PipeTransfer::PipeTransfer(const std::string& name) 
{
	std::stringstream ss;
	ss << "\\\\.\\pipe\\" << name;
	this->m_Name = ss.str();
	this->m_Pipe = 0;
}

PipeTransfer::~PipeTransfer()
{
	if (m_Pipe)
		CloseHandle(m_Pipe);
}

bool PipeTransfer::Create()
{
	if (m_Pipe)
		CloseHandle(m_Pipe);
	m_Pipe = CreateNamedPipe(m_Name.c_str(), PIPE_ACCESS_DUPLEX, PIPE_TYPE_BYTE | PIPE_READMODE_BYTE | PIPE_WAIT, 1, 256 * 1024, 16, INFINITE, NULL);
	return IsPipeOpened();
}

bool PipeTransfer::IsPipeOpened()
{
	return m_Pipe && m_Pipe != INVALID_HANDLE_VALUE;
}

bool PipeTransfer::Connect()
{
	if (IsPipeOpened())
		CloseHandle(m_Pipe);

	m_Pipe = CreateFile(m_Name.c_str(), GENERIC_READ | GENERIC_WRITE, 0, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

	return IsPipeOpened();
}

bool PipeTransfer::WaitForConnection()
{
	return ConnectNamedPipe(m_Pipe, nullptr) || GetLastError() == ERROR_PIPE_CONNECTED;
}

void PipeTransfer::ReadBytes(void* buffer, size_t size)
{
	if (size == 0 || !IsPipeOpened()) return;
	
	DWORD readCount = 0;
	auto result = ReadFile(m_Pipe, buffer, static_cast<DWORD>(size), &readCount, nullptr);
	if (!result || static_cast<size_t>(readCount) < size)
	{
		LOG_LAST_ERROR("Failed read from pipe.");
		CloseHandle(m_Pipe);
		m_Pipe = 0;
	}
}

void PipeTransfer::WriteBytes(void* buffer, size_t size)
{
	if (size == 0 || !IsPipeOpened()) return;

	DWORD writenCount = 0;
	auto result = WriteFile(m_Pipe, buffer, static_cast<DWORD>(size), &writenCount, nullptr);
	if (!result || static_cast<size_t>(writenCount) < size)
	{
		LOG_LAST_ERROR("Failed write to pipe.");
		CloseHandle(m_Pipe);
		m_Pipe = 0;
	}
}

void PipeTransfer::ReadObject(PipeSerializedObject& object)
{
	object.Read(this);
}

void PipeTransfer::WriteObject(PipeSerializedObject& object)
{
	object.Write(this);
}
