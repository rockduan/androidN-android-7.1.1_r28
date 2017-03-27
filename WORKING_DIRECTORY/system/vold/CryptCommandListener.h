/*
 * Copyright (C) 2015 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _CRYPTCOMMANDLISTENER_H__
#define _CRYPTCOMMANDLISTENER_H__

#include <sysutils/FrameworkListener.h>
#include <utils/Errors.h>
#include "VoldCommand.h"

class CryptCommandListener : public FrameworkListener {
public:
    CryptCommandListener();
    virtual ~CryptCommandListener() {}

private:
    static void dumpArgs(int argc, char **argv, int argObscure);
    static int sendGenericOkFailOnBool(SocketClient *cli, bool success);

    class CryptfsCmd : public VoldCommand {
    public:
        CryptfsCmd();
        virtual ~CryptfsCmd() {}
        int runCommand(SocketClient *c, int argc, char ** argv);
    };
    int getSocket();
};

#endif
