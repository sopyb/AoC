#!/bin/bash

# Define the URL of the uthash repository
UTHASH_URL="https://github.com/troydhanson/uthash/archive/refs/heads/master.zip"

# Download the zip file
wget $UTHASH_URL -O uthash.zip

# Unzip the file
unzip uthash.zip

# Rename the extracted directory to uthash
mv uthash-master uthash

# Remove the zip file
rm uthash.zip