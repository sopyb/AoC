# Define the URL of the uthash repository
$UTHASH_URL = "https://github.com/troydhanson/uthash/archive/refs/heads/master.zip"

# Download the zip file
Invoke-WebRequest -Uri $UTHASH_URL -OutFile uthash.zip

# Unzip the file
Expand-Archive -Path uthash.zip -DestinationPath .

# Rename the extracted directory to uthash
Rename-Item -Path uthash-master -NewName uthash

# Remove the zip file
Remove-Item uthash.zip