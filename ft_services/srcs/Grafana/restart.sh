# !/bin/bash

eval $(minikube docker-env)
kubectl delete deployment grafana-deployment
kubectl delete svc grafana-svc

docker build -t grafana_image .
kubectl apply -f grafana.yaml