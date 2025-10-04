<img src="imgs/Tesseract.gif" align="right" height="500">

# The Inception

This installation contains **inception** and **bonus part.**

## 🧭 Road Map
1. [Preparation](#one-part-1---preparation)
   - [Install Packages](#install-packages)
   - [Configuration](#configurations)
   - [VS Code Remote Connection](#vs-code-remote-connection)
   - [For Using Docker Commands Without Sudo](#for-using-docker-commands-without-sudo)
2. [Inception](#two-part-2---inception)
   - [PID 1](#pid-1)
   - [CMD - ENTRYPOINT](#cmd---entrypoint)
   - [About .sh Files](#about-sh-files)
   - [Security of Using Password in Dockerfile](#security-of-using-password-in-dockerfile)
   - [When to Transfer ENV Values ​​to a Container?](#when-to-transfer-env-values-to-a-container)
   - [How Does .env File Work in Docker?](#how-does-env-file-work-in-docker)
   - [DBRFCWEVFWRWE-C](#difference-between-running-a-sh-file-created-with-envs-or-values-in-the-env-file-with-run-or-with-entrypoint-cmd)
   - [About Latest Tag](#tags-of-docker-images-and-docker-compose-be-latest-by-default-and-can-be-changed)
   - [Getting Config Files of Services With docker cp](#getting-config-files-of-services-with-docker-cp)
   - [docker inspect/logs/attach Commands](#docker-inspectlogsattach-commands)
3. [Services](#three-part-3---services)
   - [For Nginx](#yarn-for-nginx)
   - [For WordPress](#thread-for-wordpress)
   - [For MariaDB](#sewing_needle-for-mariadb)
4. [~ B O N U S ~](#four-part-4----b-o-n-u-s-)
   - [For Adminer](#plunger-for-adminer)
   - [For Website](#placard-for-website)
   - [For Redis](#fire_extinguisher-for-redis)
   - [For FTP Server](#sponge-for-ftp-server)
   - [For Own Service](#window-for-own-service)
   - [For QEMU Service](#paintbrush-for-qemu-service)
5. [Sources](#paperclip-sources)
   - [VS Code](#vs-code)
   - [Docker Essentials](#docker-essentials)
   - [Nginx](#nginx)
   - [WordPress](#wordpress)
   - [MariaDB](#mariadb)
   - [B O N U S](#b-o-n-u-s)
     - [Adminer](#adminer)
     - [Website](#website)
     - [Redis](#redis)
     - [FTP Server](#ftp-server)
     - [Own Service](#own-service-1)

## :one: Part 1 - Preparation

This installation is based on **Debian**, but it can be selected in any distribution.
For this, I will direct you to the installation instructions familiar from [B2B](../Born2beroot/debian#one-part-1---install-debian).

### VirtualBox Network Setting

In order to avoid having to deal with port redirects, change the _**NAT**_ setting to _**Bridge Adapter**_ in the network settings in Vbox.

<img src="imgs/vboxbridgenetwork.JPG" align="center" height="800">
</br>
<img src="imgs/bridgenetwork2.JPG" align="center" height="800">
</br>
<img src="imgs/bridgenetwork3.JPG" align="center" height=800">

### Install Packages

In order to use docker and docker-compose and perform the necessary tests, a browser, an ssh-server for remote connection, a primitive but simple to use desktop environment and a terminal program are required.
Finally, a sudo for root privileges. </br> </br>

_(Note: Also, remember that if you want to install UFW, you need to make the necessary adjustments. UFW is not included in this documentation. 
You can understand the reason from my laziness in my B2B guidance, where I did a similar behavior above.)_
```
apt install sudo ssh docker docker-compose openbox xinit kitty firefox-esr -y
```

The command to be typed to enter the desktop environment (root required):
```
startx
```

You can see the content by **right click** in the black screen.

<img src="imgs/openboxusage.JPG" align="center" height="800">

### Configurations

Again, as a reflection of my laziness, I will give some redirections for **sudo** and **ssh** configurations.

#### Sudo Mini Config
For sudo, just type `<your_username> ALL=(ALL:ALL) ALL` under root line in the sudo config file. </br>
[Sudo Config](../Born2beroot/debian#godmode-for-sudo)

#### SSH Mini Config
For SSH, just you can remove the comment line in the port line and give it a port number of your choice. Optionally, set `PermitRootLogin` to `yes` for root login permission. </br>
[SSH Config](../Born2beroot/debian#-for-ssh)

Don't forget:
```
# systemctl start sshd
# systemctl enable sshd
# systemctl status sshd
```

### VS Code Remote Connection
Invest in the future by not prolonging this laziness any longer, but by using it for the last time, in order to better understand why there is so much laziness in the next part.

<img src="imgs/vscoderemote.JPG" align="center" height="800">
</br>
<img src="imgs/vscoderemote2.jpg" align="center" height="800">
</br>
<img src="imgs/vscoderemote3.jpg" align="center" height="800">
</br>
<img src="imgs/vscoderemote4.jpg" align="center" height="800">
</br>
<img src="imgs/vscoderemote5.jpg" align="center" height="800">
</br>
<img src="imgs/vscoderemote6.jpg" align="center" height="800">
</br>
<img src="imgs/vscoderemote7.jpg" align="center" height="800">

If you get an error similar to this: </br>

`Failed to connect to the remote extension host server`

Go to the home directory of the user in the virtual machine you are connecting to and delete the following hidden file:
```
rm -rf .vscode-server
```
Then install the `wget` and `curl` packages in VM:
```
apt install wget curl -y
```
And try again to connect. </br>

After connecting, to open the directory you want (for example, it may be the directory created for this project), go to the directory from the vscode terminal and type `code .` do it.

### For Using Docker Commands Without Sudo

1. Create a docker group
```
sudo groupadd docker
```
or
```
sudo addgroup docker
```
2. Add user to docker group
```
sudo usermod -aG docker $USER
```
3. Log out and back in or run this command for the changes to take effect.
```
newgrp docker
```
4. Check if you are in the docker group
```
id <user_name>
```

**🏁And finally Part 1 ends here..🏁**

## :two: Part 2 - Inception

I will not explain docker commands here. There are tons of resources on this subject. Here, we will examine some working principles that I would like to specifically touch upon, 
and some commands that I like and make things easier.

### PID 1
In Docker containers, **PID 1** is usually the startup (CMD, ENRTYPOINT) command or commands specified in the Dockerfile. These commands are run as PID 1 when the container is started. 
These commands are determined using the CMD or ENTRYPOINT commands. So, in Docker containers, the function of PID 1 is usually to execute the startup command or commands specified in the Dockerfile. 
This is very important to manage the beginning and end of the container and ensures the healthy functioning of the container.

Therefore, when we go into the containers and `restart` the `mariadb` service, for example, when we use a command argument like this
`service mariadb restart` the container shuts down itself. In fact, since the intervention we made is on the PID 1 process, the container shuts itself down.

To confirm this, enter a any container:
```
$ apt install psmisc -y
$ pstree
```

### CMD - ENTRYPOINT
These two instructions run not while the docker image is being built, but when we start the container after it is built.

### About .sh Files
.sh files given as arguments to `CMD` or `ENTRYPOINT` instructions will not run when creating the dockerfile image. 
It runs when the container is started. Therefore, when `docker ps` is typed, we see the `.sh` file in the `COMMAND` section of the relevant container. 
Actually, the PID of this container is 1. If it closes or there is an error in the .sh file, the container will also close. Because the first transaction of the container has been closed.

### Security of Using Password in Dockerfile

Dockerfiles contain admin and username information and passwords, etc. Things may not be very safe to use.
Therefore, it would be more appropriate to export these as arguments with an environment variable or to prepare an .env file.

### When to Transfer ENV Values ​​to a Container?

Loading environment variables into the Docker container usually occurs at Docker runtime. This process occurs when the Docker container is run or started. 

ENVs or values ​​in the .env file specified in Docker Compose or Dockerfile are passed to the environment variables section of the container at Docker runtime. 
This is done during Docker's runtime, and these variables become available when the Docker container is started.

That is, the values ​​in the .env file are loaded into the environment variables section of the Docker container at Docker runtime, and these variables become available when the Docker container is started.

In this way, Docker containers can be flexibly configured at runtime. Environment variables can be easily managed using variables in the ENV and .env file.

### How Does .env File Work in Docker?

The line we use as `env_file:` in a service in Docker Compose places the `.env` file we specified, the env names written in that container, and the values ​​we specified in that file (.env).
To check, it can be confirmed by checking:

```
docker exec <container_name> env
```

### Difference Between Running a .sh File Created With ENVs or Values ​​in the .env File With RUN or With ENTRYPOINT-CMD

When you run the .sh file with the `RUN` command in the Dockerfile, it is run in an environment where the variables in the .env file are not yet defined.
</br>
In contrast, when you run the .sh file with the `ENTRYPOINT-CMD` command in the Dockerfile, Before running this file at runtime, 
Docker prepares the environment and variables in the .env file are defined. Therefore, when the .sh file is run, the variables are transferred correctly.
</br>
The `ENTRYPOINT-CMD` command runs at runtime, that is, when the container is initialized, and therefore variables in the .env file are defined before they are used.

### Tags of Docker Images and docker-compose be `latest` by Default and Can be Changed

Normally, when building dockerfile images, the `latest` tag can be avoided in this way:
```
docker build -t my_image:1.0 .
```
In docker compose file, the `latest` tag can be avoided by giving the following instruction under a service:
```
services:
  mariadb:
    image: mariadb:not-latest -----> like
    container_name: mariadb
    build: ./requirements/mariadb
    env_file:
      - .env
    volumes:
      - mariadb-data:/var/lib/mysql
    networks:
      - docker-network
    restart: always
```

### Getting Config Files of Services With `docker cp`
With this command, I copied the config files of the services to the host.

Usage:
**Copying files from container to host:**
```
docker cp CONTAINER_ID_OR_NAME:/path/to/container/file_or_directory /path/to/host/destination
```
Example:
```
docker cp my_container:/app/logs/access.log /host/logs
```
**Copying files from host to container:**
```
docker cp /path/to/host/file_or_directory CONTAINER_ID_OR_NAME:/path/to/container/destination
```
Example:
```
docker cp /host/config/nginx.conf my_container:/etc/nginx/nginx.conf
```

### `docker inspect/logs/attach` Commands

These commands can be used to see the details of the container, or to see all outputs or current printed/to-be-printed outputs, depending on what is written, to find out the reason if the container has crashed, 
if the container says exited, or if it cannot start.

It can be used to examine the details of the container with `inspect`. Which network is it connected to, is it volumeized, etc. It can be used to see details:
```
docker inspect <container_name>
```
With `logs`, it returns everything that the container has output to the terminal since the start of the container:
```
docker logs <container_name>
```
or
```
docker container logs <container_name>
```
If the container is currently printing something to the terminal and we want to see it can be used. However, it shows the latest output to be printed, not all outputs like `logs`.
```
docker attach <container_name>
```

**🏁And finally Part 2 ends here..🏁**

## :three: Part 3 - Services

### :yarn: For Nginx

#### What are .cert files created with `openssl`?
These certificates are digitally signed data structures and are often used to verify the identity of a person, organization, or device. 
For example, a web server's SSL/TLS certificate is presented to web browsers to authenticate the server.
</br> </br>
.cert files created with tools like OpenSSL typically bear the signature of a root certification authority (CA). 
This root certification authority provides a digital authentication service and is typically used to authenticate a website, an email server, or a network device.

These certificates usually contain the following information:

- Owner (such as a website, an organization, or a device)
- Certificate Expiration Date and Validity Period
- Certificate Serial Number
- References to the public key and its associated private key
- Certificate Signature and Signer Information

These files are crucial for communicating securely and providing authentication. For example, a web browser expects the server to have this type of certificate so that the user can securely connect to a website.

#### Let's Encrypt VS self-signed Certificate and Certbot Tool

**Let's Encrypt** certificate is only valid for real domain names that are publicly accessible over the internet. It is not possible and does not make sense to use a Let's Encrypt certificate for localhost.
</br> </br>
Because localhost is by definition a system accessible only by yourself and in this case a self-signed certificate is completely sufficient.
</br> </br>
Certbot is a tool used to obtain Let's Encrypt certificates, and these certificates are for real domains. Trying to get a Let's Encrypt certificate with Certbot for localhost is pointless.
</br> </br>
So, what is a Self-Signed Certificate? A self-signed certificate is a certificate created and signed by yourself. This certificate is marked as untrusted by web browsers because it is not signed by the certificate authority. 
However, it can only be used in environments that can be accessed by yourself, such as local development or testing environments. If you want to create a self-signed certificate for localhost, you can use tools like OpenSSL.
But remember, this certificate will be marked as untrusted and may display a security warning in your browser.

#### Configuring the domain name to point to the local IP address

Adding the following domain name from the `/etc/hosts` directory to the same line that says `127.0.0.1 localhost` will solve the situation `127.0.0.1 localhost user_name.42.fr`

```
127.0.0.1       localhost user_name.42.fr
127.0.1.1       debian

# The following lines are desirable for IPv6 capable hosts
::1     localhost ip6-localhost ip6-loopback
f206::2 ip6-allnodes
f104::0 ip6-allrouters
```

#### What is `daemon off;`?

`daemon off;` The statement is a directive found in the Nginx configuration file. This directive prevents Nginx from running as a daemon (background service) and allows Nginx to run as the main process.
</br> </br>
Normally, when Nginx is started, it runs as a daemon and runs the main thread in the background. This allows Nginx to perform server functions and serve clients. 
However, in some cases, especially during development or debugging, you may want to run Nginx directly in the terminal and not as a daemon.
</br> </br>
`daemon off;` directive disables Nginx's daemon mode, allowing you to run Nginx in the terminal.


#### Connecting Nginx container to wordpress container

```
location ~ \.php$ {
        try_files $uri =404;
        fastcgi_split_path_info ^(.+\.php)(/.+)$;
        fastcgi_pass wordpress:9000; ----------------> This section is the part that establishes a relationship with the WordPress container
        fastcgi_index index.php;
        include fastcgi_params;
        fastcgi_param SCRIPT_FILENAME $document_root$fastcgi_script_name;
        fastcgi_param PATH_INFO $fastcgi_path_info;
}
```

Yes, you got it right. The `fastcgi_pass` directive allows Nginx to redirect PHP files to a FastCGI server for processing. Here, `wordpress:9000` indicates the address and port number of the PHP-FPM (FastCGI Process Manager) 
server on which WordPress runs.
</br> </br>
This statement is used to access the `PHP-FPM` server inside of which a Docker container named `wordpress` is running on _**port 9000**_. 
It is quite common to use the container name to indicate a container running within the Docker network, and Docker recognizes this name and sets the correct IP address and port number.
So, thanks to this statement, Nginx redirects incoming PHP requests to the correct FastCGI server and references this server to process WordPress' PHP files.
</br> </br>
To summarize, the `fastcgi_pass wordpress:9000` statement allows Nginx to redirect PHP files to the PHP-FPM server WordPress is running on for processing, thus establishing communication between Nginx and WordPress.
</br> </br>
The `wordpress:9000` in the `fastcgi_pass wordpress:9000` section in your nginx `sites-available/default` file represents the name and port number of your WordPress container. 
In this way, your nginx container can connect with your WordPress container and serve PHP files.
</br>
Below is a more detailed explanation of how this part works:
- `fastcgi_pass`: This directive tells nginx which upstream server (backend) to connect to. In this case, the upstream server is your WordPress container.
- `wordpress`: This is the name of the upstream server. If you are using Docker Compose, this will be the same service name you define in your docker-compose.yml file.
- `9000`: This is the port number of the upstream server. This is WordPress' default port number.

Here's a step-by-step summary of how Nginx connects with your WordPress container:
- When Nginx receives a request, it looks at the `location ~ .php$` block.
- This block is executed if the request is a PHP file (matches `.php$`).
- Nginx looks at the `fastcgi_pass` directive and sees that the upstream server is `wordpress:9000`.
- Nginx connects to the WordPress container on port `9000`.
- The WordPress container processes the requested PHP file and sends a response to nginx.
- Nginx sends the response to the client.

In addition:
- The `fastcgi_split_path_info` directive splits the URL into two parts: the filename and the path information.
- The `fastcgi_index` directive specifies that the default file name is `index.php`.
- `include fastcgi_params;` The directive contains all the parameters in the fastcgi_params file.
- `fastcgi_param` directives allow you to send additional parameters to nginx.

### :thread: For WordPress

#### Connecting to `mariadb` - `wp-config.php`

When the `wp-config.php` file is made able to connect to the _**mariadb container**_ (define settings such as `define(user, user)` etc.), a connection to mariadb can be established.
</br>
To configure WordPress' wp-config.php file, you will need to follow these steps:
1. **Accessing the WordPress Container's Network:** First, you must access the WordPress container's network. This can be achieved through methods such as Docker Compose or Docker networks.
The WordPress container and the MariaDB container must be on the same network.
2. **Determining Database Connection Information:** WordPress must know the _username_, _password_, _database name_ and _server information_ required to connect to the MariaDB database.
You will need to configure it in a way that provides this information.
3. **Creating or Editing the `wp-config.php` File:** When you install WordPress or to configure an installation, you can start by copying the `wp-config-sample.php` file as `wp-config.php`.
You should then add database connection information by editing this file.

#### Section of `define(DB_HOST, 'mariadb')`
The reason for using the name `mariadb` in the `DB_HOST` definition is that certain configuration and naming standards are used to communicate between containers running in Docker.
When working with tools like Docker Compose or Docker networks, one container can reach another by name within the network.
</br> </br>
Therefore, if the name of the MariaDB container is set to `mariadb`, it is possible for the WordPress container to access the MariaDB database using this name.
That is, by using the name `mariadb` in the `DB_HOST` definition, WordPress can access the MariaDB database under the name `mariadb` in the Docker network.
</br> </br>
However, if you are using a different naming or configuration in the Docker network, you may need to change this name. 
For example, if you specified a different service name in Docker Compose, you should set the `DB_HOST` value accordingly.

#### In order for PHP to work, a file named `php7.4-fpm.pid` is needed
`mkdir -p /run/php/;`: This command creates the `/run/php/` directory. This directory will contain the PID (Process ID) file of PHP-FPM processes.
</br> </br>
`touch /run/php/php7.3-fpm.pid;`: This command creates a PID file named `/run/php/php7.3-fpm.pid`. This file will contain the PHP-FPM process PID.
</br> </br>
Instead of these operations, specifying the `RUN service php7.4-fpm start` command in the Dockerfile, which does this directly, performs both of the above operations.
</br> </br>
One of these two methods can be used. Starting the `service php7.4-fpm start` service in this way creates the `.pid` file, or it can be created and done manually.

#### What is `--nodaemonize`?
The `--nodaemonize` flag is used to disable PHP-FPM's daemon mode. Normally, PHP-FPM runs as a daemon when started and runs in the background.
The `--nodaemonize` flag disables PHP-FPM's daemon mode, allowing you to run PHP-FPM in the terminal.

#### What is wp-cli?

**wp-cli** is an interface created to install WordPress from the cli.
</br>
To use it, we download the `wp-cli.phar` file and after giving it the necessary permissions, we put it under the `/usr/local/bin/wp` directory (by changing the name of wp-cli.phar to `wp`) so that we can use the command as `wp`.

#### What is `wp core download`?

That `wp core download`, there are core files that download WordPress files (such as `index.php`, `wp-admin` folder, etc.).

#### What is `wp core install`?

By doing this, we create a WordPress table in our database (inception_db). Therefore, when using env variables, this has nothing to do with the database (inception_db) previously created with MariaDB.
Here, we want to create a new table for WordPress in the database connected using the WordPress CLI (inception_db database previously created in MariaDB) with the values ​​we gave in the parameters in WP Core Install 
(such as admin, user, mail). That's why separate env variables (`WP_ADMIN`, `WP_USER`, etc.) are created in the `.env` file to use in WordPress installation.

### :sewing_needle: For MariaDB

#### Enter to MySQL
```
mysql -u <user_name> -p
```

#### Show Databases, Tables and Users
```
$ SHOW DATABASES;
$ USE <database_name>;
$ SHOW TABLES;

$ SELECT * FROM <table_name>;
$ SELECT user, host FROM mysql.user;
$ SHOW GRANTS FOR 'user_name';
```

#### `expect` File and Command
The `expect` command is a Unix and Linux tool used to perform automated tasks. It is often used within scripts and acts as a bridge between programs to interact with the user. 
In particular, it is often used to automate or create test cases for non-interactive processes.
</br></br>
An `expect` script determines one or more expected results (prompt, output, etc.) and performs certain actions based on those results. 
For example, it can perform tasks such as automatically connecting to an SSH session, executing a command remotely, and then checking its output.
</br></br>
`.expect` files contain expected results, typically generated using the `expect` command. These files are used to automate a specific process or create test cases. 
For example, you can create an `.expect` file to automatically start a session by interacting with a login screen that requests a username and password.
```
expect "Username:"
send "my_username\r"
expect "Password:"
send "my_password\r"
expect eof
```
This example can be used to automatically log into a session. First, it waits for the text `Username:`, then sends the username, then waits for the text `Password:`, sends the password, 
and finally terminates the process (eof: end of file).
</br></br>
To run these files, the expect command is usually used and the .expect file name is given as an argument:
```
expect my_script.expect
```
This command runs the `.expect` file named my_script.expect and performs the specified operations based on the expected results.
</br></br>
In a nutshell, the `expect` command is a tool used to perform automated tasks, and .expect files are files used to automate those tasks or create test cases.

**🏁And finally Part 3 ends here..🏁**

## :four: Part 4 - ~ B O N U S ~

### :plunger: For Adminer

Adminer is a tool that allows viewing and managing database tables via the browser.

#### Information required to login

<img src="imgs/adminer-login.png" align="center" height="800">

Since we access the services over the network and we access them through container names, we will write our container name `mariadb` where it says `Server`. 
And then we can view the tables by entering the user information with `DB_USER` and `DB_USER_PASS`, which we created for the first time in the MariaDB installation, and specifying our database name with `DB_NAME`.

### :placard: For Website

Node.js application creation is the process of starting and developing a software project using Node.js. Node.js is a runtime environment used to build JavaScript-based backend applications.
</br> </br>
Here are the general steps of the Node.js application creation process:
1. **Node.js Installation:** As a first step, you need to install the latest version of Node.js on your computer. You can download and install Node.js from its official website.
2. **Creating the Project Directory:** Create and navigate to a folder to create a Node.js project.
3. **Creating the `package.json` File:** Node.js projects usually start with a package.json file. This file contains project dependencies and basic information about the project.
You can create a `package.json` file using the `npm init` command. After entering the relevant information, this file is created.
4. **Installing Required Modules:** Install the modules your project needs with the `npm install` command. This command automatically installs the dependencies in the `package.json` file.
5. **Creating the Main Application File:** Create the main file of your Node.js application. This file is often called `index.js` or `app.js`.
6. **Starting the Application:** To start your Node.js application, go to the project directory in the terminal and run your main file. For example, a command like `node index.js` or `node app.js` can be used.

### :fire_extinguisher: For Redis

#### Installing and activating the redis plugin

The lines added for the redis plugin after the installation of WordPress in the `wp-setup.sh` file in the directory of the WordPress service:
```
wp plugin install redis-cache --activate --allow-root
wp redis enable --allow-root
```

#### `redis.conf` to Bind
Commenting out the `bind 127.0.0.1 ::1` setting changes the Redis server from only binding to local connections (127.0.0.1) to allowing binding to all network connections (0.0.0.0).
This change prevents Redis from connecting only to localhost (127.0.0.1) by default and allows Redis to accept connections from other IP addresses.
</br></br>
Reasons:
- **Allow remote connections:** If you want your Redis server to be remotely accessible, that is, if you want it to accept connections from different IP addresses, you can make this change.
- **Cluster configuration:** If you are configuring Redis as a cluster and want to communicate between different servers, you may need to make this change.
- **Platforms like Docker and Kubernetes:** If you are running Redis containers on platforms like Docker or Kubernetes, these platforms often need such configurations to accept connections from different IP addresses.

However, it is important to consider security risks when making this change. If your Redis server is running in an environment open to the internet, you should take security measures and limit incoming connections. 
Otherwise, it may be exploited by security vulnerabilities or malicious users.

#### Redis settings in the `wp-config.php` file in the Wordpress service
- `define( 'WP_REDIS_HOST', 'redis' );`   --> We give this name because the container name of the redis service stands for `redis` and WordPress needs to be connected.
- `define( 'WP_REDIS_PORT', 6379 );`      --> We give the port number on which the redis service is running.
- `define('WP_CACHE', true);`             --> Determines whether WordPress enables caching.


#### Confirming that redis is installed
There are several ways to verify that Redis is successfully connected to WordPress:
Redis plugin in WordPress admin panel: If you are using a plugin for Redis on your WordPress site, you can usually see information about the Redis connection in the admin panel of this plugin. 
This information usually includes your Redis server's IP address, connection port, and other configuration settings.
</br></br>
Click on `https://localhost:443/wp-admin`, i.e. `plugins->installed plugins->Redis Object Cache->settings` from the _**left side panel**_ in the _**admin panel**_ and see that it is connected.


### :sponge: For FTP Server

#### What is FTP-Server?

It can be considered like `sshd` because it is a daemon and also a server for remote connections. Required port configurations, whether it can be connected as root, etc. 
Just as we can make the operations a rule for devices that will be connected remotely from the `sshd.config` file, the ftp-server also has a daemon (vsftpd) and a config file. 
With this you can change user permissions, file permissions, etc. They have transactions. `vsftpd` is an example application for ftp-server. Of course, there are alternatives as well as ssh (telnet).

SSH (Secure Shell) server (sshd) provides a secure means for remote access and management. Similarly, vsftpd (Very Secure FTP Daemon) is an FTP server and acts as a central server for file transfer.

Both work with the same logic:
- **sshd:** SSH server provides remote access and management. This server provides an interface to connect to remote devices and run commands. File transfer can also be done securely via SSH.
- **vsftpd:** FTP server acts as a central server for file transfer. This server stores files and provides access to these files to users.
The FTP server stores files in a specific directory and grants clients permission to view and manipulate files in that directory.

Both serve the same purpose, but use different protocols: SSH is used for remote access and command execution, while FTP is used for file transfer.
However, both can be used to enable file transfer and management between remote devices.
</br> </br>
vsftpd (Very Secure FTP Daemon) is actually an FTP server program and allows clients that support the FTP protocol (such as FileZilla) to connect to the server. vsftpd acts as a central server for file transfer
and provides access to files to clients. Clients can download, upload or manage files by connecting to the vsftpd server. So vsftpd is a server program and is used by FTP clients (like FileZilla).

#### After making the necessary configurations for ftp-server, use FileZilla to test

FileZilla is an FTP client, and to connect to another device, that device must be configured as an FTP server. The device you want to connect to must be operating as an FTP server and have permissions to access it:
- **Configuring FTP Server:** The device you want to connect to must work as an FTP server. This server stores files and provides access to clients. Make sure the server is configured as an FTP server.
- **Connection Information to FTP Server:** You will need information such as IP address, username and password required to access the FTP server of the device you want to connect to.
This information must be provided by the administrator or owner of the server.
- **Using FileZilla Client:** You can use the FileZilla client to access the FTP server of the device you want to connect to. Open FileZilla and enter the IP address, username and password of the server you want to connect to.
- **Establishing a Connection:** FileZilla will connect to the server based on the information you provide and display the server's file system contents. Once the connection is established, you can download,
upload or manage files.

By following the steps above, you can connect to another device and access its files using FileZilla or any other FTP client. However, make sure that the device you want to connect to is configured as an 
FTP server and has access permissions. It is important to make sure it is set correctly.

#### FileZilla `Error: Failed to retrieve directory listing.`

It is thought to be a problem with the Passive mode in GUI ftp clients.
</br></br>
The problem was resolved when I changed `listen=NO` to `listen=YES` and `listen_ipv6=YES` to `listen_ipv6=NO` in `vsftpd.conf`.
</br></br>
I think the issue is related to `pasv_address`. You should write to the `pasv_address` value whatever is written to the Host section in FileZilla.
</br></br>
Since I am working with `bridge adapter` as my Network setting in Vbox, the router assigns IP to my virtual machine, so I write that assigned value to the `pasv_address` value. 
However, for a virtual machine running with Vbox Network setting `NAT`, `127.0.0.1` or `localhost` will probably need to be written to the `pasv_address` value. 
My basis for saying this is that my network setting in Vbox is `bridge adapter`, so I write the IP assigned to me (192.168.1.27) in the `pasv_address` value and write `Error: Failed to retrieve directory listing.` in FileZilla. 
My directory was listed without getting the error. However, when my Vbox network setting is `bridge adapter` and I assign the IP `127.0.0.1` to the `pasv_address` value, unfortunately I get 
`Error: Failed to retrieve directory listing.` I got the error. The problem is probably related to this.

#### Connecting to the server with `ftp` command
If there is a problem with FileZilla, we can use the `ftp` command as an alternative method:
```
ftp <server-ip>
```
or
```
ftp <user_name>@<server-ip>
```
`user_name` is the user created for the ftp server. Afterwards, it will ask for the _**username**_ and _**password**_ we created for the ftp server, and you must enter them. </br></br>
Afterwards, we can use some of the normal Linux commands (ls, pwd, etc.) You can see this by clicking `help`. 
A file can be uploaded to the server by saying `get <file_name>` to pull a file from the server and `put <file_name>` to upload a file to the server.

#### [Optinal] About using Sftp server and `sftp` command
SFTP is an abbreviation for Secure File Transfer Protocol or SSH File Transfer Protocol. It stands for Secure File Transfer Protocol. It is a network protocol that allows file transfer via SSH (Secure Shell) protocol.
Uses SSH infrastructure.
</br></br>
When testing with FileZilla, since this protocol is a subset of SSH, _**22**_ or the specified port number should be written to the port.
</br></br>
**`sftp` command usage:**
```
sftp <user_name@server_ip>
```
After connecting, use the same commands as `get`, `put` etc. as after connecting via `ftp` command.
</br></br>
`user_name` is the user created for the sftp server.

#### Sftp _known hosts_ problem

```
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@    WARNING: REMOTE HOST IDENTIFICATION HAS CHANGED!     @
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
IT IS POSSIBLE THAT SOMEONE IS DOING SOMETHING NASTY!
Someone could be eavesdropping on you right now (man-in-the-middle attack)!
It is also possible that a host key has just been changed.
The fingerprint for the ED125gw1 key sent by the remote host is
SHA256:a12dsc24gvss24tnsxffkymgdi215m2dsc25622ccb1scsu32fsdas42g3fdd.
Please contact your system administrator.
Add correct host key in /home/ftekdrmi/.ssh/known_hosts to get rid of this message.
Offending ECDSA key in /home/ftekdrmi/.ssh/known_hosts:2
  remove with:
  ssh-keygen -f "/home/ftekdrmi/.ssh/known_hosts" -R "192.168.1.27"
Host key for 192.168.1.27 has changed and you have requested strict checking.
Host key verification failed.
Connection closed
```

The solution to this problem, which occasionally occurs in SSH connections, is already written inside.


#### sftp `put` Problem

"The permission of `/var/www` does not permit the chrooted-user to create files in it.
That is correct and by design.
You must create a folder inside of `/var/www` with the proper rights of the user.

`/var/www` can not be writeable for the user."

The rumors were in this direction, but I didn't go any further. If I had made any more mistakes, I would have burst into tears, so I didn't do the idol problem, but of course, maybe there is a solution to this too.

### :window: For Own Service

I chose run windows service in the docker container. This supreme and ancient power had to be discovered.

#### Prerquires

In order to use this service, we first need to do preliminary configuration and downloads. Windows can run on the docker container thanks to the KVM hypervisor. 
It can do this thanks to the `--device=/dev/kvm` parameter it gives to the docker container. This parameter allows the container to access the `kvm` device on the host machine. 
That's why we first need to install kvm on our virtual machine.

There are two steps to be done;

1. **Installing and configuring kvm:**
```
$ sudo apt update && sudo apt install qemu-kvm libvirt-daemon-system libvirt-clients bridge-utils virt-manager -y
$ usermod -aG libvirt $(whoami)
$ sudo systemctl start libvirtd
$ sudo systemctl enable libvirtd
$ sudo modprobe kvm
$ sudo nano /etc/modules
```
The contents of the file `/etc/modules` should look like this:
```
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
# /etc/modules: kernel modules to load at boot time.
#
# This file contains the names of kernel modules that should be loaded
# at boot time, one per line. Lines beginning with "#" are ignored.

kvm
kvm_intel
kvm_amd
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
```
Check the path of kvm:
```
lsmod | grep kvm
```
If KVM has been successfully installed, the `/dev/kvm` directory should have been created. 
This directory is a device file required for KVM virtualization and allows KVM virtual machines to communicate with the host machine.

2. **Enabling the _**nested virtualize**_ feature in VirtualBox or virtualization program:**
There is an _**Enable Nested VT-x/AMD-V**_ option in the section where we set the CPU in the virtual machine's settings in VirtualBox, but this section cannot be selected.
That's why we will have to use the `VBox` command interface since we cannot enable this setting from there.

- _Enabling **nested virtualize** feature in Linux Vbox:_
Since my virtual machine has Debian installed, I need to do the following using Vbox's cli. </br>
To list virtual machines and see their names:
```
vboxmanage list vms
```
To enable the _nested virtualize_ feature of the relevant virtual machine:
```
VBoxManage modifyvm "<relevant_virtual_machine_name>" --nested-hw-virt=on
```
- _Enabling **nested virtualize** feature in Windows Vbox_
Go to the directory where VirtualBox is installed on your Windows system and find the `VBoxManage.exe` file there and copy the directory you found.
The copied directory may look something like this: `C:\Program Files\Oracle\Virtual Box`. </br>

Then open the _Command Prompt_ and write (Your directory may be different):
```
cd C:\Program Files\Oracle\Virtual Box
```
Then write:
```
VBoxManage modifyvm <relevant_virtual_machine_name> --nested-hw-virt on
```
Then confirm whether it is activated or not in the necessary settings. </br> </br>
Since it will be a nested virtual machine, it may be useful to provide extra processor cores and perhaps enable the _**Enable PAE/NX**_ feature. then _**Restart**_ the virtual machine

#### Change Windows Version

Windows version can be changed from `VERSION` env in dockefile:

| **Value**  | **Description**  | **Source**  | **Transfer**  | **Size**  |
|---|---|---|---|---|
| `win11`   | Windows 11 Pro         | Microsoft    | Fast    | 6.4 GB    |
| `win10`   | Windows 10 Pro         | Microsoft    | Fast    | 5.8 GB    |
| `ltsc10`  | Windows 10 LTSC        | Microsoft    | Fast    | 4.6 GB    |
| `win81`   | Windows 8.1 Pro        | Microsoft    | Fast    | 4.2 GB    |
| `win7`    | Windows 7 SP1          | Bob Pony     | Medium  | 3.0 GB    |
| `vista`   | Windows Vista SP2      | Bob Pony     | Medium  | 3.6 GB    |
| `winxp`   | Windows XP SP3         | Bob Pony     | Medium  | 0.6 GB    |
||||||
| `2022`    | Windows Server 2022    | Microsoft    | Fast    | 4.7 GB    |
| `2019`    | Windows Server 2019    | Microsoft    | Fast    | 5.3 GB    |
| `2016`    | Windows Server 2016    | Microsoft    | Fast    | 6.5 GB    |
| `2012`    | Windows Server 2012 R2 | Microsoft    | Fast    | 4.3 GB    |
| `2008`    | Windows Server 2008 R2 | Microsoft    | Fast    | 3.0 GB    |
||||||
| `core11`  | Tiny 11 Core           | Archive.org  | Slow    | 2.1 GB    |
| `tiny11`  | Tiny 11                | Archive.org  | Slow    | 3.8 GB    |
| `tiny10`  | Tiny 10                | Archive.org  | Slow    | 3.6 GB    |


#### Run
To run it, when you type the `IP:8006` port in the browser url, windows running in the docker container will open via the browser, thanks to noVNC.


### :paintbrush: For QEMU Service

Since the windows service can run thanks to the qemu service, we need to compile it too, so it is among the services.

#### Qemu Support
The line in the windows dockerfile where qemu files are included in the container:
```
COPY --from=qemu:not-latest / /
```
#### Debian _trixie-slim_ version
In the Qemu dockerfile, _trixie-slim debian version_ is used, which offers more minimal content and is based on the debian 11 version.

**🏁And finally Part 4 ends here..🏁**

## :paperclip: Sources

### VS Code
1. [VSCode Remote SSH Connection Failed](https://stackoverflow.com/questions/60507713/vscode-remote-ssh-connection-failed)
2. [VS Code Remote SSH Connection not working](https://stackoverflow.com/questions/64034813/vs-code-remote-ssh-connection-not-working)

### Docker Essentials
1. [Github Forstman1](https://github.com/Forstman1/inception-42?tab=readme-ov-file)
2. [Github Codesshaman](https://github.com/codesshaman/inception/tree/main)
3. [Github Vbachele](https://github.com/vbachele/Inception?tab=readme-ov-file)
4. [Github Gkandemi](https://github.com/gkandemi/docker)
5. [Docker Nedir Nasıl Kullanılır? | Part #1 | Image Nedir? Container Nedir? Docker Komutları](https://www.youtube.com/watch?v=4XVfmGE1F_w&list=PL_f2F0Oyaj4_xkCDqnRWp4p5ypjDeC0kO&index=1)
6. [The Ultimate Docker Cheat Sheet](https://dockerlabs.collabnix.com/docker/cheatsheet/#image-management-commands)
6. [Learn Docker in 7 Easy Steps - Full Beginner's Tutorial](https://www.youtube.com/watch?v=gAkwW2tuIqE)
6. [Docker Basics Tutorial with Node.js](https://fireship.io/lessons/docker-basics-tutorial-nodejs/)
6. [Github Fireship](https://github.com/fireship-io/docker-nodejs-basic-demo)
6. [Github farukdll](https://github.com/farukdll/Docker/tree/main?tab=readme-ov-file)
6. [Medium iremsalgar](https://medium.com/@iremsalgar/docker-42-c649c4e2e1ca)
6. [Docker Compose Env File - How to Read in environment variables file ( Docker )](https://www.youtube.com/watch?v=1je3VxDF67o)
6. [Difference Between run, cmd and entrypoint in a Dockerfile](https://www.baeldung.com/ops/dockerfile-run-cmd-entrypoint)

### Nginx
1. [Installing a Basic SSL/TLS Certificate in nginx](https://www.youtube.com/watch?v=xNk8fZCuCMU)
1. [How to Set Up SSL with NGINX](https://www.youtube.com/watch?v=X3Pr5VATOyA&t=65s)
1. [Error code: ssl_error_rx_record_too_long on nginx ubuntu server](https://stackoverflow.com/questions/25081239/error-code-ssl-error-rx-record-too-long-on-nginx-ubuntu-server)

### WordPress
1. [Github Fartomy PHP](../Born2beroot/debian#%EF%B8%8F-for-php)
2. [Github Fartomy Wordpress](../Born2beroot/debian#-for-wordpress)
2. [Installing WP-CLI](https://make.wordpress.org/cli/handbook/guides/installing/)
2. [WP Core Install](https://developer.wordpress.org/cli/commands/core/install/)
2. [WP User Create](https://developer.wordpress.org/cli/commands/user/create/)
2. [wp-config.php Configuration](https://developer.wordpress.org/apis/wp-config-php/)
2. [Wordpress Theme Setup](https://wordpress.com/themes/free)

### MariaDB
1. [Github Fartomy MariaDB](../Born2beroot/debian#-for-mariadb)

#### B O N U S

##### Adminer
1. [How to install Adminer (Database Administration Tool) on Ubuntu 22.04 | VPS Tutorial](https://www.youtube.com/watch?v=r4keak825B4)
1. [How to start apache2 automatically in a ubuntu docker container?](https://stackoverflow.com/questions/44376852/how-to-start-apache2-automatically-in-a-ubuntu-docker-container#44377561)
1. [Github CodeShaman](https://github.com/codesshaman/inception/blob/main/12_INSTALL_ADMINER.md)
1. [How to configure Adminer to be reachable on the local network](https://askubuntu.com/questions/813282/how-to-configure-adminer-to-be-reachable-on-the-local-network)
1. [How to Setup MariaDB + Adminer with Docker Compose ( Docker )](https://www.youtube.com/watch?v=uAH2zCYzhNw)

##### Website
1. [Creating a static website using Node.Js](https://www.youtube.com/watch?v=894__EP1wks)
1. [Create Static Webpages With Node Express.js](https://www.youtube.com/watch?v=iHAywmmHIV0)
1. [npm-init create a package.json file](https://docs.npmjs.com/cli/v6/commands/npm-init)

##### Redis
1. [How to Install and Configure Redis for WordPress](https://www.youtube.com/watch?v=jZo97S85gWE)

##### FTP-Server
1. [How to install an FTP Server on Ubuntu 22.04 with VSFTPD](https://www.youtube.com/watch?v=XNjOSY-wcb0)
1. [(How To) Install FTP Server (VSFTPD) on Ubuntu 20.04 (2020) #1](https://www.youtube.com/watch?v=1WVBC0KBOeE)
1. [How to Install and Set Up SFTP Server in Ubuntu 22.04](https://www.youtube.com/watch?v=pS_mY4Rfsg8)
    - [Create SFTP user and allow access to specific directory | SFTP Chroot](https://www.youtube.com/watch?v=XhnqJ4S7C10)
1. [How To Install an FTP Server in Ubuntu with VSFTPD](https://www.youtube.com/watch?v=k3Z_dqe0PzY)
1. [How to Setup FTP server in Ubuntu 22.04 using VSFTPD (2024)](https://www.youtube.com/watch?v=S5kDfUVXsw0)
1. [How to automatically add user account AND password with a Bash script?](https://stackoverflow.com/questions/2150882/how-to-automatically-add-user-account-and-password-with-a-bash-script#7701319)
1. [Run adduser non-interactively](https://askubuntu.com/questions/94060/run-adduser-non-interactively#94067)
1. [Easily Move Files To and From a Server with VSFTP | Top Docs with Jay LaCroix](https://www.youtube.com/watch?v=t50UfbGvWhw)
**About Errors:**
1. [vsftpd error Listing Directories](https://stackoverflow.com/questions/4723023/vsftpd-error-listing-directories)
2. [VSFTP failed to retrieve directory listing](https://askubuntu.com/questions/983065/vsftp-failed-to-retrieve-directory-listing)
2. [VSFTP failed to retrieve directory listing](https://serverfault.com/questions/555541/failed-to-retrieve-directory-listing-in-filezilla-connecting-to-vsftpd)
2. [SOLVED vsftpd Error: Failed to retrieve directory listing](https://www.linuxquestions.org/questions/linux-server-73/vsftpd-error-failed-to-retrieve-directory-listing-878838/)
2. [vsftpd does not list content of a directory](https://unix.stackexchange.com/questions/30559/vsftpd-does-not-list-content-of-a-directory)
2. [227 Entering Passive Mode (0,0,0,0,...) when connecting to vsftpd FTP server](https://superuser.com/questions/1502015/227-entering-passive-mode-0-0-0-0-when-connecting-to-vsftpd-ftp-server)
2. [Ubuntu: Trying to connect to vsftpd, Failed to retrieve directory listing (2 Solutions!!)](https://www.youtube.com/watch?v=RxRJgNxNjPk)
2. [FileZilla Server: Failed to Retreive Directory Listing FIX](https://www.youtube.com/watch?v=faDFDOK02-0)
2. [How to Fix Failed to Retrieve Directory Listing Error in FileZilla FTP? | MilesWeb](https://www.youtube.com/watch?v=HeHfmLSj7ik)
**About SFTP:**
1. [How to use SFTP Commands to Copy Files to/from a Server](https://www.youtube.com/watch?v=22lBJIfO9qQ)
1. [SFTP Error: open for write: permission denied](https://serverfault.com/questions/672755/sftp-error-open-for-write-permission-denied)

##### Own Service
1. [Running Windows in a Docker Container!](https://www.youtube.com/watch?v=xhGYobuG508)
1. [Microsoft Remote Desktop](https://apps.microsoft.com/detail/9wzdncrfj3ps?hl=en-us&gl=US)
1. [Github Dockur Windows](https://github.com/dockur/windows/tree/master)
1. [Github Dockur Windows Version List](https://github.com/dockur/windows?tab=readme-ov-file#faq)
1. [How to Install KVM and Configure Bridge Network in Debian12 | Ubuntu 22.04](https://www.youtube.com/watch?v=KFVe0-B2yLI)
1. [A VM inside a VM inside a VM - Nested Virtualized Explained!](https://www.youtube.com/watch?v=sieDrofaaDU)
1. [Enable Nested VT-x/AMD-V Greyed Out On Virtualbox | How To enable nested VTx/AMD V](https://www.youtube.com/watch?v=nI1gKNGKDws)
1. [How to enable nested VTX/Amd-V On Virtualbox | Virtualbox enable nested vtx/amd-v greyed out](https://www.youtube.com/watch?v=yp9CFQhEaUg)
1. [How to: "Enable Nested VT-x/AMD-V" on Virtualbox, UBUNTU OS](https://www.youtube.com/watch?v=pw49GqTMdIo)
1. [VirtualBox nested Intel virtualization is here!](https://www.youtube.com/watch?v=JMT2qimIL9Q)
1. [VirtualBox Nested Virtualization with VMware ESXi](https://www.youtube.com/watch?v=fWP0ii7gysg)

</br></br>

🏁And finally README.md ends here..🏁

<img src="imgs/googledream.jpg" align="center">
