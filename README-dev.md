Setup the secrets for the mysql passwords these are to be stored in files located at
$/configuration/amd64/secrets/mysql_root_password
and
$/configuration/amd64/secrets/mysql_password
Each file should contain just the password no extra line-feeds suggested dev password for both is "ivp"

Next from the root directory run
# buildall.sh
This will build all the containers needed including the container that is used for the dev container

Once that is complete
run VS Code
# code .
Once VS code is opened. You might be offered the option to install Dev Containers if it is not installed already.
Once you have Dev Containers installed from the command platte Remote-Containers: Reopen in Container"
After this completes you should be connected to a container from VS Code. You should be able to find and set
breakpoints in the plugin.

# Potential hangups
You may need to build the various parts of the plugin depending on the state of the container.

I'm not certain why but it appears that I'm having to build and install the "tmx" even though it was built
and installed as part of the the Docker build chain.

cd src/tmx
cmake -DCMAKE_BUILD_TYPE=Debug --config Debug .
make
make install

When the files are built they are built to :/home/V2X-Hub/build/bin
For purposes of connecting to rest of the V2i infarstructure there needs to be a manifest.json in the bin directory.
This file should be the one for the plugin you are working with and you will need to change the IP address to work
with the host machince's IP address.
