FROM alpine:3.12

MAINTAINER sgath <sgath@student.21-school.ru>

RUN apk update && apk add --no-cache mysql mysql-client supervisor \
	telegraf --repository http://dl-cdn.alpinelinux.org/alpine/latest-stable/community/ --allow-untrusted
COPY /mysql.sh ./mysql.sh
COPY /my.cnf /etc/my.cnf
COPY /supervisord.conf /etc/supervisord.conf
COPY /mysql-svc.sql ./mysql-svc.sql
COPY /telegraf.conf /etc/telegraf/telegraf.conf
RUN chmod +x ./mysql.sh &&\
	chmod +x /etc/my.cnf &&\
	chmod +x /etc/supervisord.conf
RUN mkdir /run/mysqld &&\
	chmod +x /run/mysqld
EXPOSE 3306
CMD ./mysql.sh
