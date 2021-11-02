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
Once you have Dev Containers installed fromthe command platte Remote-Containers: Reopen in Container"
After this completes you should be connected to a container from VS Code. You should be able to find and set
breakpoints in the plugin.