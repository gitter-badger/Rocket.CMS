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

#include "rcms/web/WebHandlerFactory.h"

#include <Poco/Net/HTTPServerRequest.h>

#include "rcms/web/IndexWebHandler.h"
#include "rcms/web/ApiWebHandler.h"
#include "rcms/tools/StringTools.h"

using namespace Poco::Net;

HTTPRequestHandler* WebHandlerFactory::createRequestHandler(const HTTPServerRequest& request) {
	if (StringTools::startsWith(request.getURI(), "/api/")) {
		return new ApiWebHandler;
	} else {
		return new IndexWebHandler;
	}
}
