# This script should install unit api for test: https://github.com/ThrowTheSwitch/Unity
# The folder of this API can not be versioned, the .gitignore is doing this.

#!/bin/sh

# Folder of API
cd unity

# Last release
FILE_VERSION=v2.4.0.tar.gz

# Link of releases file
wget https://github.com/ThrowTheSwitch/Unity/archive/$FILE_VERSION

# extract
tar -zxvf $FILE_VERSION

# remove downloaded file
rm $FILE_VERSION
