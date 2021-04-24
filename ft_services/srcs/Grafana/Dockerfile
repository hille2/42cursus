FROM alpine:3.12

MAINTAINER sgath <sgath@student.21-school.ru>

RUN apk update && apk add --no-cache supervisor \
	grafana --repository=http://dl-cdn.alpinelinux.org/alpine/edge/community/ --allow-untrusted\
	telegraf --repository http://dl-cdn.alpinelinux.org/alpine/latest-stable/community/ --allow-untrusted
COPY /supervisord.conf /etc/supervisord.conf
COPY /telegraf.conf /etc/telegraf/telegraf.conf
COPY /grafana.db /usr/share/grafana/data/grafana.db
EXPOSE 3000
CMD supervisord

