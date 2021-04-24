FROM alpine:3.12

MAINTAINER sgath <sgath@student.21-school.ru>

RUN apk update && apk add --no-cache php7-fpm php7-common php7-session php7-iconv php7-json \ 
	php7-gd php7-curl php7-xml php7-mysqli php7-imap php7-cgi fcgi php7-pdo \
	php7-pdo_mysql php7-soap php7-xmlrpc php7-posix php7-mcrypt php7-gettext \
	php7-ldap php7-ctype php7-dom php7-mbstring\
	wget supervisor nginx telegraf --repository http://dl-cdn.alpinelinux.org/alpine/latest-stable/community/ --allow-untrusted
RUN wget http://wordpress.org/latest.tar.gz && tar -xzvf latest.tar.gz &&\
	rm latest.tar.gz &&\
	mkdir -p /run/nginx &&\
	mv /wordpress /var/www/ &&\
	chmod +x /var/www/wordpress
COPY /wp-config.php /var/www/wordpress
COPY /supervisord.conf /etc/supervisord.conf
COPY /default.conf /etc/nginx/nginx.conf
COPY /telegraf.conf /etc/telegraf/telegraf.conf
RUN chmod +x /var/www/wordpress/wp-config.php &&\
	chmod +x /etc/nginx/nginx.conf
EXPOSE 5050
CMD supervisord