/*
   Copyright 2010-2016 Intel Corporation

   This software is licensed to you in accordance
   with the agreement between you and Intel Corporation.

   Alternatively, you can use this file in compliance
   with the Apache license, Version 2.


   Apache License, Version 2.0

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

   http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

/**
********************************************************************************
**
**    @file CommandsServerSocketsLinux.h
**
**    @brief  Contains linux sockets implementation for commands server
**
**    @author Alexander Usyskin
**
********************************************************************************
*/
#ifndef _COMMANDS_SERVER_SOCKETS_LINUX_H_
#define _COMMANDS_SERVER_SOCKETS_LINUX_H_

#include "typedefs.h"
#include "ICommandsServer.h"
#include "CSTypedefs.h"
#include <unistd.h>

namespace intel_dal
{
	typedef int SOCKET;
	typedef struct _CS_ClientThreadParams
	{
		SOCKET clientSocket;
		ICommandDispatcher* dispatcher;
		Semaphore* semaphore;
	} CS_ClientThreadParams;

	class CommandsServerSocketsLinux : public ICommandsServer
	{
	private:
		SOCKET _socket;

		void startClientSession(SOCKET clientSocket);

	public:
	   CommandsServerSocketsLinux(ICommandDispatcher* dispatcher, uint8_t maxClientNum);
	   ~CommandsServerSocketsLinux();
	   bool open();
	   bool close();
	   void waitForRequests();
	};
}//namespace intel_dal
#endif//_COMMANDS_SERVER_SOCKETS_LINUX_H_
