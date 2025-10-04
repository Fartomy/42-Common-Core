<img src="materials/rocky_linux.png" align="right" height="400">

# Rocky

Bu kurulum **Rocky Linux** tabanlıdır ve **bonus bölüm** dahildir.

## 🧭 Yol Haritası

1. [Kısım 1 - Rocky Yükleme](#1%EF%B8%8F%E2%83%A3-k%C4%B1s%C4%B1m-1---rocky-linux-y%C3%BCkleme)
2. [Kısım 2 - İndirmeler ve Ayarlamalar ve Yapılandırmalar](#2%EF%B8%8F%E2%83%A3-k%C4%B1s%C4%B1m-2---i%CC%87ndirmeler-ve-ayarlamalar-ve-yap%C4%B1land%C4%B1rmalar)
   - [SSH için](#-ssh-i%C3%A7in)
   - [Sudo için](#godmode-sudo-i%C3%A7in)
   - [Şifreleme Politikası](#%EF%B8%8F-%C5%9Fifreleme-politikas%C4%B1)
3. [Kısım 3 - Monitoring.sh ve Crontab Yapılandırmaları](#3%EF%B8%8F%E2%83%A3-k%C4%B1s%C4%B1m-3---monitoringsh-ve-crontab-yap%C4%B1land%C4%B1rmalar%C4%B1)
4. [Kısım 4 - Son Kontroller](#four-k%C4%B1s%C4%B1m-4---son-kontroller)
5. [Bonus Bölüm - WordPress Kurulumu ve Hizmetinizin Seçimi](#%EF%B8%8F%E2%83%A3-bonus-b%C3%B6l%C3%BCm---wordpress-kurulumu-ve-hizmetinizin-se%C3%A7imi)
   - [WordPress Kurulumu](#-wordpress-kurulumu)
        - [Lighttpd için](#-lighttpd-i%C3%A7in)
        - [MariaDB için](#-mariadb-i%C3%A7in)
        - [PHP için](#%EF%B8%8F-php-i%C3%A7in)
        - [WordPress için](#-wordpress-i%C3%A7in)
   - [Hizmetinizin Seçimi](#-hizmetinizin-se%C3%A7imi)
6. [Kısım 5 - Gönderim ve Akran Değerlendirmesi](#-k%C4%B1s%C4%B1m-5---g%C3%B6nderim-ve-akran-de%C4%9Ferlendirmesi)
7. [Kaynaklar](#-kaynaklar)

## 1️⃣ Kısım 1 - Rocky Linux Yükleme

Öncelikle **VirtualBox**'ı indirin ve **Rocky'nin .iso** dosyasını indirin. İşte bağlantılar:
- [VirtualBox](https://www.virtualbox.org/)
- [Rocky Linux](https://rockylinux.org/)

Kurulum videosu:

[Rocky Kurulum Videosu](materials/setup_rocky.mp4)


**🏁Ve nihayet Kısım 1 burada bitiyor.🏁**

## 2️⃣ Kısım 2 - İndirmeler ve Ayarlamalar ve Yapılandırmalar

<img src="materials/25.png" align="center" height="300">

Disk şifrenizi girdikten sonra bu ekranı göreceksiniz. Muhtemelen bu giriş ekranıdır. :D

<img src="materials/26.png" align="center" height="300">

Bu komutu çalıştırarak diskinizin bölümlerini ve şifrelenmiş bölümlerini görebilirsiniz:

`lsblk`

İndirme ve yapılandırma işlemlerine geçmeden önce şunları bilmenizde fayda var:

- Kök olmak için:

`su`

- Güncellenmiş bir paket varsa tarayın:

```
dnf -y update
```

**🛎️ Host adını değiştirin:**

Host adını değiştirmek için **(root olmalısınız)** dosyasını girelim:

```
vi /etc/hostname
```

Host adınızı değiştirilmesi gerektiği gibi değiştirin.

Kaydettikten ve çıktıktan sonra bilgisayarı yeniden başlatın:

```
reboot
```

**🧮 Kullanıcı Komutları**

Bunların dışında sisteminizdeki kullanıcıları görmenizi sağlayacak komut:

```
getent passwd
```

Kullanıcı ekleme ve silme komutları:

```
# adduser <user_name>
# userdel <user_name>
```

Oluşturulan kullanıcıya şifre atamak için:

```
passwd <user_name>
```

**🍇 Group Commands**

Sisteminizdeki grupları görme komutu:
```
# getent group
# getent group <group_name> --> Users under a group
```
Grup ekleme ve silme komutları:

```
groupadd <group_name>
groupdel <group_name>
```

Örnek olarak `user42` grubunu ekleyelim:

```
groupadd user42
```

**🤝 Kullanıcılarla kullanılan grup komutları**

Bir kullanıcının hangi grupta olduğunu görmek için ilk komut:

```
groups <user_name>
```

Bir gruba kullanıcı ekleme ve gruptan kullanıcı çıkarma komutu:

```
# usermod -aG <group_name> <user_name>
# gpasswd --delete <user_name> <group_name>
```

Şimdi kullanıcıyı `user42` grubunun altına ekleyelim:

```
usermod -aG user42 <user_name>
```

### 🛠️ Paketleri yükleme ve dosyaları yapılandırma

#### 🧰 SSH için

**SSH sunucusu** paketi muhtemelen zaten indirilmiştir. Değilse aşağıdaki komutu çalıştırın:

- SSH sunucu paketini yükleyin:

```
dnf -y install openssh-server
```

SSH etkinlik sorgusu komutu ve ssh başlatma komutları:

```
# systemctl start sshd
# systemctl enable sshd
# systemctl status sshd
```

##### 🧬 SSH Port Değişikliği

Bu dizine gitmelisiniz:

```
vi /etc/ssh/sshd_config
```

Bu ayarları değiştirmelisiniz:
- #Port 22 -> Port 4242
- #PermitRootLogin prohibit-password -> PermitRootLogin no
- Ve evet, '#' işaretini de kaldırın, yorum satırı olarak kalmaması için. :)
- Bu arada yukarıda bahsettiğim 2 ayar için '#' işaretlerini kaldırmanız yeterli. :D

<img src="materials/27.png" align="center" height="300">
</br>
<img src="materials/28.png" align="center" height="300">

Tamam, bu ayarları yaptıktan sonra şu komutla yeniden başlatın:

```
systemctl restart sshd
```

Muhtemelen şöyle bir hatayla karşılaşacaksınız:

<img src="materials/29.png" align="center" height="300">

Çözüme:

```
dnf install -y policycoreutils-python-utils
```

Bu sorunu aşmak için Selinux'un güvenlik politikası ayarlarında bazı yapılandırmalar yapmamız gerekiyor:

```
semanage port -a -t ssh_port_t -p tcp 4242
```

SSH için port içeriğini kontrol edin:

```
semanage port -l | grep ssh
```

SSHD hizmetini yeniden başlatın:

```
systemctl restart sshd
```

Daha sonra güvenlik duvarı tarafında istediğimiz port ayarı için küçük bir ayar daha yapmamız gerekiyor:

```
firewall-cmd --permanent --zone=public --add-port=4242/tcp
```

Güvenlik duvarını yeniden yükle:

```
firewall-cmd --reload
```

Güvenlik duvarı port'larını listeleyin:

```
firewall-cmd --list-port
```

Güvenlik duvarı hizmetini listeleyin:

```
firewall-cmd --list-service
```

Güvenlik duvarının tümünü listele:

```
firewall-cmd --list-all

```

Dinleme port'larını kontrol etmek için:

```
ss -tnlp | grep ssh
```

Tamam, artık birçok şeyi kontrol ettiğimize ve bundan emin olduğumuza göre, bir sonraki adım port yönlendirme olacak :d

Sanal kutunuza geri dönün ve üstteki _settings_'e, ardından _network_'e basın, ardından altta _Gelişmiş_ bölme olacaktır, oraya tıklayın ve _Port Yönlendirme_'ye basın. Sağda yeşil __+_ işaretli bir buton göreceksiniz, evet ona basın ve tablo gibi bir şey görünecektir. _Host port_ ve _Guess Port_ bölümlerinde resimdeki gibi yapın. Zaten resim ekliyorum, neden açıklama ihtiyacı hissettim bilmiyorum. Neyse, tamam tamam'a basın ve bitti.

<img src="../debian/materials/35.png" align="center" height="300">
</br>
<img src="../debian/materials/36.png" align="center" height="300">


Artık ana makineniz aracılığıyla SSH aracılığıyla bağlanmaya hazırız gibi görünüyor.

```
ssh ruser@localhost -p 4242
```

_[@@@ Opsiyonel Problem @@@]_

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
Böyle bir durumla karşılaştığınızda yapmanız gerekenler mesajda belirtilmiştir.

**🚩 Evet, SSH bu kadardı.. 🚩**

#### :godmode: Sudo için

`sudo`yu çok çok katı kurallara göre yapılandırmak.

Sudo sistemde mevcut değilse:

```
dnf install -y sudo
```

Sistemde `sudo` grubu yoksa oluşturun:

```
groupadd sudo
```

Bu gruba eklenmesi gereken kullanıcıyı ekleyin:

```
usermod -aG sudo <user_name>
```

Tamam, çok şey yaptık, şimdi yapılandırma ayarlarına geçelim:

Bu komutla konfigürasyon dosyasına girelim:

```
visudo
```

Şöyle bir ekran gelmeli:

<img src="materials/30.png" align="center" height="300">

Buraya bazı katı kurallar ekleyin:

```
Defaults     passwd_tries=3 -> 3 wrong entries
Defaults     badpass_message="Wrong Password!!!" -> wrong password message
Defaults     requiretty -> terminal requirement for sudo command
Defaults     logfile="/var/log/sudo/sudo.log" -> logs of every sudo command entered
Defaults     log_input, log_output -> I/O of sudo commands
Defaults     iolog_dir="/var/log/sudo/" -> path of inputs and outputs
```

Sonuncusu şöyle görünmeli:

<img src="materials/31.png" align="center" height="300">

_[@@@ İlginç Antik Bilgiler @@@]_

{requiretty}

Uzakta ki bir sisteme SSH aracılığıyla tam olarak bağlanmadan komutları ve komut dosyalarını uzaktan çalıştırmamızı engeller.

Ana makinenizde bu komutu deneyin:

```
ssh your_username@localhost -p 4242 'echo 'your_pass' | sudo -S ls -al'
```

Veya bir komut dosyası oluşturup bu komutu yapıştırıp komut dosyasını çalıştırabilirsiniz. tty gerektirdiğinden çalışmayacak.

Komutu ssh ile gönderebiliriz ancak tırnak işaretleri ('') arasında olması gerekir. Sudo şifresi için `-S` seçeneğini kullanmalıyız ve bunu `echo` ile gönderebiliriz.

{secure_path}
```
Ortam Değişkenleri (Ortam Değişkenleri) Nedir?
Ortam değişkenleri, işletim sisteminin ve uygulamaların yapılandırma bilgilerini depolamak ve paylaşmak için kullandığı genel değişkenlerdir. Bu değişkenler sistem veya oturum genelinde geçerli olan çeşitli ayarları ve tercihleri ​​içerir.

En Yaygın Ortam Değişkenlerinden Biri: PATH
PATH ortam değişkeni, işletim sisteminin komutları aradığı dizinlerin bir listesini içerir. Örneğin, komut satırına ls komutunu yazdığınızda sistem, ls komutunu PATH'de tanımlanan dizinlerde arar.
PATH, çeşitli dizin yolları arasında : karakteriyle ayrılan bir listedir. Örneğin: /usr/bin:/bin:/usr/sbin:/sbin
sudo ve secure_path
sudo, bir komutu süper kullanıcı (kök) haklarıyla çalıştırmanıza izin veren bir araçtır. sudo kullanıldığında, güvenlik nedeniyle sistem, PATH ortam değişkenini kullanmak yerine sudoers dosyasındaki secure_path ayarını kullanır.

secure_path İşlevi:
Sudo ile bir komut yürütüldüğünde, secure_path'te tanımlanan yollar, komutu aramak için güvenli dizinler olarak kullanılır.
Bu, kullanıcıların veya komut dosyalarının sudo ile güvenli olmayan dizinlerde komut yürütmesini engeller.
Örnek Senaryo ve Açıklama
Diyelim ki sisteminizde /custom/bin adında bir dizin var ve bu dizin secure_path'te tanımlı değil. Bu dizinde testcommand adında bir komutun olduğunu varsayalım.

Bir Komutu Normal Kullanıcı Olarak Çalıştırmak:

Kullanıcı olarak /custom/bin/testcommand komutunu çalıştırdığınızda sistem PATH ortam değişkenini kullanır ve komut çalışır.
Sudo ile bir komut çalıştırmak:

sudo/custom/bin/testcommand komutunu çalıştırdığınızda sudo, secure_path'i kullanır.
Eğer /custom/bin güvenli_yolda tanımlanmamışsa, sudo bu komutu bulamayacak ve çalıştıramayacaktır. Bu, Sudo'nun yalnızca secure_path'te tanımlanan yolları kullandığını gösterir.
Test
Bu durumu test etmek için:

/custom/bin/testcommand (veya başka bir dizin/komut) oluşturun.
Bu dizini PATH'e ekleyin: Export PATH=$PATH:/custom/bin
Komutu normal bir kullanıcı olarak çalıştırın: /custom/bin/testcommand
sudo ile çalıştır: sudo/custom/bin/testcommand
Sudo komutu "komut bulunamadı" hatası veriyorsa, bu secure_path'in çalıştığını gösterir.
```

Bunları onaylamak için _root_'tan çıkıp `sudo` komutuyla neler yapılabileceğini deneyebilirsiniz.

**🚩Evet, sudo bu kadardı..🚩**

#### ⛓️ Şifreleme Politikası

Öncelikle şifre değiştirme sıklığını yapılandırın:

```
nano /etc/login.defs
```

Buradan bulabilirsiniz _Password aging control_:

<img src="materials/32.png" align="center" height="300">

Daha sonra bunu şu şekilde yapın:

```
PASS_MAX_DAYS   30
PASS_MIN_DAYS   2
PASS_WARN_AGE   7
```

_**⚠️Evet bu kadar ama bu ayar root ve sizden (usr) sonra ki kullanıcılar için geçerlidir. Kullanıcınızı ve kökünüzü değiştirmek için şunu yapın⚠️**_

Öncelikle size şunu kanıtlayayım:

```
# chage -l root`
# chage -l <user_name>
```

Bu yeterli bir kanıt sanırım :d

Değiştirmek için:

```
# chage root
# chage <user_name>
```

<img src="materials/33.png" align="center" height="300">

Ne yapacağını biliyorsun..

Şimdi şifre oluşturma kurallarımızı ekleyelim.

Bu yolu takip edin:

```
vi /etc/security/pwquality.conf
```

Şöyle bir şeyle karşılaşacaksınız:

<img src="materials/pwquality-before.png" align="center" height="300">

İşte değiştirmeniz gerekenler:

```
difok = 7
minlen = 10
dcredit= -1
ucredit= -1
lcredit= -1
enforce_for_root
enforcing= 1
maxrepeat= 3
usercheck = 1
dictcheck = 1
```

<img src="materials/pwquality-after.png" align="center" height="300">

Açıklama yazmayacağım, zaten yazılmış :()

_**⚠️ Evet, hepsi bu, ancak bunları yaptıktan sonra yine de root'un, kullanıcınızın ve oluşturduysanız diğer tüm kullanıcıların şifrelerini değiştirmeniz gerekiyor. ⚠️**_

```
# passwd root
# passwd <user_name>
```

**🏁Ve nihayet 2. Bölüm burada bitiyor..🏁**

## 3️⃣ Kısım 3 - Monitoring.sh ve Crontab Yapılandırmaları

### 🗒️ Monitoring.sh

İncelemek isterseniz yukarıda _monitoring.sh_ dosyasını paylaştım.

[monitoring.sh](../monitoring.sh)

### ⏰ Crontab (cron)

Bu komutu yazın:

```
crontab -e
```

[mini bir bilgi]

```
'crontab -e' komutu, işlemi gerçekleştiren kullanıcıya ait bir crontab dosyasını düzenlemenizi sağlar.

Örneğin kullanıcı1 kullanıcısı 'crontab -e' komutunu kullanarak bir crontab görevi eklediğinde, bu görev kullanıcı1 kullanıcısına ait crontab dosyasına eklenir. Diğer kullanıcılar bu dosyayı göremez ve düzenleyemez.

Kullanıcının crontab dosyasına erişmek için genellikle sistem bağlamındaki `/var/spool/cron/crontabs` veya `/var/spool/cron` gibi özel bir klasör kullanılır. Ancak bu dosyalar doğrudan düzenlenmemelidir; Bunun yerine 'crontab -e' kullanılmalıdır çünkü bu komut dosyaların yapısını korur ve kullanıcıya güvenli bir düzenleme ortamı sağlar.
```

Neyse, altına şunu yazın:

```
*/10 * * * * bash /your/monitoring.sh_path
```

**🏁 Ve nihayet 3.Bölüm burada bitiyor.. 🏁**

## :four: Kısım 4 - Son Kontroller

Çıktıların beklendiği gibi olduğundan emin olun:

```
head -n 2 /etc/os-release
```

```
sestatus
```

```
ss -tunlp
```

```
firewall-cmd --list-service
```

```
firewall-cmd --list-port
```

```
firewall-cmd --state
```

Örneğin ben `ss -tunlp` komutundan beklenen çıktıyı alamadım. _chronyd_ isimli servis belli bir port üzerinde dinleme yapıyordu, şimdi kapatalım.

<img src="materials/34.png" align="center" height="300">

Çözüm:

```
# systemctl stop chronyd
systemctl disable chronyd
```

<img src="materials/35.png" align="center" height="300">

Son olarak güvenlik duvarında çalışan birçok hizmet var

<img src="materials/36.png" align="center" height="300">

Bunları kaldırmak için:

```
# firewall-cmd --permanent --remove-service=cockpit
# firewall-cmd --permanent --remove-service=dhcpv6-client
# firewall-cmd --reload
```

<img src="materials/37.png" align="center" height="300">

**🏁 Ve nihayet Kısım 4 burada bitiyor.. 🏁**

## *️⃣ Bonus Bölüm - Wordpress kurulumu ve Hizmetinizin Seçimi

### 🪑 Wordpress kurulumu

#### 🪥 Lighttpd için

**Lighttpd**'yi kurmanın en basit yolu, **EPEL** deposunu eklemek ve aşağıdaki komutları kullanarak yazılım listesini güncellemektir:

```
dnf -y install epel-release && dnf -y update && dnf -y install lighttpd
```

**Lighttpd**'yi yükledikten sonra hizmeti başlatmanız, hizmeti önyükleme sırasında otomatik olarak başlayacak şekilde etkinleştirmeniz ve aşağıdaki komutları kullanarak durumu doğruladığınızdan emin olmanız gerekir:

```
# systemctl start lighttpd
# systemctl enable lighttpd
# systemctl status lighttpd
```

**lighttpd** hizmetini etkinleştirdikten sonra _status_ çıktısında bazı hatalar oluşacaktır.

Bunları çözmek için:

<img src="materials/38.png" align="center" height="300">

Selinux politika ayarlarında "httpd_setrlimit"i etkinleştirin:
```
setsebool -P httpd_setrlimit on
```

Daha sonra diğer sorun için **lighttpd** yapılandırma dosyasına gidin:

```
vi /etc/lighttpd/lighttpd.conf
```

`server.use-ipv6 = "enable"` bölümünü bulun ve bu satırı `server.use-ipv6 = "disable"` olarak değiştirin

<img src="materials/39.png" align="center" height="300">
</br>
<img src="materials/40.png" align="center" height="300">

**lighttpd** hizmetini yeniden başlatın:

```
systemctl restart lighttpd
```

Güvenlik duvarınızda HTTP trafiğini açtığınızdan emin olun:

```
# firewall-cmd --permanent --zone=public --add-service=http
# firewall-cmd --reload
```

VirtualBox'ın bağlantı noktası yönlendirme ayarlarına port'u ekleyin:

<img src="materials/41.png" align="center" height="300">

Şimdi tarayıcınızı açın ve Lighttpd web sunucunuzun çalıştığını doğrulamak için aşağıdaki URL'ye gidin:

```
http://localhost:8080
```

**Lighttpd** için varsayılan yapılandırma dosyası `/etc/lighttpd/lighttpd.conf` şeklindedir ve belge kök dizini `/var/www/lighttpd/` şeklindedir

#### 🧼 MariaDB için

MariaDB'yi yükleyin:

```
dnf -y install mariadb mariadb-server
```

**MariaDB**'yi yükledikten sonra, gösterildiği gibi başlatmanız, etkinleştirmeniz ve durumu doğrulamanız gerekir:

```
# systemctl start mariadb
# systemctl enable mariadb
# systemctl status mariadb
```

**MariaDB** çalışmaya başladıktan sonra aşağıdaki güvenlik komut dosyası komutunu vererek kurulumu güvenli hale getirmeniz gerekir:

```
mysql_secure_installation
```

Komut dosyası sizden yeni bir root şifresi oluşturmanızı, anonim kullanıcıları kaldırmanızı, root oturum açma işlemini uzaktan devre dışı bırakmanızı, test veritabanını kaldırmanızı ve ayrıcalık tablosunu yeniden yüklemenizi isteyecektir:

<img src="materials/42.png" align="center" height="300">

**MariaDB** kurulumunu güvence altına aldıktan sonra, yeni şifreyi kullanarak terminalden **MariaDB** kabuğuna bağlanmayı deneyin:

```
# mysql -u root -p
MariaDB [(none)]> show databases;
```

<img src="materials/43.png" align="center" height="300">

#### 🕯️ PHP için

PHP'yi **PHP-FPM** ve **FastCGI** desteğiyle kurmak için, **PHP**'yi gerekli modüllerle birlikte gösterildiği gibi kurmanız gerekir:

```
dnf -y install php php-mysqlnd php-pdo php-gd php-mbstring php-fpm lighttpd-fastcgi
```

Daha sonra **php-fpm** yapılandırma dosyasını açın:

```
vi /etc/php-fpm.d/www.conf
```

Kullanıcıyı ve grubu gösterildiği gibi **lighttpd** olarak ayarlayın:
```
; Unix user/group of processes
; Note: The user is mandatory. If the group is not set, the default user's group
;       will be used.
; RPM: apache Choosed to be able to access some dir as httpd
user = lighttpd
; RPM: Keep a group allowed to write in log dir.
group = lighttpd
```

Ayrıca php-fpm varsayılan olarak `listen = /run/php-fpm/www.sock` soketini kullanır, bu satırı **TCP** bağlantısı olarak `listen = 127.0.0.1:9000` olarak yapmanız gerekir.

```
;listen = /run/php-fpm/www.sock
listen = 127.0.0.1:9000 
```

Önce:

<img src="materials/44.png" align="center" height="300">

Sonra:

<img src="materials/45.png" align="center" height="300">

Değişiklikleri yaptıktan sonra **php-fpm**'yi başlatmanız, etkinleştirmeniz ve durumunu doğrulamanız gerekir:

```
# systemctl start php-fpm.service
# systemctl enable php-fpm.service
# systemctl status php-fpm.service
```

##### 🏮 Lighttpd'de FastCGI ile PHP ve PHP-FPM'yi etkinleştirme

**PHP**'de **FastCGI** desteğini etkinleştirmek için üç dosyada konfigürasyon değişikliklerini aşağıdaki gibi yapmanız gerekmektedir.

İlk önce bu dosyayı açın, `/etc/php.ini`

```
vi /etc/php.ini
```

`cgi.fix_pathinfo=1` satırını söyleyen aşağıdaki satırın yorumunu kaldırın

Önce:

<img src="materials/46.png" align="center" height="300">

Sonra:

<img src="materials/47.png" align="center" height="300">

Daha sonra `/etc/lighttpd/modules.conf` adlı ikinci dosyayı açın.

```
vi /etc/lighttpd/modules.conf
```

`include conf_dir + "/conf.d/fastcgi.conf"` yazan aşağıdaki satırın yorumunu kaldırın

Önce:

<img src="materials/48.png" align="center" height="300">

Sonra:

<img src="materials/49.png" align="center" height="300">


Daha sonra `/etc/lighttpd/conf.d/fastcgi.conf` adlı üçüncü dosyayı açın.

```
vi /etc/lighttpd/conf.d/fastcgi.conf
```

Şimdi aşağıdaki kapsayıcıyı dosyanın altına ekleyin ve kaydedin:

```
fastcgi.server += ( ".php" =>
        ((
                "host" => "127.0.0.1",
                "port" => "9000",
                "broken-scriptfilename" => "enable"
        ))
)
```

Önce:

<img src="materials/50.png" align="center" height="300">

Sonra:

<img src="materials/51.png" align="center" height="300">

Değişiklikleri yansıtmak ve **PHP** desteğini etkinleştirmek için Lighttpd hizmetini yeniden başlatın:

```
systemctl restart lighttpd
```

Yukarıdaki yapılandırma değişikliklerinin tümünü yaptıktan sonra, `/var/www/lighttpd/` dizini altında bir `phpinfo.php` dosyası oluşturarak **PHP**'de **FastCGI** desteğini test etmeniz gerekir:

```
vi /var/www/lighttpd/phpinfo.php
```

Aşağıdaki satırları buna ekleyin:

```
<?php
phpinfo();
?>
```

**PHP**'de **FastCGI** desteğini test etmek için tarayıcınızı açın ve aşağıdaki URL'ye gidin:

```
http://localhost:8080/phpinfo.php
```

Yanılmıyorsam 'phpinfo.php' sayfasına erişmeye çalıştığınızda '503 Hizmet Kullanılamıyor' hatasını görüyorsunuz:

Yine selinux politikalarına başvurmanız gerekecek:

```
setsebool -P httpd_can_network_connect on
```

_[@@@ mini bir bilgi @@@]_
Bu selinux politikalarının tam listesi için:

```
getsebool -a
```

#### 🎬 WordPress için

Öncelikle şu paketleri kurmalısınız:

```
dnf install -y wget unzip
```

**WordPress** paketlerini indirin:

```
wget https://wordpress.org/latest.zip
```

Dosyaları çıkart:

```
unzip latest.zip
```

Okuma ve yazmada sorun yaşamamak için bazı izin ayarlarını düzenleyelim:

```
# find wordpress/ -type d -exec chmod 755 {} \;
# find wordpress/ -type f -exec chmod 644 {} \;
```

Wordpress dizinine girin ve dosyaları `/var/www/lighttpd/` dizinine kopyalayın:

```
cp -r * /var/www/lighttpd/
```

**MariaDB**'de **WordPress** için bir veritabanı ve kullanıcı oluşturalım:

```
mysql -u root -p
```

**MariaDB**'de aşağıdaki komutları yürütün:

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

Son olarak MariaDB'den _exit_ diyin.

Artık WordPress kurulum sayfasına gidebiliriz:

```
http://localhost:8080/index.php
```

<img src="materials/52.png" align="center" height="300">
</br>
<img src="materials/53.png" align="center" height="300">
</br>
<img src="materials/54.png" align="center" height="300">

Sistemdeki `wp-config.php` dosyasına yazma izniyle ilgili sorun yaşıyorsak.

Çözüme:

```
chcon -t httpd_sys_rw_content_t /var/www/lighttpd/
```

Tekrar deneyin

<img src="materials/55.png" align="center" height="300">
</br>
<img src="materials/56.png" align="center" height="300">
</br>
<img src="materials/57.png" align="center" height="300">
</br>
<img src="materials/58.png" align="center" height="300">
</br>
<img src="materials/59.png" align="center" height="300">


Son olarak, `/var/www/lighttpd/` yolundaki `index.html` dosyasını yeniden adlandırmalı veya silmelisiniz:

```
# mv /var/www/lighttpd/index.html /var/www/lighttpd/d.html
or
# rm -rf /var/www/lighttpd/index.html
```

Ana sayfanızı ziyaret edin:

```
http://localhost:8080
```

### 📺 Hizmetinizin Seçimi

Benim seçimim _Python'un http sunucusunu_ hizmet olarak sunmak.

Bunun için önce 'python3' paketini kurun:

```
dnf install -y python3
```

_Firewall_'da gerekli port izinlerini verin:

```
firewall-cmd --permanent --zone=public --add-port=5050/tcp
```

Güvenlik duvarını yeniden yükle:

```
firewall-cmd --reload
```

VirtualBox ayarlarındaki **port yönlendirme** ayarından _5050_ bağlantı noktasını ekleyin:

<img src="../debian/materials/35.png" align="center" height="300">

Hizmeti oluşturmak için `/etc/systemd/system` dizininde `python-http-server.service` adında bir dosya oluşturun.

```
vi /etc/systemd/system/python-http-server.service
```

İçine şunları yazın:

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

Kaydedip çıktıktan sonra hizmeti başlatmak için:

```
# systemctl enable python-http-server.service
# systemctl start python-http-server.service
# systemctl status python-http-server.service
```

Etkinse tarayıcı aracılığıyla erişin:

```
http://localhost:5050
```

**🏁 Ve son olarak Bölüm Bonusu burada bitiyor.. 🏁**

## 📒 Kısım 5 - Gönderim ve Akran Değerlendirmesi

Artık her şey bittiğine göre disk imzanızı almanın zamanı geldi:

Öncelikle _/goinfre_ dizinine kurduğumuz dosyaya girip sanal makinenizi bulmalısınız.
Buranın nerede olduğunu bilmediğim için oraya gittiğinizi varsayıyorum.

Bunu yazın:

```
shasum <your_virtual_machine>.vdi.
```

Biraz zaman alabilir..

Disk imzanız geldiğinde 'signature.txt' dosyasına gönderip push alacaksınız. Hepsi bu. Buraya kadar geldiyseniz, 🥳TEBRİKLER!!!🥳

**🏁Ve nihayet Kısım 5 burada bitiyor..🏁**

## 📚 Kaynaklar

1. [SSH Port Policies and Configures Setup](https://serverfault.com/questions/538037/sshd-service-fails-to-start)
2. [Linux Groups](https://www.redhat.com/sysadmin/linux-groups)
3. [PASSWORD POLICY (PAM CONFIG)](https://ostechnix.com/how-to-set-password-policies-in-linux/)
4. [Bonus Lighttpd Config](https://www.tecmint.com/install-lighttpd-rockylinux-almalinux/)
5. [Install WordPress in Virtual Machine (Video)](https://www.youtube.com/watch?v=PsMhopODLTY)
6. [Install WordPress in Locally (Video)](https://www.youtube.com/watch?v=PhNxEZcxXV0)

**🏁Ve son olarak README.md burada bitiyor..🏁**

<img src="../debian/materials/matrix.gif" align="right" height="550">
