# !/bin/bash
eval $(minikube docker-env)
kubectl delete deployment wp-deployment
kubectl delete svc wp-svc
docker rmi wp_image

docker build -t wp_image .
kubectl apply -f wp.yaml