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

#ifndef ROCKET_CMS_APIMANAGER_H
#define ROCKET_CMS_APIMANAGER_H

#include <vector>

#include <Poco/SharedPtr.h>

#include "AbstractApiHandler.h"

class ApiManager {

public:
    static void invokeApiCall(ApiConnection& connection);

    static inline void addNewApiManager(AbstractApiHandler* handler) {
        _apiHandlers.push_back(handler);
    }

private:
    ApiManager() { }
    ApiManager(const ApiManager&) = delete;
    ApiManager& operator=(const ApiManager&) = delete;

    static std::vector<AbstractApiHandler*> _apiHandlers;
};

#endif //ROCKET_CMS_APIMANAGER_H