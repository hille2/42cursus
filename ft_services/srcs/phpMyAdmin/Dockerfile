FROM alpine:3.12

MAINTAINER sgath <sgath@student.21-school.ru>

RUN apk update && apk add --no-cache php7-fpm php7-common php7-session php7-iconv php7-json \ 
	php7-gd php7-curl php7-xml php7-mysqli php7-imap php7-cgi fcgi php7-pdo \
	php7-pdo_mysql php7-soap php7-xmlrpc php7-posix php7-mcrypt php7-gettext \
	php7-ldap php7-ctype php7-dom php7-mbstring\
	wget supervisor nginx openssl telegraf --repository http://dl-cdn.alpinelinux.org/alpine/latest-stable/community/ --allow-untrusted
RUN wget http://files.directadmin.com/services/all/phpMyAdmin/phpMyAdmin-5.0.4-all-languages.tar.gz &&\
	tar zxvf phpMyAdmin-5.0.4-all-languages.tar.gz &&\
	rm phpMyAdmin-5.0.4-all-languages.tar.gz &&\
	mv /phpMyAdmin-5.0.4-all-languages /var/www/phpmyadmin &&\
	chmod +x /var/www/phpmyadmin &&\
	mkdir -p /run/nginx
RUN openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj \
	"/C=RU/ST=Republic_of_Tatarstan/L=Kazan/O=Ecole42/OU=School21/CN=sgath/emailAddress=sgath@student.21-school.ru" \
	-keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt 
EXPOSE 5000
COPY /config.inc.php /var/www/phpmyadmin/config.inc.php
COPY /supervisord.conf /etc/supervisord.conf
COPY /default.conf /etc/nginx/nginx.conf
COPY /telegraf.conf /etc/telegraf/telegraf.conf
CMD supervisord