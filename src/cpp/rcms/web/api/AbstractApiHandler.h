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

#ifndef ROCKET_CMS_ABSTRACTAPIHANDLER_H
#define ROCKET_CMS_ABSTRACTAPIHANDLER_H

#include <string>
#include <map>

#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>

class AbstractApiHandler {

public:
    virtual ~AbstractApiHandler() = 0;
    virtual bool isHandlerNameEquals(const std::string& handlerName) = 0;
    virtual void handleRequest(const std::string& methodName,
                               const std::map<std::string, std::string>& args,
                               Poco::Net::HTTPServerRequest& request,
                               Poco::Net::HTTPServerResponse& response) = 0;
};

#endif //ROCKET_CMS_ABSTRACTAPIHANDLER_H
