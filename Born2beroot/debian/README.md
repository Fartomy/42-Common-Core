<img src="materials/debian_gif.gif" align="right" height="400">

# Debian

This installation is based on **Debian** and **bonus part** is included.

## 🧭 Road Map

1.  [Part 1 - Install Debian](#one-part-1---install-debian)

2. [Part 2 - Downloads and Adjustments and and Configurations](#two-part-2---downloads-and-adjustments-and-and-configurations)
   - [For SSH](#-for-ssh)
   - [For UFW](#%EF%B8%8F-for-ufw)
   - [For Sudo](#godmode-for-sudo)
   - [Password Policy](#%EF%B8%8F-password-policy)

3. [Part 3 - Monitoring.sh and Crontab Configurations](#3%EF%B8%8F%E2%83%A3-part-3---monitoringsh-and-crontab-configurations)

4. [Part Bonus - WordPress Setup and Choice of Your Service](#%EF%B8%8F%E2%83%A3-part-bonus---wordpress-setup-and-choice-of-your-service)

      - [WordPress Setup](#-wordpress-setup)
         - [For Lighttpd](#-for-lighttpd)
         - [For MariaDB](#-for-mariadb)
         - [For PHP](#%EF%B8%8F-for-php)
         - [For WordPress](#-for-wordpress)
      - [Choice of Your Service](#-choice-of-your-service)

6. [Part 4 - Submission and Peer-evaluation](#4%EF%B8%8F%E2%83%A3-part-4---submission-and-peer-evaluation)

7. [Extras and Resources](#5%EF%B8%8F%E2%83%A3-extras-and-resources)

   - [Extras](#-extras)
   - [Resources](#brain-resources)
  
## :one: Part 1 - Install Debian

First download VirtualBox and download Debian's .iso file. Here are the links:

- [VirtualBox](https://www.virtualbox.org/)

- [Debian](https://www.debian.org/)

After installing open virtualbox:

Press the above will also be the new key!

<img src="materials/1.png" align="center" height="325">

Next next next.. and 'Machine Folder' your machine folder path will be '/goinfre' but but be careful the hard disk file type will be vdi.

And then choose **'.iso'** Debian file. Click on the virtual machine you have created and click **'settings'** above. and from there click on **'Storage'**, click on **'Empty'** and press the **CD** sign next to the **'Optical Drive'** option in the right window. From there, click on **'Choose Disk File'** and select your downloaded debian **'.iso' file.

<img src="materials/2.png" align="center" height="325">

Setup video:

[Debian Setup Video](materials/setup_debian.mp4)

**🏁And finally Part 1 ends here..🏁**

## :two: Part 2 - Downloads and Adjustments and and Configurations

You will see this screen, probably this is the login screen

<img src="materials/31.png" align="center" height="300">
</br>
<img src="materials/32.png" align="center" height="300">

You can see the partitions and encrypted partitions of your disk by running this command:

```
lsblk
```

Before proceeding with the downloads and configurations, it is useful to know these:

- Be root:

```
su -
```

- Scan if there is an updated package:

```
apt update
```

- If there is a package that needs to be updated, update it:

```
apt upgrade
```

### 🛎️ Change the Hostname

Command to see hostname:

```
hostname
```

To change the hostname, let's enter the following file with nano **(you must be root)**:

```
nano /etc/hostname
```

You will probably see the hostname, yes change it and save:

`CTRL + O then ENTER and then CTRL + X to save and exit in nano`

Restart the computer after saving and exiting:

```
reboot
```

If you want to revert repeat these steps :d

### 🧮 User Commands

Apart from these, the command to see the users in your virtual machine:

```
getent passwd
```

Commands for adding and deleting users:

```
# adduser <user_name>```
# deluser <username>
```

### 🍇 Group Commands

The command to see the groups in your virtual machine:

```
# getent group```
# getent group <group_name> -> Users under a group
```

Commands for adding and deleting groups:

```
# groupadd <group_name>
# groupdel <group_name>
```

As an example, let's add the `user42` group:

```
groupadd user42
```

### 🤝 Commands of groups used with users

First command to see which group a user is in:

```
groups <user_name>
```

Command to add and remove a user from a group:

```
# usermod -aG <group_name> <user_name>
# gpasswd --delete <user_name> <group_name>
```

Now let's add the user under the `user42` group:

```
usermod -aG user42 <user_name>
```

## 🛠️ Installing packages and configuring files

### 🧰 For SSH

Install SSH:

```
apt install openssh-server
```

SSH activity query command and ssh start commands:

```
# systemctl start sshd
# systemctl enable sshd
# systemctl status ssh
```

#### :dna: SSH Port Change

You should go to this directory:

```
nano /etc/ssh/sshd_config
```
You should change these settings:

```
- #Port 22 -> Port 4242
- #PermitRootLogin prohibit-password -> PermitRootLogin no
- And yes, remove the '#' as well, they will comment out what you wrote. :)
- Hey! by the way just remove the '#' signs for the 2 settings I mentioned above. :d
```

<img src="materials/33.png" height="300">
</br>
<img src="materials/34.png" align="center" height="300">

Okay, after making these settings, restart with the command:

```
systemctl restart sshd
```

Then come to your virtualbox and press **'settings'** at the top, then **'network'**, 
then there will be an **'Advanced'** pane at the bottom, click there and press **'Port Forwarding'**. 
You will see a button with a green **'+'** sign on the right, yes press it and something like a 
table will appear. Do as in the picture in the **'Host port'** and **'Guess Port'** sections. 
I'm already adding a picture, I don't know why I felt the need to explain. Anyway, press ok ok and it's over.

<img src="materials/35.png" align="center" height="300">
</br>
<img src="materials/36.png" align="center" height="300">

After doing these restart your virtual machine:

```
reboot
```

After these settings, you can now connect to the virtual machine from the your host:

```
ssh your_username@localhost -p 4242
```

<img src="materials/37.png" align="center" height="300">
</br>
<img src="materials/38.png" align="center" height="300">

And you can access the virtual machine from the terminal of the host by entering the password of the user in your virtual machine.

_[@@@ Optional Problem @@@]_

```
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@    WARNING: REMOTE HOST IDENTIFICATION HAS CHANGED!     @
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
IT IS POSSIBLE THAT SOMEONE IS DOING SOMETHING NASTY!
Someone could be eavesdropping on you right now (man-in-the-middle attack)!
It is also possible that a host key has just been changed.
The fingerprint for the ***** key sent by the remote host is
SHA256:*****************/********/****.
Please contact your system administrator.
Add correct host key in /home/your_username/.ssh/known_hosts to get rid of this message.
Offending ECDSA key in /home/your_username/.ssh/known_hosts:3
  remove with:
  ssh-keygen -f "/home/your_username/.ssh/known_hosts" -R "[localhost]:4242"
Host key for [localhost]:4242 has changed and you have requested strict checking.
Host key verification failed.
```
If you encounter such a situation, what you need to do is stated in the message.

**🚩Yes, SSH that was it..🚩**

### 🛡️ For UFW

Install UFW:

```
apt install ufw
```

#### :eye_speech_bubble: Some UFW related commands

Deny all requests to us:

```
ufw default deny incoming
```

Allow all outbound requests:

```
ufw default allow outgoing
```

Enable ufw on system startup (Reboot your virtual machine after doing this):

```
ufw enable
```

Check out UFW's status:

```
# ufw status
# ufw status numbered -> numbered the rules
```

Allow incoming requests to port 4242 or deny this port:

```
# ufw allow 4242
# ufw deny 4242
```

<img src="materials/39.png" align="center" height="300">

to delete a rule:

```
# ufw delete allow 4242 -> this command deletes 'allow' rules 4242
# ufw delete deny 4242  -> deletes 'deny' rules 4242 <br/>
# ufw delete 1 -> deletes rule 1
```

**🚩Yes, UFW that was it..🚩**

### :godmode: For Sudo

Configuring `sudo` according to very very strict rules

Install Sudo:

```
apt install sudo
```

Add your user under the `sudo` group before proceeding to the config settings:

```
usermod -aG sudo <user_name>
```

```
visudo -> Let's enter the configuration file with this command
```

A screen like this should come:

<img src="materials/40.png" align="center" height="300">

Add some strict rules here:
 
 ```
 Defaults     passwd_tries=3 -> 3 wrong entries
 Defaults     badpass_message="Wrong Password!!!" -> wrong password message
 Defaults     requiretty -> terminal requirement for sudo command
 Defaults     logfile="/var/log/sudo/sudo.log" -> logs of every sudo command entered
 Defaults     log_input, log_output -> I/O of sudo commands
 Defaults     iolog_dir="/var/log/sudo/" -> path of inputs and outputs
```

_[@@@ Intriguing Ancient Infos @@@]_

{requiretty}

It prevents us from running commands and scripts remotely without fully connecting to a remote system via SSH.

Try this command on your host machine:

```
ssh your_username@localhost -p 4242 'echo 'your_pass' | sudo -S ls -al'
```

Or you can create a script file and paste that command and run the script file. It will not be working because require tty

We can send command with ssh but it is must be between quotes (''). And for sudo password we must use `-S` option and we can send that with `echo`

{secure_path}
```
What are Environment Variables (Environment Variables)?
Environment variables are global variables that the operating system and applications use to store and share configuration information. These variables contain various settings and preferences that are valid throughout the system or session.

One of the Most Common Environment Variables is: PATH
The PATH environment variable contains a list of directories where the operating system searches for commands. For example, when you type the ls command on the command line, the system searches for the ls command in directories defined in PATH.
A PATH is a list Decoupled by the character : between various directory paths. For example: /usr/bin:/bin:/usr/sbin:/sbin
sudo and secure_path
sudo is a tool that allows you to run a command with superuser (root) rights. when sudo is used, for security reasons, the system uses the secure_path setting in the sudoers file instead of using the PATH environment variable.

secure_path Function:
when a command is executed with sudo, the paths defined in secure_path are used as secure directories to search for the command.
This prevents users or scripts from executing commands in unsafe directories with sudo.
Example Scenario and Description
Let's say that your system has a directory named /custom/bin, and this directory is not defined in secure_path. Let's assume that there is a command named testcommand in this directory.

Running a Command as a Normal User:

When you run the /custom/bin/testcommand command as a user, the system uses the PATH environment variable and the command runs.
Running a Command with sudo:

when you run the sudo/custom/bin/testcommand command, sudo uses secure_path.
If /custom/bin is not defined in secure_path, sudo will not be able to find this command and will not be able to execute it. This indicates that sudo uses only the paths defined in secure_path.
Test
To test this situation:

create /custom/bin/testcommand (or another directory/command).
Add this directory to the PATH: export PATH=$PATH:/custom/bin
Run the command as a normal user: /custom/bin/testcommand
run with sudo: sudo/custom/bin/testcommand
If the sudo command gives a "command not found" error, this indicates that secure_path is working.
```

The last one should look like this:

<img src="materials/41.png" align="center" height="300">

To confirm these, you can exit _root_ and try what can be done with the `sudo` command.

**🚩Yes, `sudo` that was it..🚩**

### ⛓️ Password Policy

First, configure the password change frequency:

```
nano /etc/login.defs
```
You find it _Password aging control_:

<img src="materials/42.png" align="center" height="300">

Then do it like this:

```
PASS_MAX_DAYS   30
PASS_MIN_DAYS   2
PASS_WARN_AGE   7
```

_**⚠️Yes, that's all, but this setting is valid for root and users after you (usr). To change your user and root's, do this⚠️**_

First, let me prove it to you:

```
# chage -l root
# chage -l <user_name> -> I think that's a enough proof :()
```

To change:

```
# chage root
# chage <user_name>
```

<img src="materials/43.png" align="center" height="300">

You know what to do..

Now let's add our password creation rules

Install it:

```
apt install libpam-pwquality
```

Then follow this path:

```
nano /etc/security/pwquality.conf
```
You will encounter something like this:

<img src="materials/44.png" align="center" height="300">

Here's what you need to change:

```
difok = 7
minlen = 10
dcredit= -1
ucredit= -1
lcredit=-1
enforce_for_root
enforcing= 1
maxrepeat= 3
usercheck = 1
dictcheck = 1
```

I'm not going to write explanations, it's already written :()

_**⚠️Yes, that's all, but after you've done these, you still need to change the passwords for root, your user, and all other users if you have created them⚠️**_

How does?

```
# passwd root
# passwd <user_name>
```

**🏁And finally Part 2 ends here..🏁**

## 3️⃣ Part 3 - Monitoring.sh and Crontab Configurations

### 🗒️ Monitoring.sh

If you want to examine it, I shared the _monitoring.sh_ file above.

[Monitoring.sh](../monitoring.sh)

### ⏰ Crontab (cron)

Type this command:

```
crontab -e
```

[mini info]

```
The crontab -e command allows you to edit a crontab file belonging to the user who performed the operation.

For example, when user user1 adds a crontab task using the crontab -e command, that task is added to the crontab file belonging to user user1. 
Other users cannot see or edit this file.

A special folder in the system context, such as `/var/spool/cron/crontabs` or `/var/spool/cron`, is often used to access the user's crontab file. 
However, these files should not be edited directly; `crontab -e` should be used instead because this command preserves the structure of the files and provides the user with a safe editing environment.
```

Anyway, write at the bottom:

```
*/10 * * * * bash /your/monitoring.sh_path
```

<img src="materials/45.png" align="center" height="300">

**🏁And finally Part 3 ends here..🏁**

## *️⃣ Part Bonus - WordPress Setup and Choice of Your Service

### 🪑 Wordpress setup

#### 🪥 For Lighttpd

Use the following command to install **Lighttpd** on Debian:

```
apt install lighttpd -y
```

Activate **Lighttpd** service:

```
# systemctl start lighttpd
# systemctl enable lighttpd
# systemctl status lighttpd
```

Settings of **UFW** for **Lighttpd**:

```
ufw allow 80
```

Forward port _80_ from _port forwarding_ settings on **VirtualBox**.

<img src="../rocky/materials/41.png" align="center" height="300">

#### 🧼 For MariaDB

Install **MariaDB**:

```
apt install mariadb-server mariadb-client -y
```

Activate **MariaDB** service:

```
# systemctl start mariadb
# systemctl enable mariadb
# systemctl status mariadb
```

You have **MariaDB** installed on your server you need to secure your **MariaDB** by running a security script:

```
mysql_secure_installation
```

```
Output
Enter current password for root (enter for none): 
You already have your root account protected, so you can safely answer 'n'. 
Switch to unix_socket authentication [Y/n] n
You already have your root account protected, so you can safely answer 'n'. 
Change the root password? [Y/n] Y
New password: 
Re-enter new password: 
Remove anonymous users? [Y/n] Y
Disallow root login remotely? [Y/n] Y
Remove test database and access to it? [Y/n] Y
Reload privilege tables now? [Y/n] Y
```

Now you can use the command below to access your **MariaDB**:

```
mysql -u root -p
```

### 🕯️ For PHP

To enable **PHP-FPM** with **FastCGI** support, first, you need to install **PHP** along with the necessary extensions. 
To do this, you can use the command below:

```
apt install php php-cgi php-fpm php-mysql -y
```

Next, you need to edit the _php.ini_ file (where _X_ is your version of php):

```
nano /etc/php/X.X/fpm/php.ini
```

Find the following line **uncomment** it and change it to **1** as shown below:

```
cgi.fix_pathinfo=1
```

By default, **PHP** points to the UNIX socket `/var/run/php/phpX.X-fpm.sock`. So, you will need to configure the **PHP-FPM** pool to set **PHP** to listen to the **TCP** socket.

You can do this by editing `/etc/php/X.X/fpm/pool.d/www.conf` file:

```
nano /etc/php/X.X/fpm/pool.d/www.conf
```

Find the following line:

```
listen = /run/php/php8.2-fpm.sock
```

And replace it with the following line:

```
listen = 127.0.0.1:9000
```

Then, restart the **PHP-FPM** service to apply the **Lighttpd** configuration changes:

```
systemctl restart phpX.X-fpm
```

Next, you will need to modify the _15-fastcgi-php.conf_ file:

```
nano /etc/lighttpd/conf-available/15-fastcgi-php.conf
```

Find the following lines in the file:

```
fastcgi.server += ( ".php" =>
((
"bin-path" => "/usr/bin/php-cgi",
"socket" => "/run/lighttpd/php.socket",
...
))
)
```

And replace them with the following:

```
"host" => "127.0.0.1",
"port" => "9000",
```

Then, enable both **FastCGI** and **FastCGI-PHP** modules with the following commands:

```
# lighty-enable-mod fastcgi
# lighty-enable-mod fastcgi-php
```

Finally, restart the **Lighttpd** service to apply the changes:

```
systemctl restart lighttpd
```

Go to this path `/var/www/html` and delete `index.html` file:

```
rm -rf index.html
```

For the **PHP** testing, create `info.php` file:

```
nano info.php
```

Write these lines in the file:

```
<?php
phpinfo();
?>
```

Check on your browser:

```
http://localhost:8080/info.php
```

### 🎬 For Wordpress

First of all, you should install these packages:

```
apt install -y wget unzip
```

Download **WordPress** packages:

```
wget https://wordpress.org/latest.zip
```

Extract files:

```
unzip latest.zip
```

Let's adjust some permission settings to avoid problems with reading and writing:

```
# find wordpress/ -type d -exec chmod 755 {} \;
# find wordpress/ -type f -exec chmod 644 {} \;
```

Enter wordpress dir and copy the files to `/var/www/html/`:

```
cp -r * /var/www/html/
```

Let's create a database and user for **WordPress** in **MariaDB**:

```
mysql -u root -p
```

Execute the following commands in **MariaDB**:

```
create database example_db default character set utf8 collate utf8_unicode_ci;
```

```
create user 'example_user'@'localhost' identified by 'example_pw';
```

```
grant all privileges on example_db.* TO 'example_user'@'localhost';
```

```
flush privileges;
```

Finally, _exit_ from **MariaDB**.

Now we can go to the WordPress installation page:

```
http://localhost:8080/index.php
```

<img src="../rocky/materials/52.png" align="center" height="300">
</br>
<img src="../rocky/materials/53.png" align="center" height="300">
</br>
<img src="../rocky/materials/54.png" align="center" height="300">


We are having a problem with write permission to the `wp-config.php` file on the system.

```
chown -R www-data:www-data /var/www/html/
```

Try again.

<img src="../rocky/materials/55.png" align="center" height="300">
</br>
<img src="../rocky/materials/56.png" align="center" height="300">
</br>
<img src="../rocky/materials/57.png" align="center" height="300">
</br>
<img src="../rocky/materials/58.png" align="center" height="300">
</br>
<img src="../rocky/materials/59.png" align="center" height="300">

Lastly, you should rename or delete `index.lighttpd.html` file in the this path `/var/www/html/`:

```
# mv /var/www/html/index.lighttpd.html /var/www/html/d.html
or
# rm -rf /var/www/html/index.lighttpd.html
```

Visit your main page:

```
http://localhost:8080
```

### 📺 Choice of Your Service

My choice is to serve _Python's http server_ as a service.

For that install the `python3` package first:

```
apt install -y python3
```

Give the necessary port permissions in the _UFW_:

```
ufw allow 5050
```

Add the _5050_ port from the **port forwarding** setting in the virtualBox's settings:

<img src="materials/35.png" align="center" height="300">

To create the service, create a file named `python-http-server.service` in the `/etc/systemd/system` directory:

```
nano /etc/systemd/system/python-http-server.service
```

Write the following in it:

```
[Unit]
Description=Python HTTP Server

[Service]
ExecStart=/usr/bin/python3 -m http.server 5050
WorkingDirectory=/directory/path/to/be/presented/on/the/browser
Restart=always
User=user_name

[Install]
WantedBy=multi-user.target
```

To start the service after saving and exiting:

```
# systemctl enable python-http-server.service
# systemctl start python-http-server.service
# systemctl status python-http-server.service
```

If it is active, access it via browser:

```
http://localhost:5050
```

**🏁 And finally Part Bonus ends here.. 🏁**

## 4️⃣ Part 4 - Submission and Peer-evaluation

Now that everything is finished, it's time to get your disc signature:

First of all, you should go into the file we have installed in _/goinfre_ and find your virtual machine.
I'm assuming you went there as I wouldn't know where this is.

Type this:

```
shasum <your_virtual_machine>.vdi
```

When your disk signature comes, you will send it to the 'signature.txt' file and get push. That's all. If you've come this far, 🥳CONGRATULATIONS!!!🥳

**🏁**And finally Episode 4 ends here..🏁**

## 5️⃣ Extras and Resources

### ➕ Extras

1-) You can connect to your friend's virtual machine using SSH.

2-) With _netcat_, you can chat with your friends via terminal.

Materials:

- IPv4adress
```
# apt install net-tools
# ifconfig
```

- Port

```
netstat -anvp tcp | awk 'NR<3 || /LISTEN/' -> find open port
```

🥂 How to use NetCat

First of all, type the open port of your friend's PC into the terminal:

```
nc -l <port -> and ENTER. and your friend wait. Then go to your own computer
```

After that, type your friend's _IPv4_ address and port number and press _ENTER_.
Let the messaging begin!

```
nc <IPv4_adress> <port>
```

☣️ If you forget your Debian user and root passwords

[Debian Password Reset](https://www.youtube.com/watch?v=3Hrm3_CFKic)

### :brain: Resources

1. [Aptitude vs apt](https://dijitalders.net/icerik/22/2369/apt_get_ve_aptitude.html)
2. [Sudo](https://medium.com/@gokhansengun/sudo-nas%C4%B1l-kullan%C4%B1l%C4%B1r-ve-incelikleri-nelerdir-52db87d74ba)
3. [SElinux](https://www.redhat.com/en/topics/linux/what-is-selinux)
4. [AppArmor](https://apparmor.net/)
5. [SSH](https://www.hostinger.web.tr/rehberler/ssh-nedir)
6. [awk command](https://www.howtogeek.com/562941/how-to-use-the-awk-command-on-linux/)
7. [sudo config](https://www.tecmint.com/sudoers-configurations-for-setting-sudo-in-linux/)
8. [List Users Commands](https://devconnected.com/how-to-list-users-and-groups-on-linux/#:~:text=In%20order%20to%20list%20users,navigate%20within%20the%20username%20list)
9. [Lighttpd Setup on Debian](https://orcacore.com/install-lighttpd-web-server-debian-12/)
10. [Wordpress Setup Video](https://www.youtube.com/watch?v=PsMhopODLTY&t=565s)
11. [Wordpress Setup Video 2](https://www.youtube.com/watch?v=PhNxEZcxXV0)

**🏁And finally README.md ends here..🏁**

<img src="materials/matrix.gif" align="right" height="550">
