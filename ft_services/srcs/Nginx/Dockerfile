FROM alpine:3.12

MAINTAINER sgath <sgath@student.21-school.ru>

RUN apk update &&\
	apk add --no-cache nginx openssl supervisor \
	telegraf --repository http://dl-cdn.alpinelinux.org/alpine/latest-stable/community/ --allow-untrusted &&\
	mkdir -p /run/nginx
COPY /nginx.conf /etc/nginx/
COPY /index.html /var/www/index.html
COPY /supervisord.conf /etc/supervisord.conf
COPY /telegraf.conf /etc/telegraf/telegraf.conf
RUN openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj \
	"/C=RU/ST=Republic_of_Tatarstan/L=Kazan/O=Ecole42/OU=School21/CN=sgath/emailAddress=sgath@student.21-school.ru" \
	-keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt 
EXPOSE 80 443
CMD supervisord