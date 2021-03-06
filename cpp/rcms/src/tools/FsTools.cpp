/*
 * Copyright 2015 Oleg Morozenkov
 * Copyright 2015 Alexander Rizaev
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

#include "rcms/tools/FsTools.h"

#include <map>
#include <sstream>

#include <Poco/Process.h>
#include <Poco/PipeStream.h>
#include <Poco/StreamCopier.h>

using namespace std;
using namespace Poco;

namespace FsTools {

string getMimeType(const string& name) {
	static const map<string, string> mimeTypes = {
		{ "gif",   "image/gif" },
		{ "jpg",   "image/jpeg" },
		{ "jpeg",  "image/jpeg" },
		{ "png",   "image/png" },
		{ "bmp",   "image/bmp" },
		{ "svg",   "image/svg+xml" },
		{ "tiff",  "image/tiff" },
		{ "js",	"application/javascript" },
		{ "ogg",   "application/ogg" },
		{ "pdf",   "application/pdf" },
		{ "rss",   "application/rss+xml" },
		{ "woff",  "application/font-woff" },
		{ "xhtml", "application/xhtml+xml" },
		{ "xml",   "application/xml" },
		{ "zip",   "application/zip" },
		{ "gz",	"application/gzip" },
		{ "mp3",   "audio/mpeg" },
		{ "ogg",   "audio/ogg" },
		{ "flac",  "audio/flac" },
		{ "opus",  "audio/opus" },
		{ "wave",  "audio/vnd.wave" },
		{ "css",   "text/css" },
		{ "csv",   "text/csv" },
		{ "html",  "text/html" },
		{ "md",	"text/markdown" },
		{ "rtf",   "text/rtf" },
		{ "avi",   "video/avi" },
		{ "mpeg",  "video/mpeg" },
		{ "mp4",   "video/mp4" },
		{ "webm",  "video/webm" },
		{ "mkv",   "video/x-matroska" },
		{ "flv",   "video/x-flv "}
	};
	auto iter = mimeTypes.find(name);
	if (iter == mimeTypes.end()) {
		return "text/plain";
	}
	return iter->second;
}

string concat(const vector<Path>& files, const string& separator) {
	string result;
	for (const Path& item : files) {
		result += loadFileToString(item);
		result += separator;
	}
	return result;
}

string concat(const vector<string>& files, const string& separator) {
	string result;
	for (const string& item : files) {
		result += loadFileToString(item);
		result += separator;
	}
	return result;
}

std::string exec(const std::string& command, const std::vector<std::string>& args) {
	Pipe outPipe;
	Process::launch(command, args, 0, &outPipe, 0);
	PipeInputStream input(outPipe);
	stringstream output;
	StreamCopier::copyStream(input, output);
	return output.str();
}

}
