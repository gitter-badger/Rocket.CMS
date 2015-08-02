#!/bin/bash
# must be run from the directory where this script is

set -e

mkdir -p rcms/lib
cd rcms/lib
wget https://cdnjs.cloudflare.com/ajax/libs/underscore.js/1.8.3/underscore-min.js
wget https://cdnjs.cloudflare.com/ajax/libs/backbone.js/1.2.1/backbone-min.js
wget https://cdnjs.cloudflare.com/ajax/libs/q.js/2.0.3/q.min.js
cd ../..

mkdir -p markdownWysiwygEditor/lib
cd markdownWysiwygEditor/lib
wget https://cdnjs.cloudflare.com/ajax/libs/marked/0.3.2/marked.min.js
wget https://cdnjs.cloudflare.com/ajax/libs/to-markdown/1.2.1/to-markdown.min.js
cd ../..
