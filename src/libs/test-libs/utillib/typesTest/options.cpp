/*-------------------------------------------------------------------------
 * This source code is confidential proprietary information which is
 * Copyright (c) 2017 by Great Hill Corporation.
 * All Rights Reserved
 *
 * The LICENSE at the root of this repo details your rights (if any)
 *------------------------------------------------------------------------*/
#include "options.h"

//---------------------------------------------------------------------------------------------------
CParams params[] = {
    CParams("~mode", "a number between 0 and 2 inclusive"),
    CParams("",      "Test 'c' library strings against quickBlocks strings.\n"),
};
uint32_t nParams = sizeof(params) / sizeof(CParams);

//---------------------------------------------------------------------------------------------------
bool COptions::parseArguments(SFString& command) {

    if (!standardOptions(command))
        return false;

    Init();
    while (!command.empty()) {
        SFString arg = nextTokenClear(command, ' ');
        if (arg.startsWith('-')) {  // do not collapse

            if (!builtInCmd(arg)) {
                return usage("Invalid option: " + arg);
            }
        } else {
            testNum = (int32_t)toLong(arg);
        }
    }
    return true;
}

//---------------------------------------------------------------------------------------------------
void COptions::Init(void) {
    paramsPtr = params;
    nParamsRef = nParams;

    testNum = -1;
}

//---------------------------------------------------------------------------------------------------
COptions::COptions(void) {
    Init();
}

//--------------------------------------------------------------------------------
COptions::~COptions(void) {
}
