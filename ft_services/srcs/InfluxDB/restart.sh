# !/bin/bash

eval $(minikube docker-env)
kubectl delete deployment influxdb-deployment
kubectl delete svc influxdb-svc

docker build -t influxdb_image .
kubectl apply -f influxdb.yaml