FROM debian:buster

MAINTAINER sgath <sgath@student.21-school.ru>

RUN apt-get update && apt-get -y upgrade
RUN apt-get -y install wget unzip vim
RUN apt-get -y install nginx mariadb-server && \
    apt-get -y install php-fpm php-mbstring php-gettext php-mysql && \
    wget https://files.phpmyadmin.net/phpMyAdmin/5.0.4/phpMyAdmin-5.0.4-all-languages.zip https://wordpress.org/latest.tar.gz && \
    tar -xzvf latest.tar.gz && unzip phpMyAdmin-5.0.4-all-languages.zip
EXPOSE 80 443
COPY srcs/start_server.sh .
COPY srcs/wp-config.php /wordpress
COPY srcs/default /etc/nginx/sites-available/default
COPY srcs/config.inc.php phpMyAdmin-5.0.4-all-languages/config.inc.php
CMD bash start_server.sh 

