# !/bin/bash

#ssl protocol
openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=RU/ST=Republic_of_Tatarstan/L=Kazan/O=Ecole42/OU=School21/CN=sgath/emailAddress=sgath@student.21-school.ru" -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt

#start service
service nginx start
service php7.3-fpm start
service mysql start

#install wordpress
echo "CREATE DATABASE wordpress DEFAULT CHARACTER SET utf8 COLLATE utf8_unicode_ci;" | mysql -u root
echo "GRANT ALL ON wordpress.* TO 'root'@'localhost';" | mysql -u root
echo "update mysql.user set plugin = 'mysql_native_password' where user='root';" | mysql -u root
mv /wordpress /var/www/html
chown -R www-data:www-data /var/www/html/wordpress

#install phpMyAdmin
mv /phpMyAdmin-5.0.4-all-languages /var/www/html/phpmyadmin


#u a great person!
bash
