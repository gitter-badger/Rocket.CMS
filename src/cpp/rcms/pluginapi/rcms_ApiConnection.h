/*
 * Copyright 2015 Reo_SP
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ROCKET_CMS_RCMS_APICONNECTION_H
#define ROCKET_CMS_RCMS_APICONNECTION_H

#include <stddef.h>
#include "rcms_StrPair.h"

extern "C" {

struct rcms_ApiConnection {
    const char* handler = NULL;
    const char* method = NULL;
    const rcms_StrPair* args = NULL;
    const size_t argsCount = 0;
    const char* postData = NULL;
    char* response = NULL;
    char* responseMimeType = "text/plain";
};

};

#endif //ROCKET_CMS_RCMS_APICONNECTION_H