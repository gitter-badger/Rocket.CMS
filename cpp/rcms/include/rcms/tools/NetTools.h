/*
 * Copyright 2015 Oleg Morozenkov
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *	 http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ROCKET_CMS_NETTOOLS_H
#define ROCKET_CMS_NETTOOLS_H

#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>

namespace NetTools {

bool checkAuth(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);

void sendError(Poco::Net::HTTPServerResponse& response, Poco::Net::HTTPResponse::HTTPStatus errorCode = Poco::Net::HTTPResponse::HTTPStatus::HTTP_INTERNAL_SERVER_ERROR, const std::string& shortDescription = "");

}

#endif //ROCKET_CMS_NETTOOLS_H
