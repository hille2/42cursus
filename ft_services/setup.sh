# !/bin/sh

#if need restart minikube
#minikube stop
#minikube delete 

#start minikube
#minikube start --vm-driver=virtualbox --cpus=4 --memory=4G --disk-size=50G
#minikube addons enable metallb
eval $(minikube docker-env)

#if metallb doesn't issue ip
#docker pull metallb/speaker:v0.8.2
#docker pull metallb/controller:v0.8.2

#metallb
kubectl apply -f srcs/configmap.yaml

#clear all docker images
docker rmi $(docker images -f dangling=true -q)

#clear all pod
kubectl delete svc nginx-svc
kubectl delete deployment nginx-deployment

kubectl delete deployment mysql-deployment
kubectl delete svc mysql-svc

kubectl delete deployment wp-deployment
kubectl delete svc wp-svc

kubectl delete deployment phpma-deployment
kubectl delete svc phpma-svc

kubectl delete deployment grafana-deployment
kubectl delete svc grafana-svc

kubectl delete deployment ftps-deployment
kubectl delete svc ftps-svc

#start nginx
docker build -t nginx_image srcs/Nginx
kubectl apply -f srcs/Nginx/nginx.yaml

#start mysql
docker build -t mysql_image srcs/Mysql
kubectl apply -f srcs/Mysql/mysql.yaml

#start wordpress
docker build -t wp_image srcs/Wordpress
kubectl apply -f srcs/Wordpress/wp.yaml

#start phpMyadmin
docker build -t phpma_image srcs/phpMyAdmin
kubectl apply -f srcs/phpMyAdmin/phpma.yaml

#start FTPS
docker build -t ftps_image srcs/FTPS
kubectl apply -f srcs/FTPS/ftps.yaml

#start InfluxDB
docker build -t influxdb_image srcs/InfluxDB
kubectl apply -f srcs/InfluxDB/influxdb.yaml

#start Grafana
docker build -t grafana_image srcs/Grafana
kubectl apply -f srcs/Grafana/grafana.yaml
