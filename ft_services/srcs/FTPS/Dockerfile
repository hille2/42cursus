FROM alpine:3.12

MAINTAINER sgath <sgath@student.21-school.ru>

RUN apk update && apk add --no-cache vsftpd openssl supervisor \
	telegraf --repository http://dl-cdn.alpinelinux.org/alpine/latest-stable/community/ --allow-untrusted
RUN mkdir -p /var/sgath &&\
	chmod +x /var/sgath &&\
	adduser -D sgath && echo "sgath:0000" | chpasswd
COPY /vsftpd.conf /etc/vsftpd/vsftpd.conf
COPY /supervisord.conf /etc/supervisord.conf
COPY /telegraf.conf /etc/telegraf/telegraf.conf
RUN openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj \
	"/C=RU/ST=Republic_of_Tatarstan/L=Kazan/O=Ecole42/OU=School21/CN=sgath/emailAddress=sgath@student.21-school.ru" \
	-keyout /etc/ssl/private/vsftpd.key -out /etc/ssl/certs/vsftpd.pem
EXPOSE 21 21212
RUN chmod +x /etc/vsftpd/vsftpd.conf
CMD supervisord